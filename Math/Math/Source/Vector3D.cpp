#include "../Header/Matrix4x4.h"
//#include "../Header/Vector3DQuaternion.h"
#include "../Header/Vector3D.h"



#pragma region Init

Vector3D::Vector3D()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3D::Vector3D(float x)
{
	this->x = x;
	y = 0.0f;
	z = 0.0f;
}

Vector3D::Vector3D(float x, float y)
{
	this->x = x;
	this->y = y;
	z = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D Vector3D::One()
{
	return Vector3D(1.0f, 1.0f, 1.0f);
}
#pragma endregion

Vector3D::~Vector3D()
{
}


#pragma region Sum
Vector3D Vector3D::operator+ (Vector3D other) {
	Vector3D sum;
	sum.x = x + other.x;
	sum.y = y + other.y;
	sum.z = z + other.z;
	return sum;
}
Vector3D Vector3D::operator+ (float other) {
	Vector3D sum;
	sum.x = x + other;
	sum.y = y + other;
	sum.z = z + other;
	return sum;
}
Vector3D Vector3D::operator++() {
	Vector3D added;
	added.x = x + 1;
	added.y = y + 1;
	added.z = z + 1;
	return added;
}
#pragma endregion

#pragma region Sub
Vector3D Vector3D::operator-(Vector3D other) {
	Vector3D sub;
	sub.x = x - other.x;
	sub.y = y - other.y;
	sub.z = z - other.z;
	return sub;
}

Vector3D Vector3D::operator-(float other) {
	Vector3D sub;
	sub.x = x - other;
	sub.y = y - other;
	sub.z = z - other;
	return sub;
}

Vector3D Vector3D::operator--() {
	Vector3D sub;
	sub.x = x - 1.0f;
	sub.y = y - 1.0f;
	sub.z = z - 1.0f;
	return sub;
}
#pragma endregion

#pragma region Mul
Vector3D Vector3D::operator*(Vector3D other) {
	Vector3D mul;
	mul.x = x * other.x;
	mul.y = y * other.y;
	mul.z = z * other.z;
	return mul;
}
Vector3D Vector3D::operator*(float scaler) {
	Vector3D scaled;
	scaled.x = x * scaler;
	scaled.y = y * scaler;
	scaled.z = z * scaler;
	return scaled;
}
#pragma endregion

#pragma region Div
Vector3D Vector3D::operator/(Vector3D other) {
	Vector3D div;
	div.x = x / other.x;
	div.y = y / other.y;
	div.z = z / other.z;
	return div;

}
Vector3D Vector3D::operator/(float other) {
	Vector3D div;
	div.x = x / other;
	div.y = y / other;
	div.z = z / other;
	return div;
}
#pragma endregion

#pragma region Equal
bool Vector3D::operator==(Vector3D other) {
	return x == other.x && y == other.y && z == other.z;
}
bool Vector3D::operator!=(Vector3D other) {
	return x == other.x || y == other.y || z == other.z;
}
bool Vector3D::Equal(Vector3D other, float offset)
{
	bool xEqualitX = ((x - other.x) < offset);
	bool yEqualitY = ((y - other.y) < offset);
	bool zEqualitY = ((z - other.z) < offset);
	return xEqualitX && yEqualitY && zEqualitY;
}
bool Vector3D::Equal(Vector3D a, Vector3D b, float offset) {

	return a.Equal(b, offset);
}

#pragma endregion

#pragma region Lenght
float Vector3D::Lenght()
{
	float lenght = 0.0f;
	float squareX = x * x;
	float squareY = y * y;
	float squareZ = z * z;
	float squareSum = squareX + squareY + squareZ;
	return sqrtf(squareSum);
}
#pragma endregion

#pragma region Normal
Vector3D Vector3D::Normal()
{
	float lenght = Lenght();

	return Vector3D(x / lenght, y / lenght, z / lenght);
}

#pragma endregion


#pragma region Dot
float Vector3D::Dot(Vector3D other)
{
	return (x * other.x) + (y * other.y) + (z * other.z);
}
float Vector3D::Dot(Vector3D a, Vector3D b)
{
	return a.Dot(b);
}
#pragma endregion

#pragma region Cross
Vector3D Vector3D::Cross(Vector3D other)
{
	//return (x * other.x) + (y * other.y) + (z * other.z);
	return Vector3D((y * other.z) - (z * other.y),
		(z * other.x) - (x * other.z),
		(x * other.y) - (y * other.x));
}
Vector3D Vector3D::Cross(Vector3D a, Vector3D b)
{
	return a.Cross(b);
}
#pragma endregion


#pragma region Angle
float Vector3D::Angle(Vector3D other) {
	float dot = Dot(other);
	float lenght0 = Lenght();
	float lenght1 = other.Lenght();

	return dot / (lenght0 * lenght1);
}
float Vector3D::Angle(Vector3D a, Vector3D b) {
	return a.Angle(b);
}
Vector3D Vector3D::Lerp(Vector3D clamp, float t)
{
	t = MathUtils::Clamp(t, 0.0f, 1.0f);
	return Vector3D();
}
Vector3D Vector3D::Lerp(Vector3D a, Vector3D b, float t)
{
	return a.Lerp(b, t);
}
Vector3D Vector3D::ReflectVector(Vector3D normalVector)
{
	auto s = 2.0f * Dot(*this, normalVector);
	return *this - (normalVector * s);
}
Vector3D Vector3D::ReflectVector(Vector3D a, Vector3D normalVector)
{
	return a.ReflectVector(normalVector);
}
#pragma endregion

#pragma region GetSet

float Vector3D::GetX() {
	return x;
}

float Vector3D::GetY() {
	return y;
}

float Vector3D::GetZ() {
	return z;
}

void Vector3D::SetX(float x) {
	this->x = x;
}
void Vector3D::SetY(float y) {
	this->y = y;
}
void Vector3D::SetZ(float z) {
	this->z = z;
}
#pragma endregion

#pragma endregion
Vector3D Vector3D::RotateRad(Vector3D vector) {


	/*

	Vector3D result = *this;
#pragma region First

	std::vector<float> first;
	first.push_back(1);
	first.push_back(0);
	first.push_back(0);
	first.push_back(0);

	first.push_back(0);
	first.push_back(cosf(rotate.GetX()));
	first.push_back(-sinf(rotate.GetX()));
	first.push_back(0);

	first.push_back(0);
	first.push_back(sinf(rotate.GetX()));
	first.push_back(cosf(rotate.GetX()));
	first.push_back(0);

	first.push_back(0);
	first.push_back(0);
	first.push_back(0);
	first.push_back(1);

#pragma endregion

#pragma region Second
	std::vector<float> second;
	second.push_back(cosf(rotate.GetY()));
	second.push_back(0);
	second.push_back(sinf(rotate.GetY()));
	second.push_back(0);

	second.push_back(0);
	second.push_back(1);
	second.push_back(0);
	second.push_back(0);

	second.push_back(-sinf(rotate.GetY()));
	second.push_back(0);
	second.push_back(cosf(rotate.GetY()));
	second.push_back(0);

	second.push_back(0);
	second.push_back(0);
	second.push_back(0);
	second.push_back(1);

#pragma endregion

#pragma region Third

	std::vector<float> third;
	third.push_back(cosf(rotate.GetZ()));
	third.push_back(-sinf(rotate.GetZ()));
	third.push_back(0);
	third.push_back(0);

	third.push_back(sinf(rotate.GetZ()));
	third.push_back(cosf(rotate.GetZ()));
	third.push_back(0);
	third.push_back(0);

	third.push_back(0);
	third.push_back(0);
	third.push_back(1);
	third.push_back(0);

	third.push_back(0);
	third.push_back(0);
	third.push_back(0);
	third.push_back(1);

	Matrix4x4 m1 = Matrix4x4(first);
	Matrix4x4 m3 = Matrix4x4(third);
	Matrix4x4 m2 = Matrix4x4(second);
	result = m1 * result;
	result = m2 * result;
	result = m3 * result;

#pragma endregion


	return result;
	*/

	Quaternion q = Quaternion(vector);

	return RotateRad(q);
}

Vector3D Vector3D::RotateRad(Quaternion quaternion) {

	Vector3D xyz = Vector3D(quaternion.GetX(), quaternion.GetY(), quaternion.GetZ());
	Vector3D temp = Vector3D::Cross(xyz, *this);
	Vector3D temp2 = *this * quaternion.GetW();
	temp = temp + temp2;
	temp2 = Vector3D::Cross(xyz, temp);
	temp2 = temp2 * 2.0f;
	return *this + temp2;
}

Vector3D Vector3D::RotateDeg(Vector3D vector)
{
	/*vector = Vector3D(
		vector.GetX() * 0.0174532924f,
		vector.GetY() * 0.0174532924f,
		vector.GetZ() * 0.0174532924f);*/
	vector = vector * 0.0174532924f;
	return RotateRad(vector);
}



#pragma region Rotate

