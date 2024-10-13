#include <iostream>
#include <cmath>

class Cone {
public:
    double radius;
    double height;

    // Constructor
    Cone(double r, double h) {
        radius = r;
        height = h;
    }

    // Menghitung volume kerucut
    double volume() {
        return (M_PI * radius * radius * height) / 3;
    }

    // Menghitung luas permukaan kerucut
    double surfaceArea() {
        double slantHeight = sqrt((radius * radius) + (height * height));
        return M_PI * radius * (radius + slantHeight);
    }
};

int main() {
    Cone myCone(5.0, 12.0);

    std::cout << "Volume kerucut: " << myCone.volume() << std::endl;
    std::cout << "Luas permukaan kerucut: " << myCone.surfaceArea() << std::endl;

    return 0;
}