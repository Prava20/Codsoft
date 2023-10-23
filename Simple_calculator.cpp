#include <iostream>
using namespace std;

int main() {
    char ch;
    double a, b;

    while (true) {
        cout << "Enter an operator (+, -, *, /), if you want to exit, press 'x': ";
        cin >> ch;

        if (ch == 'x')
            exit(0);

        cout << "Enter the first and second operands: ";
        cin >> a >> b;

        switch (ch) {
            case '+':
                cout << a << " + " << b << " = " << a + b << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << a - b << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << a * b << endl;
                break;
            case '/':
                if (b != 0)
                    cout << a << " / " << b << " = " << a / b << endl;
                else
                    cout << "Error! Division by zero." << endl;
                break;
            default:
                cout << "Error! Please enter a valid operator." << endl;
        }

        cout << endl;
    }

    return 0;
}
