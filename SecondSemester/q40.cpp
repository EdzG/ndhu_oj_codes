#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Coord {
    int x, y; 
public:
    Coord() : x(0), y(0) {}
    Coord(int _x, int _y) : x(_x), y(_y) {}
    Coord(const Coord& c) : x(c.x), y(c.y) {}

    void setX(int newX) { x = newX; }
    int getX() const { return x; }
    void setY(int newY) { y = newY; }
    int getY() const { return y; }

    bool operator<(const Coord& other) const {
        return (x < other.x || (x == other.x && y < other.y));
    }

    bool operator>(const Coord& other) const {
        return (x > other.x || (x == other.x && y > other.y));
    }

    Coord& operator=(const Coord& other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    friend double getDistance(const Coord& start, const Coord& end) {
        return sqrt(pow(end.getX() - start.getX(), 2) + pow(end.getY() - start.getY(), 2));
    }

    friend std::ostream &operator<<(std::ostream& out, const Coord& c) {
        out << "(" << c.x << ", " << c.y << ")";
        return out;
    }
};

// Function to read coordinates from input, find maximum y, and sort coordinates in descending order
std::vector<Coord> getCoords(int n, int* y_max) {
    std::vector<Coord> coords;
    int x, y;

    // Start with the origin (0, 0)
    coords.push_back(Coord(0, 0));
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y; // Read coordinates
        *y_max = std::max(*y_max, y); // Update y_max if current y is greater
        coords.push_back(Coord(x, y)); // Add coordinate to vector
    }
    std::sort(coords.begin(), coords.end(), std::greater<Coord>()); // Sort coordinates in descending order

    return coords;
}

// Function to calculate the distance to be climbed
double getDistance(const std::vector<Coord>& coords, int y_max) {
    double sum = 0;
    int temp_y_max = 0;

    for (size_t i = 1; i < coords.size() && temp_y_max != y_max; ++i) {
        if (coords[i].getY() > temp_y_max) {
            Coord b = coords[i];
            Coord c = coords[i - 1];
            Coord a(b.getX(), c.getY());

            // Calculate the additional distance required to climb
            sum += getDistance(b, c) - sqrt(pow(temp_y_max - c.getY(), 2) * (1 + pow(getDistance(a, c), 2) / pow(getDistance(a, b), 2)));

            temp_y_max = coords[i].getY();
        }
    }

    return sum;
}

int main() {
    int test_cases, nCoords, y_max;
    double d;

    std::cin >> test_cases; // Read the number of test cases

    while (test_cases--) {
        std::cin >> nCoords; // Read the number of coordinates for current test case
        y_max = 0;
        std::vector<Coord> coords = getCoords(nCoords, &y_max); // Get the coordinates
        d = getDistance(coords, y_max); // Calculate the distance to be climbed
        printf("%.2lf\n", d); // Print the result with 2 decimal places
    }

    return 0;
}
