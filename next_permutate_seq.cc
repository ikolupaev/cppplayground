#include <iostream>

using namespace std;

bool next_permutate_seq(bool seq[], int size) {
    for ( int i = 0; i < size; i++ ) {
        if( seq[i] ) seq[i] = false;
        else {
            seq[i] = true;
            return true;
        }
    }
    return false;
}

int main() {
    bool pack[] = {0,0,0,0};
    int size = sizeof(pack) / sizeof(bool);
    
    while ( next_permutate_seq( pack, size ) ) {
        
        for ( int i = 0; i<size; i++ ) 
            cout << pack[i] << " ";
            
        cout << endl;
    }
}