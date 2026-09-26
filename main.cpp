#include <iostream>
#include <string>
#include <algorithm>

int main() {
   
    std::string calcAgain;
    do {
        double num1;
        double num2;
        char op;
        std::cout << "Choose:" << '\n';
        std::cout << "1. Addition" << '\n';
        std::cout << "2. Subtraction" << '\n';
        std::cout << "3. Multiplication" << '\n';
        std::cout << "4. Division" << '\n';
        std::cout << "Enter [1,2,3,4]: " << '\n';
        std::cin >> op;

        std::cout << "Enter first number:" << '\n';
        std::cin >> num1;
        std::cout << "Enter second number:" << '\n';
        std::cin >> num2;

        if (op == '1') {
            std::cout << "Result: " << num1 + num2 << '\n';
        }
        else if (op == '2') {
            std::cout << "Result: " << num1 - num2 << '\n';
        }
        else if (op == '3') {
            std::cout << "Result: " << num1 * num2 << '\n';
        }
        else if (op == '4'){
            if (num2 != 0){
            std::cout << "Result: " << num1/num2 << '\n';
            }
            else {
            std::cout << "Error. Division by zero.\n";
            }
        }
        else {
            std::cout << "Invalid" << '\n';
        }

    std::cout << "Calculate again? " << '\n';
    std::cin >> calcAgain;

    
    std::transform(calcAgain.begin(), calcAgain.end(), calcAgain.begin(), ::tolower);

    } while (calcAgain == "yes" || calcAgain == "y");

    std::cout << "tata nig" << '\n';


    return 0;

}
