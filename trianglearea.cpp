#include <iostream>
using namespace std;
int main()
{
    double x, y;
    cout << "Enter the a point x and y coordinates of the first point: ";
    cin >> x >> y;

    if (y + 4*x <23 && y>3 && y - 2*x < -1)
    {
        cout << "The point is inside the triangle." << endl;
    }
    else
    {
        cout << "The point is not inside the triangle." << endl;
    }






    return 0;
}