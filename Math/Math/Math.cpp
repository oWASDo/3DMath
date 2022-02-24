// Math.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.


#include <iostream>
#include "Header/Vector2D.h"
#include "Header/Vector3D.h"
#include "Header/Quaternion.h"
#include "Header/Matrix4x4.h"
#include "Header/MathUtils.h"

#include "UnitTest/UnitTest.h"

int main()
{
#pragma region Vector2D


	{
		Vector2D v = Vector2D();
		UnitTest::Assert(v.GetX() == 0.0f);
		UnitTest::Assert(v.GetY() == 0.0f);

		Vector2D v1 = Vector2D(1);
		UnitTest::Assert(v1.GetX() == 1.0f);
		UnitTest::Assert(v1.GetY() == 0.0f);

		Vector2D v2 = Vector2D(1, 1);
		UnitTest::Assert(v2.GetX() == 1.0f);
		UnitTest::Assert(v2.GetY() == 1.0f);
	}
	{
		Vector2D v = Vector2D(1, 1);
		UnitTest::Assert(v.GetX() == 1.0f);
		UnitTest::Assert(v.GetY() == 1.0f);
		v.SetX(5);
		v.SetY(7);
		UnitTest::Assert(v.GetX() == 5.0f);
		UnitTest::Assert(v.GetY() == 7.0f);
	}
	{
		Vector2D v = Vector2D(1.0f, 1.0f);
		Vector2D v2 = Vector2D(1.0f, 1.0f);

		UnitTest::Assert(v == v2);
	}
	{
		Vector2D v = Vector2D(1.0f, 1.0f);
		Vector2D v2 = Vector2D(3.0f, 1.0f);

		UnitTest::Assert(v != v2);

		v = Vector2D(1.0f, 1.0f);
		v2 = Vector2D(1.0f, 5.0f);

		UnitTest::Assert(v != v2);
	}
	{
		Vector2D v = Vector2D::One();

		UnitTest::Assert(v.GetX() == 1.0f && v.GetY() == 1.0f);
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D v2 = Vector2D(5.00001f, 5.21401f);
		UnitTest::Assert(v.Equal(v2, 0.001f));
	}
	{
		Vector2D v = Vector2D(1.0f, 1.1f);
		Vector2D v2 = Vector2D(1.0f, 1.0f);
		Vector2D result = v + v2;
		UnitTest::Assert(result == Vector2D(2.0f, 2.1f));
	}

	{
		Vector2D v = Vector2D(5.0f, 5.1f);
		Vector2D v2 = Vector2D(2.0f, 2.0f);
		Vector2D result = v - v2;
		UnitTest::Assert(result == Vector2D(3.0f, 3.1f));
	}

	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D v2 = Vector2D(2.0f, 2.0f);
		Vector2D result = v * v2;
		UnitTest::Assert(result == Vector2D(10.0f, 10.428f));
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D v2 = Vector2D(2.0f, 2.0f);
		Vector2D result = v / v2;
		UnitTest::Assert(result == Vector2D(2.5f, 2.607f));
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D result = v + 2.0f;
		UnitTest::Assert(result == Vector2D(7.0f, 7.214f));
	}
	{
		Vector2D v = Vector2D(5.0f, 6.0f);
		Vector2D result = v - 2.0f;
		UnitTest::Assert(result == Vector2D(3.0f, 4.0f));
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D result = v * 2.0f;
		UnitTest::Assert(result == Vector2D(10.0f, 10.428f));
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214f);
		Vector2D result = v / 4.0f;
		UnitTest::Assert(result == Vector2D(1.25, 1.3035f));
	}
	{
		Vector2D v = Vector2D(1.0f, 5.0f);
		float lenght = v.Lenght();
		UnitTest::Assert(lenght == 5.09901951359f);
	}
	{
		Vector2D v = Vector2D(7.0f, 5.0f);
		Vector2D norm = v.Normal();
		UnitTest::Assert(norm.Equal(Vector2D(0.81373f, 0.58124f), 0.001f));
	}
	{
		Vector2D v = Vector2D(2.0f, 3.0f);
		Vector2D v1 = Vector2D(5.0f, 8.0f);
		float dot = v.Dot(v1);
		float c = (dot - 34.0f);
		UnitTest::Assert((dot - 34.0f) < 0.001f);
	}
	{
		Vector2D v = Vector2D(2.1f, 3.01f);
		Vector2D v1 = Vector2D(5.24f, 8.25f);
		float dot = v.Dot(v1);
		UnitTest::Assert((dot - 35.8365f) < 0.001f);
	}
	{
		Vector2D v = Vector2D(2.1f, 3.01f);
		Vector2D v1 = Vector2D(5.24f, 8.25f);
		float dot = Vector2D::Dot(v, v1);
		UnitTest::Assert((dot - 35.8365f) < 0.001f);
	}


	{
		Vector2D v = Vector2D(7.1f, 1.25f);
		Vector2D v1 = Vector2D(5.02f, 5.42f);
		float angle = v.AngleDeg(v1);
		UnitTest::Assert((angle - 0.7964f) < 0.001f);
	}


	{
		Vector2D v = Vector2D(-7.1f, 1.25f);
		Vector2D v1 = Vector2D(-5.02f, -5.42f);
		float angle = v.AngleDeg(v1);
		UnitTest::Assert((angle - 0.54201f) < 0.001f);
	}
	{
		Vector2D v = Vector2D(-7.1f, 1.25f);
		Vector2D v1 = Vector2D(-5.02f, -5.42f);
		float angle = Vector2D::AngleDeg(v, v1);
		UnitTest::Assert((angle - 0.54201f) < 0.001f);
	}


	{
		Vector2D v = Vector2D(0.0f, 0.0f);
		Vector2D v1 = Vector2D(1.0f, 1.0f);
		Vector2D lerped = v.Lerp(v1, 0.25f);
		UnitTest::Assert(lerped.Equal(Vector2D(0.25f, 0.25f), 0.001f));
		lerped = v.Lerp(v1, 0.75f);
		UnitTest::Assert(lerped.Equal(Vector2D(0.75f, 0.75f), 0.001f));
	}

	{
		Vector2D v = Vector2D(0.2f, 5.0f);
		Vector2D v1 = Vector2D(5.2f, 1.0f);
		Vector2D lerped = v.Lerp(v1, 0.25f);
		UnitTest::Assert(lerped.Equal(Vector2D(1.45f, 4.0f), 0.001f));
	}

	{
		Vector2D v = Vector2D(0.7f, 3.6f);
		Vector2D v1 = Vector2D(3.8f, 2.0f);
		Vector2D lerped = v.Perpendicular();
		UnitTest::Assert(lerped.Equal(Vector2D(3.6f, -0.7f), 0.001f));
	}


	{
		Vector2D v = Vector2D(0.7f, 3.6f);

		Vector2D normal = Vector2D(0.9f, 0.1f);
		Vector2D reflect = v.ReflectVector(normal);
		UnitTest::Assert(Vector2D::Equal(reflect, Vector2D(-1.08f, 3.4f), 0.01f));
	}
	{
		Vector2D v = Vector2D(0.7f, 3.6f);
		Vector2D normal = Vector2D(1.0f, 0.0f);
		Vector2D reflect = Vector2D::ReflectVector(v, normal);
		UnitTest::Assert(Vector2D::Equal(reflect, Vector2D(-0.7f, 3.6f), 0.001f));
	}
	{
		Vector2D v = Vector2D(2.5, 1.0f);
		Vector2D rotated = v.RotateDeg(30.0f);
		UnitTest::Assert(
			Vector2D::Equal(rotated, Vector2D(2.66506f, -0.3839f), 0.001f));
	}
	{
		Vector2D v = Vector2D(2.5, 0.0f);
		Vector2D rotated = Vector2D::RotateDeg(v, 30.0f);
		UnitTest::Assert(Vector2D::Equal(rotated, Vector2D(
			2.1650f, -1.25f), 0.001f));
	}

	{
		Vector2D v = Vector2D(2.5, 0.0f);
		Vector2D rotated = v.RotateRad(0.1f);
		UnitTest::Assert(Vector2D::Equal(rotated, Vector2D(2.4875104131951f, -0.24958354161707f), 0.001f));
	}
	{
		Vector2D v = Vector2D(2.5, 0.0f);
		Vector2D rotated = Vector2D::RotateRad(v, 0.1f);
		UnitTest::Assert(Vector2D::Equal(rotated, Vector2D(2.4875104131951f, -0.24958354161707f), 0.001f));
	}

