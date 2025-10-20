#include <stdio.h>
#include <math.h>


typedef struct {
    double x, y;
} Point;


void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

/// @return 
Point createPoint(double x, double y) {
    Point result = {x, y};
    return result;
}

double getDistance(Point a, Point b) {
    double x_square = (a.x - b.x) * (a.x - b.x);
    double y_square = (a.y - b.y) * (a.y - b.y);

    return sqrt(x_square + y_square);
}

int main() {
    // a)
    // Point p1 = {2.0, -3.0}, p2 = {-4.0, 5.0};

    // b)
    // printPoint(p1);
    // printf("\n");
    // printPoint(p2);

    // c)
    // Point p1 = createPoint(2.0, -3.0);
    // Point p2 = createPoint(-4.0, 5.0);

    // d)
    double distance = getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));
    // printf("%.2f", distance);
    
    return 0;
}