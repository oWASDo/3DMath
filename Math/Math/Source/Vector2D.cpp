#include "../Header/Vector2D.h"

#pragma region Init
Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x)
{
	this->x = x;
	this->y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;

}
Vector2D Vector2D::One() {
	return Vector2D(1.0f, 1.0f);
}
#pragma endregion


Vector2D::~Vector2D() {

}

#pragma region Sum
Vector2D Vector2D::operator+ (Vector2D other) {
	Vector2D sum;
	sum.x = x + other.x;
	sum.y = y + other.y;
	return sum;
}
Vector2D Vector2D::operator+ (float other) {
	Vector2D sum;
	sum.x = x + other;
	sum.y = y + other;
	return sum;
}
Vector2D Vector2D::operator++() {
	Vector2D added;
	added.x = x + 1;
	added.y = y + 1;
	return added;
}
#pragma endregion

#pragma region Sub
Vector2D Vector2D::operator-(Vector2D other) {
	Vector2D sub;
	sub.x = x - other.x;
	sub.y = y - other.y;
	return sub;
}

Vector2D Vector2D::operator-(float other) {
	Vector2D sub;
	sub.x = x - other;
	sub.y = y - other;
	return sub;
}

Vector2D Vector2D::operator--() {
	Vector2D sub;
	sub.x = x - 1.0f;
	sub.y = y - 1.0f;
	return sub;
}
#pragma endregion

#pragma region Mul
Vector2D Vector2D::operator*(Vector2D other) {
	Vector2D mul;
	mul.x = x * other.x;
	mul.y = y * other.y;
	return mul;
}
Vector2D Vector2D::operator*(float scaler) {
	Vector2D scaled;
	scaled.x = x * scaler;
	scaled.y = y * scaler;
	return scaled;
}
#pragma endregion

#pragma region Div
Vector2D Vector2D::operator/(Vector2D other) {
	Vector2D div;
	div.x = x / other.x;
	div.y = y / other.y;
	return div;

}
Vector2D Vector2D::operator/(float other) {
	Vector2D div;
	div.x = x / other;
	div.y = y / other;
	return div;
}
#pragma endregion

#pragma region Equal
bool Vector2D::operator==(Vector2D other) {
	return x == other.x && y == other.y;
}
bool Vector2D::Equal(Vector2D other, float offset)
{
	bool xEqualitX = ((x - other.x) < offset);
	float vv = y - other.y;
	bool yEqualitY = ((vv) < offset);
	return xEqualitX && yEqualitY;
}
bool Vector2D::Equal(Vector2D a, Vector2D b, float offset) {

	return a.Equal(b, offset);
}

#pragma endregion

#pragma region Lenght
float Vector2D::Lenght()
{
	float lenght = 0.0f;
	float squareX = x * x;
	float squareY = y * y;
	float squareSum = squareX + squareY;
	return sqrtf(squareSum);
}
#pragma endregion

#pragma region Normal
Vector2D Vector2D::Normal()
{
	float lenght = Lenght();

	return Vector2D(x / lenght, y / lenght);
}

#pragma endregion

#pragma region Dot
float Vector2D::Dot(Vector2D other)
{
	return (x * other.x) + (y * other.y);
}
float Vector2D::Dot(Vector2D a, Vector2D b)
{
	return a.Dot(b);
}
#pragma endregion

#pragma region Angle
float Vector2D::Angle(Vector2D other) {
	float dot = Dot(other);
	float lenght0 = Lenght();
	float lenght1 = other.Lenght();

	return dot / (lenght0 * lenght1);
}
float Vector2D::Angle(Vector2D a, Vector2D b) {
	return a.Angle(b);
}
#pragma endregion

#pragma region Lerp
Vector2D Vector2D::Lerp(Vector2D other, float t)
{
	if (t < 0.0f)
	{
		t = 0.0f;
	}
	else if (t > 1.0f) {

		t = 1.0f;
	}
	Vector2D dir = other - *this;

	return *this + (dir * t);
}

Vector2D Vector2D::Lerp(Vector2D a, Vector2D b, float t)
{
	return a.Lerp(b, t);
}

#pragma endregion

#pragma region Perpendicular
Vector2D Vector2D::Perpendicular() {
	return Vector2D(y, -x);
}

Vector2D Vector2D::Perpendicular(Vector2D a) {
	return a.Perpendicular();
}

#pragma endregion

#pragma region Reflect
Vector2D Vector2D::ReflectVector(Vector2D normalVector) {

	auto s = 2.0f * Dot(*this, normalVector);
	return *this - (normalVector * s);
}

Vector2D Vector2D::ReflectVector(Vector2D a, Vector2D normalVector) {


	return a.ReflectVector(normalVector);

}
#pragma endregion

#pragma region GetSet

float Vector2D::GetX() {
	return x;
}

float Vector2D::GetY() {
	return y;
}

void Vector2D::SetX(float x) {
	this->x = x;
}
void Vector2D::SetY(float y) {
	this->y = y;
}
#pragma endregion

