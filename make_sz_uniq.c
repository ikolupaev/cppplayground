#include <string.h>
#include <stdio.h>

void make_sz_uniq( char *sz ) {

    char *ch = sz;

    while( *ch ) {
        char *ch1 = ch+1;
        while( *ch1 && *ch != *ch1 ) ch1++;
        if( ch1 ) ::memcpy( ch1, ch1+1, ::strlen( ch1+1 )+1 );
      
        ch++;
    }
};

void print_uniq( const char *sz )
{
    char sz_uniq[100];
    ::memset( sz_uniq, 0, 100 );
    ::strcpy( sz_uniq, sz );
    make_sz_uniq( sz_uniq );
 
    printf( "%s - %s\n", sz, sz_uniq );
};

int main()
{
    print_uniq( "123" );
    print_uniq( "1234" );
    print_uniq( "11234" );
    print_uniq( "12234" );
    print_uniq( "11223344" );
}
