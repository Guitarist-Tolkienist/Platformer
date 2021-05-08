#ifndef PLATFORMER_MATH_H
#define PLATFORMER_MATH_H

#include <iostream>

namespace _2D {

    // VECTOR 2D
    struct SVector_2D {
        float X;
        float Y;

        SVector_2D();
        SVector_2D(float x, float y);
        SVector_2D(const SVector_2D& Vector_2D);

        // OPERATORS
        SVector_2D& operator=(const SVector_2D& Vector2);

        SVector_2D& operator+=(const SVector_2D& Vector2);
        SVector_2D& operator-=(const SVector_2D& Vector2);
        SVector_2D& operator*=(float Value);
        SVector_2D& operator/=(float Value);
    };

    // OPERATORS
    SVector_2D operator+(const SVector_2D& Vector1, const SVector_2D& Vector2);
    SVector_2D operator-(const SVector_2D& Vector1, const SVector_2D& Vector2);

    SVector_2D operator*(const SVector_2D &Vector1, float Value);
    SVector_2D operator*(float Value, const SVector_2D &Vector1);

    float DotProduct();

    std::ostream& operator<<(std::ostream& out, const SVector_2D& Vector);


    const SVector_2D ZeroVector_2D(0.0f, 0.0f);



    // RECTANGLE
    struct SRectangle {
        SVector_2D TopLeft;
        SVector_2D BottomRight;
    };

    bool DoRectanglesOverlap(const SRectangle& rect1, const SRectangle& rect2);

    bool DoRectanglesOverlap_X(const SRectangle& rect1, const SRectangle& rect2);

    bool DoRectanglesOverlap_Y(const SRectangle& rect1, const SRectangle& rect2);
}

#endif //PLATFORMER_MATH_H
