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

    uint64_t find_next_prime( uint64_t number ) {
        number++;
        while( number < size && !primes[number] ) number++;
        
        if( number >= size ) throw std::out_of_range( "no more primes calculated" );
        
        return number;
    };
};

void print_prime_factors_of( uint64_t number ) {
    
    primes_provider pr(1500000000);
    auto last_prime = 2;

    while ( number != last_prime ) { 
        if ( number % last_prime == 0 ) {
            std::cout << last_prime << std::endl;
            number /= last_prime;
        }
        else {
            last_prime = pr.find_next_prime( last_prime );
            std::cout << last_prime << "\r";
        }
    }

    std::cout << last_prime << std::endl;
};

int main(int argc, char *argv[]) {
    auto num = atoi( argv[1] );    
    print_prime_factors_of( num );
}

