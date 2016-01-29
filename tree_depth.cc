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

    std::cout << get_depth( n ) << std::endl;
}