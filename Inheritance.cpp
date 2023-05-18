#include <iostream>

class Shape {
protected:
    std::string m_strType;
    double m_width;
    double m_height;

public:
    Shape(double width, double height) : m_width(width), m_height(height) {
        m_strType = "Shape";
    }

    virtual ~Shape() {}

    void displayProperties() {
        std::cout << "Shape Type: " << m_strType << ", Height: " << m_height << ", Width: " << m_width << std::endl;
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void scale(double factor) = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : Shape(width, height) {
        m_strType = "Rectangle";
    }

    ~Rectangle() {}

    double area() const override {
        return m_width * m_height;
    }

    double perimeter() const override {
        return 2 * (m_width + m_height);
    }

    void scale(double factor) override {
        m_width *= factor;
        m_height *= factor;
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape(2 * radius, 2 * radius) {
        m_strType = "Circle";
    }

    ~Circle() {}

    double area() const override {
        return 3.14159 * m_width * m_height / 4.0;
    }

    double perimeter() const override {
        return 3.14159 * m_width;
    }

    void scale(double factor) override {
        m_width *= factor;
        m_height *= factor;
    }
};

int main() {
    Shape* p_shapes[2];
    p_shapes[0] = new Circle(1.0);
    p_shapes[1] = new Rectangle(3.0, 2.0);

    for (int i = 0; i < 2; i++) {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area()  << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
    }

    delete p_shapes[0];
    delete p_shapes[1];

    return 0;
}
