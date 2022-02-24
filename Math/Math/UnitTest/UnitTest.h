#pragma once
#include <iostream>
#include <string>


class UnitTest
{
public:
	UnitTest();
	~UnitTest();

	static void Assert(bool assetOk);
	static void Assert(bool assetOk, std::string assertName);
	static void End();

	static int assertNumber;
	static int assertNumberWrong;



	/*void Assert(bool assetOk) {
		if (assetOk)
		{
			std::cout << "Assetion Ok" << std::endl;
		}
		else
		{
			std::cout << "Assetion NOT Ok" << std::endl;
		}
	}*/
private:

};

