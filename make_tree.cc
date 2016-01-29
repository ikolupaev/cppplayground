// make tree from sorted buff of ints

#include <iostream>

struct node
{
    node *left;
    node *right;

    int item;

    node( int item )
    {
        left = NULL;
        right = NULL;
        this->item = item;
    };
};

node *make_tree( int *begin, int* end )
{
    if( end < begin ) return NULL;

    auto size = end - begin + 1;
    auto half_way = size / 2;

    int *half_head = begin + half_way;

    node *n = new node( *half_head );
    n->left = make_tree( begin, half_head-1 );
    n->right = make_tree( half_head+1, end );

    return n;
}

void print_node( node *n )
{
    if( n ) std::cout << "item: " << n->item;
    if( n->left ) std::cout << " left: " << n->left->item;
    if( n->right ) std::cout << " right: " << n->right->item;

    std::cout << std::endl;
};

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9};
    
    auto head = make_tree( array, array+8 ); 

    print_node( head );
    print_node( head->left );
    print_node( head->right );
    print_node( head->left->left );
    print_node( head->left->right );
}
