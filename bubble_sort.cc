#include <iostream>

void bubble_sort( int *buff, int size ) {

    if ( size < 2 ) return;
    
    for ( int i = 0; i < size-1; i++ ) {
        if ( buff[i] > buff[i+1] ) std::swap( buff[i], buff[i+1] );
    }
    
    bubble_sort( buff, size-1 );

}

int main() {

    int buff[] = {9,8,7,6,2,4,3,5,1};
    bubble_sort( buff, sizeof(buff) / sizeof(int) );

    for( int x: buff ) std::cout << x << std::endl;
}