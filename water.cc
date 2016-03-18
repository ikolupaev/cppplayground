//calculate volume of the water inside cap shaped by ints
//where ints are heights

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int get_v( vector<int> a ) {
    
    int max = *(a.begin());
    int sum = 0;
    int accum = 0;
    
    for ( auto it = a.begin()+1; it != a.end(); it++ ) {
        if ( *it >= max ) {
            sum += accum;
            accum = 0;
            max = *it;
        }
        else {
            accum += max - *it;
        }
    }

    max = *(a.rbegin());
    accum = 0;    
    for ( auto it = a.rbegin()+1; it != a.rend(); it++ ) {
        if ( *it > max ) {
            sum += accum;
            accum = 0;
            max = *it;
        }
        else {
            accum += max - *it;
        }
    }

    return sum;
}

#define as( expression, expected ) \
{ \
    int a = expression; \
    cout << a << (a != expected ? " !" : " =") << "= " << expected << " : " << #expression << endl; \
}

int main() {
    as( get_v( { 4,1,1,5 } ), 6 )
    as( get_v( { 5,1,1,5 } ), 8 )
    as( get_v( { 4,1,1,5 } ), 6 )
    as( get_v( { 10, 4, 5, 3, 6, 4, 9 } ), 23 )
    as( get_v( { 1,1,5 } ), 0 )
    as( get_v( { 1,1,1 } ), 0 )
    as( get_v( { 5,3,2 } ), 0 )
    as( get_v( { 2,3,5 } ), 0 )
    as( get_v( { 3,2,6,4,5 } ), 2 )
    as( get_v( { 5,4,6,2,3} ), 2 )
}
