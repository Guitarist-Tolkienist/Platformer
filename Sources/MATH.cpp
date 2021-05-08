#include "MATH.h"


namespace _2D {

    SVector_2D::SVector_2D() :
            X(0),
            Y(0) {}

    SVector_2D::SVector_2D(float x, float y) :
            X(x),
            Y(y) {}

    SVector_2D::SVector_2D(const SVector_2D& Vector_2D) {
        X = Vector_2D.X;
        Y = Vector_2D.Y;
    }

    // OPERATORS
    SVector_2D& SVector_2D::operator=(const SVector_2D &Vector2) {
        this->X = Vector2.X;
        this->Y = Vector2.Y;
        return *this;
    }

    SVector_2D& SVector_2D::operator+=(const SVector_2D &Vector2) {
        this->X += Vector2.X;
        this->Y += Vector2.Y;
        return *this;
    }
    SVector_2D& SVector_2D::operator-=(const SVector_2D &Vector2) {
        this->X -= Vector2.X;
        this->Y -= Vector2.Y;
        return *this;
    }
    SVector_2D& SVector_2D::operator*=(float Value) {
        this->X *= Value;
        this->Y *= Value;

        return *this;
    }
    SVector_2D& SVector_2D::operator/=(float Value) {
        this->X /= Value;
        this->Y /= Value;

        return *this;
    }

    SVector_2D operator+(const SVector_2D& Vector1, const SVector_2D& Vector2) {
        return SVector_2D(Vector1.X + Vector2.X, Vector1.Y + Vector2.Y);
    }
    SVector_2D operator-(const SVector_2D& Vector1, const SVector_2D& Vector2) {
        return SVector_2D(Vector1.X - Vector2.X, Vector1.Y - Vector2.Y);
    }

    SVector_2D operator*(const SVector_2D &Vector1, float Value) {
        return SVector_2D(Vector1.X * Value, Vector1.Y * Value);
    }
    SVector_2D operator*(float Value, const SVector_2D &Vector1) {
        return Vector1 * Value;
    }

    std::ostream& operator<<(std::ostream& out, const SVector_2D& Vector) {
        out << "Vector (" << Vector.X << ", " << Vector.Y << ")\n";
        return out;
    }


    // RECTANGLE
    bool DoRectanglesOverlap(const SRectangle& R1, const SRectangle& R2) {
        if (DoRectanglesOverlap_X(R1, R2) &&
            DoRectanglesOverlap_Y(R1, R2)) {
            return true;
        }

        return false;
    }

    bool DoRectanglesOverlap_X(const SRectangle& R1, const SRectangle& R2) {
        if ((R1.TopLeft.X < R2.BottomRight.X  ) && (R1.BottomRight.X > R2.TopLeft.X  )) {
            return true;
        }

        return false;
    }

    bool DoRectanglesOverlap_Y(const SRectangle& R1, const SRectangle& R2) {
        if ((R1.TopLeft.Y < R2.BottomRight.Y  ) &&
            (R1.BottomRight.Y > R2.TopLeft.Y  ) ) {
            return true;
        }
        return false;
    }
}