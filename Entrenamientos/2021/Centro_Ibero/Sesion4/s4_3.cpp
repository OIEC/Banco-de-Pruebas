#include<iostream>
#include<vector>
#include<climits>
#include<cassert>
#include<utility>
#include<set>
#include<unordered_set>
#include<tuple>
#include<deque>

using namespace std;

struct StationInfo {
    int num = -1;
    int walk_time_to_n = -1;
    int train_time = -1;

    StationInfo() = default;
    StationInfo(const StationInfo&) = default;
    StationInfo(StationInfo&&) = default;
    StationInfo& operator=(StationInfo&&) = default;
    StationInfo& operator=(const StationInfo&) = default;

    int total_time() const {
        if (walk_time_to_n >= 0) {
            return train_time + walk_time_to_n;
        }
        return INT_MAX;
    }

    bool operator<(const StationInfo& rhs) const {
        if (total_time()!= rhs.total_time()) {
            return total_time() < rhs.total_time();
        }
        return num < rhs.num;
    }

    void print() const {
        cout << num << " " << walk_time_to_n << " " << train_time << endl;
    }
};


int main() {
    int n, w, d;
    cin >> n >> w >> d;

    vector<StationInfo> stations(n + 1);
    vector<int> in_route(n);
    vector<vector<int>> upstreams(n + 1);

    for (int i = 0; i < n + 1; i++) {
        stations[i].num = i;
    }


    for (int i = 0; i < w; i++) {
        int from, to;
        cin >> from >> to;
        upstreams[to].push_back(from);
    }


	unordered_set<int> visited;
	deque<tuple<int, int>> q;
	q.emplace_back(n, 0);
	while (!q.empty()) {
        int current, dist;
        std::tie(current, dist) = q.front();
        q.pop_front();
        if (visited.find(current) != visited.end()) {
            continue;
        }
        visited.insert(current);
        auto& info = stations[current];
        if (info.walk_time_to_n == -1) {
            info.walk_time_to_n = dist;
        }

        for (int up : upstreams[current]) {
            q.emplace_back(up, dist + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        in_route[i] = s;
        stations[s].train_time = i;
    }

    set<StationInfo> station_ordered;
    for (int s : visited) {
        station_ordered.insert(stations[s]);
    }


    for (int i = 0; i < d; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        StationInfo& to_change_1 = stations[in_route[s1 - 1]];
        StationInfo& to_change_2 = stations[in_route[s2 - 1]];

        if (station_ordered.erase(to_change_1)) {
            to_change_1.train_time = s2 - 1;
            station_ordered.insert(to_change_1);
        } else {
            to_change_1.train_time = s2 - 1;
        }
        if (station_ordered.erase(to_change_2)) {
            to_change_2.train_time = s1 - 1;
            station_ordered.insert(to_change_2);
        } else {
            to_change_2.train_time = s1 - 1;
        }

        swap(in_route[s1 - 1], in_route[s2 - 1]);

        cout << station_ordered.begin()->total_time() << endl;
    }

    return 0;
}

