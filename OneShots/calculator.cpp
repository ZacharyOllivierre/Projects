#include <iostream>
#include <cstdlib>
using namespace std;

class Calculator {
private:
    double numberOne;
    double numberTwo;
    int choice = 1;
    double answer;

    void getInput(bool again = false) {
        // Prompt for Normal Input
        if (!again) {
            do {
                cout << "\nEnter an Option: ";
                cin >> choice;
            } while(!inputValidation(1));
            
            // Exit early if quit
            if (choice == 0) {
                exit(0);
            }
            
            // Prompt for numbers
            do {
                cout << "\nEnter number one: ";
                cin >> numberOne;
                cout << "Enter number two: ";
                cin >> numberTwo;
            } while(!inputValidation(3));
        }
        // Prompt For Play Again Input
        else {
            do {
                cout << "\nRun again (0 or 1): ";
                cin >> choice;
            } while(!inputValidation(2));
            cout << endl;
        }
        
    }
    bool inputValidation(int type) {
        switch (type) {
            // 0 through 5 inclusive
            case 1:
                if (choice >= 0 && choice <= 5) {
                    return true;
                }
                cout << "\nChoose between 0 and 5\n";
                return false;

            // 0 or 1
            case 2:
                if (choice == 0 || choice == 1) {
                    return true;
                }
                cout << "\nEnter 0 or 1\n";
                return false;
                
            // Dissallow 0 as divisor for division and modulo (also greater modulo second)
            case 3:
                if ((choice == 4 || choice == 5) && numberTwo == 0) {
                    cout << "\n0 is not a valid divisor\n"; 
                    return false;
                }
                if (choice == 5 && numberTwo > numberOne) {
                    cout << "\nNumber two cannot be greater than number one\n";
                    return false;
                }
                return true;

            default:
                cout << "\nError | Input Validation type\n";
                exit(1);
        }
    }
    void callOperation() {
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                modulo();
                break;
            default:
                cout << "Error | callOperation choice\n";
                exit(1);
        }
    }
    void printMenu() {
        cout << "Calculator\n----------\n";
        cout << "0. Quit\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Modulo\n"; 
    }
    void outputAnswer() {
        cout << "\nThe answer is " << answer << "!\n";
    }
    void divide() {
        answer = numberOne / numberTwo;
    }
    void multiply() {
        answer = numberOne * numberTwo;
    }
    void add() {
        answer = numberOne + numberTwo;
    }
    void subtract() {
        answer = numberOne - numberTwo;
    }
    void modulo() {
        answer = static_cast<int>(numberOne) % static_cast<int>(numberTwo);
    }

public:
    void run() {
        while (choice) {
            printMenu();
            getInput();
            callOperation();
            outputAnswer();
            getInput(true);
        }
    }
};

int main() {
    Calculator calc;

    calc.run();

    return 0;
}