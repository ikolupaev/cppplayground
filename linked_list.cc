#include <iostream>  

class node
{
public:
    node *next = NULL;
};

class linked_list
{
public:
    void add(node*);
    node* at(int index);
    bool remove(node*);
    bool insert(node *insert_after_node, node *node_to_insert);
    int count();

    linked_list();

private:
    node *head = NULL;
};

void print_count(linked_list list)
{
    std::cout << "number of elements: " << list.count() << std::endl;
}

int main()
{
    linked_list list;

    print_count(list);

    std::cout << "inserting node\n";

    list.add( new node() );
    list.add( new node() );
    list.add( new node() );

    print_count(list);

    std::cout << "second node is " << list.at(1) << std::endl;

    std::cout << "removing the second node\n";

    list.remove( list.at(1) );
    
    print_count(list);

    std::cout << "inserting after the second\n";

    list.insert( list.at(1), new node() );

    print_count(list);

    std::cout << "free and remove all nodes\n";

    while( list.count() > 0 )
    {
        auto n = list.at(0);
        list.remove(n);
        delete n;
    }
    
    print_count(list);
}

linked_list::linked_list()
{
    head = NULL;
}

void linked_list::add(node *node_to_insert)
{
    if( head == NULL )
    {
       head = node_to_insert;
       return;
    }

    auto n = head;
    while( n->next != NULL )
    {
        n = n->next;
    }

    n->next = node_to_insert;
    node_to_insert->next = NULL;
}

bool linked_list::remove(node *node_to_remove)
{
    if( node_to_remove == head )
    {
        head = node_to_remove->next;
        return true;
    }

    auto n = head;
    
    while( n->next != node_to_remove && n->next != NULL )
    {
        n = n->next;
    }

    if( n->next != NULL )
    {
       n->next = n->next->next;
       return true;
    }

    return false;
}

node* linked_list::at(int index)
{
    auto n = head;

    while( index > 0 && n != NULL ) 
    {
        n = n->next;
        index--;
    }
 
    return n;
}

bool linked_list::insert(node *insert_after, node *node_to_insert)
{
    node_to_insert->next = insert_after->next;
    insert_after->next = node_to_insert;
}

int linked_list::count()
{
    int count = 0;
    auto n = head;
    while( n != NULL )
    {
        count++;
        n = n->next;
    }

    return count;
}
