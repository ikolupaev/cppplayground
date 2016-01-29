#include <iostream>
#include <algorithm>


struct node

{
    
    node *left;
    
    node *right;

    
};


int get_depth( node *head )
{
    if( head == NULL ) return 0;
    return std::max( get_depth( head->left ) + 1, get_depth( head->right ) + 1 );
};

bool is_balanced( node *head )
{
    if( head == NULL )
    {
        return true;
    }

    int left_length = get_depth( head->left );
    int right_length = get_depth( head->right );
    if( std::abs( left_length - right_length ) > 1 ) return false;

    return is_balanced( head->left ) && is_balanced( head->right );
};

void print_tree( node *n )
{
    std::cout << "depth: " << get_depth( n ) << " balanced: " << is_balanced( n ) << std::endl;
};

int main()
{
    node *n = new node();
    n->left = new node();
    n->left->left = new node();

    n->right = new node();
    n->right->right = new node();
    n->right->right->right = new node();

    n->right->left = new node();
    n->right->left->right = new node();
    n->right->left->right->right = new node();
    n->right->left->right->right->right = new node();

    print_tree( n );

    node *n1 = new node();
    n1->left = new node();
    n1->right = new node();
    n1->left->left = new node();
    n1->left->right = new node();
    n1->right->left = new node();
    n1->right->right = new node();

    print_tree( n1 );
}