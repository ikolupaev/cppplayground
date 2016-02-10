#include <iostream>

int divide( int a, int b ) {

    int result = 1;
    int sum = b;
    
    while ( sum <= a ) {
        result++;
        sum += b;
    }
    
    return result - 1;
}

int main() {
    std::cout << divide( 10, 5 ) << std::endl;
    std::cout << divide( 7, 2 ) << std::endl;
    std::cout << divide( 5, 10 ) << std::endl;
    std::cout << divide( 100, 100 ) << std::endl;
}