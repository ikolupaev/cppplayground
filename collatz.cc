#include <iostream> 

using namespace std;

uint32_t get_print_collatz_len( uint64_t n ) {
    uint32_t len = 1;

    while ( n > 1 ) {
        
        if ( n % 2 == 0 )
            n = n / 2;
        else
            n = 3 * n + 1;
            
        len++;
    }
    
    return len;
} 

int main() {
    uint32_t max_sequence = 0;
    int max_i = 0;
    for( int i = 0; i < 1000000; i++ ) {
        uint32_t len = get_print_collatz_len( i );
        if( len > max_sequence ) {
            max_sequence = len;
            max_i = i;
        }
    }

    cout << "max_i: " << max_i << " len: " << max_sequence << endl;
}