#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<double> rainfall;

    double sum = 0;
    int count = 0;
    double average = 0;
    double median;
    double rf;
    cout<< "Enter the rainfall for 10 days (-1 to stop): " << endl;
    cin >> rf;
    while (rf != -1)
    {
        rainfall.push_back(rf);
        cin >> rf;
    }
    
    for (int i = 0; i < rainfall.size(); ++i)
    {
        sum = sum + rainfall[i];
        count++;
    }
    average = sum / count;
    sort(rainfall.begin(), rainfall.end());
    if (count % 2 == 0)
    {
        double median = (rainfall[count / 2] + rainfall[(count / 2) - 1])/2;
    }else {
        double median = rainfall[count/2];
    }
    // range for loop
    //for (double R:rainfall)
    std::cout << "median" << median << endl;
    std::cout << "averge" << average << endl;

    return 0;
}