#include <iostream>

struct node {
    node *next;
    
    node() { next = nullptr; }
};

node *find_loop( node *head ) {

    node *r1 = head;
    node *r2 = head;

    while ( r2->next != nullptr ) {
        r1 = r1->next;
        r2 = r2->next;
        if( r2->next != nullptr ) r2 = r2->next;
        if( r1 == r2 ) break;
    }
    
    if( r2->next == nullptr ) return nullptr;
    
    r1 = head;
    while ( r1 != r2 ) {
        r1 = r1->next;
        r2 = r2->next;
    }
    
    return r1;
};

int main() {
    node *head = new node;
    head->next = new node;
    head->next->next = new node;
    head->next->next->next = new node;
    
    std::cout << find_loop( head ) << std::endl;

    head->next->next->next->next = head->next;
    std::cout << (find_loop( head ) == head->next) << std::endl;

    head->next->next = head->next;
    std::cout << (find_loop( head ) == head->next) << std::endl;
}