//https://projecteuler.net/problem=529

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool is_n_friendly( uint64_t number, int n ) {
    
    string s = to_string( number );
    int max_right = s.size() - 1;
    int data[max_right+1];
    
    for ( int i = 0; i <= max_right; i++ ) data[i] = s[i] - '0';
    
    int left = 0;
    int right = 0;
    int sum = 0;

    while (1) {
        sum += data[right];
        if ( right == max_right ) return sum == n;
        if ( sum > n ) return false;
        if ( sum == n ) break;
        right++;
    }

    int gap = right + 1;
    
    while(1)
    {
        while ( sum >= n ) {
            sum -= data[left];
            left++;
        }
        
        while ( sum < n ) {
            sum += data[++right];
        }
        
        if( !(sum == n && left <= gap) ) return false;
        if ( right == max_right ) break;
    }

    return sum == n && left <= gap;
}

uint64_t count_friendly_numbers( int digits, int n ) {
    uint64_t counter = 0;
    uint64_t max = static_cast<uint64_t>( pow( 10, digits ) );
    
    for( uint64_t i = 0; i < max; i++ ) {
        if( is_n_friendly(i, n) ) {
            counter++;
        }
    }
    
    return counter;
}

int main() {
    
    cout << is_n_friendly( 3523014, 10 ) << endl;
    cout << is_n_friendly( 28546, 10 ) << endl;
    cout << count_friendly_numbers( 2, 10 ) << endl;
    cout << count_friendly_numbers( 5, 10 ) << endl;
}