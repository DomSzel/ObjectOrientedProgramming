#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define M_PI 3.14159265358979323846

class Vector {
private:
    double x, y;

public:
    // Parameterized and default constructors
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);

    // Addition of two vectors
    // Returns a new vector
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    // Scalar multiplication of vectors
    // Returns a double
    double operator*(const Vector& other) const {
        return x * other.x + y * other.y;
    }

    // Returns the length of the vector
    // Does not modify x and y
    double length() const {
        return std::sqrt(x * x + y * y);
    }
};

// Output stream (display) operator for Vector
std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << "[" << vector.x << ", " << vector.y << "]";
    return out;
}

// Comparison function for sorting vectors by length
bool compareByLength(const Vector& a, const Vector& b) {
    return a.length() < b.length();
}

// Finds the vector in the vector array that is closest to the target vector
Vector findClosestVector(const std::vector<Vector>& vectorArray, const Vector& target) {
    Vector closestVector = vectorArray[0];
    double closestDistance = (vectorArray[0].length() - target.length());

    for (int i = 0; i < vectorArray.size(); i++) {
        double distance = std::abs(vectorArray[i].length() - target.length());
        if (distance < closestDistance) {
            closestVector = vectorArray[i];
            closestDistance = distance;
        }
    }

    return closestVector;
}

// Calculates the angle between two vectors
double calculateAngle(const Vector& a, const Vector& b) {
    double dotProduct = a * b;
    double aLength = a.length();
    double bLength = b.length();
    double cosAlfa = dotProduct / (aLength * bLength);
    // Converts from radians to degrees
    return std::acos(cosAlfa) * (180.0 / M_PI);
}

int main() {

    Vector v1(3, 5);
    Vector v2(-2, 7);

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    //   v1.operator+(v2)
    Vector sum = v1 + v2;
    std::cout << "v1 + v2 = " << sum << std::endl;

    double dotProduct = v1 * v2;
    std::cout << "v1 * v2 = " << dotProduct << std::endl;

    std::vector<Vector> vectorArray;
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        double x = (rand() % 31) - 15;
        double y = (rand() % 31) - 15;
        vectorArray.emplace_back(x, y); // C++ vector method, add to the end
    }

    std::sort(vectorArray.begin(), vectorArray.end(), compareByLength);

    std::cout << "Sorted vectors:" << std::endl;
    for (int i = 0; i < vectorArray.size(); i++) {
        std::cout << vectorArray[i] << ", Length: " << vectorArray[i].length() << std::endl;
    }

    Vector closestVector = findClosestVector(vectorArray, v1);
    std::cout << "Closest to v1: " << closestVector << ", Length: " << closestVector.length() << std::endl;

    double angleBetweenV1V2 = calculateAngle(v1, v2);
    std::cout << "Angle between v1 and v2: " << angleBetweenV1V2 << std::endl;

    return 0;
}
