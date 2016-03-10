#include <map>
#include <string>
#include <iostream>

using namespace std;

int index_of( const string &text, const string &s ) {
    int default_skip = s.size();
    map<char,int> skip_map;

    for ( int i = 0; i < s.size() - 1; i++ ) {
        skip_map[s[i]] = s.size() - i - 1;
    }

    int n = s.size()-1;
    int sn = n;

    while ( n < text.size() ) {
        if ( text[n] == s[sn] ) {
            n--;
            sn--;
            
            if ( sn < 0 ) 
                return n+1;
        }
        else if ( skip_map.count(text[n]) ) {
            n += skip_map[text[n]];
            sn = s.size()-1;
        }
        else { 
            n += default_skip;
            sn = s.size()-1;
        }
    }
    
    return -1;
}

int main() {
    string s( "01234 567890 76676 4552" );

    int index = index_of( s, "01" );
    cout << s.substr( index ) << endl;  

    index = index_of( s, "76" );
    cout << s.substr( index ) << endl;  

    index = index_of( s, "52" );
    cout << s.substr( index ) << endl;  
}