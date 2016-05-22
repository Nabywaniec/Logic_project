#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

void ClrScr()
{
	printf("\033[2J"); // Czyści ekran
	printf("\033[0;0f"); // Ustawia kursor w lewym, górnym rogu
}

char result(const string & file, char a, char b)
{
	string line;
	fstream plik;
	char c;
	plik.open(file.c_str());
    while(getline(plik, line)!=NULL)
    {
		if(line[0]==a and line[2]==b)
		{
			c = line[4];
			return c;
		}
	}
	return ' ';
}
char resultNOT(const string & file, char a)
{
	string line;
	fstream plik;
	char wynik;
	plik.open(file.c_str());
    while(getline(plik, line)!=NULL)
    {
		if(line[0]==a)
		{
			wynik = line[2];
			return wynik;
		}
	}
	return ' ';
}

int main(int argc, char **argv)
{
	string OR, NOT, AND, IMPL;
	string arguments[argc+1];
	int wynik = 2;
	char answer;
	char x;

	if(argc!=9)
	{
		cout << "Zła ilosc argumentow. Poprawna ilosc to 8" << endl;
		return 0;
	}

	for(int i=1;i<argc;i++)
	{
		arguments[i]=argv[i];
	}

	for(int i=1; i<argc;i+=2)
	{
		if(arguments[i]=="--not") NOT = arguments[i+1];
		if(arguments[i]=="--or") OR = arguments[i+1];
		if(arguments[i]=="--and") AND = arguments[i+1];
		if(arguments[i]=="--impl") IMPL = arguments[i+1];
	}

	//przywitanie gracza
	cout << "Witaj w grze logicznej" << endl;

	cout << "Przed Tobą 5 zagadek logicznych" << endl;
	cout << "Pytania zamknięte ztrzema wariantami odpowiedzi" << endl;
	cout << "Jesli odpowiesz dobrze dostajesz 1 pkt" << endl;
	cout << "Jezeli zle to dostajesz -1 pkt" << endl;
	cout << "Na początek dostajesz 2 pkt, a Twoim zadaniem jest osiagnac jak najlepszy rezultat" << endl;



	cout << "Czy jesteś gotowy (T/N)" << endl;
	cin >> x;
	while(x!='T' and x!='N' and x!='t' and x!='n')
	{
		cout << "Sprobuj jeszcze raz.Nacisnij (T/N)" << endl;
		cin >> x;
	}

	if(x=='n' or x=='N')
	{
		cout << "Wróć jak bedziesz gotów do gry" << endl;
		return 0;
	}

	ClrScr();

	cout << "Rozpoczynamy gre :) Twoj wynik to: " << wynik << endl;

	//zagadka nr 1

	cout << "Zagadka nr I" << endl;
	cout << "Jacek bardzo chce sie nauczyc na kolokwium" << endl;
	cout << "Jednak wie, ze moze zda go wtedy gdy Mateusz mu pomoze " << endl;
	cout << "Mateusz nie wie czy jest w stanie pomoc Jackowi  " << endl;
	cout << "Czy jezeli Mateusz bedzie wiedzial czy jest w stanie pomoc Jackowi to Jacek zda" << endl;
	cout << "1) tak" << endl;
	cout << "0) nie" << endl;
	cout << "X) nie wiadomo" << endl;
	cin >> answer;
	char Jacek = '1';
	char Mateusz = 'X';

	if(answer==result(OR, result(IMPL, Jacek, Mateusz), result(IMPL, Mateusz, Jacek))) wynik +=1;
	else wynik--;

	ClrScr();

	cout << "Twoj aktualny wynik to: " << wynik << endl;

	//zagadka nr 2
	cout << "Zagadka nr II" << endl;
	cout << "Fernando Alonso jest dwukrotnym mistrzem swiata" << endl;
	cout << "Jego kolega Jenson Button zdobyl ten tytul jeden raz" << endl;
	cout << "W sumie maja na przeszlo trzy razy mniej tytulow niz" << endl;
	cout << "Schumacher i Vettel.Schumacher ma wiecej niz 5 tytulow" << endl;
	cout << "Czy mozemy powiedziec, ze Vettel ma dwa razy wiecej" << endl;
	cout << "tytulow niz Fernando Alonso" << endl;
	cout << "1) tak" << endl;
	cout << "0) nie" << endl;
	cout << "X) nie wiadomo" << endl;
	cin >> answer;
	char Alonso = '1';
	char Button = 'X';
	char Schumacher = 'X';
	char Vettel = '0';

	if(answer==result(AND, result(OR, Alonso, Button), result(OR, Schumacher, Vettel))) wynik +=1;
	else wynik--;

	ClrScr();
	//zagadka nr 3
	cout << "Twoj aktualny wynik to: " << wynik << endl;
	cout << "Zagadka nr III" << endl;
	cout << "Dzis wiele ludi nie chce walczyc o naprawde wielkie rzeczy" << endl;
	cout << "Czy z tego wynika że kiedys ludzie byli bardziej waleczni?" << endl;
	cout << "1) tak" << endl;
	cout << "0) nie" << endl;
	cout << "X) nie wiadomo" << endl;
	cin >> answer;
	char rzeczy = '1';
	char kiedys = '1';


	if(answer==result(IMPL, result(IMPL, rzeczy, kiedys), result(IMPL, resultNOT(NOT, rzeczy), resultNOT(NOT, kiedys)))) wynik +=1;
	else wynik--;

	ClrScr();
	//zagadka nr 4
	cout << "Twoj aktualny wynik to: " << wynik << endl;
	cout << "Zagadka nr IV" << endl;
	cout << "Krzysiek ma kilka jablek" << endl;
	cout << "Gdyby mial 2 razy wiecej to mialby wiecej niz 8 a gdyby mial 2 razy mniej to mialby wiecej niz 2" << endl;
	cout << "Czy z tego wynika, ze Krzysiek ma 5 jablka?" << endl;
	cout << "1) tak" << endl;
	cout << "0) nie" << endl;
	cout << "X) nie wiadomo" << endl;
	cin >> answer;
	char Krzysiek = '0';

	char jablka = 'X';

	if(answer==result(AND, Krzysiek, jablka)) wynik +=1;
	else wynik--;

	ClrScr();
	//zagadka nr 5
	cout << "Twoj aktualny wynik to: " << wynik << endl;
	cout << "Zagadka nr V" << endl;
	cout << "Michal jest wspanialym zeglarzem ale nie lubi nurkowac" << endl;
	cout << "Piotrek nie jest zeglarzem i moze lubi nurkowac" << endl;
	cout << "Pawel lubi jedna z tych rzeczy co Piotrek" << endl;
	cout << "Czy mozna powiedziec ze wszyscy maja jakas jedna wspolna rzecz?" << endl;
	cout << "1) tak" << endl;
	cout << "0) nie" << endl;
	cout << "X) nie wiadomo" << endl;
	cin >> answer;
	char Michal = '1';
	char Piotrek = 'X';
	char Pawel = '0';

	if(answer==result(OR, result(OR, Pawel, Piotrek), resultNOT(NOT, result(AND, Pawel, Michal)))) wynik +=1;
	else wynik--;


	ClrScr();
	cout << "Quiz zakończony!" << endl;
	cout << "Twoj wynik to: " << wynik << endl;
	return 0;
}
