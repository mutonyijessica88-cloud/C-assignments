// A buffer region is an area created around a geographic feature at a specified distance.
// For example, a 1 km buffer around a water point represents all areas located within 1 km of that water source.
// Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

// Write a program that creates buffers of different sizes around a specific point coordinate and returns the points in a given set that lie within each buffer.
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    double x;
    double y;

    Point(double xValue, double yValue)
    {
        x = xValue;
        y = yValue;
    }
};

// Function to calculate distance between two points
double calculateDistance(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to find points within a buffer
void findPoints(Point centre, Point points[], int numberOfPoints, double buffer)
{
    cout << "\nPoints within buffer of " << buffer << " units:\n";

    bool found = false;

    for (int i = 0; i < numberOfPoints; i++)
    {
        double distance = calculateDistance(centre, points[i]);

        if (distance <= buffer)
        {
            cout << "Point " << i + 1 << ": ("
                 << points[i].x << ", "
                 << points[i].y << ")"
                 << " - Distance: " << distance << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No points found within this buffer.\n";
    }
}

int main()
{
    // The specific point coordinate
    Point centre(0, 0);

    // Given set of points
    Point points[] =
    {
        Point(1, 1),
        Point(2, 2),
        Point(3, 1),
        Point(4, 4),
        Point(5, 2),
        Point(-2, -1),
        Point(-4, -3)
    };

    int numberOfPoints = 7;

    // Different buffer sizes
    double buffers[] = {2, 4, 6};

    int numberOfBuffers = 3;

    cout << "Centre Point: ("
         << centre.x << ", "
         << centre.y << ")\n";

    cout << "============================\n";

    // Check points for each buffer
    for (int i = 0; i < numberOfBuffers; i++)
    {
        findPoints(
            centre,
            points,
            numberOfPoints,
            buffers[i]
        );
    }

    return 0;
}