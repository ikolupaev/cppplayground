#include "sum.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> numbers;
    string s;

    while ( getline( cin, s ) && !s.empty() ) {
        numbers.push_back(s);
    }

    cout << sum_str::sum( numbers ) << endl;
}