#include <iostream>

int fib( int n ) {
    
    if ( n < 1 ) return 0;
    if ( n < 3 ) return 1;
    
    return fib( n - 2 ) + fib( n - 1 );
}

int main()
{
    std::cout << fib( 1 ) << std::endl;
    std::cout << fib( 5 ) << std::endl;
    std::cout << fib( 40 ) << std::endl;
}   