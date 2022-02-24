#ifndef Quat
#define Quat
#pragma once

#include "Vector3D.h"

class Vector3D;

class Quaternion
{
public:
#pragma region Ctors


	Quaternion(Vector3D euler);
	Quaternion(float x, float y, float z, float w);
	~Quaternion();
#pragma endregion

#pragma region Operator
	bool operator==(Quaternion quaternion);
	bool operator!=(Quaternion quaternion);

	/// <summary>
	/// Check equality
	/// </summary>
	/// <param name="Quaternion quaternion: quaternion to check"></param>
	/// <param name="float secondValue: second value"></param>
	/// <param name="float tolerance: tolerance value"></param>
	/// <returns>"Return if is equal BOOL"</returns>
	bool Equal(Quaternion quaternion, float tolerance);

#pragma endregion
	
#pragma region Getter
	/// <summary>
	/// Check equality
	/// </summary>
	/// <returns>"Return x FLOAT"</returns>
	float GetX();

	/// <summary>
	/// Check equality
	/// </summary>
	/// <returns>"Return Y FLOAT"</returns>
	float GetY();

	/// <summary>
	/// Check equality
	/// </summary>
	/// <returns>"Return Z FLOAT"</returns>
	float GetZ();

	/// <summary>
	/// Check equality
	/// </summary>
	/// <returns>"Return W FLOAT"</returns>
	float GetW();

#pragma endregion


private:
	float x;
	float y;
	float z;
	float w;
};
#endif