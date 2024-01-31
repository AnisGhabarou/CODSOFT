#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;


// Function to count the number of digits in a double, considering precision
int countDigits(double num, int q) {
    // Convert the double to a string
    stringstream stream;
    stream << fixed << setprecision(q) << num;
    string myString = stream.str();

    return myString.length();
}


int main()
{
    // Declare variables
    long double a, b ;
    char op;
    int p;
    string decision;

    // Welcome message
    cout << "Welcome to my simple calculator, press any button to calculate\nREMARK! Enter 'Exit' if you want to quit\n";
    cin >> decision;

    // Main loop
    while(decision != "Exit"){
        // Input numbers
        cout << "Enter the first number" << endl;
        cin >> a;
        cout << "Enter the second number" << endl;
        cin >> b;

        // Input operator
        cout << "Enter + if you want to add the two numbers" << endl;
        cout << "Enter - if you want to subtract the second number from the first one" << endl;
        cout << "Enter * if you want to multiply the two numbers" << endl;
        cout << "Enter / if you want to divide the first number by the second one" << endl;
        cout << "Enter an operator:" << endl;
        cin >> op;
        cout << endl;

        // Input precision
        cout <<"Enter the precision (number of digits displayed after the decimal point):" << endl;
        cin >> p;
        cout << endl;

        // Perform calculations based on the chosen operator
        switch (op) {
            case '+':
                // Addition
                cout << "  " << fixed << setprecision(p) << a << endl << "+" << endl << "  " << fixed << setprecision(p) << b << endl ;
                cout << "  ";
                for(int i=0; i< max(countDigits(a+b,p), max(countDigits(a,p), countDigits(b,p))); i++){
                    cout << "-";
                }
                cout << endl << "  "  << fixed << setprecision(p) << a+b <<endl;
                break;
            case '-':
                // Subtraction
                cout << "  " << fixed << setprecision(p) << a << endl << "-" << endl << "  " << fixed << setprecision(p) << b << endl ;
                cout << "  ";
                for(int i=0; i< max(countDigits(a-b,p), max(countDigits(a,p), countDigits(b,p))); i++){
                    cout << "-";
                }
                cout << endl << "  " << fixed << setprecision(p) << a-b <<endl;
                break;
            case '*':
                // Multiplication
                cout << "  " << fixed << setprecision(p) << a << endl << "*" << endl << "  " << fixed << setprecision(p) << b << endl ;
                cout << "  ";
                for(int i=0; i< max(countDigits(a*b,p), max(countDigits(a,p), countDigits(b,p))); i++){
                    cout << "-";
                }
                cout << endl << "  " << fixed << setprecision(p) << a*b <<endl;
                break;
            case '/':
                // Division
                if ( b != 0){
                    cout << fixed << setprecision(p) << a << " | " << fixed << setprecision(p) << b << endl ;
                    for(int i=0; i< countDigits(a,p); i++){
                        cout << " ";
                    }
                    cout << " --";
                    for(int i=0; i< countDigits(b,p); i++){
                        cout << "-";
                    }
                    cout << endl;
                    for(int i=0; i<= countDigits(a,p); i++){
                        cout << " ";
                    }
                    cout << "| " << fixed << setprecision(p) <<a/b <<endl;
                    for(int i=0; i<= countDigits(a,p); i++){
                        cout << " ";
                    }
                    cout << "|" << endl;
                }
                else{
                    cout << "Invalid operation; the second number is 0 !\n";
                }
                break;
            default:
                cout << "Invalid choice, enter a valid operator ( +, -, *, / )\n";
                break;
        }

        // Asking for continuation or exit
        cout << "REMARK! Press any button to calculate again or enter 'Exit' if you want to quit\n";
        cin >> decision;
        system("cls");  // Clear the console screen
    }

    return 0;
}
