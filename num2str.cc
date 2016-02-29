#include <string>
#include <vector>
#include <iostream>

// https://www.englishclub.com/kids/numbers-chart.htm

using namespace std;

string num2str( int n ) {
    vector<string> one = { "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten", "eleven", "twelve" };
    vector<string> teen = { "twen", "thir", "four", "fif", "six", "seven", "eigh", "nine" };

    if ( n < 13 ) {
        return one[n-1];
    }
    
    if ( n < 20 ) {
        return teen[n-13] + "teen";
    }
    
    if ( n < 100 ) {
        int tens = n / 10 - 2;
        string ret = teen[tens] + "ty";
        
        int onces = n % 10;
        if ( onces > 0 ) {
            ret += "-" + num2str( onces );     
        }
        
        return ret;
    }
    
    if ( n < 1000 ) {
        return num2str( n / 100 ) + " hundred " + num2str( n % 100 ); 
    }
    
    if ( n < 1000000 ) {
        return num2str( n / 1000 ) + " thousand " + num2str( n % 1000 ); 
    }

    return "";
}

string num2str1( int n ) {
    return to_string( n ) + ": " + num2str( n );
}

int main() {
    cout << num2str1( 10 ) << endl;
    cout << num2str1( 12 ) << endl;
    cout << num2str1( 13 ) << endl;
    cout << num2str1( 19 ) << endl;
    cout << num2str1( 20 ) << endl;
    cout << num2str1( 30 ) << endl;
    cout << num2str1( 31 ) << endl;
    cout << num2str1( 39 ) << endl;
    cout << num2str1( 99 ) << endl;
    cout << num2str1( 199 ) << endl;
    cout << num2str1( 256 ) << endl;
    cout << num2str1( 999 ) << endl;
    cout << num2str1( 123456 ) << endl;
}