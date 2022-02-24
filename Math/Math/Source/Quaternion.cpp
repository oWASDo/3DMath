#include <math.h>
#include "../Header/MathUtils.h"
//#include "../Header/Vector3DQuaternion.h"
#include "../Header/Quaternion.h"

#pragma region Ctors
Quaternion::Quaternion(Vector3D euler)
{

	auto c1 = cosf(euler.GetX() * 0.5f);
	auto c2 = cosf(euler.GetY() * 0.5f);
	auto c3 = cosf(euler.GetZ() * 0.5f);
	auto s1 = sinf(euler.GetX() * 0.5f);
	auto s2 = sinf(euler.GetY() * 0.5f);
	auto s3 = sinf(euler.GetZ() * 0.5f);

	w = (c1 * c2 * c3) - (s1 * s2 * s3);
	x = (s1 * c2 * c3) + (c1 * s2 * s3);
	y = (c1 * s2 * c3) - (s1 * c2 * s3);
	z = (c1 * c2 * s3) + (s1 * s2 * c3);
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}


Quaternion::~Quaternion()
{
}
#pragma endregion

#pragma region Operator
bool Quaternion::operator==(Quaternion quaternion)
{
	return quaternion.x == x &&
		quaternion.y == y &&
		quaternion.z == z &&
		quaternion.w == w;
}

bool Quaternion::operator!=(Quaternion quaternion)
{
	return quaternion.x != x ||
		quaternion.y != y ||
		quaternion.z != z ||
		quaternion.w != w;
}

bool Quaternion::Equal(Quaternion quaternion, float tolerance)
{

	return MathUtils::Equal(x, quaternion.x, tolerance) &&
		MathUtils::Equal(y, quaternion.y, tolerance) &&
		MathUtils::Equal(z, quaternion.z, tolerance) &&
		MathUtils::Equal(w, quaternion.w, tolerance);
}
#pragma endregion

#pragma region Getter
float Quaternion::GetX()
{
	return x;
}

float Quaternion::GetY()
{
	return y;
}

float Quaternion::GetZ()
{
	return z;
}

float Quaternion::GetW()
{
	return w;
}
#pragma endregion