#pragma endregion


#pragma region Vector3D
	{
		Vector3D v = Vector3D();
		UnitTest::Assert(v.GetX() == 0.0f);
		UnitTest::Assert(v.GetY() == 0.0f);
		UnitTest::Assert(v.GetZ() == 0.0f);

		Vector3D v1 = Vector3D(1.0f);
		UnitTest::Assert(v1.GetX() == 1.0f);
		UnitTest::Assert(v1.GetY() == 0.0f);
		UnitTest::Assert(v1.GetZ() == 0.0f);

		Vector3D v2 = Vector3D(1.0f, 1.0f);
		UnitTest::Assert(v2.GetX() == 1.0f);
		UnitTest::Assert(v2.GetY() == 1.0f);
		UnitTest::Assert(v2.GetZ() == 0.0f);

		Vector3D v3 = Vector3D(1.0f, 1.0f, 1.0f);
		UnitTest::Assert(v3.GetX() == 1.0f);
		UnitTest::Assert(v3.GetY() == 1.0f);
		UnitTest::Assert(v3.GetZ() == 1.0f);
	}
	{
		Vector3D v = Vector3D(1.0f, 1.0f, 1.0f);
		UnitTest::Assert(v.GetX() == 1.0f);
		UnitTest::Assert(v.GetY() == 1.0f);
		UnitTest::Assert(v.GetZ() == 1.0f);
		v.SetX(5.0f);
		v.SetY(7.0f);
		v.SetZ(99.0f);
		UnitTest::Assert(v.GetX() == 5.0f);
		UnitTest::Assert(v.GetY() == 7.0f);
		UnitTest::Assert(v.GetZ() == 99.0f);
	}
	{
		Vector3D v = Vector3D(1.0f, 1.0f, 1.0f);
		Vector3D v2 = Vector3D(1.0f, 1.0f, 1.0f);

		UnitTest::Assert(v == v2);
	}

	{
		Vector3D v = Vector3D(1.0f, 1.0f, 1.0f);
		Vector3D v2 = Vector3D(2.0f, 1.0f, 1.0f);

		UnitTest::Assert(v != v2);

		v = Vector3D(1.0f, 1.0f, 1.0f);
		v2 = Vector3D(1.0f, 2.0f, 1.0f);

		UnitTest::Assert(v != v2);

		v = Vector3D(1.0f, 1.0f, 1.0f);
		v2 = Vector3D(1.0f, 1.0f, 2.0f);

		UnitTest::Assert(v != v2);
	}
	{
		Vector3D v = Vector3D::One();

		UnitTest::Assert(v.GetX() == 1.0f && v.GetY() == 1.0f && v.GetZ() == 1.0f);
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 2.151f);
		Vector3D v2 = Vector3D(5.00001f, 5.21401f, 2.151f);
		UnitTest::Assert(v.Equal(v2, 0.001f));
	}
	{
		Vector3D v = Vector3D(1.0f, 1.1f, 2.0f);
		Vector3D v2 = Vector3D(1.0f, 1.0f, 2.0f);
		Vector3D result = v + v2;
		UnitTest::Assert(result == Vector3D(2.0f, 2.1f, 4.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.1f, 2.0f);
		Vector3D v2 = Vector3D(2.0f, 2.0f, 1.0f);
		Vector3D result = v - v2;
		UnitTest::Assert(result == Vector3D(3.0f, 3.1f, 1.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 2.0f);
		Vector3D v2 = Vector3D(2.0f, 2.0f, 3.0f);
		Vector3D result = v * v2;
		UnitTest::Assert(result == Vector3D(10.0f, 10.428f, 6.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 5.0f);
		Vector3D v2 = Vector3D(2.0f, 2.0f, 2.0f);
		Vector3D result = v / v2;
		UnitTest::Assert(result == Vector3D(2.5f, 2.607f, 2.5f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 4.0f);
		Vector3D result = v + 2.0f;
		UnitTest::Assert(result == Vector3D(7.0f, 7.214f, 6.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 6.0f, 2.0f);
		Vector3D result = v - 2.0f;
		UnitTest::Assert(result == Vector3D(3.0f, 4.0f, 0.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 7.0f);
		Vector3D result = v * 2.0f;
		UnitTest::Assert(result == Vector3D(10.0f, 10.428f, 14.0f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214f, 4.0f);
		Vector3D result = v / 4.0f;
		UnitTest::Assert(result == Vector3D(1.25, 1.3035f, 1.0f));
	}
	{
		Vector3D v = Vector3D(1.0f, 5.0f, 7.0f);
		float lenght = v.Lenght();
		UnitTest::Assert(lenght == 8.660254037844387f);
	}
	{
		Vector3D v = Vector3D(7.0f, 5.0f, 25.0f);
		Vector3D norm = v.Normal();
		UnitTest::Assert(norm.Equal(Vector3D(0.26476f, 0.18911f, 0.94558f), 0.001f));
	}
	{
		Vector3D v = Vector3D(2.0f, 3.0f, 5.0f);
		Vector3D v1 = Vector3D(5.0f, 8.0f, 2.5f);
		float dot = v.Dot(v1);
		float c = (dot - 34.0f);
		UnitTest::Assert((dot - 46.5f) < 0.001f);
	}
	{
		Vector3D v = Vector3D(2.1f, 3.01f, 5.25f);
		Vector3D v1 = Vector3D(5.24f, 8.25f, 1.34f);
		float dot = Vector3D::Dot(v, v1);
		UnitTest::Assert((dot - 42.8715f) < 0.001f);
	}
	{
		Vector3D v = Vector3D(2.1f, 3.01f, 5.25f);
		Vector3D v1 = Vector3D(5.24f, 8.25f, 1.34f);
		Vector3D cross = v.Cross(v1);
		UnitTest::Assert(cross.Equal(Vector3D(-39.2791f, 24.696f, 1.5526f), 0.001f));
	}
	{
		Vector3D v = Vector3D(7.1f, 1.25f, 2.0f);
		Vector3D v1 = Vector3D(5.02f, 5.42f, 4.0f);
		float angle = v.Angle(v1);
		UnitTest::Assert((angle - 0.8021f) < 0.001f);
	}
	{
		Vector3D v = Vector3D(-7.1f, 1.25f, 7.0f);
		Vector3D v1 = Vector3D(-5.02f, -5.42f, 2.0f);
		float angle = v.Angle(v1);
		UnitTest::Assert((angle - 0.55738f) < 0.001f);
	}
	{
		Vector3D v = Vector3D(0.0f, 0.0f, 0.0f);
		Vector3D v1 = Vector3D(1.0f, 1.0f, 1.0f);
		Vector3D lerped = v.Lerp(v1, 0.25f);
		UnitTest::Assert(lerped.Equal(Vector3D(0.25f, 0.25f), 0.001f));
		lerped = v.Lerp(v1, 0.75f);
		UnitTest::Assert(lerped.Equal(Vector3D(0.75f, 0.75f), 0.001f));
	}
	{
		Vector3D v = Vector3D(0.2f, 5.0f, 0.0f);
		Vector3D v1 = Vector3D(5.2f, 1.0f, 1.0f);
		Vector3D lerped = v.Lerp(v1, 0.25f);
		UnitTest::Assert(lerped.Equal(Vector3D(1.45f, 4.0f, 0.25f), 0.001f));
	}
	{
		Vector3D v = Vector3D(0.2f, 5.0f, 0.0f);
		Vector3D normal = Vector3D(0.1490128f, -0.309673f, 0.9390942f);
		Vector3D reflect = v.ReflectVector(normal);
		UnitTest::Assert(
			Vector3D::Equal(reflect, Vector3D(0.6525703f, 4.059485f, 2.852146f), 0.1f));
	}
	{
		Vector3D v = Vector3D(0.2f, 5.0f, 0.0f);
		Vector3D normal = Vector3D(0.1490128f, -0.309673f, 0.9390942f);
		Vector3D reflect = Vector3D::ReflectVector(v, normal);
		UnitTest::Assert(
			Vector3D::Equal(reflect, Vector3D(0.6525703f, 4.059485f, 2.852146f), 0.1f));
	}


	{
#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14); vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region Second

		std::vector<float> vector1;
		vector1.push_back(1); vector1.push_back(2); vector1.push_back(3); vector1.push_back(4);
		vector1.push_back(5); vector1.push_back(6); vector1.push_back(7); vector1.push_back(8);
		vector1.push_back(9); vector1.push_back(10); vector1.push_back(11); vector1.push_back(12);
		vector1.push_back(13); vector1.push_back(14); vector1.push_back(15); vector1.push_back(16);
#pragma endregion

		Matrix4x4 m = Matrix4x4(vector);
		Matrix4x4 m1 = Matrix4x4(vector1);

		UnitTest::Assert(m == m1);

	}


	{
#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14);	vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region Second

		std::vector<float> vector1;
		vector1.push_back(1); vector1.push_back(2); vector1.push_back(3); vector1.push_back(4);
		vector1.push_back(5); vector1.push_back(6); vector1.push_back(7); vector1.push_back(8);
		vector1.push_back(9); vector1.push_back(10); vector1.push_back(4); vector1.push_back(12);
		vector1.push_back(13); vector1.push_back(14); vector1.push_back(15); vector1.push_back(16);
#pragma endregion

		Matrix4x4 m = Matrix4x4(vector);
		Matrix4x4 m1 = Matrix4x4(vector1);

		UnitTest::Assert(m != m1);

	}

	{

#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14); vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region Second

		std::vector<float> vector1;
		vector1.push_back(1);	vector1.push_back(2);	vector1.push_back(3);	vector1.push_back(4);
		vector1.push_back(5);	vector1.push_back(6);	vector1.push_back(7);	vector1.push_back(8);
		vector1.push_back(9);	vector1.push_back(10);	vector1.push_back(11);	vector1.push_back(12);
		vector1.push_back(13);	vector1.push_back(14);	vector1.push_back(15);	vector1.push_back(16);
#pragma endregion
#pragma region Mul

		std::vector<float> mulV;
		mulV.push_back(90); mulV.push_back(100); mulV.push_back(110); mulV.push_back(120); 
		mulV.push_back(202); mulV.push_back(228); mulV.push_back(254); mulV.push_back(280);
		mulV.push_back(314); mulV.push_back(356); mulV.push_back(398); mulV.push_back(440);
		mulV.push_back(426); mulV.push_back(484); mulV.push_back(542); mulV.push_back(600);
#pragma endregion

		Matrix4x4 m = Matrix4x4(vector);
		Matrix4x4 m1 = Matrix4x4(vector1);
		bool b = m == m1;
		UnitTest::Assert(b == true);
		Matrix4x4 mul = m * m1;
		Matrix4x4 mochMul = Matrix4x4(mulV);
		b = mul == mochMul;
		UnitTest::Assert(b == true);

		b = m == mul;
		UnitTest::Assert(b == false);
	}

	{

#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14);	vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region Second

		std::vector<float> vector1;
		vector1.push_back(1); vector1.push_back(2); vector1.push_back(3); vector1.push_back(4);
		vector1.push_back(5); vector1.push_back(6); vector1.push_back(7); vector1.push_back(8);
		vector1.push_back(9); vector1.push_back(10); vector1.push_back(11); vector1.push_back(12);
		vector1.push_back(13); vector1.push_back(14); vector1.push_back(15); vector1.push_back(16);
#pragma endregion
#pragma region Sum

		std::vector<float> sumV;
		sumV.push_back(2);
		sumV.push_back(4);
		sumV.push_back(6);
		sumV.push_back(8);
		sumV.push_back(10);
		sumV.push_back(12);
		sumV.push_back(14);
		sumV.push_back(16);
		sumV.push_back(18);
		sumV.push_back(20);
		sumV.push_back(22);
		sumV.push_back(24);
		sumV.push_back(26);
		sumV.push_back(28);
		sumV.push_back(30);
		sumV.push_back(32);
#pragma endregion

		Matrix4x4 m = Matrix4x4(vector);
		Matrix4x4 m1 = Matrix4x4(vector1);
		Matrix4x4 add = m + m1;
		Matrix4x4 mochSum = Matrix4x4(sumV);
		bool b = mochSum == add;
		UnitTest::Assert(b == true);

		Matrix4x4 sub = m - m1;
		b = sub == Matrix4x4();

		UnitTest::Assert(b == true);

		Matrix4x4 t = m.Transpose();

	}
	{
#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14); vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region T

		std::vector<float> t;
		t.push_back(1); t.push_back(5); t.push_back(9); t.push_back(13);
		t.push_back(2); t.push_back(6); t.push_back(10); t.push_back(14);
		t.push_back(3); t.push_back(7); t.push_back(11); t.push_back(15);
		t.push_back(4); t.push_back(8); t.push_back(12); t.push_back(16);

#pragma endregion
		Matrix4x4 m = Matrix4x4(vector);
		Matrix4x4 mochT = Matrix4x4(t);

		Matrix4x4 tM = m.Transpose();

		UnitTest::Assert(mochT == tM);




	}

	{
#pragma region First

		std::vector<float> vector;
		vector.push_back(1); vector.push_back(2); vector.push_back(3); vector.push_back(4);
		vector.push_back(5); vector.push_back(6); vector.push_back(7); vector.push_back(8);
		vector.push_back(9); vector.push_back(10); vector.push_back(11); vector.push_back(12);
		vector.push_back(13); vector.push_back(14);	vector.push_back(15); vector.push_back(16);

#pragma endregion

#pragma region Vector

		Vector3D vec = Vector3D(1, 2, 3);

#pragma endregion
		Matrix4x4 m = Matrix4x4(vector);
		Vector3D multi = m * vec;

		UnitTest::Assert(multi == Vector3D(14, 38, 62));
	}

	{
		Vector3D vec = Vector3D(1, 2, 3);

		Vector3D rotatedVector =
			vec.RotateRad(Vector3D(1, 2, 3));

	}

	{

		Quaternion q = Quaternion(2.0f, 4.0f, 5.0f, 7.0f);
		Quaternion equalQ = Quaternion(2.0f, 4.0f, 5.0f, 7.0f);

		UnitTest::Assert(q.Equal(equalQ, 0.001f));

	}

	{

		Quaternion q = Quaternion(2.0f, 4.0f, 5.0f, 7.0f);
		Quaternion equalQ = Quaternion(2.0f, 4.0f, 5.0f, 7.0f);

		UnitTest::Assert(q == equalQ);

	}


	{

		Quaternion q = Quaternion(2.0f, 4.0f, 5.0f, 7.0f);
		Quaternion notEqualQ0 = Quaternion(4.0f, 4.0f, 5.0f, 7.0f);
		Quaternion notEqualQ1 = Quaternion(2.0f, 44.0f, 5.0f, 7.0f);
		Quaternion notEqualQ2 = Quaternion(2.0f, 4.0f, 35.0f, 7.0f);
		Quaternion notEqualQ3 = Quaternion(2.0f, 4.0f, 5.0f, 27.0f);
		Quaternion notEqualQ4 = Quaternion(2.0f, 4.0f, 55.0f, 27.0f);
		Quaternion notEqualQ5 = Quaternion(2.0f, 64.0f, 5.0f, 27.0f);
		Quaternion notEqualQ6 = Quaternion(22.0f, 64.0f, 5.0f, 27.0f);

		UnitTest::Assert(q != notEqualQ0);
		UnitTest::Assert(q != notEqualQ1);
		UnitTest::Assert(q != notEqualQ2);
		UnitTest::Assert(q != notEqualQ3);
		UnitTest::Assert(q != notEqualQ4);
		UnitTest::Assert(q != notEqualQ5);
		UnitTest::Assert(q != notEqualQ6);

	}

	{
		Vector3D v = Vector3D(1, 2, 3);
		Quaternion q = Quaternion(v);
		Quaternion equalQ = Quaternion(0.7549338f, -0.2061492f, 0.5015091f, -0.3688714f);

		UnitTest::Assert(q.Equal(equalQ, 0.001f));

	}
	{
		Vector3D v = Vector3D(
			1.0f,
			2.0f,
			3.0f);

		float xDeg = 1;
		float yDeg = 2;
		float zDeg = 3;

		Vector3D rotated =
			v.RotateRad(Quaternion(Vector3D(
				xDeg * MathUtils::Deg2Rad,
				yDeg * MathUtils::Deg2Rad,
				zDeg * MathUtils::Deg2Rad)));

		UnitTest::Assert(
			rotated.Equal(
				Vector3D(0.9993439f, 1.996926f, 3.002266f), 0.001f));
	}

	{
		Vector3D v = Vector3D(
			2.0f,
			4.0f,
			6.0f);

		float xDeg = 1;
		float yDeg = 2;
		float zDeg = 3;

		Vector3D rotated =
			v.RotateRad(Quaternion(Vector3D(
				xDeg * MathUtils::Deg2Rad,
				yDeg * MathUtils::Deg2Rad,
				zDeg * MathUtils::Deg2Rad)));

		UnitTest::Assert(
			rotated.Equal(
				Vector3D(1.998688f, 3.993851f, 6.004531f), 0.01f));

	}



	{
		Vector3D v = Vector3D(1.0f, 2.0f, 3.0f);

		Vector3D rotated =
			v.RotateDeg(Vector3D(1, 2, 3));
		UnitTest::Assert(
			rotated.Equal(
				Vector3D(0.9993439f, 1.996926f, 3.002266f), 0.001f));

	}

	{
		Vector3D v = Vector3D(2.0f, 4.0f, 6.0f);

		Vector3D rotated =
			v.RotateDeg(Vector3D(1, 2, 3));
		UnitTest::Assert(
			rotated.Equal(
				Vector3D(1.998688f, 3.993851f, 6.004531f), 0.01f));

	}

#pragma endregion
	UnitTest::End();
	//std::cout << "Hello World!\n";
}


// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
