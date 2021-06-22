#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int arr[] = {};
    // int arrLength = sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    while (index != 10) {
        // arr[index] = (rand() % 10) + 1;
        cout<<index<<endl;
        // cout << "arr[" << index << "] : " << arr[index] << endl;
        index++;
    }

    return 0;
}