#include <iostream>
#include <cstdio>
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

class Bank {
    using Cola = map<pair<int, int>, const string*>;
    using Position = Cola::iterator;
  public:
    void llega(string name, int priority) {
        nombres.emplace_back(new string(move(name)));
        insertar(*nombres.back(), priority, tiempo);
        ++tiempo;
    }

    void insertar(const string& name, int priority, int t) {
        pair<int, int> p(priority, t);
        auto pos = cola.insert(make_pair(p, &name)); // log
        assert(pos.second);
        initiales[name[0] - 'A'].push_back(pos.first); // const
        pos_in_initiales[&name] = --initiales[name[0]-'A'].end(); // log?
    }

    bool need_to_move(Position p, int priority) const {
        auto nn = next(p);
        if (nn == cola.end()) {
            return false;
        }
        if (nn->first.first > p->first.first) {
            return false;
        }
        if (nn->first.first == p->first.first && nn->first.second > p->first.first) {
            return false;
        }
        return true;
    }

    void exec_sorteo() {
        for (int i = 0; i < 26; i++) {
          if (pending[i] == 0) {
            continue;
          }
          std::list<Position> nuevos;
          for (Position p : initiales[i]) {
            std::pair<int, int> new_p = p->first;
            const string* name = p->second;
            new_p.first += pending[i];
            //if (need_to_move(p, new_p.first)) {
                cola.erase(p);
                auto new_iter = cola.insert(make_pair(new_p, name));
                nuevos.push_back(new_iter.first);
            //} else {
            //    const_cast<pair<int, int>&>(p->first) = new_p;
            //    nuevos.push_back(p);
            //}
            pos_in_initiales[name] = --nuevos.end();
          }
          initiales[i].swap(nuevos);
          pending[i] = 0;
        }
        dirty = false;
    }

    void sorteo(char letra, int priority) {
      if (priority == 0) return;
        pending[letra - 'A'] += priority;
        dirty = true;
    }

    const string& atender() {
        if(dirty) exec_sorteo();
        auto last = --cola.end();
        const string* name = last->second;
        cola.erase(last);
        auto iter = pos_in_initiales.find(name);
        assert(iter != pos_in_initiales.end());
        initiales[name->at(0) - 'A'].erase(iter->second);
        pos_in_initiales.erase(iter);
        return *name;
    }

    Bank() {
      for (int i = 0; i < 26; i++) {
        pending[i] = 0;
      }
    }

  private:
    // cosas
    std::vector<unique_ptr<string>> nombres;
    Cola cola;
    // puede ser array
    array<std::list<Position>, 26> initiales;
    array<int, 26> pending;
    unordered_map<const string*, std::list<Position>::iterator> pos_in_initiales;
    int tiempo = 0;
    bool dirty = false;
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