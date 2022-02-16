#include "../Header/Matrix4x4.h"


Matrix4x4::Matrix4x4()
{
	for (int i = 0; i < 16; i++)
	{
		elements.push_back(0);
	}
}

Matrix4x4::Matrix4x4(std::vector<float> vector)
{
	elements = vector;
}

Matrix4x4::~Matrix4x4()
{
	elements.clear();
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 matrix)
{
	Matrix4x4 result = Matrix4x4();
	Matrix4x4 transpose = matrix.Transpose();
	int columnIndex = 0;
	int rowIndex = 0;
	for (int i = 0; i < 16; i++)
	{
		result.elements[i] =
			elements[0 + rowIndex] * matrix.elements[0 + columnIndex] +
			elements[1 + rowIndex] * matrix.elements[4 + columnIndex] +
			elements[2 + rowIndex] * matrix.elements[8 + columnIndex] +
			elements[3 + rowIndex] * matrix.elements[12 + columnIndex];

		columnIndex++;

		if (columnIndex == 4)
		{
			columnIndex = 0;
			rowIndex += 4;
		}
	}

	return result;
}

Vector3D Matrix4x4::operator*(Vector3D vector)
{
	Vector3D result = Vector3D();
	result.SetX(elements[0] * vector.GetX() +
		elements[1] * vector.GetY() +
		elements[2] * vector.GetZ() +
		elements[3] * 0);

	result.SetY(elements[0 + 4] * vector.GetX() +
		elements[1 + 4] * vector.GetY() +
		elements[2 + 4] * vector.GetZ() +
		elements[3 + 4] * 0);

	result.SetZ(elements[0 + 8] * vector.GetX() +
		elements[1 + 8] * vector.GetY() +
		elements[2 + 8] * vector.GetZ() +
		elements[3 + 8] * 0);

	float w =
		elements[0 + 12] * vector.GetX() +
		elements[1 + 12] * vector.GetY() +
		elements[2 + 12] * vector.GetZ() +
		elements[3 + 12] * 0;
	return result;
}

Matrix4x4 Matrix4x4::operator+(Matrix4x4 matrix)
{
	Matrix4x4 result = Matrix4x4();
	for (int i = 0; i < 16; i++)
	{
		result.elements[i] = elements[i] + matrix.elements[i];
	}
	return result;

}

Matrix4x4 Matrix4x4::operator-(Matrix4x4 matrix)
{
	Matrix4x4 result = Matrix4x4();
	for (int i = 0; i < 16; i++)
	{
		result.elements[i] = elements[i] - matrix.elements[i];
	}
	return result;

}

bool Matrix4x4::operator==(Matrix4x4 matrix)
{
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == matrix.elements[i]) {

		}
		else
		{
			return false;
		}
	}
	return true;

}
Matrix4x4 Matrix4x4::Transpose() {

	std::vector<float> newVector(16);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int index1 = i * 4 + j;
			int index2 = j * 4 + i;

			newVector[index2] = elements[index1];
		}
	}
	return Matrix4x4(newVector);
}

bool Matrix4x4::SetByIndex(int index, float value)
{
	if (index >= 16)
	{
		return false;
	}
	elements[index] = value;
	return true;

}
