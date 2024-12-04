/*
	Delvis Kouete
	Computer Science Fall 2024
	Due: Dec. 3, 2024
	Lab 6, Lab 6 Binary to Decimal Conversion
	Write a C++ program that reads characters representing binary (base 2)
	numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
	numbers. 
	*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int binaryToDecimal(const string& binaryNumber)
{
	int decimalNumber = 0;
	int power = 0;

	for (int i = binaryNumber.length() - 1; i >= 0; --i)
	{
		if (binaryNumber[i] == '1')
		{
			decimalNumber += pow(2, power);
		}

		power++;
	}
	return decimalNumber;
}

int main()
{
	ifstream inputFile("BinaryIn.dat");

	if (!inputFile)
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	string binaryNumber;

	cout << "Binary Number/tDecimal Equivalent" << endl;
	cout << "-------------------------------------" << endl;

	while (inputFile >> binaryNumber)
	{
		bool isValid = true;
		for (char ch : binaryNumber)
		{
			if (ch != '0' && ch != '1')
			{
				isValid = false;
				break;
			}
		}

		if (isValid)
		{
			int decimalNumber = binaryToDecimal(binaryNumber);
			cout << binaryNumber << "\t" << decimalNumber << endl;
		}
		else
		{
			cerr << "Invalid Binary number: " << binaryNumber << endl;
		}
	}
	inputFile.close();
	return 0;

}