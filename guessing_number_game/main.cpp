#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // Declare variables
	int n, g, m, M, i = 1;
    string decision = "No";
    // Welcome message and game rules explanation
	cout << "Welcome to the number guessing game!" << endl; //<< "Guess a number between a specified range." << endl;
	cout << "Your task is to guess the randomly generated number within the given range.(both minimum and maximum are included)" << endl;
	cout << "Good luck and have fun !" << endl;
    while(decision != "exit"){
	// User input for the range of guessing
	cout << "Enter the range of guessing:\n" << "Minimum : ";
	cin >> m;
	cout << "Maximum : " ;
	cin >> M;

	// Validate user input
	while (m >= M) {
        cout << "Invalid input! Please make sure the minimum is less than the maximum." << endl;
        cout << "Enter the range of guessing, " << "the minimum : ";
        cin >> m;
        cout << "the maximum : ";
        cin >> M;
    }

	// Seed the random number generator based on the current time
	srand(static_cast<unsigned int>(time(nullptr)));

	// Generate a random number within the specified range
	g = (rand() % (M - m + 1)) + m;

	// First guess
    cout << "Enter your your first try" << endl;
    cin >> n;

    // Main game loop
	while(n != g){

        // Out of the specified range condition
        if( (n < m) || (n > M)){
            cout << "Be careful you guessed out of the interval: [ " << m << " ; " << M << " ]!" << endl;
            cout << "Don't worry, this try will not be counted. ;-)" << endl;
            cin >> n;
        }

        // Guess is too high
        else if(n>g){
            cout << "The guess is too high, try again" << endl;
            cin >> n;
            i++;
        }

        // Guess is too low
        else {
            cout << "The guess is too low, try again" << endl;
            cin >> n;
            i++;
        }
	}
	//Add the right guess count
  	i++;
	    
    // Display the result based on the number of tries
	if(i==1){
        cout << "Excellent you did it in the first try" << endl;
    }
    else if (i == 2){
        cout << "Excellent you did it in the second try" << endl;
    }
    else{
        cout << "Good job! you did it in the " << i << "th try" << endl;
    }
    cout << "if you want to play again press any button, if you want to exit enter 'exit'" << endl;
    cin >> decision;

	//reinitialize the counter
	i=0;

	//clear the console every new round
    system("cls");
    }

    return 0;
}
