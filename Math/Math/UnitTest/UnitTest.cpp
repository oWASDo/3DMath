#include "UnitTest.h"

UnitTest::UnitTest()
{
	assertNumber = 1;
}

UnitTest::~UnitTest()
{
}
int UnitTest::assertNumber;

void UnitTest::Assert(bool assetOk)
{
	if (assetOk)
	{
		std::cout << assertNumber << " " << "Assetion Ok" << std::endl;
	}
	else
	{
		std::cout << assertNumber << " " << "Assetion NOT Ok" << std::endl;
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
	}
	assertNumber++;

}
