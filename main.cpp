#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
   
    std::string calcAgain;
    do {
        double num1;
        double num2;
        char op;
        char primechoice;
        std::cout << "Choose:" << '\n';
        std::cout << "1. Addition" << '\n';
        std::cout << "2. Subtraction" << '\n';
        std::cout << "3. Multiplication" << '\n';
        std::cout << "4. Division" << '\n';
        std::cout << "5. HCF/GCD  " << '\n';
        std::cout << "6. LCM" << '\n';
        std::cout << "7. Prime Numbers" << '\n';

        std::cout << "Enter: " << '\n';
        std::cin >> op;

        if (op >= '1' && op <= '6'){
            std::cout << "Enter first number:" << '\n';
            std::cin >> num1;
            std::cout << "Enter second number:" << '\n';
            std::cin >> num2;
        }    

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
        else if (op == '5'){
            int hcf = std::gcd(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << hcf << '\n';
        }
        else if (op == '6'){
            int lcm = std::lcm(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << lcm << '\n';
        }
        else if (op == '7') {
            std::cout << "Check if a number is prime" << '\n';
            std::cout << "List prime numbers up to N" << '\n';
            std::cout << "Prime factorization" << '\n';
            std::cout << "Enter [1,2,3]" << '\n';
            std::cin >> primechoice;
            if (primechoice == '1'){
                int primenum;
                bool isPrime = true;
                std::cout << "Enter number: " << '\n';
                std::cin >> primenum;
                if (primenum <=1) {
                    isPrime = false;
                }
                else if (primenum == 2){
                    isPrime = true;
                }
                else if (primenum % 2 == 0){
                    isPrime = false;
                }
                else {
                    for (int i = 3; i*i <= primenum; i +=2) {
                        if (primenum % i == 0){
                            isPrime = false;
                            break;
                        }
                    }
                }
                if (isPrime) {
                    std::cout << primenum << " is a prime number." << std::endl;
                } else {
                    std::cout << primenum << " is not a prime number." << std::endl;
                }    
            }
            else if (primechoice == '2'){
                int limit;
                std::cout << "Enter limit number (N): " << '\n';
                std::cin >> limit;
                if (limit < 2) {
                    std::cout << "There are no prime numbers less than 2." << '\n';
                } else {
                    std::cout << "Prime numbers up to " << limit << " are: " << '\n';
                    for (int currentNum = 2; currentNum <= limit; ++currentNum) {
                        bool isPrime = true;
                        if (currentNum == 2) {
                            isPrime = true;
                        }
                        else if (currentNum % 2 == 0) {
                            isPrime = false;
                        }
                        else {
                            for (int i = 3; i * i <= currentNum; i += 2) {
                                if (currentNum % i == 0) {
                                    isPrime = false;
                                    break;
                                }
                            }
                        }
                        if (isPrime) {
                            std::cout << currentNum << " ";
                        }
                    }    
                }
                std::cout << '\n';
            }
            else if (primechoice == '3') {
                int factorNum;
                std::cout << "Enter number for prime factorization: " << '\n';
                std::cin >> factorNum;

                if (factorNum <= 1) {
                    std::cout << "Numbers less than or equal to 1 do not have prime factors." << '\n';
                } else {
                    std::cout << "Prime factorization of " << factorNum << " is: ";
                    
                    while (factorNum % 2 == 0) {
                        std::cout << 2 << " ";
                        factorNum /= 2;
                    }

                    for (int i = 3; i * i <= factorNum; i += 2) {
                        while (factorNum % i == 0) {
                            std::cout << i << " ";
                            factorNum /= i;
                        }
                    }

                    if (factorNum > 2) {
                        std::cout << factorNum;
                    }
                    std::cout << '\n';
                }
        
            }
            else {
                std::cout << "Invalid selection in Prime menu" << '\n';
            }
        }
        else {
            std::cout << "Invalid" << '\n';
        }

    std::cout << "Calculate again? " << '\n';
    std::cin >> calcAgain;

    
    std::transform(calcAgain.begin(), calcAgain.end(), calcAgain.begin(), ::tolower);

    } while (calcAgain == "yes" || calcAgain == "y");

    std::cout << "Goodbye" << '\n';


    return 0;

}
