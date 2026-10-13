#include<iostream>
using namespace std;
int main ()
{
double x, y;
cout<<"Enter x :"<< " ";
cin >> x;

cout <<"Enter y :" << " ";
cin >> y;

if(y+x<3 && 4*y-x>2 && 2*y-3*x<6){
    cout<< "The point lies within the triangle.";
}
else{
    cout<< "The point lies outside the triangle.";
}
return 0;
}