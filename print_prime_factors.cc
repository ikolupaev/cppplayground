#include <iostream>

#include "primes_provider.h"

void print_prime_factors_of( uint64_t number ) {
    
    primes_provider pr(15000000);
    auto last_prime = 2;

    while ( number != last_prime ) { 
        if ( number % last_prime == 0 ) {
            number /= last_prime;
            std::cout << number << " / " << last_prime << std::endl;
        }
        else {
            last_prime = pr.find_next_prime( last_prime );
            std::cout << last_prime << "\r";
        }
    }

    std::cout << last_prime << std::endl;
};

int main(int argc, char *argv[]) {
    uint64_t num = std::stoull( argv[1] );  
    print_prime_factors_of( num );
}

