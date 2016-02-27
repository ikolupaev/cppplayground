#include "sum.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    string power = "2";
    vector<string> v;

    for ( int i = 1; i < 1000 ; i++ ) {
        v.clear();
        v.push_back(power);
        v.push_back(power);
        
        power = sum_str::sum( v );
    }

    cout << "2^1000 = " << power << endl;
    
    int sum = 0;
    for ( auto s: power ) {
        int n = s - '0';
        sum += n;
    }
    
    cout << "sum of  digits = " << sum << endl;
}