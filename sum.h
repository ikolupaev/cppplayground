#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace sum_str
{
    using namespace std;

    string sum( const vector<string> &numbers ) {
        
        vector<string> reversed;

        for ( auto &s: numbers ) {
            string s1 = s;
            reverse( s1.begin(), s1.end() );
            reversed.push_back( s1 );
        }

        int p = 0;
        int extra = 0;
        string sum;
        
        while (1) {
            int numbers_added = 0;
            int sub_sum = extra;
            
            for ( auto &s: reversed ) {
                
                if ( s.size() > p ) {
                    numbers_added++;
                    sub_sum += s[p] - '0';
                }
            }
            
            if ( numbers_added == 0 ) break;
            
            char ch = '0' + sub_sum % 10;
            sum.append( 1, ch );
            extra = sub_sum / 10;
            p++;
        }
        
        reverse( sum.begin(), sum.end() );
        sum.insert( 0, to_string(extra) );
 
        while ( !sum.empty() && sum[0] == '0' ) 
            sum.erase( sum.begin() );
        
        return sum;
    };
}