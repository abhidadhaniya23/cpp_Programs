#include <iostream>
// include some library to generate random number in this game
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
    // getting username...
    cout << "\nPlease enter your name : ";
    cin >> userName;
    // do-while loop for run game while balance finished...
    do {
        if (totalAmount == 0) {
            getAmountData();
            gameLogic();
        }
        else {
            // variable playAgain to check user want to play again or not ??
            string playAgain;
            cout << "\nDO you want to play again ? (y/n) : ";
            cin >> playAgain;
            if (playAgain == "y" || playAgain == "Y") {
                // displaying user howmany balance are left
                cout << "Now, Your total balance is : " << totalAmount << "$" << endl;
                // if user want to play game again then run gameLogic function and start the game 
                gameLogic();
            }
            // if user don't want to play again then break do-while loop...
            else if (playAgain == "n" || playAgain == "N") {
                cout << "Thank you for playing this game !\n" << endl;
                break;
            }
            else {
                // if user enter wrong character by mistake...
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

// building game logic function
int gameLogic() {
    // declaring this variable to define howmany bid user betting...!
    int betAmountScope;
    // terminating this loop (do-while) if user entered bid amount greter than total balance...
    do {
        // if user entered bid amount greter than total balance then...
        if (totalAmount < betAmountScope) {
            cout << "Your betting amount should be less than your balance, please bid again: $";
            cin >> betAmountScope;
        }
        else {
            cout << "\nPlease enter your bid amount : $";
            cin >> betAmountScope;
        }
    } while (totalAmount < betAmountScope);
    cout << "you bet " << betAmountScope << "$" << endl;
    // I already defined betAmount in global scop but its decreasing if guess wrong then how could we know howmany bid user bitting ? so,...
    betAmount = betAmountScope;

    // generating random number
    srand(time(0));
    // limit of generating random number between : 1 => 100
    int randomNumber = (rand() % 100) + 1;
    // cout << "Random No is : " << randomNumber << endl;
    // defining this localscop userChoice variable to define which number user guessed ?
    int userChoice;
    cout << "\nHey " << userName << "! Guess a number between 1 to 100 : ";
    // getting input userChoice number...
    cin >> userChoice;
    // terminating this loop (do-while) while user guess correct number...
    // if guessed correct number then break loop...
    do {
        // halping to show user, is it guessing lower or higher number than computer-random-number...
        if (randomNumber < userChoice) {
            // halping user to say that you are to close to guess correct number...
            // and it's different between 10...
            if (userChoice - randomNumber < 10) {
                cout << "good! you are too close please try to guess the correct number...!" << endl;
            }
            // if user guess wrong number then cut 1$ from bitting amount...
            betAmount -= 1;
            cout << "Now your bet amount is : $" << betAmount << endl;
            cout << "Please guess lower number...!" << endl;
            cout << "\nguess again : ";
            // again input number from user to guess correct number...
            cin >> userChoice;
        }
        // also same logic...
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
        // if bid amount finished then break this loop and user loss the game...
        if (betAmount <= 1) {
            cout << "Oops! You lost the game...! Your betting amount finished (your chances finished...!)" << endl;
            totalAmount -= betAmountScope;
            cout << "Now, Your total balance is : " << totalAmount << "$" << endl;
            break;
        }
    } while (userChoice != randomNumber);
    // if user guessed correct number... the win game...
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