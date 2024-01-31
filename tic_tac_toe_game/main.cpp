#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int number(int q){
    if (q == 1){
        q = 2;}
    else{
        q = 1;}
    return q;
}

char character(char c){
    if (c == 'X'){
        c = 'O';}
    else{
        c = 'X';}
    return c;
}

int main()
{
    // Welcome message and setup
    cout << "Welcome! happy to see you both playing my game" << endl;
    cout << "First, each player choose a number; 1 or 2" << endl;
    cout << "Second the number that will be shown on the screen will allow the player that have choose it to play first; remember only X and O are allowed to play with!" << endl;
    cout << "Third you both are going to play alternatively" << endl;
    cout << "Fourth every player is going to enter the number of column (1, 2 or 3) and row (1, 2 or 3) every turn and the board will be showing the current state" << endl;
    cout << "Finally the result of the game will be shown (win, draw, or ongoing)" << endl;
    cout << "Enjoy!" << endl;

    // Seed for random player selection
    srand(static_cast<unsigned int>(time(nullptr)));

    // Variables initialization
    int a, b, n = rand() % 2 + 1;  // n represents the player who plays first (1 or 2)
    bool y, z;  // Flags for checking winning conditions
    char tab[3][3]; // Game board
    char X_or_O;
    string decision = "No"; // Variable to decide whether to play again


    cout << "Press any button to play, enter 'exit' to quit the game\n";
    cin >> decision;

    while(decision != "exit"){

        // Initializing the game board
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                tab[j][k] = ' ';
            }
        }

        cout << "The player who had chosen the number " << n << " will be the first to play" << endl;
        cout << "Enter X if you want to play with X or O if you want to play with O, only X or O can be accepted !\n";
        cin >> X_or_O;

        if(X_or_O != 'X' && X_or_O != 'O'){
            cout << "Invalid input, again enter X if you want to play with X or O if you want to play with O\n";
        cin >> X_or_O;
        }
        cout << "The player who had chosen the number " << number(n) << " will play with " << character(X_or_O) << endl;
        // Main game loop
        for(int i=1; i<10; i++){
            // Alternate turns between players
            if(i/2*2 != i){
                cout << "Player " << n << " enter the number of row : ";
                cin >> a ;
                cout << "Enter the number of column : ";
                cin >> b;
                cout <<endl;
            }
            else{

                    cout << "Player " << number(n) << " enter the number of row : ";
                    cin >> a ;
                    cout << "Enter the number of column : ";
                    cin >> b;
                    cout <<endl;
                }


            // Update the game board
            if((a<4) && (a>0) && (b<4) && (b>0) && (i/2*2-i != 0)){
                tab[a-1][b-1] = X_or_O;
            }
            else{
                tab[a-1][b-1] = character(X_or_O);
            }

            // Check for winning conditions
            y =(((tab[0][0] == X_or_O) && (tab[1][1] == X_or_O) && (tab[2][2] == X_or_O)) || ((tab[0][2] == X_or_O) && (tab[1][1] == X_or_O) && (tab[2][0] == X_or_O)) || ((tab[0][0] == X_or_O) && (tab[0][1] == X_or_O) && (tab[0][2] == X_or_O)) || ((tab[1][0] == X_or_O) && (tab[1][1] == X_or_O) && (tab[1][2] == X_or_O)) || ((tab[2][0] == X_or_O) && (tab[2][1] == X_or_O) && (tab[2][2] == X_or_O)) || ((tab[0][0] == X_or_O) && (tab[1][0] == X_or_O) && (tab[2][0] == X_or_O)) || ((tab[0][1] == X_or_O) && (tab[1][1] == X_or_O) && (tab[2][1] == X_or_O)) || ((tab[0][2] == X_or_O) && (tab[1][2] == X_or_O) && (tab[2][2] == X_or_O)));
            z = (((tab[0][0] == character(X_or_O)) && (tab[1][1] == character(X_or_O)) && (tab[2][2] == character(X_or_O))) || ((tab[0][2] == character(X_or_O)) && (tab[1][1] == character(X_or_O)) && (tab[2][0] == character(X_or_O))) || ((tab[0][0] == character(X_or_O)) && (tab[0][1] == character(X_or_O)) && (tab[0][2] == character(X_or_O))) || ((tab[1][0] == character(X_or_O)) && (tab[1][1] == character(X_or_O)) && (tab[1][2] == 'O')) || ((tab[2][0] == character(X_or_O)) && (tab[2][1] == character(X_or_O)) && (tab[2][2] == character(X_or_O))) || ((tab[0][0] == character(X_or_O)) && (tab[1][0] == character(X_or_O)) && (tab[2][0] == character(X_or_O))) || ((tab[0][1] == character(X_or_O)) && (tab[1][1] == character(X_or_O)) && (tab[2][1] == character(X_or_O))) || ((tab[0][2] == character(X_or_O)) && (tab[1][2] == character(X_or_O)) && (tab[2][2] == character(X_or_O))));

            // Display the current state of the board
            cout << "\t " <<tab[0][0] <<" | " << tab[0][1] << " | " << tab[0][2] << endl;
            cout << "\t--- --- ---" << endl;
            cout << "\t " <<tab[1][0] <<" | " << tab[1][1] << " | " << tab[1][2] << endl;
            cout << "\t--- --- ---" << endl;
            cout << "\t " <<tab[2][0] <<" | " << tab[2][1] << " | " << tab[2][2] << endl << endl;

            // Check for a winner
            if(y){
                cout << "********** Player " << n << " is the winner! **********" << endl;
                cout << "Good luck next time player " << number(n) <<endl;
                cout << endl;
                i=10;
            }
            else if(z){
                cout << "********** Player " << number(n) << " is the winner! **********" << endl;
                cout << "Good luck next time player " << n <<endl;
                cout << endl;
                i=10;
            }
            else{
                cout << "\tOngoing...\n\n";
            }



        }

        // If no winner, it's a draw
        if( (!z) && (!y)){
            cout << "---------- Draw ! ----------\n";
        }

        // Ask to play again
        cout << "Press to play again any button, enter 'exit' to quit the game\n";
        cin >> decision;
        system("cls");	// Clear the console screen

	// Display welcome message for the next game
        cout << "Welcome! happy to see you both playing my game again" << endl;
        cout << "As i said before, first, each player choose a number; 1 or 2" << endl;
        cout << "Second the number that will be shown on the screen will allow the player that have choose it to play first; remember only X and O are allowed to play with!" << endl;
        cout << "Third you both are going to play alternatively" << endl;
        cout << "Fourth every player is going to enter the number of column (1, 2 or 3) and row (1, 2 or 3) every turn and the board will be be showing the current state" << endl;
        cout << "Finally the result of the game will be shown (win, draw, or ongoing)" << endl;
        cout << "Enjoy!" << endl;
    }
    system("cls");
    return 0;
}
