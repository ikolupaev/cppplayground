#include <iostream>

int calc_next_prime(uint64_t number) {
    number++;
    uint64_t divider = 2;
    while ( number != divider ) {
        if ( number % divider == 0 ) {
            divider = 1;
            number++;
        }
        divider++;
    } 
    return number;
}

void print_prime_factors_of( uint64_t number ) {
    
    auto last_prime = 2;

    while ( number != last_prime ) { 
        if ( number % last_prime == 0 ) {
            std::cout << last_prime << std::endl;
            number /= last_prime;
        }
        else {
            last_prime = calc_next_prime( last_prime );
            std::cout << last_prime << "\r";
        }
    }

    std::cout << last_prime << std::endl;
}

int main(int argc, char *argv[]) {
    auto num = atoi( argv[1] );    
    print_prime_factors_of( num );
}