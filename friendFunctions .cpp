#include <iostream>
#include <cmath>
#include <ctime>

class Segment;
class Circle;
class Rectangle;

class Point {
    friend class Segment;
    friend class Circle;
    friend class Rectangle;
    friend std::ostream& operator<<(std::ostream& str, const Point& p);
    int x, y;

public:
    // Constructor with default arguments
    Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {};
    // Copy constructor
    Point(const Point& p0) {
        x = p0.x;
        y = p0.y;
    }
};

// Overloaded output operator for Point class
std::ostream& operator<<(std::ostream& str, const Point& p) {
    str << "(" << p.x << " , " << p.y << ")";
    return str;
}

class Segment {
    Point start, end;
    friend std::ostream& operator<<(std::ostream& str, const Segment& p);
    friend Circle;

public:
    // Constructor with default arguments
    Segment(Point p0 = { 0,0 }, Point k0 = { 0,0 }) : start(p0), end(k0) {};
    // Method to calculate the length of the segment
    int length() {
        return(sqrt((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y)));
    }
};

// Overloaded output operator for Segment class
std::ostream& operator<<(std::ostream& str, const Segment& p) {
    str << "Start: " << p.start << " End: " << p.end << std::endl;
    return str;
}

class Circle {
    friend std::ostream& operator<<(std::ostream& str, const Circle& o);
    Point center;
    int r;

public:
    // Constructor with default arguments
    Circle(Point o0 = Point(), int r0 = 0) : center(o0), r(r0) {}

    // Method to check if two circles intersect
    bool intersects(Circle& second) {
        Segment r1r2 = (center, second.center);
        if ((r + second.r) <= r1r2.length())
            return true;
        else
            return false;
    }
};

// Overloaded output operator for Circle class
std::ostream& operator<<(std::ostream& str, const Circle& o) {
    str << "Center: " << o.center << " Radius " << o.r << std::endl;
    return str;
}

class Rectangle {
    friend std::ostream& operator<<(std::ostream&, const Rectangle&);
    Point leftTop;
    int width, height;

public:
    // Constructor with default arguments
    Rectangle(Point p0 = { 0,0 }, int w = 0, int h = 0) :leftTop(p0), width(w), height(h) {};
    // Method to check if a point is contained within the rectangle
    bool contains(const Point& p0) {
        if ((leftTop.x <= p0.x && p0.x <= (leftTop.x + width)) && (leftTop.y <= p0.y && p0.y <= (leftTop.y + height)))
            return true;
        else
            return false;
    }
};

// Overloaded output operator for Rectangle class
std::ostream& operator<<(std::ostream& str, const Rectangle& p) {
    str << p.leftTop << " Height " << p.height << " Width " << p.width << std::endl;
    return str;
}

// Function to count intersections between two arrays of circles
void countIntersections(Circle tab1[], int d1, Circle tab2[], int d2) {
    int intersectionCount = 0;
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            if (tab1[i].intersects(tab2[j]))
                intersectionCount++;
        }
    }
    std::cout << "Number of intersections of circle arrays: " << intersectionCount << std::endl;
}

// Function to print a Point
void print(Point p) {
    std::cout << p << std::endl;
}

// Function to print a Segment
void print(Segment s) {
    std::cout << s << std::endl;
}

// Function to print a Circle
void print(Circle c) {
    std::cout << c << std::endl;
}

// Function to print a Rectangle
void print(Rectangle r) {
    std::cout << r << std::endl;
}

int main() {
    Point pointArray[3] = { Point(5,2), Point(-9,-9), Point(2,3) };
    Rectangle r1 = { Point(-8,-6), 13, 10 };

    // Check if points are contained within the rectangle
    for (int i = 0; i < 3; i++)
        if (r1.contains(pointArray[i]))
            std::cout << pointArray[i] << " is contained in rectangle " << r1;

    Circle circleArray[100];
    srand(time(NULL));
    int x = 0, y = 0, r = 0;
    // Generate circles with random parameters
    for (int i = 0; i < 100; i++) {
        x = rand() % 6;
        y = (rand() % 6) - 5;
        r = (rand() % 10) + 1;
        circleArray[i] = Circle(Point(x, y), r);
    }

    // Generate second array of circles
    Circle* circleArray2 = new Circle[50];
    for (int i = 0; i < 50; i++) {
        x = (rand() % 16) - 5;
        y = (rand() % 16) + 5;
        r = (rand() % 15) + 1;
        circleArray2[i] = Circle(Point(x, y), r);
    }

    // Count intersections between the two arrays of circles
    countIntersections(circleArray, 100, circleArray2, 50);
    // Print example objects
    print(circleArray[0]);
    print(r1);
    print(Point(5, 2));

    delete[] circleArray2;
    return 0;
}
