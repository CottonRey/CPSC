#include <iostream>
#include <stdexcept>

unsigned long sigma(unsigned long n) {
    try {
        // Precondition: n >= 1
        if (n < 1) {
            throw std::runtime_error("Invalid argument: n must be greater than or equal to 1. Error at " + std::string(__FILE__) + ":" + std::to_string(__LINE__) + ". n = " + std::to_string(n));
        }

        unsigned long sum = 0;
        for (unsigned long i = 1; i <= n; i++) {
            sum += i;
        }

        // Post-condition: Check sum using formula n(n+1)/2
        if (sum != (n * (n + 1)) / 2) {
            throw std::runtime_error("Post-condition failed: Sum computed is not equal to expected sum. Error at " + std::string(__FILE__) + ":" + std::to_string(__LINE__) + ". n = " + std::to_string(n));
        }

        return sum;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return 0;
    }
}

int main() {
    unsigned long validArg = 5;
    unsigned long invalidArg = 0;

    unsigned long validSum = sigma(validArg);
    std::cout << "Sigma (" << validArg << ") = " << validSum << std::endl;

    unsigned long invalidSum = sigma(invalidArg);
    std::cout << "Sigma (" << invalidArg << ") = " << invalidSum << std::endl;

    return 0;
}
