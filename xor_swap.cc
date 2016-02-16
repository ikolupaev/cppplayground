#include <iostream>

using namespace std;

void swap( int &a, int &b )
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main()
{
    int a = 100;
    int b = 999;
    
    cout << a << " " << b << endl;
    
    swap( a, b );

    cout << a << " " << b << endl;
}