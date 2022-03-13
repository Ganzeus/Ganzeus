#include "Shape.h"

Shape::Shape() = default;
Shape::Shape(Color color_, bool filled_) {
	color = color_;
	filled = filled_;
}

Color Shape::getColor() { return color; }
void Shape::setColor(Color color_) {
	color = color_;
}
bool Shape::isFilled() {
	return filled;
}
void Shape::setFilled(bool filled_) {
	filled = filled_;
}

string Shape::toString() {
	std::array<string, 6> c{ "white"s, "black"s, "red"s,"green"s, "blue"s, "yellow"s, };
	return "Shape: " + c[static_cast<int>(color)] + " " + (filled ? "filled"s : "not filled"s);
}

string Shape::colorToString() {
	return colorNames[static_cast<int>(color)];
}

string Shape::filledToString() {
	return (filled ? "filled"s : "not filled"s);
}