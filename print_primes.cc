#include <iostream>

int calc_next_prime(int number) {
    number++;
    int divider = 2;
    while ( number != divider ) {
        if ( number % divider == 0 ) {
            divider = 1;
            number++;
        }
        
        divider++;
    } 
}

int main() {    
    int num = 1;
    for( int i = 0; i < 100; i++ ) {
        num = calc_next_prime( num );
        std::cout << num << std::endl;
    }
}