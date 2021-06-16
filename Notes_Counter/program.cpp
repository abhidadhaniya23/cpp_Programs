#include <iostream>
using namespace std;

int countNotes(int rupees);

int main() {
    int rupees;
    cout << "\nEnter the total amount of cash in rupees : ";
    cin >> rupees;
    cout << endl;
    countNotes(rupees);
    return 0;
}

int countNotes(int rupees) {
    int arr[] = { 2000,500,200,100,50,10,5,2,1 };
    int counterArr[] = { 0,0,0,0,0,0,0,0,0 };
    int temp_counter_arr[] = { 0,0,0,0,0,0,0,0,0 };
    int notesCounter = 0;
    int resultRupees = 0;
    int arrLength = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrLength; i++) {
        temp_counter_arr[i] = rupees / arr[i];
        // cout << rupees << " / " << arr[i] << " is equal to : " << temp_counter_arr[i] << endl;
    }
    for (int i = 0; i < arrLength; i++) {
        if (i == 0) {
            counterArr[i] = temp_counter_arr[i];
        }
        else {
            counterArr[i] = (rupees - (temp_counter_arr[i - 1] * arr[i - 1])) / arr[i];
        }
    }
    for (int i = 0; i < arrLength; i++) {
        notesCounter += counterArr[i];
        if (counterArr[i] != 0) {
            switch (i) {
            case 7:
                cout << "Number of " << arr[i] << " rupees coin : " << counterArr[i] << endl;
                break;
            case 8:
                cout << "Number of " << arr[i] << " rupees coin : " << counterArr[i] << endl;
                break;

            default:
                cout << "Number of " << arr[i] << " rupees note : " << counterArr[i] << endl;
                break;
            }
        }
        resultRupees += counterArr[i] * arr[i];
    }
    cout << "Number of total cash notes : " << notesCounter << endl << endl;
    cout << "total counted rupees from result : " << resultRupees << endl << endl;

    return 0;
}