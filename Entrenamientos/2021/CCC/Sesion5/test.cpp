#include<iterator>
#include<map>
#include<iostream>
using namespace std;

int main() {
    map<int, int> a;
    a[2] = 5;
    a[3] = 5;
    auto b = make_reverse_iterator(a.begin());
    

    cout << ((b) == a.rend()) << endl;
    cout << ((b)->first) << endl;

}