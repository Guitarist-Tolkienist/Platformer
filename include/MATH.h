#ifndef PLATFORMER_MATH_H
#define PLATFORMER_MATH_H

namespace _2D {

    struct SVector_2D {
        float m_X;
        float m_Y;

        SVector_2D();
        SVector_2D(float x, float y);
        SVector_2D(const SVector_2D& Vector_2D);

        // OPERATORS
        void operator+=(const SVector_2D& Vector2);
        void operator-=(const SVector_2D& Vector2);

        SVector_2D& operator=(const SVector_2D& Vector2);

        friend SVector_2D operator*(const SVector_2D &V1, float value) {
            return SVector_2D(V1.m_X * value, V1.m_Y * value);
        }

        friend SVector_2D operator*(float value, const SVector_2D &V1) {
            return V1 * value;
        }
    };


    const SVector_2D ZeroVector_2D(0.0f, 0.0f);
}

#endif //PLATFORMER_MATH_H
