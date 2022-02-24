#include "../Header/MathUtils.h"
#include <math.h>

MathUtils::MathUtils()
{

}
MathUtils::~MathUtils()
{

}

float MathUtils::Clamp(float value, float min, float max) {

	if (value < min)
	{
		value = min;
	}
	else if (value > max) {

		value = max;
	}
	return value;
}

bool MathUtils::Equal(float firstValue, float secondValue, float tolerance)
{
	return fabsf(firstValue - secondValue) < tolerance;
}

const float MathUtils::Deg2Rad = 0.0174532924f;
const float  MathUtils::Rad2Deg = 57.29578F;