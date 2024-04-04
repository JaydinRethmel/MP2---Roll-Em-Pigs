// MP-2 Roll'em Pigs'
// Author - Jaydin Rethmel
// Created on 4/2/2024
// Description- The program "Roll'em" is a game that is played by the user against the computer. In this game you will be rolling dice against the computer. The goal of this game is to get to 100 points.
// When you roll you add the dice together then roll again and continue to add to the total of that turn. If you roll a 1 on either die you will loss all your points on that turn. You can end your turn whenever
// and keep all the points that you earned. The computer will do the same thing until one of the scores reaches 100.
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
char getPlayerInput(void);
bool hasWinningScore(int score);
bool isTurnPointsLost(int die1value, int die2value);
bool isGameScoreLost(int die1value, int die2value);
int rollDie(void);

int main() {
    srand(time(0)); // Seed the random number generator

    // creating the varibles that will be need to determine score of turn and total
    int humanScore = 0;
    int computerScore = 0;
    int humanTurnPoints = 0;
    int computerTurnPoints = 0;

    cout << "Welcome to the game of Pig!" << endl;

    // while statements that establishes who turn is whos and all the options that can be done during a turn

    while (true) {
        cout << "Human's turn:" << endl;

        // This section of the while statement completes the users turn. This includes roll the dice, ending your turn if you roll a 1, and ending your turn by choice with e or E.

        char choice;
        do {
            choice = getPlayerInput();

            if (choice == 'r' || choice == 'R') {
                int die1 = rollDie();
                int die2 = rollDie();

                cout << "You rolled: " << die1 << " " << die2 << endl;

                if (isTurnPointsLost(die1, die2)) {
                    cout << "You rolled a 1. Turn points lost." << endl;
                    humanTurnPoints = 0;
                    break;
                }
                else {
                    humanTurnPoints += die1 + die2;
                    cout << "Current turn points: " << humanTurnPoints << endl;
                }
            }
            else if (choice == 'e' || choice == 'E') {
                break;
            }
            else {
                cout << "Invalid input. Please enter 'R' or 'E'." << endl;
            }
        } while (true);

        humanScore += humanTurnPoints;
        cout << "Your total score: " << humanScore << endl;

        if (hasWinningScore(humanScore)) {
            cout << "Congratulations! You win!" << endl;
            break;
        }

        cout << "Computer's turn:" << endl;

        // This section completes the computer's turn. It has logic so that if the computer gets to 23 points it will end its turn.

        while (computerTurnPoints < 23 && !isGameScoreLost(rollDie(), rollDie())) {
            int die1 = rollDie();
            int die2 = rollDie();

            cout << "Computer rolled: " << die1 << " " << die2 << endl;

            if (isTurnPointsLost(die1, die2)) {
                cout << "Computer rolled a 1. Turn points lost." << endl;
                computerTurnPoints = 0;
                break;
            }
            else {
                computerTurnPoints += die1 + die2;
            }
        }

        computerScore += computerTurnPoints;
        cout << "Computer's total score: " << computerScore << endl;

        if (hasWinningScore(computerScore)) {
            cout << "Computer wins!" << endl;
            break;
        }

        humanTurnPoints = 0;
        computerTurnPoints = 0;
    }

    return 0;
}

char getPlayerInput() {

    // This function will get the player's input with the choices r,R,e, and E, while also saying anyother is invalid.

    char choice;
    do {
        cout << "Enter 'R' to roll again or 'E' to end your turn: ";
        cin >> choice;
        if (choice == 'r' || choice == 'R' || choice == 'e' || choice == 'E') {
            break;
        }
        else {
            cout << "Invalid input. Please enter 'R' or 'E'." << endl;
        }
    } while (true);
    return choice;
}

bool hasWinningScore(int score) {

    // Creates a winning score

    return score >= 100;
}

bool isTurnPointsLost(int die1value, int die2value) {

    // Creates the result if a only a single 1 is rolled in a turn

    return die1value == 1 || die2value == 1;
}

bool isGameScoreLost(int die1value, int die2value) {

    // Creates the result if double 1s are rolled in a turn

    return die1value == 1 && die2value == 1;
}

int rollDie() {

    // Creates a random value for the dice

    return rand() % 6 + 1;
}