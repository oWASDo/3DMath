#pragma once
 class MathUtils
{
public:


	MathUtils();


	~MathUtils();

	/// <summary>
	/// Clamp value
	/// </summary>
	/// <param name="float value: value to check"></param>
	/// <param name="float min: min value"></param>
	/// <param name="float max: max value"></param>
	/// <returns>"Return clamped value FLOAT"</returns>
	static float Clamp(float value, float min, float max);

	/// <summary>
	/// Check equality
	/// </summary>
	/// <param name="float firstValue: first value"></param>
	/// <param name="float secondValue: second value"></param>
	/// <param name="float tolerance: tolerance value"></param>
	/// <returns>"Return if is equal BOOL"</returns>
	static bool Equal(float firstValue, float secondValue, float tolerance);

	static const float Deg2Rad;// = 0.0174532924f;
	static const float  Rad2Deg;// = 57.29578F;
//private:

};
//
//MathUtils::MathUtils()
//{
//}
//
//MathUtils::~MathUtils()
//{
//}