
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int nivel = 0;
  std::vector<int> monstruos;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    monstruos.push_back(m);
  }
  std::sort(monstruos.begin(), monstruos.end());
  for (auto m : monstruos) {
        if (nivel >= m)
            nivel += 1;
        else
            break;
  }
  cout << nivel << endl;
  return 0;
}
