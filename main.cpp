#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
	queue <char> wynik;
    queue <string> k;
	string kod="", x="";
	char y=0;
    int v=0, z=0, c=0;
    
    vector<vector<int> > alfabet;
    alfabet.resize(10);
    int a=0;
    alfabet[0].push_back(32);
    for (int i=2; i<10; i++){
    	if (i==7 || i==9){
    		for (int j=0; j<4; j++)
    			alfabet[i].push_back(j+65+a);
			a=a+4;
		}
		else{
    		for (int j=0; j<3; j++)
    			alfabet[i].push_back(j+65+a);
			a=a+3;
		}
	}

	cout << "0-spacja " << "2-abc " << "3-def " << endl << "4-ghi " << "5-jkl " << "6-mno "<< endl << "7-pqrs " << "8-tuv " << "9-wxyz " << endl;
	cout << "Wpisz kod z klawiatury oddzielone spacją, zakoncz wczytywanie '#' : " << endl;
	cout << "Jeśli chcesz wczytać tekst z pliku napisz @ i potwierdź enterem ";
	cin >> kod;	

	if(kod=="@")
	{
		ifstream plik("C:/cpp/szyfr.txt");
		while (!plik.eof()) {
			plik >> kod;
			if(kod!="#") {
				k.push(kod);
			}
		}
	}

	else 
	{
    	while (kod!="#") {
			k.push(kod);
			cin >> kod;	
    	}
	}

	while (!k.empty())
	{
		x = k.front();
		y = x[0];
		v = y-'0';
		wynik.push(alfabet[v][x.size()-1]);
		k.pop();
	}

	while (!wynik.empty())
	{
		cout << wynik.front();
		wynik.pop();
    }
    
	ofstream plik("C:/cpp/szyfr.txt");
	
    return 0;
}
