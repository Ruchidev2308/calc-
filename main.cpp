#include <iostream>
#include <string>
#include <algorithm>
// I don't strictly require #include <numeric> as I made my own gcd lcm function.

// Check a num is prime 
bool checkPrime(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// void function for listing prime numbers
void listPrimes(int limit) {
    for (int currentNum = 2; currentNum <= limit; ++currentNum) {
        if (checkPrime(currentNum)) {
               std::cout << currentNum << " ";
            }
        }

        std::cout << '\n';
}

// void function for prime factorization
void primeFactorization(int factorNum) {
    if (factorNum <= 1) {
        std::cout << "Numbers less than or equal to 1 do not have prime factors.";
        return;
    }

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

// custom function for GCD
int customGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a; 
}



// custom fucntion for LCM using GCD
int customLCM(int a , int b) {
    if (a == 0 || b == 0) return 0;
    return (a / customGCD(a,b))*b;
}

// factorial function
long long calculateFactorial(int n) {
    if (n < 0) return 0;
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// power funtion
long long calculatePower(int base, int exponent) {
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
   
    std::string calcAgain;
    do {
        double num1 =  0.0;
        double num2 =  0.0;
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
        std::cout << "8. Factorial" << '\n';
        std::cout << "9. Power" << '\n';



        std::cout << "Enter: " << '\n';
        std::cin >> op;

        if ((op >= '1' && op <= '6') || op == '9') {
            if (op == '9') {
                std::cout << "Enter base: " << '\n';
                std::cin >> num1;
                std::cout << "Enter exponent: " << '\n';
                std::cin >> num2;
            } else {
            std::cout << "Enter first number:" << '\n';
            std::cin >> num1;
            std::cout << "Enter second number:" << '\n';
            std::cin >> num2;
            }
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
            int hcf = customGCD(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << hcf << '\n';
        }
        else if (op == '6'){
            int lcm = customLCM(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << lcm << '\n';
        }
        else if (op == '7') {
            std::cout << "1. Check if a number is prime" << '\n';
            std::cout << "2. List prime numbers up to N" << '\n';
            std::cout << "3. Prime factorization" << '\n';
            std::cout << "Enter [1,2,3]" << '\n';
            std::cin >> primechoice;
            if (primechoice == '1'){
                int primenum;
                std::cout << "Enter number: " << '\n';
                std::cin >> primenum;
 
                // calling function
                if(checkPrime(primenum)) {
                    std::cout << primenum << " is prime." << '\n';
                } else {
                    std::cout << primenum << " is not prime." << '\n';
                }
            }
            else if (primechoice == '2') {
                int limit;
                std::cout << "Enter limit: ";
                std::cin >> limit;
                listPrimes(limit);
            }
            else if (primechoice == '3') {
                int factorNum;
                std::cout << "Enter number for prime factorization: " << '\n';
                std::cin >> factorNum;
                primeFactorization(factorNum);
            }
            else {
                std::cout << "Invalid selection in Prime menu" << '\n';
            }
        }

        else if (op == '8') {
            int factNum;
            std::cout << "Enter Number: ";
            std::cin >> factNum;
            std::cout << factNum << "! = " << calculateFactorial(factNum) << '\n';
        }
        else if (op == '9') {
            std::cout << num1 << "^" << num2 << " = "
                      << calculatePower(static_cast<int>(num1), static_cast<int>(num2)) << '\n';
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
