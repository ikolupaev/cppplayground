#include <iostream>

void print_prime_factors_of( uint64_t number ) {
    
    uint64_t factor = 1;

    while ( number != factor ) { 
        factor++;
        if ( number % factor == 0 ) {
            number /= factor;
            std::cout << number << " / " << factor << std::endl;
            factor = 1;
        }
    }

    std::cout << number << std::endl;
};

int main(int argc, char *argv[]) {
    uint64_t num = std::stoull( argv[1] );    
    std::cout << "arg: " << num << std::endl;
    print_prime_factors_of( num );
}

