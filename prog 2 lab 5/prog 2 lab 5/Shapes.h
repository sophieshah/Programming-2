#include <iostream>
#include <iomanip>
#include <random>
using namespace std;


class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape();
};

class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
	virtual ~Shape2D();
};

class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
	virtual ~Shape3D();
};

class Square :virtual public Shape2D {
private:
	float sideLength;
public:
	Square();
	Square(float userLength);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle :virtual public Shape2D {
private:
	float baseLength;
	float height;
public:
	Triangle();
	Triangle(float userBaseLength, float userHeight);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Circle :virtual public Shape2D {
private:
	float radius;
public:
	Circle();
	Circle(float userRadius);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class TriangularPyramid :virtual public Shape3D, private Triangle {
private:
	float height;
	float baseLength;
	float baseHeight;
public:
	TriangularPyramid();
	TriangularPyramid(float userHeight, float userBaseLength, float userBaseHeight);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder :virtual public Shape3D, private Circle {
private:
	float height;
	float radius;
public:
	Cylinder();
	Cylinder(float userHeight, float userRadius);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere :virtual public Shape3D, private Circle {
private:
	float radius;
public:
	Sphere();
	Sphere(float userRadius);
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};