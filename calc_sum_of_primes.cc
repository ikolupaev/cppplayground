#include "primes_provider.h"
#include <iostream>

using namespace std;
 
uint64_t calc_prime_sum( uint32_t max ) {

    primes_provider pp( max );
    
    uint32_t prime = 2;
    uint64_t primes_sum = 0;
   
    while (1) {
    
        primes_sum += prime;
        
        try { 
            prime = pp.find_next_prime( prime ); 
        }
        catch( out_of_range ) { 
            break; 
        }
    }  
    
    return primes_sum;
}

int main()
{
    cout << calc_prime_sum( 2000000 ) << endl;
}
