#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main(void)
{
	// Key input and variables
	string keyInput, hexString;
	int digit, remainder;

	// Prompt user they can test inputs
	cout << "Team Cantaloupe Conversion Program" << endl
	<< "i. Convert base 10 to binary" << endl
	<< "ii. Convert binary to base 10" << endl
	<< "iii. Convert base 16 to binary" << endl
	<< "iv. Convert binary to base 16" << endl
	<< "v. End program" << endl;

	do {
		cin >> keyInput;
		// Test if key input was base 10 to binary conversion
		if (keyInput == "i")
		{
			cout << "Enter a base 10 number to convert: ";
			cin >> digit;
			// Create vector to hold binary digits
			vector <int> binaryContainer;
			while (digit != 0)
			{
				remainder = digit % 2;
				binaryContainer.push_back(remainder);
				digit = digit / 2;
				if (digit == 1)
				{
					binaryContainer.push_back(1);
					digit = 0;
				}
			}
			cout << "Result: ";
			// Iterate through vector in reverse to display correct binary order
			for (int i = binaryContainer.size() - 1; i >= 0; i--)
			{
				cout << binaryContainer[i];
			}
			cout << "\n";
		}
		// Test if key input was binary to base 10 conversion
		if (keyInput == "ii")
		{
			cout << "Enter a binary number to convert: ";
			cin >> digit;
			// Create vector to hold binary digits
			vector <int> binaryContainer;
			while (digit != 0)
			{
				remainder = digit % 10;
				binaryContainer.push_back(remainder);
				digit = digit / 10;
				if (digit == 1)
				{
					binaryContainer.push_back(1);
					digit = 0;
				}
			}
			// Iterate through vector in reverse to ensure correct order of operations on result
			int sum = 0;
			for (int i = binaryContainer.size() - 1; i >= 0; i--)
			{
				sum += binaryContainer[i] * pow(2, i);
			}
			cout << "Result: " << sum << endl;
		}
		// Test if key input was base 16 to binary conversion
		if (keyInput == "iii")
		{
			cout << "Enter a base 16 number to convert: ";
			cin >> hexString;
			int length = hexString.size();

			vector <char> hexContainer(hexString.length());
			copy(hexString.begin(), hexString.end(), hexContainer.begin());

			for (int i = 0; i < hexContainer.size(); i++)
			{
				if (hexContainer[i] == '0')
					cout << "0000" << " ";
				else if (hexContainer[i] == '1')
					cout << "0001" << " ";
				else if (hexContainer[i] == '2')
					cout << "0010" << " ";
				else if (hexContainer[i] == '3')
					cout << "0011" << " ";
				else if (hexContainer[i] == '4')
					cout << "0100" << " ";
				else if (hexContainer[i] == '5')
					cout << "0101" << " ";
				else if (hexContainer[i] == '6')
					cout << "0110" << " ";
				else if (hexContainer[i] == '7')
					cout << "0111" << " ";
				else if (hexContainer[i] == '8')
					cout << "1000" << " ";
				else if (hexContainer[i] == '9')
					cout << "1001" << " ";
				else if (hexContainer[i] == 'A')
					cout << "1010" << " ";
				else if (hexContainer[i] == 'B')
					cout << "1011" << " ";
				else if (hexContainer[i] == 'C')
					cout << "1100" << " ";
				else if (hexContainer[i] == 'D')
					cout << "1101" << " ";
				else if (hexContainer[i] == 'E')
					cout << "1110" << " ";
				else if (hexContainer[i] == 'F')
					cout << "1111" << " ";
			}
			cout << "\n";
		}
		// Test if key input was binary to base 16 conversion
		if (keyInput == "iv")
		{
			cout << "Enter a base 16 number to convert: ";
			cin >> hexString;
			int length = hexString.size();

			std::string s = "scott>=tiger>=mushroom";
			std::string delimiter = ">=";

			int pos = 0;
			string token;
			vector <char> hexContainer;
			while ((pos = hexString.find(delimiter)) != std::string::npos) {
				token = hexString.substr(0, pos);
				cout << token << endl;
				hexContainer.push_back(token);
				hexString.erase(0, pos + delimiter.length());
			}
			std::cout << s << std::endl;

			for (int i = 0; i < hexContainer.size(); i++)
			{
				if (hexContainer[i] == "0000")
					cout << "0" << " ";
				else if (hexContainer[i] == "0001")
					cout << "1" << " ";
				else if (hexContainer[i] == "0010")
					cout << "2" << " ";
				/*
				else if (hexContainer[i] == '0011')
					cout << "3" << " ";
				else if (hexContainer[i] == '0100')
					cout << "4" << " ";
				else if (hexContainer[i] == '0101')
					cout << "5" << " ";
				else if (hexContainer[i] == '0110')
					cout << "6" << " "; 
				else if (hexContainer[i] == '0111')
					cout << "7" << " ";
				else if (hexContainer[i] == '1000')
					cout << "8" << " ";
				else if (hexContainer[i] == '1001')
					cout << "9" << " ";
				else if (hexContainer[i] == '1010')
					cout << "A" << " ";
				else if (hexContainer[i] == '1011')
					cout << "B" << " ";
				else if (hexContainer[i] == '1100')
					cout << "C" << " ";
				else if (hexContainer[i] == '1101')
					cout << "D" << " ";
				else if (hexContainer[i] == '1110')
					cout << "E" << " ";
				else if (hexContainer[i] == '1111')
					cout << "F" << " ";
					*/
			}
			cout << "\n";
		}

		cout << "\n"
		<< "Team Cantaloupe Conversion Program" << endl
		<< "i. Convert base 10 to binary" << endl
		<< "ii. Convert binary to base 10" << endl
		<< "iii. Convert base 16 to binary" << endl
		<< "iv. Convert binary to base 16" << endl;

		// Test whether key input was to end program
	} while (keyInput != "v");
	cout << "Program Quit. Goodbye!";
}