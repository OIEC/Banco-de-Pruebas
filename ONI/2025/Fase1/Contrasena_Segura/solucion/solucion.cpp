#include <bits/stdc++.h>
using namespace std;

int main() {
    string password;
    getline(cin, password); // leer con espacios incluidos
    
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    string specials = "!@#$%^&*()-+";

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else if (specials.find(c) != string::npos) hasSpecial = true;
    }

    if (password.size() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        cout << "SEGURA" << endl;
    } else {
        cout << "INSEGURA" << endl;
    }

    return 0;
}