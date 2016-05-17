#include "utils.h"


void clearScreen(){
  // A IMPLEMENTAR
}


unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max){
	unsigned short int escolha;
	cin >> escolha;
	while (cin.fail()||(escolha < min || escolha > max))
	{
		cout << "Tente novamente: ";
		cin >> escolha;
	}
	return escolha;
}


int leInteiro(int min, int max){
	return 9; //!!!!
	// A IMPLEMENTAR

}


void checkFile(ifstream &stream, string nomeFicheiro)//verifica se um ficheiro foi lido com sucesso e caso contrario vai pedindo um nome de ficheiro valido
{
	stream.open(nomeFicheiro);
	while (!stream.is_open())
	{
		cout << "O ficheiro" << "\"" << nomeFicheiro << "\"" << " nao foi encontrado." << endl << endl;
		cout << "Insira novamente o nome do ficheiro: ";
		cin >> nomeFicheiro;
		stream.open(nomeFicheiro);
	}
	cout << "O ficheiro foi lido com sucesso! ";
}


void extractProducts(vector<string> vetor, string listaprodutos)
{
	while (listaprodutos != "")
	{
		unsigned int index = listaprodutos.find_first_of(',');
		string produto = listaprodutos.substr(0, index);
		vetor.push_back(produto);
		extractProducts(vetor, listaprodutos.substr(index + 2));
	}
}

void lowerCase(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
}

void trim(string &s)
{
	if ((int)s[0] == 32) //codigo ascii do espaço é 32
	{
		s.erase(0, 1);
		trim(s);
	}

	if ((int)s[s.size() - 1] == 32)
	{
		s.erase(s.size() - 1, 1);
		trim(s);
	}

	for (int i = 1; i<s.size(); i++)
	{
		if ((int)s[i] == 32 && s[i] == s[i + 1])
			s.erase(i, 1);
	}
}

int encontraPosicao(string s, char *c, unsigned int num)// retorna a posição do numº caracter *c na string s
{
	int contador = 0;
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] == *c)
			contador++;

		if (contador == num)
			return i;
	}
}

bool verifyDate(int day, int month, int year)
{//Verifies if a date is valid
	bool leapYear;

	if (year % 4 == 0 && year % 100 != 0)
		leapYear = true;
	else if (year % 4 == 0 && year % 400 == 0)
		leapYear = true;
	else leapYear = false;

	if (month <= 0 || month > 12)
	{
		return false;
	}

	int leapMonths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int notLeapMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (leapYear)
	{
		if (day <= 0 || day > leapMonths[month - 1])
		{
			return false;
		}
		else return true;
	}
	else if (day <= 0 || day > notLeapMonths[month - 1])
	{
		return false;
	}
	else return true;

}

bool verifyDatesOrder(int oldDay, int oldMonth, int oldYear, int recentDay, int recentMonth, int recentYear)
{//Verifies if two given dates are respectively the older and most recent date
	if (!(oldYear <= recentYear))
	{
		return false;
	}
	if (oldYear < recentYear)//if the old year is smaller than the recent one, than it's guaranteed to be a valid date
		return true;

	
	if (!(oldMonth <= recentMonth))
	{
		return false;
	}
	if (oldMonth < recentMonth)  //after comparing the years if the old month is smaller than the recent one, than it's guaranteed to be a valid date
		return true;

	if (!(oldDay <= recentDay))
	{
		return false;
	}
	if (oldDay < recentDay)////after comparing the months if the old day is smaller than the recent one, than it's guaranteed to be a valid date
		return true;
	else
	{
		
		return false;
	}

}
