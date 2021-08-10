#include <iostream>
using namespace std;

int main() {
    string str;

    system("md virus-files");
    system("cd virus-files");
    system("echo > virus1.bat");
    system("echo > virus2.bat");
    system("echo > virus3.bat");
    system("cls");
    
    cout << endl;
    cout << "Virus successfully injected in your pc...! by Abhi...!\n" << endl;
    cout << "Now, if you try to DELETE or OPEN this folder (virus files) then 3-virus files are activated automatically and boom...!\n" << endl;
    cout << "I really apologize for this work...!\n" << endl;

    cout << "Enter anything...!";
    cin >> str;

    return 0;
}