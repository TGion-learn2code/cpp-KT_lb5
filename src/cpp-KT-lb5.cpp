//============================================================================
// Name        : cpp-KT_lb5.cpp
// Author      : Tobias Gion
// Version     :
// Copyright   : Your copyright notice
// Description : Karriere Tutor Übungsblatt LB5 - Literale, ASCII,
// 				 Indirektion, Zeiger
//============================================================================

#include <iostream>
#include <iomanip>		// Needed for formating cout output
#include <typeinfo>
#include <string>

using namespace std;

void type_print (string var_name, auto *var) {

	cout	<< setw(18)						// Set width of column to 20
		<< var_name					// Print var_name (string)
		<< setw(17)
		<< "typeid.name: "
		<< setw (2)
		<< typeid(*var).name()			// Pointer to auto *var, print typeid.name (e.g. i for integer)
		 	 	 	 	 	 	 	 	 	// WARNING: Does not have to work at all. The output is implementation-defined
		 	 	 	 	 	 	 	 	 	// and does not have to output anything at all. Here it works, of some sort
			<< setw(12)
			<< "sizeof: "
			<< setw(2)
			<< sizeof(*var)
			<< setw(10)
			<< "value: "
			<< setw(8)						// static_cast<char>() to explicit print Char
			<< *var
			<< fixed						// Show digits for float and double according to cout.precision
			<< endl;

	return;
}


void char_print (string num_type, char var) {

	cout << setw(20)
		 << num_type
		 << setw(10)
		 << " als Zeichen == "
		 << "'" << var << "'"
		 << endl;

	return;
}

int main() {

	cout << "//==============================================================================" << endl;
	cout << "// Aufgabe 1" << endl;
	cout << "//==============================================================================" << endl;

	// Set precision of cout for float and double
	cout.precision(1);

	// 1.1
	auto sign_int {-2};
	type_print("signed int", &sign_int);

	// 1.2
	auto unsign_int {2U};
	type_print("unsigned int", &unsign_int);

	// 1.3
	auto sign_long {-2L};
	type_print("signed long", &sign_long);

	// 1.4
	auto unsign_long {2UL};
	type_print("unsigned long", &unsign_long);

	// 1.5
	auto sign_long_long {-2LL};
	type_print("signed long long", &sign_long_long);

	// 1.6
	auto unsign_long_long {2ULL};
	type_print("unsigned long long", &unsign_long_long);

	// 1.7
	auto flt {-2.0F};
	type_print("float", &flt);

	// 1.8
	auto dbl {-2.0};
	type_print("double", &dbl);

	// 1.9
	auto long_dbl {-2.0L};
	type_print("long double", &long_dbl);

	// 1.10
	auto chr {'C'};
	type_print("char", &chr);

	// 1.11
	auto wchr_t {L'C'};
	type_print("wchar_t", &wchr_t);

	// 1.12
	auto chr16_t {u'C'};
	type_print("char16_t", &chr16_t);

	// 1.13
	auto chr32_t {U'C'};
	type_print("char32_t", &chr32_t);


	cout << endl;
	cout << "//==============================================================================" << endl;
	cout << "// Aufgabe 2" << endl;
	cout << "//==============================================================================" << endl;

	char 	chrC;
	string 	strC;

	// 2.1
	strC = "75"; 				// 'K' = 75 dec
	chrC = stoi(strC, 0, 10); 	// Initialize chrC with value 75 decimal == 'K'
	char_print("Dezimalwert " + strC, chrC);


	// 2.2
	strC = "01110100"; 			// 't' == 116 decimal / 01110100 binary
	chrC =  stoi(strC, 0, 2); 	// Initialize chrC with value 01110100 binary == 't'
	char_print("Binärwert 0b" + strC, chrC);

	// 2.3
	strC = "32";				// '2' == 50 decimal / 32 hexadecimal
	chrC = stoi(strC, 0, 16); 	// Initialize chrC with value 32 hexadecimal == '2'
	char_print("Hexadezimalwert 0x" + strC, chrC);

	// 2.4
	strC = "53";				// '+' == 43 decimal / 53 octadecimal
	chrC = stoi(strC, 0, 8); 	// Initialize chrC with value 53 octadecimal == '+'
	char_print("Oktadezimalwert 0" + strC, chrC);

	// 2.5
	strC = "'1' << 1 == ('1' * 2)";
	chrC = '1' << 1;					// Initialize char chrC with value of '1' * 2 without using '* 2'
										// shift left 1 for multiplication * 2
	char_print("\nErgebnis von " + strC, chrC);

	// Check if we did the right calculation
	int  ii = '1';
	char cc;

	cout << "-->> Überprüfung: "
		 << "'1' == "
		 << ii
		 << " << 1 ( == * 2) == "
		 << (ii << 1)
		 << " == "
		 << "'"
		 << (cc = (ii<<1))
		 << "'"
		 << endl;


	// 2.6
	cout << endl
		 << "'1' + '2' == "
		 << +'1'
		 << " + "
		 << +'2'
		 << " == "
		 << ('1' + '2')			// cout '1' + '2' as integer
		 << endl;


	cout << endl;
	cout << "//==============================================================================" << endl;
	cout << "// Aufgabe 3" << endl;
	cout << "//==============================================================================" << endl;

	// 3.1
	char 	cArr[] = "Guten Morgen";

	// 3.2
	int 	posArr = 6;					// Set some index for char array cArr

	cout << "Position von cArr["		// cout position (index) and char of array at that position
		 << posArr
		 << "] == "
		 << cArr[posArr]
		 << endl;


	cout << endl;
	cout << "//==============================================================================" << endl;
	cout << "// Aufgabe 4" << endl;
	cout << "//==============================================================================" << endl;

	// 4.1
	double	d_double = 3.0;

	// 4.2
	double *d_zeiger = &d_double;		// Set pointer *d_zeiger to address of d_double

	cout << "d_zeiger: "				// cout *d_zeiger (value) and d_double
		 << *d_zeiger
		 << "\t d_double: "
		 << d_double
		 << endl;

	// 4.3
	*d_zeiger = 0.0;					// Change d_double through pointer *d_zeiger

	// 4.4
	cout << "d_zeiger: "				// cout *d_zeiger (value) and d_double
		 << *d_zeiger
		 << "\t d_double: "
		 << d_double
		 << endl;

	return 0;
}
