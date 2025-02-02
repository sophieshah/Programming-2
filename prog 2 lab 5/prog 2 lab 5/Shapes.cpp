#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "Shapes.h"
using namespace std;

const float PI = 3.14159f;

Shape::~Shape() {

}


void Shape2D::ShowArea() const {
	cout << "The area of the "<< this->GetName2D()<< " is : "<< this->Area() << endl;
}
bool Shape2D::operator>(const Shape2D& rhs) const {
	if (this->Area() > rhs.Area()) {
		return true;
	}
	return false;
}
bool Shape2D::operator<(const Shape2D& rhs) const {
	if (this->Area() < rhs.Area()) {
		return true;
	}
	return false;
}
bool Shape2D::operator==(const Shape2D& rhs) const {
	if (this->Area() == rhs.Area()) {
		return true;
	}
	return false;
}
Shape2D::~Shape2D() {

}


void Shape3D::ShowVolume() const {
	cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
}
bool Shape3D::operator>(const Shape3D& rhs) const {
	if (this->Volume() > rhs.Volume()) {
		return true;
	}
	return false;
}
bool Shape3D::operator<(const Shape3D& rhs) const {
	if (this->Volume() < rhs.Volume()) {
		return true;
	}
	return false;
}
bool Shape3D::operator==(const Shape3D& rhs) const {
	if (this->Volume() == rhs.Volume()) {
		return true;
	}
	return false;
}
Shape3D::~Shape3D() {

}


Square::Square() {
	sideLength = 0.0;
}
Square::Square(float userLength) {
	sideLength = userLength;
}
void Square::Scale(float scaleFactor) {
	sideLength *= scaleFactor;
}
void Square::Display() const {
	cout << "The area of the Square is : " <<fixed << setprecision(2) << Area() << endl;
	cout << "Length of a side: " << sideLength << endl;

}
float Square::Area() const {
	return sideLength * sideLength;
}
string Square::GetName2D() const {
	return "Square";
}


Triangle::Triangle() {
	baseLength = 0.0;
	height = 0.0;
}
Triangle::Triangle(float userBaseLength, float userHeight) {
	baseLength = userBaseLength;
	height = userHeight;
}
void Triangle::Scale(float scaleFactor) {
	baseLength *= scaleFactor;
	height *= scaleFactor;
}
void Triangle::Display() const {
	cout << "The area of the Triangle is : " << Area() << endl;
	cout << "Base: " << baseLength << endl;
	cout << "Height: " << height << endl;
}
float Triangle::Area() const {
	return  0.5*baseLength*height;
}
string Triangle::GetName2D() const {
	return "Triangle";
}


Circle::Circle() {
	radius = 0.0;
}
Circle::Circle(float userRadius) {
	radius = userRadius;
}
void Circle::Scale(float scaleFactor) {
	radius *= scaleFactor;
}
void Circle::Display() const {
	cout << "The area of the Circle is : " << Area() << endl;
	cout << "Radius: " << radius << endl;
}
float Circle::Area() const {
	return PI*radius*radius;
}
string Circle::GetName2D() const {
	return "Circle";
}


TriangularPyramid::TriangularPyramid() {
	height = 0.0;
	baseLength = 0.0;
	baseHeight = 0.0;
}
TriangularPyramid::TriangularPyramid(float userHeight, float userBaseLength, float userBaseHeight) {
	height = userHeight;
	baseLength = userBaseLength;
	baseHeight = userBaseHeight;
}
void TriangularPyramid::Scale(float scaleFactor) {
	baseLength *= scaleFactor;
	height *= scaleFactor;
	baseHeight *= scaleFactor;
}
void TriangularPyramid::Display() const {
	Triangle triangle1(baseLength, baseHeight);
	cout << "The volume of the Triangular Pyramid is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	cout << "The area of the Triangle is : " << triangle1.Area() << endl;
	cout << "Base: " << baseLength << endl;
	cout << "Height: " << baseHeight << endl;
}
float TriangularPyramid::Volume() const {
	Triangle triangle1(baseLength, baseHeight);
	return  triangle1.Area()*height*(0.33333);
} 
string TriangularPyramid::GetName3D() const {
	return "Triangular Pyramid";
}


Cylinder::Cylinder() {
	height = 0.0;
	radius = 0.0;
}
Cylinder::Cylinder(float userHeight, float userRadius) {
	height = userHeight;
	radius = userRadius;
}
void Cylinder::Scale(float scaleFactor) {
	radius *= scaleFactor;
	height *= scaleFactor;
}
void Cylinder::Display() const {
	Circle circle1(radius);
	cout << "The volume of the Cylinder is : " << Volume() << endl;
	cout << "The height is: " << height << endl;
	cout << "The area of the Circle is : " << circle1.Area() << endl;
	cout << "Radius: " << radius << endl;
}
float Cylinder::Volume() const {
	Circle circle1(radius);
	return  circle1.Area() * height;
}
string Cylinder::GetName3D() const {
	return "Cylinder";
}


Sphere::Sphere() {
	radius = 0.0;
}
Sphere::Sphere(float userRadius) {
	radius = userRadius;
}
void Sphere::Scale(float scaleFactor) {
	radius *= scaleFactor;
}
void Sphere::Display() const {
	Circle circle1(radius);
	cout << "The volume of the Sphere is : " << Volume() << endl;
	cout << "The area of the Circle is : " << circle1.Area() << endl;
	cout << "Radius: " << radius << endl;
}
float Sphere::Volume() const {
	Circle circle1(radius);
	return  (1.33333333) * circle1.Area() * radius;
}
string Sphere::GetName3D() const {
	return "Sphere";
}