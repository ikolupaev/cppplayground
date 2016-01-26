#include <string>
#include <iostream>

void reverse(std::string &str);

int main() {

    std::string s( "abcdefg" );
    reverse( s );
    std::cout << s << std::endl;

    s = "";
    reverse( s );
    std::cout << s << std::endl;
}

void reverse(std::string &str) {

    auto ch1 = str.begin();
    auto ch2 = str.end()-1;

    for ( auto i = 0; i<str.size()/2; i++ ) {
     
        auto ch = *ch1;
        *ch1 = *ch2;
        *ch2 = ch;
   
        ch1++;
        ch2--;   
    }
}
