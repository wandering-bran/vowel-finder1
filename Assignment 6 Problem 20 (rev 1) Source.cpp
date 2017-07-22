/*Brandon M Bartlett
COSC 1436--Assignment 6 Problem 20
Dr. Nina Javaher
4/19/2015*/
#include <iostream>
#include <string>

using namespace std;

void vowelReturn(string info, int& a, int& e, int& i, int& o, int& u);
int main()
{
	string info;
	bool exit=true;
	char b;
	int a = 0, e = 0, i = 0, o = 0, u = 0, z;
	
	
	while (exit == true)
	{
		cout << "greetings user! please enter a word or a sequence of letters: ";
		cin >> info;
		cout << "thank you! I will now tell you how many lowercase vowels"
			"\nare present in " << info << "." << endl;
		
		vowelReturn(info, a, e, i, o, u);
		z = a + e + i + o + u;                                 //totals all returning vowel values
		cout << z << " lowercase vowels are present."
			<< "\nSpecifically " << a << " a('s), " << e << " (e's), "             //outputs vowel values
			<< i << " i('s), " << o << " o('s), and " << u << " u('s)."    << endl;

		a = 0, e = 0, i = 0, o = 0, u = 0;                                     //resets all to 0 if user wishes to run program again
		cout << "press x to exit or any other letter to repeat program: ";
		cin >> b;
		if (b == 'x' || b == 'X')
			exit = false;
		cout << endl;
	}

	return 0;

}
void vowelReturn(string info, int& a, int& e, int& i, int& o, int& u)
{
	int l, x, y;

	x = info.length();                //gets total length of user entered string
	for (y = 0; y < x; y++)            //uses length for loop parameter
	{
		l = info.at(y);                //assigns each char to its ascii value
		if (l == 97)			      //lowercase vowels will total and return to main in this function
			a += 1;
		else if (l == 101)
			e += 1;
		else if (l == 105)
			i += 1;
		else if (l == 111)
			o += 1;
		else if (l == 117)
			u += 1;
	}
    					
}