#include <queue>
#include <cstdio>
#include <climits>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include <memory>
#include <cassert>

using namespace std;

size_t hash_str(const string* x) {
    return std::hash<string>()(*x);
}

bool eq_str(const string* x, const string* y) {
    return *x == *y;
}

struct Client {
  int priority;
  int time;
  const string* name;
  bool operator<(const Client& rhs) const {
    if (priority < rhs.priority) {
      return true;
    }
    if (priority > rhs.priority) {
      return false;
    }
    return rhs.time < time;
  }

  Client() : priority(INT_MIN), time(1000000), name(nullptr) {}

  Client(int priority, int time, const string* name) :
    priority(priority), time(time), name(name) {}
};



class Bank {
    using Cola = priority_queue<Client>;

  public:
    void llega(string name, int priority) {
        nombres.emplace_back(new string(move(name)));
        insertar(*nombres.back(), priority, tiempo);
        ++tiempo;
    }

    void insertar(const string& name, int priority, int t) {
        char pos = name[0] - 'A';
        colas[pos].emplace(priority - boosts[pos], t, &name); // log
    }

    void sorteo(char letra, int priority) {
      boosts[letra - 'A'] += priority; // const
    }

    const string& atender() {
      Client mejor;
      int pos;
      for (int i = 0; i < 26; i++) {
        if (colas[i].empty()) continue;
        auto top = colas[i].top();  // const
        top.priority += boosts[i];
        if (mejor < top) {
          mejor = top;
          pos = i;
        }
      }
      const string* name = mejor.name;
      colas[pos].pop(); // log
      return *name;
    }

    Bank() {
      for (int i = 0; i < 26; i++) {
        boosts[i] = 0;
      }
    }

  private:
    // cosas
    std::vector<unique_ptr<string>> nombres;
    array<Cola, 26> colas;
    array<int, 26> boosts;
    int tiempo = 0;
};

int main() {
  Bank bank;
  int n;
  scanf("%d\n", &n);
  char command;
  char name[100];
  int priority;
  for (int i = 0; i < n; i++) {
    scanf("%c ", &command);
    switch (command) {
      case 'C':
        scanf("%s %d\n", name, &priority);
        bank.llega(name, priority);
        break;
      case 'S':
        scanf("%s %d\n", name, &priority);
        bank.sorteo(name[0], priority);
        break;
      case 'A':
        scanf("\n");
        puts(bank.atender().c_str());
        break;
      default:
        break;
    }

  }
  return 0;
}