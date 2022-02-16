#pragma once
#include <math.h> 
#include <vector>
#include "MathUtils.h"
class Vector3D
{
public:
#pragma region Init

	Vector3D();
	Vector3D(float x);
	Vector3D(float x, float y);
	Vector3D(float x, float y, float z);
	static Vector3D One();

	~Vector3D();
#pragma endregion

#pragma region Sum
	Vector3D operator+ (Vector3D other);
	Vector3D operator+ (float other);
	Vector3D operator++ ();
#pragma endregion

#pragma region Sub
	Vector3D operator- (Vector3D other);
	Vector3D operator- (float other);
	Vector3D operator--();

#pragma endregion
#pragma region Mul	
	Vector3D operator*(Vector3D other);
	Vector3D operator*(float scalar);

#pragma endregion
#pragma region Div
	Vector3D operator/(Vector3D other);
	Vector3D operator/(float other);

#pragma endregion

#pragma region Equal
	bool operator==(Vector3D vector);
	bool Equal(Vector3D other, float offset);
	static bool Equal(Vector3D a, Vector3D b, float offset);

#pragma endregion

#pragma region Lenght
	float Lenght();

#pragma endregion


#pragma region Normal
	Vector3D Normal();

#pragma endregion

#pragma region Dot
	float Dot(Vector3D other);
	static float Dot(Vector3D a, Vector3D b);

#pragma endregion

#pragma region Cross
	Vector3D Cross(Vector3D other);
	static Vector3D Cross(Vector3D a, Vector3D b);
#pragma endregion


#pragma region Angle
	float Angle(Vector3D other);
	static float Angle(Vector3D a, Vector3D b);

#pragma endregion

#pragma region Lerp
	Vector3D Lerp(Vector3D clamp, float t);
	static Vector3D Lerp(Vector3D a, Vector3D b, float t);

#pragma endregion

#pragma region Reflect
	Vector3D ReflectVector(Vector3D normalVector);
	static Vector3D ReflectVector(Vector3D a, Vector3D normalVector);

#pragma endregion

#pragma region GetSet
	float GetX();
	float GetY();
	float GetZ();
	void SetX(float X);
	void SetY(float y);
	void SetZ(float y);

#pragma endregion
	Vector3D Rotate(Vector3D vec);
#pragma region Rotate

#pragma endregion


private:
	float x;
	float y;
	float z;
};
