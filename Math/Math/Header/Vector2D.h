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
	bool operator!=(Vector2D vector);

	/// <summary>
	/// Check equality
	/// </summary>
	/// <param name="Vector2D other: vector to check"></param>
	/// <param name="float secondValue: second value"></param>
	/// <param name="float tolerance: tolerance value"></param>
	/// <returns>"Return if is equal BOOL"</returns>
	bool Equal(Vector2D other, float tolerance);

	/// <summary>
	/// Check equality
	/// </summary>
	/// <param name="Vector2D a: quaternion a to check"></param>
	/// <param name="Vector2D b: quaternion b to check"></param>
	/// <param name="float tolerance: tolerance value"></param>
	/// <returns>"Return if is equal BOOL"</returns>
	static bool Equal(Vector2D a, Vector2D b, float tolerance);

#pragma endregion

#pragma region Lenght
	/// <summary>
	/// Get lenght of vector
	/// </summary>
	/// <returns>"Return lenght FLOAT"</returns>
	float Lenght();

#pragma endregion

#pragma region Normal
	/// <summary>
	/// Get vector normalizer
	/// </summary>
	/// <returns>"Return normal VECTOR2D"</returns>
	Vector2D Normal();

#pragma endregion

#pragma region Dot
	/// <summary>
	/// Make dot product
	/// </summary>
	/// <param name="Vector2D other: other vector to make DOT product"></param>
	/// <returns>"Return dot product FLOAT"</returns>
	float Dot(Vector2D other);

	/// <summary>
	/// Make dot product
	/// </summary>
	/// <param name="Vector2D a: a vector to make DOT product"></param>
	/// <param name="Vector2D b: b vector to make DOT product"></param>
	/// <returns>"Return dot product FLOAT"</returns>
	static float Dot(Vector2D a, Vector2D b);

#pragma endregion

#pragma region Angle
	/// <summary>
	/// Compute angle between to vector
	/// </summary>
	/// <param name="Vector2D other: other vector to calculate angle"></param>
	/// <returns>"Return angle FLOAT"</returns>
	float AngleDeg(Vector2D other);

	/// <summary>
	/// Compute angle between to vector
	/// </summary>
	/// <param name="Vector2D a: a vector to calculate angle"></param>
	/// <param name="Vector2D b: b vector to calculate angle"></param>
	/// <returns>"Return angle FLOAT"</returns>
	static float AngleDeg(Vector2D a, Vector2D b);

#pragma endregion

#pragma region Lerp
	/// <summary>
	/// Compute lerped vector
	/// </summary>
	/// <param name="Vector2D clamp: end part vector to compute"></param>
	/// <param name="float t: value of lerp between 0.0f - 1.0f"></param>
	/// <returns>"Return lerped angle VECTOR2D"</returns>
	Vector2D Lerp(Vector2D clamp, float t);

	/// <summary>
	/// Compute lerped vector
	/// </summary>
	/// <param name="Vector2D a: a vector to calculate angle"></param>
	/// <param name="Vector2D b: b vector to calculate angle"></param>
	/// <param name="float t: value of lerp between 0.0f - 1.0f"></param>
	/// <returns>"Return lerped angle VECTOR2D"</returns>
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

#pragma region Rotate
	Vector2D RotateDeg(float angle);
	static Vector2D RotateDeg(Vector2D vector, float angle);

	Vector2D RotateAboutDeg(Vector2D center, float angle);
	static Vector2D RotateAboutDeg(Vector2D vector, Vector2D center, float angle);

	Vector2D RotateRad(float angle);
	static Vector2D RotateRad(Vector2D vector, float angle);

	Vector2D RotateAboutRad(Vector2D center, float angle);
	static Vector2D RotateAboutRad(Vector2D vector, Vector2D center, float angle);
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
