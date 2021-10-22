 /*
	Cantaloupe Conversions!

	Munk Batjargal
	Connor Holland
	Eli Madi
	Nicholas Wood

	Applied Discrete Structures, Fall 2021, Dr. J

	2021 October 11

	Menu-driven program to convert numbers from base ten to binary, binary to base ten,
	hexadecimal to binary, and binary to hexadecimal.
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

//Prototypes:
void prompt();
void menu();
void tenToBinary();
void binaryToTen();
void hexToBinary();
void binaryToHex();

//Functions:
//main
int main() {
	menu();
	return 0;
}

//prompt user for input
void prompt() {

	cout
		<< endl << "Please select an option:" << endl
		<< "1. Convert base ten to binary" << endl
		<< "2. Convert binary to base ten" << endl
		<< "3. Convert hexadecimal to binary" << endl
		<< "4. Convert binary to hexadecimal" << endl
		<< "5. End program" << endl << endl;

	return;
}

//menu logic
void menu() {

	int input = 0;

	cout << " ~ Cantaloupe Conversions! ~ " << endl;
	prompt();
	cin >> input;

	while (input != 5) {
		switch (input) {
		case 1:
			tenToBinary();
			break;
		case 2:
			binaryToTen();
			break;
		case 3:
			hexToBinary();
			break;
		case 4:
			binaryToHex();
			break;
		default:
			cout << "Invalid input; please enter an integer between 1 and 5." << endl;
		}
		prompt();
		cin >> input;
	}

	cout << endl << "Thank you for using our program!" << endl << "Exiting now..." << endl;
	return;
}

//convert base ten to binary
void tenToBinary() {

	//prompt user for input
	int num = 0, tally = 0;
	vector<char> bin;

	cout << endl << "You chose: Base Ten -> Binary" << endl << "Please enter a positive base ten integer: ";
	cin >> num;
	cout << endl << "You entered: " << num << endl << "Result: ";

	while (num != 0) {
		if (num % 2 == 0){
			bin.push_back('0');
		}
		else{
			bin.push_back('1');
		}
		num = num / 2;
	}
	
	tally = bin.size();
	while (tally != 0) {
		cout << bin[tally - 1];
		tally--;
	}
	cout << endl;
}

//convert binary to base ten
void binaryToTen() {

	//prompt user for input
	string num = "0";

	cout << endl << "You chose: Binary -> Base Ten" << endl << "Please enter a positive binary integer: ";
	cin >> num;
	cout << endl << "You entered: " << num << endl << "Result: ";

	//set up vectors and variables
	vector<char> bin(num.begin(), num.end()); //!
	vector<int> tenResult;
	unsigned tally = bin.size();
	int power = 0;

	//use weighted multiplication to solve for each place
	char val = 'e';
	int ten = 0;
	while (tally) {
		tally--;

		val = bin[tally];
		if (val == '0') {
			ten = 0;
		}
		if (val == '1') {
			ten = pow(2, power);
		}

		power++;
		tenResult.push_back(ten);
	}

	//sum the results
	int sum = 0;
	tally = tenResult.size();
	while (tally) {
		tally--;
		sum = sum + tenResult[tally];
	}

	//return final sum to user
	cout << sum << endl;
	return;
}

//convert hexadecimal to binary
void hexToBinary() {

	//prompt user for input
	string hexString = "empty";

	cout << endl << "You chose: Hexadecimal -> Binary" << endl << "Please enter a positive hexadecimal integer: ";
	cin >> hexString;
	cout << endl << "You entered: " << hexString << endl << "Result: ";

	//break string into character vector
	int length = hexString.size();
	vector <char> hexContainer(hexString.length());
	copy(hexString.begin(), hexString.end(), hexContainer.begin());

	//use lookup table to find hexadecimal equivalent
	for (int i = 0; i < hexContainer.size(); i++)
	{
		if (hexContainer[i] == '0')
			cout << "0000";
		else if (hexContainer[i] == '1')
			cout << "0001";
		else if (hexContainer[i] == '2')
			cout << "0010";
		else if (hexContainer[i] == '3')
			cout << "0011";
		else if (hexContainer[i] == '4')
			cout << "0100";
		else if (hexContainer[i] == '5')
			cout << "0101";
		else if (hexContainer[i] == '6')
			cout << "0110";
		else if (hexContainer[i] == '7')
			cout << "0111";
		else if (hexContainer[i] == '8')
			cout << "1000";
		else if (hexContainer[i] == '9')
			cout << "1001";
		else if (hexContainer[i] == 'A')
			cout << "1010";
		else if (hexContainer[i] == 'B')
			cout << "1011";
		else if (hexContainer[i] == 'C')
			cout << "1100";
		else if (hexContainer[i] == 'D')
			cout << "1101";
		else if (hexContainer[i] == 'E')
			cout << "1110";
		else if (hexContainer[i] == 'F')
			cout << "1111";
		else {
			cout << "Invalid input; next time, please enter a positive hexadecimal integer." << endl;
			return;
		}
			
	}

	//return result to user
	cout << endl;
	return;
}

//convert binary to hexadecimal
void binaryToHex() {

	//initialize array
	const int MaxLength = 81;
	const int MaxHexLength = (MaxLength / 4) + 1;
	char inputArr[MaxLength];
	for (int i = 0; i < MaxLength; i++){
		inputArr[i] = ' ';
	}
	char outputArr[MaxHexLength];
	for (int i = 0; i < MaxHexLength; i++){
		inputArr[i] = ' ';
	}

	//prompt user for input
	cout << endl << "You chose: Binary -> Hexadecimal" << endl << "Please enter a positive binary integer: ";
	cin >> inputArr;
	cout << endl << "You entered: " << inputArr << endl << "Result: ";

	//determine length of input & whether it is divisible by four
	int strLength = strlen(inputArr);
	int fourDigs = 4 - (strLength % 4);

	//set up string/number so that its number of digits are a multiple of four
	if (fourDigs != 4){
		if (fourDigs >= 1){
			for (int i = MaxLength - 1; i > 0; i--){
				inputArr[i] = inputArr[i - 1];
			}
			inputArr[0] = '0';
		}
		if (fourDigs >= 2){
			for (int i = MaxLength - 1; i > 0; i--){
				inputArr[i] = inputArr[i - 1];
			}
			inputArr[0] = '0';
		}
		if (fourDigs == 3){
			for (int i = MaxLength - 1; i > 0; i--){
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

	for (int i = 0; i < hexDigs; i++){
		sumTemp = 0;
		for (int t = 0; t < 4; t++){
			int tempDigit = 0;
			int digitPlcmnt = 3 - t; //this tells us what power of two this digit represents
			if (i == 0){
				tempDigit = t;
			}
			else{
				tempDigit = (t + (4 * i)); //this tells us which character in the inputArr we need to read
			}

			temp = inputArr[tempDigit];

			if (temp == '1'){
				sumTemp += pow(2, digitPlcmnt); //this gives us each hex digit's value in base 10
			}
			temp = 0;
		}

		//convert number char to int, replace number char >nine with letter A-F
		if (sumTemp < 10){
			sumTemp += '0';
			outputArr[i] = sumTemp;
		}
		else
		{
			switch (sumTemp){
			case 10:
				outputArr[i] = 'A';
				break;
			case 11:
				outputArr[i] = 'B';
				break;
			case 12:
				outputArr[i] = 'C';
				break;
			case 13:
				outputArr[i] = 'D';
				break;
			case 14:
				outputArr[i] = 'E';
				break;
			case 15:
				outputArr[i] = 'F';
				break;
			}
		}
	}

	//mark end of output string
	outputArr[hexDigs] = '\0';

	//return result to user
	cout << outputArr << endl;
	return;
}
