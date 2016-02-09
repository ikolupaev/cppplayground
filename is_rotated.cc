#include <iostream>

using namespace std;

bool is_rotated( string &s1, string &s2 ) {

    return (s1+s1).find(s2) != string::npos;
}

int main()
{
    string s1("apple");
    string s2("plea");
    cout << is_rotated( s1, s2 ) << endl;
}