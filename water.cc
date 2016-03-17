//calculate volume of the water inside cap shaped by ints
//where ints are heights

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int get_v( vector<int> a ) {
    
    int size = a.size();
    
    int min_i = 0;
    for ( int i = 1; i < size; i++ ) {
        if ( a[i] < a[min_i] ) 
            min_i = i; 
    }        

    if ( min_i == 0 || min_i == size - 1 ) 
        return 0;

    int max_left = min_i;
    for ( int i = min_i-1; i >= 0; i-- ) {
        if ( a[i] > a[max_left] ) 
            max_left = i; 
    }

    if ( a[max_left] <= a[min_i] ) 
        return 0;

    int max_right = min_i;
    for ( int i = min_i+1; i < size; i++ ) {
        if ( a[i] > a[max_right] ) 
            max_right = i; 
    }

    if ( a[max_right] <= a[min_i] ) 
        return 0;

    int min_max = min( a[max_left], a[max_right] ); 

    int sum = 0;
    for ( int i = max_left+1; i <= max_right-1; i++ ) {
        sum += min_max - a[i];
    }

    return sum;
}

#define as( expression, expected ) \
{ \
    int a = expression; \
    cout << a << (a != expected ? " !" : " =") << "= " << expected << " : " << #expression << endl; \
}

int main() {
    as( get_v( { 5,1,1,5 } ), 8 )
    as( get_v( { 5,1,1,4 } ), 6 )
    as( get_v( { 4,1,1,5 } ), 6 )
    as( get_v( { 10, 4, 5, 3, 6, 4, 9 } ), 23 )
    as( get_v( { 1,1,5 } ), 0 )
    as( get_v( { 1,1,1 } ), 0 )
    as( get_v( { 5,3,2 } ), 0 )
    as( get_v( { 2,3,5 } ), 0 )
    as( get_v( { 3,2,6,4,4,5 } ), 2 )
}
