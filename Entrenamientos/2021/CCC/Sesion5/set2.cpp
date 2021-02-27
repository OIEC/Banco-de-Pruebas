// set::find
#include <cstdlib>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

bool duplicate(const std::vector<int>& input) {
    std::set<int> s;
    for (auto x : input) {
        s.insert(x);
    }
    return s.size() < input.size();
}

int main ()
{
  std::vector<int> input;

  srand(time(nullptr));

  for (int i=1; i<=2000000; i++) {
    input.push_back(rand());
  }

  cout << duplicate(input) << endl;
  
  return 0;
}