#include <iostream>

int count_1_bits( int n ) {

    int count = 0;
    while ( n != 0 ) {
        n &= n - 1;
        count++;
    } 
    
    return count;
}

int main() {
    std::cout << count_1_bits( 0 ) << std::endl;
    std::cout << count_1_bits( 1 ) << std::endl;
    std::cout << count_1_bits( 2 ) << std::endl;
    std::cout << count_1_bits( 3 ) << std::endl;
    std::cout << count_1_bits( 0xff ) << std::endl;
}