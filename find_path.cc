#include <iostream>
#include <vector>

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

bool find_path( node *head, node *n, std::vector<node*> &path )
{
    if ( head == NULL ) return false;
    path.push_back( head );
    if ( head == n ) return true;
    
    if ( find_path( head->left, n, path) || find_path( head->right, n, path ) ) return true;
    
    path.pop_back();
    return false;        
}

void print_node( node *n )
{
    if( n ) std::cout << "item: " << n->item << std::endl;
};

int main()
{
    node *n = new node(1);
    n->left = new node(2);
    n->left->left = new node(3);

    n->right = new node(4);
    n->right->right = new node(5);
    n->right->right->right = new node(6);

    n->right->left = new node(7);
    n->right->left->right = new node(8);
    n->right->left->right->right = new node(9);
    n->right->left->right->right->right = new node(10);

    std::vector<node*> v;

    find_path( n, n->right->left->right->right, v ); 

    for( auto x: v ) print_node( x );
}