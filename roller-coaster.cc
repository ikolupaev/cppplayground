#include <inttypes.h>
#include <iostream>
#include <ctime>

int main() {
    
    int places;
    int rides;
    int groupsNumber;

    std::cin >> places >> rides >> groupsNumber;

    int groups[groupsNumber];
    
    for (int i = 0; i < groupsNumber; i++) {
        std::cin >> groups[i];
    }

    uint64_t dirhams = 0; 
    int people = 0; 
    int groupsLoaded = 0;
    int n = 0;

    unsigned int start = clock();
    
    for( int i = 0; i < rides; i++ ) { 
         people = 0; 
         groupsLoaded = 0; 
         while( people+groups[n%groupsNumber] <= places && groupsLoaded < groupsNumber ) { 
              people += groups[n%groupsNumber]; groupsLoaded++; n++;
         }

         dirhams = dirhams + (uint64_t) people;
    }
    
    std::cerr << "Time taken in millisecs: " << clock()-start << std::endl;
    std::cout << dirhams << std::endl;
    return 0;
}
