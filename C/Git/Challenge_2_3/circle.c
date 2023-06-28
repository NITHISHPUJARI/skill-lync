#include "circle.h"
#include <math.h>
#define PI 3.14

double circle_area(double radius) {
    return PI * radius * radius;
}

double circle_perimeter(double radius) {
    return 2 * PI * radius;
}
