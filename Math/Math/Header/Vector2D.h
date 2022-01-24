#pragma once
#include <math.h> 
#include "MathUtils.h"

class Vector2D
{
public:
#pragma region Init
	Vector2D();
	Vector2D(float x);
	Vector2D(float x, float y);
	static Vector2D One();
	~Vector2D();

#pragma endregion

#pragma region Sum
	Vector2D operator+ (Vector2D other);
	Vector2D operator+ (float other);
	Vector2D operator++ ();

#pragma endregion

#pragma region Sub
	Vector2D operator- (Vector2D other);
	Vector2D operator- (float other);
	Vector2D operator--();

#pragma endregion

#pragma region Mul	
	Vector2D operator*(Vector2D other);
	Vector2D operator*(float scalar);

#pragma endregion

#pragma region Div
	Vector2D operator/(Vector2D other);
	Vector2D operator/(float other);

#pragma endregion

#pragma region Equal
	bool operator==(Vector2D vector);
	bool Equal(Vector2D other, float offset);
	static bool Equal(Vector2D a, Vector2D b, float offset);

#pragma endregion

#pragma region Lenght
	float Lenght();

#pragma endregion

#pragma region Normal
	Vector2D Normal();

#pragma endregion

#pragma region Dot
	float Dot(Vector2D other);
	static float Dot(Vector2D a, Vector2D b);

#pragma endregion

#pragma region Angle
	float Angle(Vector2D other);
	static float Angle(Vector2D a, Vector2D b);

#pragma endregion

#pragma region Lerp
	Vector2D Lerp(Vector2D clamp, float t);
	static Vector2D Lerp(Vector2D a, Vector2D b, float t);

#pragma endregion

#pragma region Perpendicular
	Vector2D Perpendicular();
	static Vector2D Perpendicular(Vector2D a);

#pragma endregion

#pragma region Reflect
	Vector2D ReflectVector(Vector2D normalVector);
	static Vector2D ReflectVector(Vector2D a, Vector2D normalVector);

#pragma endregion

#pragma region GetSet
	float GetX();
	float GetY();
	void SetX(float X);
	void SetY(float y);

#pragma endregion

private:

	float x;
	float y;


};
