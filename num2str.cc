#include <string>
#include <vector>
#include <iostream>

// https://www.englishclub.com/kids/numbers-chart.htm

using namespace std;

const vector<string> one = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
const vector<string> teen = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const vector<string> ty = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string num2str( int n ) {

    if ( n < 11 ) {
        return string(one[n-1]);
    }
    
    if ( n < 20 ) {
        return string( teen[n-11] );
    }
    
    if ( n < 100 ) {
        string ret( ty[n / 10 - 2] );
        
        int onces = n % 10;
        if ( onces > 0 ) {
            ret.append( "-" );
            ret.append( num2str( onces ) );     
        }
        
        return ret;
    }
    
    if ( n < 1000 ) {
        string ret( num2str( n / 100 ) + " hundred" );
    
        int tens = n % 100;         
        if ( tens != 0 ) {
            ret.append( " and " + num2str( tens ) );
        }
        
        return ret;
    }
    
    if ( n < 1000000 ) {
        string ret( num2str( n / 1000 ) + " thousand" );

        int hundred = n % 1000;         
        if ( hundred != 0 ) {
            ret.append( " and " + num2str( hundred ) );
        }
        
        return ret;
    }

    return string("");
}

string num2str1( int n ) {
    return to_string( n ) + ": " + num2str( n );
}

uint32_t count_letters( string s ) {
    int count = 0;
    for ( const char ch:s ) 
        if ( ch != ' ' && ch != '-' ) count++;
        
    return count;
}

int main() {
    cout << num2str1( 601 ) << endl;
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
    
    cout << count_letters( num2str(342) ) << endl;
    cout << count_letters( num2str(115) ) << endl;
    
    uint32_t count = 0;
    
    for ( int i = 1; i <= 1000; i++ ) {
        string s = num2str( i );
        count += count_letters( s ); 
        cout << s << endl;
    }
    cout << count << endl;
}