#include "../Header/MathUtils.h"


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