#include <cstdint>
#include <iostream>
#include <algorithm>
#include <iomanip>

void transpose_matrix( uint32_t *matrix, int size ) {
    
    for( int row = 0; row < size; row++ )
        for( int col = 0; col < row; col++ )
            std::swap( matrix[col+row*size], matrix[row+col*size] );

};

void print_matrix( uint32_t *matrix, int size )
{
     for( int row = 0; row < size; row++ ) {
        for( int col = 0; col < size; col++ ) {
            std::cout << std::setw(3) << matrix[row+col*size];
        }
        std::cout << std::endl;
    } 

};

int main()
{
    int matrix_size = 3;
    uint32_t matrix[matrix_size*matrix_size];

     for( int row = 0; row < matrix_size; row++ ) 
        for( int col = 0; col < matrix_size; col++ ) 
            matrix[row+col*matrix_size] = col+1+row*matrix_size;
     
     std::cout << "original matrix:" << std::endl;
     print_matrix( matrix, matrix_size );

     transpose_matrix( matrix, matrix_size );

     std::cout << "result matrix:" << std::endl;
     print_matrix( matrix, matrix_size );
}
