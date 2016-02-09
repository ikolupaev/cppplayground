#include <limits>
#include <iostream>

#include "primes_provider.h"

uint64_t get_prime_of_index( const primes_provider &pr, uint64_t index ) {
    uint64_t prime = 1;
    
    for( uint64_t i = 0; i < index; i++ ) {
        prime = pr.find_next_prime( prime );
    }
    
    return prime;
}

int main() {    
    
    std::cout << "initializing prime matrix..." << std::endl;
    
    primes_provider pr(15000000);

    std::cout << get_prime_of_index( pr, 6 ) << std::endl;
    std::cout << get_prime_of_index( pr, 10001 ) << std::endl;
}