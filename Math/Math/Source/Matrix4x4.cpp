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
