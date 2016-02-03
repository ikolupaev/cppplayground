//find the sum of the even-valued Fibonacci terms whose values do not exceed command line arg 

#include <iostream>

uint64_t sum_fibonacci_even_terms( uint64_t limit )
{
    uint64_t sum = 0;
    uint64_t a = 1;
    uint64_t b = 2;
    
    std::cout << 1 << std::endl;
    
    while( b < limit ) {
        std::cout << b << std::endl;
        
        if( b % 2 == 0 ) sum += b;

        uint64_t ab = a + b;
        a = b;
        b = ab;
    }
 
    return sum;   
}

int main(int argc, char *argv[]) {
    auto limit = atoi( argv[1] );
    
    std::cout << "limit is " << limit << std::endl; 
    
    std::cout << "* " << sum_fibonacci_even_terms( limit ) << std::endl;
}