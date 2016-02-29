#include <iostream>
#include <cmath>

using namespace std;
 
void rotate_point( int &x, int &y, int cx, int cy, int angle ) {
    x -= cx;
    y -= cy;
    double a = angle * 3.14 / 180;

    int xx = x * cos(a) - y * sin(a);
    int yy = y * cos(a) + x * sin(a);
   
    x = xx + cx;
    y = yy + cy;
}

int main() {

    int x = 100;
    int y = 0;    
    int angle = 45;

    cout << x << " " << y << endl;

    rotate_point(x,y,0,0,angle);
    cout << x << " " << y << endl;
    
    rotate_point(x,y,0,0,angle);
    cout << x << " " << y << endl;

    rotate_point(x,y,0,0,angle);
    cout << x << " " << y << endl;

    rotate_point(x,y,0,0,angle);
    cout << x << " " << y << endl;
}