#include <iostream>
using namespace std;

int getNotes(int rupees);

int main() {
    int rupees;
    cout << "Howmany Rupees are there? : ";
    cin >> rupees;
    getNotes(rupees);
    return 0;
}

int getNotes(int rupees) {
    // cout << "you have " << rupees << " rupees" << endl;
    int arr[] = { 2000,500,200,100,50,10,5,2,1 };
    int counterArr[]={};
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrLength; i++) {
        // cout << arr[i] << endl;
        while (rupees / arr[i]) {
            cout << rupees << endl;
        }

    }

    return 0;
}