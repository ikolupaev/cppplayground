//calculate volume of the water inside cap shaped by ints
//where ints are heights

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int get_v( vector<int> a ) {
    
    int max = a[0];
    int sum = 0;
    int accum = 0;
    
    for ( int i = 1; i < a.size(); i++ ) {
        if ( a[i] >= max ) {
            sum += accum;
            accum = 0;
            max = a[i];
        }
        else {
            accum += max - a[i];
        }
    }

    max = a[a.size()-1];
    accum = 0;    
    for ( int i = a.size()-2; i >= 0; i-- ) {
        if ( a[i] > max ) {
            sum += accum;
            accum = 0;
            max = a[i];
        }
        else {
            accum += max - a[i];
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
