#include <iostream>
#include <cstring>

int main() {    
    uint64_t size = 1000000;
    bool primes[size];
    for( int i = 0; i < size; i++ ) primes[i] = true;

    uint64_t next_prime = 2;
    while( next_prime < size ) {
        
        uint64_t n = next_prime*2;
        while( n < size ) {
            primes[n] = false;
            n+=next_prime;
        }
        
        next_prime++;
        while( !primes[next_prime] ) next_prime++;
    }

    for( uint64_t i = 2; i < size; i++ ) {
        if( primes[i] ) std::cout << i << std::endl;
    }
}