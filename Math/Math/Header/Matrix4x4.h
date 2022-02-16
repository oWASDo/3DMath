#pragma once
#include <vector>
#include "Vector3D.h"
class Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(std::vector<float> vector);
	~Matrix4x4();

	Matrix4x4 operator* (Matrix4x4 matrix);

	Vector3D operator* (Vector3D vector);

	Matrix4x4 operator+ (Matrix4x4 matrix);

	Matrix4x4 operator- (Matrix4x4 matrix);

	bool operator== (Matrix4x4 matrix);

	Matrix4x4 Transpose();

	bool SetByIndex(int index, float value);

private:

	std::vector<float> elements;


};
