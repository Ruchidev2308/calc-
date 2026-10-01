#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

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
        std::cout << "Numbers less than or equal to 1 do not have prime factors.\n";
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
        std::cout << factorNum << " ";
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

// custom function for LCM
int customLCM(int a , int b) {
    if (a == 0 || b == 0) return 0;
    return (a / customGCD(a, b)) * b;
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

// permutation function
long long calculatePermutation(int n, int r) {
    if (r < 0 || r > n) return 0; 
    return calculateFactorial(n) / calculateFactorial(n - r);
}

// combination function
long long calculateCombination(int n, int r) {
    if (r < 0 || r > n) return 0; 
    return calculateFactorial(n) / (calculateFactorial(r) * calculateFactorial(n - r));
}

// power function
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
        double num1 = 0.0;
        double num2 = 0.0;
        int op = 0;
        char primechoice;
        
        std::cout << "Choose:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. HCF/GCD\n";
        std::cout << "6. LCM\n";
        std::cout << "7. Prime Numbers\n";
        std::cout << "8. Factorial\n";
        std::cout << "9. Power\n";
        std::cout << "10. Permutations and Combinations\n";

        std::cout << "Enter selection (1-10): ";
        std::cin >> op;

        if (op >= 1 && op <= 6) {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
        } 
        else if (op == 9) {
            std::cout << "Enter base: ";
            std::cin >> num1;
            std::cout << "Enter exponent: ";
            std::cin >> num2;
        }

        if (op == 1) {
            std::cout << "Result: " << num1 + num2 << '\n';
        }
        else if (op == 2) {
            std::cout << "Result: " << num1 - num2 << '\n';
        }
        else if (op == 3) {
            std::cout << "Result: " << num1 * num2 << '\n';
        }
        else if (op == 4) {
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << '\n';
            } else {
                std::cout << "Error: Division by zero.\n";
            }
        }
        else if (op == 5) {
            int hcf = customGCD(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << hcf << '\n';
        }
        else if (op == 6) {
            int lcm = customLCM(static_cast<int>(num1), static_cast<int>(num2));
            std::cout << "Result: " << lcm << '\n';
        }
        else if (op == 7) {
            std::cout << "1. Check if a number is prime\n";
            std::cout << "2. List prime numbers up to N\n";
            std::cout << "3. Prime factorization\n";
            std::cout << "Enter: ";
            std::cin >> primechoice;
            
            if (primechoice == '1') {
                int primenum;
                std::cout << "Enter number: ";
                std::cin >> primenum;
                if (checkPrime(primenum)) {
                    std::cout << primenum << " is prime.\n";
                } else {
                    std::cout << primenum << " is not prime.\n";
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
                std::cout << "Enter number for prime factorization: ";
                std::cin >> factorNum;
                primeFactorization(factorNum);
            }
            else {
                std::cout << "Invalid selection in Prime menu\n";
            }
        }
        else if (op == 8) {
            int factNum;
            std::cout << "Enter Number: ";
            std::cin >> factNum;
            std::cout << factNum << "! = " << calculateFactorial(factNum) << '\n';
        }
        else if (op == 9) {
            std::cout << num1 << "^" << num2 << " = "
                      << calculatePower(static_cast<int>(num1), static_cast<int>(num2)) << '\n';
        }
        else if (op == 10) {
            char percom;
            int n, r;
            std::cout << "1. Permutations (nPr)\n";
            std::cout << "2. Combinations (nCr)\n";
            std::cout << "Enter Choice (1 or 2): ";
            std::cin >> percom;
            
            if (percom == '1' || percom == '2') {
                std::cout << "Enter total number of items (n): ";
                std::cin >> n;
                std::cout << "Enter items to arrange (r): ";
                std::cin >> r;
                
                if (n < 0 || r < 0 || r > n) {
                    std::cout << "Invalid inputs\n";
                } else {
                    if (percom == '1') {
                        std::cout << "Result of Permutation (" << n << "P" << r << ") = " 
                                  << calculatePermutation(n, r) << '\n';
                    } else {
                        std::cout << "Result of Combination (" << n << "C" << r << ") = " 
                                  << calculateCombination(n, r) << '\n';
                    }
                }
            } else {
                std::cout << "Invalid selection .\n";
            }
        }
        else {
            std::cout << "Invalid Operation Selection.\n";
        }

        std::cout << "Calculate again? (yes/no): ";
        std::cin >> calcAgain;
        std::transform(calcAgain.begin(), calcAgain.end(), calcAgain.begin(), ::tolower);

    } while (calcAgain == "yes" || calcAgain == "y");

    std::cout << "Goodbye\n";
    return 0;
}
