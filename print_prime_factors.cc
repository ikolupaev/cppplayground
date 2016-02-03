#include <iostream>

class primes_provider {
    
public:
    const static uint64_t size = 1000000;
    bool primes[size];

    primes_provider() {
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
    };

    uint64_t get_next_prime( uint64_t number ) {
        number++;
        while( !primes[number] ) number++;
        return number;
    };
};

void print_prime_factors_of( uint64_t number ) {
    
    primes_provider pr;
    auto last_prime = 2;

    while ( number != last_prime ) { 
        if ( number % last_prime == 0 ) {
            std::cout << last_prime << std::endl;
            number /= last_prime;
        }
        else {
            last_prime = pr.get_next_prime( last_prime );
            std::cout << last_prime << "\r";
        }
    }

    std::cout << last_prime << std::endl;
};

int main(int argc, char *argv[]) {
    auto num = atoi( argv[1] );    
    print_prime_factors_of( num );
}

