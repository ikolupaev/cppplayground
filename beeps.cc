#include <iostream>
#include <string>

void beep();
void beep(int);

int main()
{
    beep(5123);
}

void beep(int num)
{
    std::cout << num << " beeps as \n";

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
        }

        std::cout << std::endl;
    }
}

void beep()
{
    std::cout << "*";
}
