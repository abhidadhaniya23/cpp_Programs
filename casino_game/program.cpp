#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function definitions
void getRules();
int getAmountData();
int gameLogic();
// int amountOperations(int totalAmount, int betAmount);

// global variables
string userName;
int totalAmount = 0;
int betAmount = 0;

// main function
int main(void) {
    // call getRules defined function
    getRules();
    // defining variable 
    cout << "\nPlease enter your name : ";
    cin >> userName;
    do {
        if (totalAmount == 0) {
            getAmountData();
            gameLogic();
        }
        else {
            string playAgain;
            // amountOperations(totalAmount,betAmount);
            cout << "\nDO you want to play again ? (y/n) : ";
            cin >> playAgain;
            if (playAgain == "y" || playAgain == "Y") {
                gameLogic();
            }
            else if (playAgain == "n" || playAgain == "N") {
                cout << "Thank you for playing this game !\n" << endl;
                break;
            }
            else {
                cout << "Please enter proper characters." << endl;
                cout << "\nDO you want to play again ? (y/n) : ";
                cin >> playAgain;
            }
        }
    } while (totalAmount != 0);

    return 0;
}

// function for amount data about total howmany $ have user... and it's all about... 
int getAmountData() {
    cout << "\nEnter your balance : $";
    cin >> totalAmount;
    cout << "Your total balance is: " << totalAmount << "$" << endl;
    return 0;
}

// game logic
int gameLogic() {
    int betAmountScope;
    do {
        if (totalAmount < betAmountScope) {
            cout << "Your betting amount should be less than your balance, please bid again: $";
            cin >> betAmountScope;
        }
        else {
            cout << "Please enter your bid amount : $";
            cin >> betAmountScope;
        }
    } while (totalAmount < betAmountScope);
    cout << "\nyou bet " << betAmountScope << "$\n" << endl;
    betAmount = betAmountScope;

    // generating random number
    srand(time(0));
    // limit = 1 => 100
    int randomNumber = (rand() % 100) + 1;
    // cout << "Random No is : " << randomNumber << endl;
    int userChoice;
    cout << "\nHey " << userName << "! Guess a number : ";
    cin >> userChoice;
    do {
        if (randomNumber < userChoice) {
            if (userChoice - randomNumber < 10) {
                cout << "good! you are too close please try to guess the correct number...!" << endl;
            }
            betAmount -= 1;
            cout << "Now your bet amount is : $" << betAmount << endl;
            cout << "Please guess lower number...!" << endl;
            cout << "\nguess again : ";
            cin >> userChoice;
        }
        else if (randomNumber > userChoice) {
            if (randomNumber - userChoice < 10) {
                cout << "good! you are too close please try to guess the correct number...!" << endl;
            }
            betAmount -= 1;
            cout << "Now your bet amount is : $" << betAmount << endl;
            cout << "Please guess higher number..!" << endl;
            cout << "\nguess again : ";
            cin >> userChoice;
        }
        if (betAmount <= 1) {
            cout << "Oops! You lost the game...! Your betting amount finished (your chances finished...!)" << endl;
            totalAmount -= betAmountScope;
            cout << "Now, Your total balance is : " << totalAmount << "$" << endl;
            break;
        }
    } while (userChoice != randomNumber);
    if (userChoice == randomNumber) {
        cout << "Congratulations...! You won " << userName << " !" << endl;
        totalAmount += betAmount * 20;
        cout << "Now, Your total balance is : " << totalAmount << "$" << endl;
    }
    return 0;
}

// function to show rules to user
void getRules() {
    // about game...
    if (totalAmount == 0) {
        // command to clear terminal...
        system("cls");
    }
    cout << "\n\t= = = = = = = = = = = = = = = = = = = = = = = =\n";
    cout << "\n\t * CASINO NUMBER GUESSING RULES! * \n";
    cout << endl;
    cout << "\t1. Choose a number between 1 to 100\n";
    cout << "\t2. Winner gets 20 times of the bid money\n";
    cout << "\t3. Wrong choice, and you lose 1$ per wrong guess of the amount you bet\n";
    cout << "\t4. Wrong choice till end the game, you loss bid amount from total balance\n";
    cout << "\t5. Number of chance to guess the number is equal to the bidding amount.\n";
    cout << "\t==> To quit the game anytime, press ctrl+c\n";
    cout << "\n\t= = = = = = = = = = = = = = = = = = = = = = = =\n";
    cout << endl;
}