#include <iostream>
using namespace std;

/*
|\
| \
|  \
|   \
|    \
>>>>>>
*/

int main() {
    int num;
    cout << "\nEnter a number >=5 and see the magic! : ";
    cin >> num;
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == num) {
                cout << ">";
            }
            if (j == 0) {
                if (i == num)
                    continue;
                cout << "|";
            }
            if (j < i) {
                if (i == num)
                    continue;
                cout << " ";
            }
            if (j == i) {
                if (i == num)
                    continue;
                cout << "\\";
            }
        }
        cout << "\n";
    }

    return 0;
}