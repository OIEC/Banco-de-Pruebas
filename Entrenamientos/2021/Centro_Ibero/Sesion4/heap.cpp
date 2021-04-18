#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int padre(int pos) {
    return (pos - 1) / 2;
}
int hijo1(int pos) {
    return 2*pos + 1;
}
int hijo2(int pos) {
    return 2*pos + 2;
}

void sift_up(vector<int>& arr, int index) {
    int p = padre(index);
    while (p >= 0 && arr[index] > arr[padre(index)] ) {
        swap(arr[index], arr[padre(index)]);
        index = p;
        p = padre(index);
    }
}

void sift_down(vector<int>& arr, int index) {
    int h1 = hijo1(index);
    int h2 = hijo2(index);
    int largest_h;
    if (h2 >= arr.size()) {
        largest_h = h1;
    } else {
        largest_h = arr[h1] < arr[h2] ? h2 : h1;
    }
    while (largest_h < arr.size() && arr[largest_h] > arr[index]) {
        swap(arr[largest_h], arr[index]);
        index = largest_h;
        h1 = hijo1(index);
        h2 = hijo2(index);
        if (h2 >= arr.size()) {
            largest_h = h1;
        } else {
            largest_h = arr[h1] < arr[h2] ? h2 : h1;
        }
    }
}

void make_heap(vector<int>& arr) {
    for (int i = arr.size() - 1; i >= 0; i--) {
        sift_down(arr, i);
    }
}

void remove_head(vector<int>& arr) {
    arr[0] = arr.back();
    arr.pop_back();
    sift_down(arr, 0);
}

void insert(vector<int>& arr, int val) {
    arr.push_back(val);
    sift_up(arr, arr.size() - 1);
}

vector<int> heap_sort(vector<int> arr) {
    vector<int> res;
    make_heap(arr);
    while (!arr.empty()) {
        res.push_back(arr[0]);
        remove_head(arr);
    }
    return res;
}

class MyCompare {
public:
    bool operator()(int lhs, int rhs) {
        return abs(lhs) > abs(rhs);
    }
};

int main() {
    vector<int> a = { 2, 3, 3, 5, 19, 2, 10, 1, 0,  123, 3, 12, 82};
    vector<int> b = a;

    make_heap(a);
    cout << "=== orden monticulo ===" << endl;
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
    std::make_heap(b.begin(), b.end());
    cout << "=== orden monticulo std ===" << endl;
    for (int i : b) {
        cout << i << " ";
    }
    cout << endl;

    cout << "=== ordenenado ===" << endl;
    vector<int> sorted = heap_sort(a);
    for (int x : sorted) {
        cout << x << " ";
    }
    cout << endl;

    priority_queue<
        int,
        vector<int>,
        MyCompare> q;

    vector<int> abc = { -2, -3, 3, 5, 19, -2, -10, -1, 0,  123, 3, 12, 82};
    for (int x : abc) {
        q.push(x);
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

}
