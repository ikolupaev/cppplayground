#include <limits>
#include <iostream>

#include "primes_provider.h"

int main() {    
    
    primes_provider pr(150000000);
    uint64_t prime = 1;
    
    for( int i = pr.size - 1; i > 0; i-- ) 
        if( pr.primes[i] ) { std::cout << i << std::endl; break; }
}