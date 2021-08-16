#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

// bool isSymbol(char ch);
// char convert_to_lowercase(char ch);

class PlayWithString {
private:
    char ch;
public:
    char convert_to_lowercase(char ch) {
        if (ch >= 65 && ch <= 90) {
            ch += 32;
            // cout << "Converted char : " << ch << endl;
        }
        return ch;
    }

    bool isSymbol(char ch) {
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
            return false;
        else {
            // cout << "Please Enter only alphabats" << endl;
            return true;
        }
    }
};


int main() {

    PlayWithString obj;

    string name = "ABhioasi";
    int i;
    cout << "Howmany name do you want to add ? ";
    cin >> i;
    string character[i] = { "Abhi","Dadhaniya" };
    string lowerCaseName;

    for (int i = 0;i < name.length();i++) {
        lowerCaseName += obj.convert_to_lowercase(name[i]);
        if (obj.isSymbol(name[i])) {
            cout << "Please enter only alphabats" << endl;
            break;
        }
    }
    cout << endl;
    cout << typeid(lowerCaseName).name() << endl;
    // character[sizeof(character) / sizeof(character[0])] = lowerCaseName;
    for (int i = 0;i < sizeof(character) / sizeof(character[0]);i++) {
        cout << "i : " << i << "=>" << character[i] << endl;
        cout << endl;
    }

    return 0;
}