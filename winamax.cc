#include <iostream>
#include <string>
#include <list>

using namespace std;

list<string> stack1;
list<string> stack2;

list<string> war1;
list<string> war2;

int turn = 0;
list<string>::iterator p1; 
list<string>::iterator p2; 
    
void load_cards( list<string> &stack ) {

    int n;
    cin >> n; 
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        cardp1.resize( cardp1.size()-1 );
        stack.push_back(cardp1);
    }
};

int first_takes( string c1, string c2 ) {

    cerr << c1 << " - " << c2 << endl;

    string cards("2345678910JQKA");
    
    auto a1 = cards.find_first_of( c1 ); 
    auto a2 = cards.find_first_of( c2 );
    
    return a1 - a2;    
};


void move( list<string> &to, list<string> &from, size_t count ) {
    
    while ( count > 0 && !from.empty() ) {
        to.push_back(from.front());
        from.pop_front();
        count--;
    }

};

void print_seq( string label, list<string> l ) {

    cerr << label << " " ;
    for ( auto it = l.begin(); it != l.end(); it++ ) cerr << *it << " ";
    cerr << endl;
}

int main() {

    load_cards( stack1 );
    load_cards( stack2 );

    cerr << "inital: " << " " << stack1.size() << " " << stack2.size() << endl; 

    while( !stack1.empty() && !stack2.empty() ) {
        
        print_seq( "stack1", stack1 );
        print_seq( "stack2", stack2 );

        print_seq( "war1  ", war1 );
        print_seq( "war2  ", war2 );
  
        auto p = first_takes( stack1.front(), stack2.front() );
        
        cerr << turn << " " << p << endl;
        
        move( war1, stack1, (size_t) 1 );
        move( war2, stack2, (size_t) 1 );
  
        if ( p > 0 ) { 
            move( stack1, war1, war1.size() );
            move( stack1, war2, war2.size() );
        }
        
        if ( p < 0 ) { 
            move( stack2, war1, war1.size() );
            move( stack2, war2, war2.size() );
        }
        
        if ( p == 0 ) {
            
            if ( stack1.size() < 3 || stack2.size() < 3 ) {
                cout << "PAT" << endl;
                return 1;
            }

            move( war1, stack1, (size_t) 3 );
            move( war2, stack2, (size_t) 3 );
            turn--;
        }

        turn++;
    }
    
    cerr << "***" << endl;
    print_seq( "stack1", stack1 );
    print_seq( "stack2", stack2 );

    print_seq( "war1  ", war1 );
    print_seq( "war2  ", war2 );
    
    if ( !stack1.empty() )
        cout << 1 << " " << turn << endl;
    else if ( !stack2.empty() )
        cout << 2 << " " << turn << endl;
    else cout << "PAT" << endl;
}