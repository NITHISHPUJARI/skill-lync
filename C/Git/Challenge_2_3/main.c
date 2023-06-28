#include <stdio.h>
#include "rectangle.h"
#include "circle.h"
#include "square.h"

int main() {
    // Rectangle
    double rectLength = 5.0;
    double rectWidth = 3.0;
    double rectArea = rectangle_area(rectLength, rectWidth);
    double rectPerimeter = rectangle_perimeter(rectLength, rectWidth);
    printf("Rectangle Area: %.2f\n", rectArea);
    printf("Rectangle Perimeter: %.2f\n", rectPerimeter);

    // Circle
    double circleRadius = 4.0;
    double circleArea = circle_area(circleRadius);
    double circlePerimeter = circle_perimeter(circleRadius);
    printf("Circle Area: %.2f\n", circleArea);
    printf("Circle Perimeter: %.2f\n", circlePerimeter);

    // Square
    double squareSide = 6.0;
    double squareArea = square_area(squareSide);
    double squarePerimeter = square_perimeter(squareSide);
    printf("Square Area: %.2f\n", squareArea);
    printf("Square Perimeter: %.2f\n", squarePerimeter);

    return 0;
}
