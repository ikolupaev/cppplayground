#include <algorithm>
#include <iostream>

typedef std::vector<int>::iterator int_iterator;

void merge( std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &result ) {
    auto b1 = v1.begin();
    auto b2 = v2.begin();
     
    while( b1 != v1.end() && b2 != v2.end() ) {
        if( *b1 < *b2 ) {
            result.push_back( *b1 );
            b1++;
        } else {
            result.push_back( *b2 );
            b2++;
        }
    }
    
    while( b1 != v1.end() ) {
        result.push_back( *b1 );
        b1++;
    }
    
    while( b2 != v2.end() ) {
        result.push_back( *b2 );
        b2++;
    }
};

void merge_sort( const std::vector<int> &v, std::vector<int> &result ) {

    if( v.size() < 2 ) {
        result.push_back(*v.begin());
        return;
    }
    
    auto half = v.size() / 2;
    
    std::vector<int> v1(v.begin(), v.begin() + half);
    std::vector<int> result1;

    std::vector<int> v2(v.begin() + half, v.end());    
    std::vector<int> result2;
    
    merge_sort( v1, result1 );
    merge_sort( v2, result2 );
    
    merge( result1, result2, result );
}

int main() {
    
    std::vector<int> v = {9,8,7,6,5,4,3,2,1,0};
    std::vector<int> result;

    merge_sort( v, result );
    
    for( auto p: result ) std::cout << p << std::endl;
}