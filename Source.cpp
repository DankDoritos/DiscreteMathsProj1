#include <cstring>
#include <iostream>
#include <cstdio>


using namespace std;


int main()
{
	//declare max size of input and output.
	const int MaxLength = 81;
	//Hex string will be exactly 1/4th the size of the binary string.
	const int MaxHexLength = (MaxLength / 4) + 1;

	//initialize the input and output char array with all spaces
	char inputArr[MaxLength];
	for (int i = 0; i < MaxLength; i++)
	{
		inputArr[i] = ' ';
	}
	char outputArr[MaxHexLength];
	for (int i = 0; i < MaxHexLength; i++)
	{
		inputArr[i] = ' ';
	}
	
	cout << "Please enter a binary integer to convert to base 16: " << endl;
	cout << "(Please do not use spaces in your input.)" << endl;

	//Grab the entire line and pray to god the user inputs a
	//binary number with less than 80 digits
	cin.getline(inputArr, MaxLength);

	//determine length of input
	int strLength = strlen(inputArr);
	//determine if the amount of digits is divisible by 4
	int fourDigs = 4 - (strLength % 4);

	//Make sure input is actually in binary
	for (int i = 0; i < strLength; i++)
	{
		if (inputArr[i] != '0' && inputArr[i] != '1')
		{
			cout << "It seems the number you've entered is not a binary number.\n\n";
			cout << "Better luck next time!";
			return 0;
		}
	}

	

	//set up string/number so that it's number of digits are a multiple of 4
	if (fourDigs != 4)
	{
		if (fourDigs >= 1)
		{
			for (int i = MaxLength - 1; i > 0; i--)
			{
				inputArr[i] = inputArr[i - 1];
			}
			inputArr[0] = '0';
		}
		if (fourDigs >= 2)
		{
			for (int i = MaxLength - 1; i > 0; i--)
			{
				inputArr[i] = inputArr[i - 1];
			}
			inputArr[0] = '0';
		}
		if (fourDigs == 3)
		{
			for (int i = MaxLength - 1; i > 0; i--)
			{
				inputArr[i] = inputArr[i - 1];
			}
			inputArr[0] = '0';
		}
	}

	//start converting given number into Hex
	strLength = strlen(inputArr);
	int hexDigs = strLength / 4;
	char temp = '0';
	int sumTemp = 0;
	

	for (int i = 0; i < hexDigs; i++)
	{
		sumTemp = 0;
		for (int t = 0; t < 4; t++)
		{
			int tempDigit = 0;
			int digitPlcmnt = 3 - t; //This tells us what power of two this digit represents
			if (i == 0)
			{
				tempDigit = t;
			}
			else
			{
				tempDigit = (t + (4*i)); //this tells us which character in the inputArr we need to read
			}

			temp = inputArr[tempDigit];

			if (temp == '1') 
			{
				//This gives us each hex digit's value in base 10
				sumTemp += pow(2, digitPlcmnt);
			}



			temp = 0;
		}
		//convert number char to int
		if (sumTemp < 10)
		{
			sumTemp += '0';
			outputArr[i] = sumTemp;
		}
		else //Replace number char >9 with letter A-F
		{
			switch (sumTemp)
			{
			case 10:
			{
				outputArr[i] = 'A';
				break;
			}
			case 11:
			{
				outputArr[i] = 'B';
				break;
			}
			case 12:
			{
				outputArr[i] = 'C';
				break;
			}
			case 13:
			{
				outputArr[i] = 'D';
				break;
			}
			case 14: 
			{
				outputArr[i] = 'E';
				break;
			}
			case 15:
			{
				outputArr[i] = 'F';
				break;
			}
			}

		}
		//switch
		//outputArr[i] = ?
	}
	//Mark end of output string
	outputArr[hexDigs] = '\0';

	cout << "Your binary number (" << inputArr << ")" << endl;
	cout << "Hexidecimal value: " << outputArr << "\n\n\n";

	cin.getline(inputArr, MaxLength);
	//comment out the above line.
	//Ijust put it there so I could read the 
	//output without setting up a loot that
	//takes y/n command to keep going.
	
	return 0;
}