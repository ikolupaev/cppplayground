#include <iostream>

using namespace std;

uint64_t calc_diff_of_squares( int begin, int end ) {

	uint64_t sum_of_squares = 0;
	uint64_t sum = 0;

	for( int i = begin; i <= end; i++ ) {
	   sum_of_squares += i*i;
	   sum += i;
    }

    return sum*sum - sum_of_squares;
}

int main() {
    cout << calc_diff_of_squares(1,10) << endl;
    cout << calc_diff_of_squares(1,100) << endl;
}
