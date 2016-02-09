#include <limits>
#include <iostream>

class primes_provider {
public:
    size_t size;
    bool *primes;

    primes_provider( size_t size ) {
        this->size = size;
        primes = new bool[size];
        
        std::fill(primes, primes+size, true);

        size_t next_prime = 2;
        while( next_prime < size ) {
            
            uint64_t n = next_prime*2;
            while( n < size ) {
                primes[n] = false;
                n+=next_prime;
            }
            
            next_prime++;
            while( next_prime < size && !primes[next_prime] ) next_prime++;
        }
    };
    
    ~primes_provider() {
        delete[] primes;
    }

    uint64_t find_next_prime( uint64_t number ) const {

        number++;
        while( number < size && !primes[number] ) number++;
        if( number >= size ) throw std::out_of_range( "no more primes calculated" );
        return number;
    };
};

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