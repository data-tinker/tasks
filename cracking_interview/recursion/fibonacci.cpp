#include <iostream>
#include <vector>

int fibonacciRecursive(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n) {
    if (n < 2) {
        return n;
    }
    int a = 1, b = 1;

    for (size_t i = 3; i <= n; ++i) {
        int c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    std::cout << fibonacciIterative(3) << std::endl;

    return 0;
}
