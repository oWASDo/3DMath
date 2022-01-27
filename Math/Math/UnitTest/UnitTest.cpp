#include "UnitTest.h"
# define M_PI           3.14159265358979323846
UnitTest::UnitTest()
{
	assertNumber = 1;
	assertNumberWrong = 0;
}

UnitTest::~UnitTest()
{
}
int UnitTest::assertNumber;
int UnitTest::assertNumberWrong = 0;

void UnitTest::Assert(bool assetOk)
{
	if (assetOk)
	{
		std::cout << assertNumber << " " << "Assetion Ok" << std::endl;
	}
	else
	{
		std::cout << assertNumber << " " << "Assetion NOT Ok" << std::endl;
		assertNumberWrong++;
	}
	assertNumber++;
}
void UnitTest::Assert(bool assetOk, std::string assertName)
{
	if (assetOk)
	{
		std::cout << assertNumber << " " << assertName << ": " << "Assetion Ok" << std::endl;
	}
	else
	{
		std::cout << assertNumber << " " << assertName << ": " << "Assetion NOT Ok" << std::endl;
		assertNumberWrong++;
	}
	assertNumber++;

}

void UnitTest::End()
{
	if (assertNumberWrong > 0)
	{
		std::cout << "There are:" << assertNumberWrong << " wrong tests"<< std::endl;
	}
	else
	{
		std::cout << "All tests gone ok" << std::endl;
	}
}
