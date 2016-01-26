#include <iostream>

struct node
{
    node *left;
    node *right;
};

bool is_child( node *head, node *n);

int main()
{
   auto head = new node();

   head->left = new node();
   head->right = new node();

   head->left->left = new node();

   head->right->left = new node();
   head->right->right = new node();

   auto deattached_node = new node();

   std::cout << "h.r.r: " << is_child( head, head->right->right ) << std::endl;
   std::cout << "h.l: " << is_child( head, head->left ) << std::endl;
   std::cout << "deattached: " << is_child( head, deattached_node ) << std::endl;
}

bool is_child(node *head, node *n )
{
    if( head == n ) return true;
    if( head == NULL ) return false;
    if( is_child( head->left, n ) ) return true;
    if( is_child( head->right, n ) ) return true;

    return false;
}
