#include<iostream>
#include<vector>
#include<climits>
#include<cassert>
#include<utility>
#include<unordered_set>

using namespace std;


struct StationInfo {
    int num = 0;
    int train_time = INT_MAX;
    int walk_time = INT_MAX;
    int min_time = INT_MAX;
    vector<StationInfo*> downstream;
    vector<StationInfo*> upstream;

    int last_stop = -1;
    bool is_dummy = true;

    // return true if min_time modified
    void update_train_time(int new_time) {
		if (is_dummy) return;
        train_time = new_time;
        int new_min_time = std::min(train_time, walk_time);
        if (min_time != new_min_time) {
            min_time = new_min_time;
            for (auto* s : downstream) {
                s->update_walk_time(num, min_time);
            }
        }
    }

    void update_walk_time(int who, int new_time) {
		if (is_dummy) return;
        if (last_stop == who) {
            if ((new_time + 1) < walk_time) {
                walk_time = new_time + 1;
            } else {
                // recompute
                int wtime = INT_MAX;
                for (auto* s : upstream) {
                    if (wtime > s->get_min() + 1) {
                        wtime = s->get_min() + 1;
                        last_stop = s->num;
                    }
                }
                walk_time = wtime;
            }
        } else {
            if ((new_time + 1) < walk_time) {
                walk_time = new_time + 1;
                last_stop = who;
            }
        }


        int new_min_time = min(walk_time, train_time);

        if (new_min_time != min_time) {
            min_time = new_min_time;
            for (auto* s : downstream) {
                s->update_walk_time(num, min_time);
            }
        }
    }

    int get_min() {
        return min_time;
    }
};

void update_min_time(
        vector<StationInfo>& stations,
        int s1, int s2) {
    assert(s1 < stations.size());
    assert(s2 < stations.size());
    int s1_time = stations[s1].train_time;
    int s2_time = stations[s2].train_time;

    stations[s1].update_train_time(s2_time);
    stations[s2].update_train_time(s1_time);
}


int main() {
    int n, w, d;
    cin >> n >> w >> d;
    vector<StationInfo> stations(n + 1);
    vector<int> in_route(n);

    for (int i = 1; i < n + 1; i++) {
        stations[i].num = i;
    }

    for (int i = 0; i < w; i++) {
        int from, to;
        cin >> from >> to;
        stations[from].downstream.push_back(
                &stations[to]);
        stations[to].upstream.push_back(
                &stations[from]);
    }

	unordered_set<int> non_dummies;
	unordered_set<int> visited;
	vector<StationInfo*> stack;
	stack.push_back(&stations[n]);
	while (!stack.empty()) {
        auto* current = stack.back();
        stack.pop_back();
        if (visited.find(current->num) != visited.end()) {
            continue;
        }
        visited.insert(current->num);
        current->is_dummy = false;
        for (auto* up : current->upstream) {
            stack.push_back(up);
        }
    }

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        in_route[i] = s;
        stations[s].train_time = i;
        stations[s].update_train_time(i);
    }

    for (int i = 0; i < d; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        assert(s1 <= n);
        assert(s2 <= n);
        stations[in_route[s1 - 1]].update_train_time(s2 - 1);
        stations[in_route[s2 - 1]].update_train_time(s1 - 1);
        swap(in_route[s1 - 1], in_route[s2 - 1]);
        cout << stations[n].get_min() << endl;
    }

    return 0;
}

