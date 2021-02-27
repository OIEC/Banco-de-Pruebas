#include <iostream>


using namespace std;

class Bank {
  public:
    void llega(const std::string& name, int priority) {

    }

    void sorteo(char letra, int priority) {

    }

    string atender() {
      return "";
    }

  private:
    // cosas

};

int main() {
  Bank bank;
  int n;
  cin >> n;
  char command;
  string name;
  int priority;
  for (int i = 0; i < n; i++) {
    cin >> command;
    switch (command) {
      case 'C':
        cin >> name >> priority;
        bank.llega(name, priority);
        break;
      case 'S':
        cin >> name >> priority;
        bank.sorteo(name[0], priority);
        break;
      case 'A':
        cout << bank.atender() << endl;
        break;
      default:
        break;
    }

  }
  return 0;
}