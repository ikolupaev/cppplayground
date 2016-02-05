#include <iostream>
#include <vector>

using namespace std;

int get_min_dist_index( int v, vector<int> &centroids ) {
    int min_dist = abs( v - centroids[0] );
    int min_index = 0;
    
    for ( int i = 0; i<centroids.size(); i++ ) {
        auto dist = abs( v - centroids[i] );
        if( dist < min_dist ) {
            min_dist = dist;
            min_index = i;
        }
    }
    
    return min_index;
}

int calc_centroid( vector<int> data ) {
    int sum = 0;
    for( auto d: data ) sum += d;
    return sum/data.size();
}

void k_means( const vector<int> &data, vector<vector<int>> &means ) {
    vector<int> centroids( means.size() );
    for ( auto i = 0; i<means.size(); i++ ) centroids[i] = data[i];
    
    while ( true ) {

        for ( auto it: data ) {
            auto ix = get_min_dist_index( it, centroids );
            means[ix].push_back( it );
        }

        auto completed = 0;
        for ( int i = 0; i<means.size(); i++ ) {
            auto c = calc_centroid(means[i]);
            if ( c == centroids[i] ) completed++;
            else centroids[i] = c;
        }
        if ( completed == means.size() ) return;
        for ( auto &it: means ) it.clear();
    }
}

int main() {
    vector<int> data = { 1,2,10,11,100,101 };
    vector<vector<int>> means;
    means.push_back(vector<int>());
    means.push_back(vector<int>());
    means.push_back(vector<int>());
    
    k_means( data, means );
    
    for( auto m: means ) {
        cout << "***" << endl;
        for( auto it: m ) {
            cout << it << endl;
        }
    }
}