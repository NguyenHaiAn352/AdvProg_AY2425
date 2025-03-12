#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:

    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    int output = rand() % 99;
    return output + 1;
}


/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/

int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int output;
    cout << "Please input in your guess:" << endl;
    cin >> output;
    do{
        cout << "Number is not in range. Please try again." << endl;
        cin >> output;
    } while (output < 1 || output > 100);
    return output;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/


string getAnswer(int number, int randomNumber) {
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if (number > randomNumber) answer = "Your number is  higher.";
    else if (number < randomNumber) answer = "Your number is lower.";
    else answer = "Congratulations! You win.";
    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/


bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if (answer != "Congratulations! You win.") return false;
    else return true;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if (isContinued == 'N' || isContinued == 'n') result = false;
    else if (isContinued == 'Y' || isContinued == 'y') result = true;
    return result;
}


/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cout << "Do you want to continue?" << endl;
    cin >> isContinued;
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
