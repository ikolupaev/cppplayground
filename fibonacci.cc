#include <iostream>
#include <chrono>

int fib( int n ) {
    
    if ( n < 1 ) return 0;
    if ( n < 3 ) return 1;
    
    return fib( n - 2 ) + fib( n - 1 );
}

int fib2( int n ) {
    
    if ( n < 1 ) return 0;

    int a = 1;
    int b = 1;
    
    for( int i = 3 ; i <= n; i++ ) {
        int ab = a+b;
        a = b;
        b = ab;
    }
    
    return b;
}

void run_fib( int (*f) (int) ) {
    
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << f( 1 ) << std::endl;
    std::cout << f( 5 ) << std::endl;
    std::cout << f( 40 ) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>( end-start );
    std::cout << "elapsed: " << diff.count() << std::endl;

}
int main() {
    run_fib(fib);
    run_fib(fib2);
}   