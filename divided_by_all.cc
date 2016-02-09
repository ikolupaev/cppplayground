#include <iostream>

using namespace std;

int calc_divided_by_all( int min, int max ) {
    int result = max+1;
    int n = max;
    
    while ( n > min ) {
        if ( result % n != 0 ) {
            result++;
            n = max;
        }
        
        n--;
    }
    
    return result;
}

int main() {
    
    cout << calc_divided_by_all(1,20) << endl;
    
}