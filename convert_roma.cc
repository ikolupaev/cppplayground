#include <map>
#include <string>
#include <iostream>

using namespace std;

void insert( map<char,int> &map, char ch, int n ) {
    map.insert( pair<char,int>(ch, n) );
}

int convert( const string &roma ) { 
    map<char,int> numbers;
    
    insert(numbers, 'I', 1);
    insert(numbers, 'V', 5);
    insert(numbers, 'X', 10);
    insert(numbers, 'L', 50);
    insert(numbers, 'C', 100);
    insert(numbers, 'D', 500);
    insert(numbers, 'M', 1000);

    int result = 0;
    int accum = 0;
    int max = 0;
    
    for ( auto it = roma.rbegin(); it != roma.rend(); it++ ) {
        int c = numbers[*it];
        if( c >= max )
        {
            result += max - accum;
            max = c;
            accum = 0;
        }
        else
        {
            accum += c;
        }
    }
        
    result += max - accum;
    return result;
}

int main()
{
    cout << convert( "CDXCIX" ) << endl;    
    cout << convert( "IV" ) << endl;    
    cout << convert( "XCIV" ) << endl;    
    cout << convert( "V" ) << endl;    
    cout << convert( "IV" ) << endl;    
    cout << convert( "VI" ) << endl;    
    cout << convert( "VII" ) << endl;    
}
    