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
	int index = 0;
	int index2 = 0;
	for (int i = 0; i < 16; i++)
	{
		result.elements[i] = elements[0 + index2] * matrix.elements[0 + index] + elements[1 + index2] * matrix.elements[4 + index] +
			elements[2 + index2] * matrix.elements[8 + index] + elements[3 + index2] * matrix.elements[12 + index];
		index++;
		if (index == 4)
		{
			index = 0;
			index2 += 4;
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
