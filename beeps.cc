#include <iostream>
#include <string>

void beep();
void beep(int);

void main()
{
    beep(123);
}

void beep(int num)
{
	auto s = std::to_string(num);
    
	for( auto ch = s.begin(); ch != s.end(); ch++ )
	{
		auto a = (*ch) - '0';

        if( a == 0 )
        {
            a = 10;
        }

		for( auto i = 0; i < a; i++ )
		{
			beep();
            cout << endl;
		}
	}
}

void beep()
{
    cout << "*";
}
