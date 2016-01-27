#include <string>
#include <iostream>

bool has_uniq_chars( const std::string &s );

void print_is_uniq( const std::string &s ) {
    std::cout << s << " is uniq: " << has_uniq_chars( s ) << std::endl;
};


int main() {
    print_is_uniq( "" );
    print_is_uniq( "1234" );    
    print_is_uniq( "11234" );
    print_is_uniq( "12234" );
    print_is_uniq( "12344" );
}


bool has_uniq_chars( const std::string &s ) {
    for( auto ch = s.begin(); ch != s.end(); ch++ ) {
        for( auto ch1 = ch+1; ch1 != s.end(); ch1++ ) {
            if( *ch == *ch1 ) return false;
        }
    }
    
    return true;
}
