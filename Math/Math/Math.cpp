// Math.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include "Header/Vector2D.h"
#include "Header/Vector3D.h"
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
		Vector2D v = Vector2D(5.0f, 5.214);
		Vector2D v2 = Vector2D(2.0f, 2.0f);
		Vector2D result = v / v2;
		UnitTest::Assert(result == Vector2D(2.5f, 2.607f));
	}
	{
		Vector2D v = Vector2D(5.0f, 5.214);
		Vector2D result = v + 2.0f;
		UnitTest::Assert(result == Vector2D(7.0f, 7.214));
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
		UnitTest::Assert(lerped.Equal(Vector2D(1.45, 4.0f), 0.001f));
	}

	{
		Vector2D v = Vector2D(0.7f, 3.6f);
		Vector2D v1 = Vector2D(3.8f, 2.0f);
		Vector2D lerped = v.Perpendicular();
		UnitTest::Assert(lerped.Equal(Vector2D(3.6f, -0.7f), 0.001f));
	}


	{
		Vector2D v = Vector2D(0.7f, 3.6f);
		//Vector2D normal = Vector2D(1.0f, 0.0f);
		Vector2D normal = Vector2D(0.9f, 0.1f);
		Vector2D reflect = v.ReflectVector(normal);
		//UnitTest::Assert(Vector2D::Equal(reflect, Vector2D(-0.7f, 3.6f), 0.001f));
		UnitTest::Assert(Vector2D::Equal(reflect, Vector2D(-1.08, 3.4f), 0.01f));
	}
	{
		Vector2D v = Vector2D(0.7f, 3.6f);
		Vector2D normal = Vector2D(1.0f, 0.0f);
		Vector2D reflect = Vector2D::ReflectVector(v, normal);
		UnitTest::Assert(Vector2D::Equal(reflect, Vector2D(-0.7f, 3.6f), 0.001f));
	}
	{
		Vector2D v = Vector2D(2.5, 1.0f);
		//Vector2D normal = Vector2D(1.0f, 0.0f);
		//Vector2D rotated = v.RotateDeg(-0.1f);
		Vector2D rotated = v.RotateDeg(30.0f);
		//UnitTest::Assert(Vector2D::Equal(rotated, Vector2D(-0.7679f, 5.3301f), 0.001f));
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
		//Vector2D normal = Vector2D(1.0f, 0.0f);
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
		Vector3D v = Vector3D(5.0f, 5.214, 5.0f);
		Vector3D v2 = Vector3D(2.0f, 2.0f, 2.0f);
		Vector3D result = v / v2;
		UnitTest::Assert(result == Vector3D(2.5f, 2.607f, 2.5f));
	}
	{
		Vector3D v = Vector3D(5.0f, 5.214, 4.0f);
		Vector3D result = v + 2.0f;
		UnitTest::Assert(result == Vector3D(7.0f, 7.214, 6.0f));
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
		UnitTest::Assert(lerped.Equal(Vector3D(1.45, 4.0f, 0.25f), 0.001f));
	}
	{
		Vector3D v = Vector3D(0.2f, 5.0f, 0.0f);
		Vector3D normal = Vector3D(0.1490128f, -0.309673f, 0.9390942f);
		Vector3D reflect = v.ReflectVector(normal);
		UnitTest::Assert(
			Vector3D::Equal(reflect, Vector3D(0.6525703, 4.059485f, 2.852146f), 0.1f));
	}
	{
		Vector3D v = Vector3D(0.2f, 5.0f, 0.0f);
		Vector3D normal = Vector3D(0.1490128f, -0.309673f, 0.9390942f);
		Vector3D reflect = Vector3D::ReflectVector(v, normal);
		UnitTest::Assert(
			Vector3D::Equal(reflect, Vector3D(0.6525703, 4.059485f, 2.852146f), 0.1f));
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
