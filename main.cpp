#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

string capsloc(string a)
{
	int i=0;
	for(i=0; i<a.size(); i++){
		a[i]=toupper(a[i]);
	}
	return a;
}

string zamiana3(char a)
{
	int i=0, grupa=0, numer=0;
	string wynik="";
	
	grupa=(a-'A')/3+2;
	numer=(a-'A')%3+1;
	for(i=0; i<numer; i++){
		wynik+=to_string(grupa);
	}

	return 	wynik;
}

string szyfr(string a)
{
	int i=0;
	char litera=0;
	string wynik="";

	for(i=0; i<a.size(); i++)
	{
		litera=a[i];

		if(litera=='S')
			wynik+="7777";

		else if(litera=='Z')
			wynik+="9999";
		
		else
			wynik+=zamiana3(litera);
		wynik+=" ";
	}
	wynik+="#";

	return wynik;
}

int main(int argc, char** argv) {
	ofstream plik("C:/cpp/szyfr.txt");

	int i=0;
	string input="";

	cout<<"Wpisz tekst oddzielony spacjami: ";
	cin>>input;

	input=capsloc(input);
	plik<<szyfr(input)<<endl;
	plik.close();

	return 0;
}
