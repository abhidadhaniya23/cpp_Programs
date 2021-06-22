#include <iostream>
using namespace std;

#include <cstdlib> 
#include <ctime>


int main(void) {
    srand(time(0));
    // limit = 1 => 10
    cout << "Random No. " << (rand() % 10) + 1 << endl;

    return 0;
}
