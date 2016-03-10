#include <iostream>
#include <vector>
#include <algorithm>

int get_index( int r, int c ) {
	int n = c;
	int rr = 1;
	while ( rr < r ) n += (rr++);
	return n-1;
};

int get_max_path( std::vector<int> &pyramide, int r, int c ) {
	int index = get_index( r,c );
	if ( index >= pyramide.size() ) return 0;	
	
	int left = get_max_path( pyramide, r+1, c );
	int right = get_max_path( pyramide, r+1, c+1 );

	return pyramide[index] + std::max( left, right );
};

void read_pyramide( std::vector<int> &pyramide ) {
	while ( std::cin ) {
		int v;
		std::cin >> v;
		pyramide.push_back( v );
	}
};

int main() {
	std::vector<int> pyramide;
	read_pyramide( pyramide );
	std::cout << get_max_path( pyramide, 1,1 ) << std::endl;
}
