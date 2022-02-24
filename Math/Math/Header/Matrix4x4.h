#pragma once
#include <vector>
#include "Vector3D.h"
class Matrix4x4
{
public:

	Matrix4x4();

	/// <summary>
	/// Create matrix from vector array
	/// </summary>
	/// <param name="std::vector<float> vector: first value"></param>
	Matrix4x4(std::vector<float> vector);

	~Matrix4x4();

	Matrix4x4 operator* (Matrix4x4 matrix);
	Vector3D operator* (Vector3D vector);
	Matrix4x4 operator+ (Matrix4x4 matrix);
	Matrix4x4 operator- (Matrix4x4 matrix);

	bool operator== (Matrix4x4 matrix);
	bool operator!= (Matrix4x4 matrix);


	/// <summary>
	/// Transpose Matrix
	/// </summary>
	/// <returns>"Return transposed MATRIX4X4"</returns>
	Matrix4x4 Transpose();

    /// <summary>
	/// SetValue at index
	/// </summary>
	/// <param name="int index: matrix index"></param>
	/// <param name="float value: setting value"></param>
	/// <returns>"Return if value is setted BOOL"</returns>
	bool SetByIndex(int index, float value);

private:

	std::vector<float> elements;


};
