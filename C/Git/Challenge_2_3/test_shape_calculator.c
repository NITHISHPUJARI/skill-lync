#include <stdio.h>
#include <assert.h>
#include "rectangle.h"
#include "circle.h"
#include "square.h"

void test_rectangle() {
    double length = 4.5;
    double width = 3.2;
    double expected_area = 14.4;
    double expected_perimeter = 15.4;

    double actual_area = rectangle_area(length, width);
    double actual_perimeter = rectangle_perimeter(length, width);

    assert(actual_area == expected_area);
    assert(actual_perimeter == expected_perimeter);

    printf("Rectangle tests passed.\n");
}

void test_circle() {
    double radius = 5.0;
    double expected_area = 78.53;
    double expected_perimeter = 31.41;

    double actual_area = circle_area(radius);
    double actual_perimeter = circle_perimeter(radius);

    assert(actual_area == expected_area);
    assert(actual_perimeter == expected_perimeter);

    printf("Circle tests passed.\n");
}

void test_square() {
    double side = 6.7;
    double expected_area = 44.89;
    double expected_perimeter = 26.8;

    double actual_area = square_area(side);
    double actual_perimeter = square_perimeter(side);

    assert(actual_area == expected_area);
    assert(actual_perimeter == expected_perimeter);

    printf("Square tests passed.\n");
}

int main() {
    test_rectangle();    
    test_square();
    test_circle();

    return 0;
}
