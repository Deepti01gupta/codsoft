#include<bits/stdc++.h>
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess_number = 0;

    cout << "Guess the number between 1 and 100: ";

    // Loop until the user guesses the correct number
    while (guess_number != randomNumber) {
        cin >> guess_number;

        if (guess_number < randomNumber) {
            cout << "Too low! Try again: ";
        } else if (guess_number > randomNumber) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    }

    return 0;
}
