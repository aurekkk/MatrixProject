#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.hpp"


int main()
{
	std::ifstream reader("date.txt");
	if (!reader)
	{
		std::cout << "Citirea din fisier a esuat";
		return - 1;
	}
	int randuri, coloane;
	reader >> randuri >> coloane;
	Matrix obiect(randuri, coloane);
	reader >> obiect;
	Matrix obiect2(randuri, coloane);
	reader >> obiect2;
	//std::cin >> obiect;
	//std::cin >> obiect2;
	Matrix obiect3(6, 6);
	std::cout << randuri<< " " << coloane<<std::endl;
	std::cout << obiect2 << std::endl;
	std::cout << obiect << std::endl;;
	//std::cout << -obiect;
	try
	{
		obiect3 = obiect + obiect2;
	}
	catch (const std::runtime_error& a)
	{
		std::cout << "Error divide:" << a.what();
	}
	obiect = obiect ^ 3;
	std::cout <<"obiectul3="<<std::endl<< obiect3;
	std::cout << std::endl;
	std::cout << "obiect1 ridicat la putere" <<std::endl<< obiect;
	std::cout<<std::endl;

	reader.close();

}