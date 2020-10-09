#include <iostream>
#include <conio.h>
#include <string.h>
struct name
{
	char name[20];
	char surname[20];
	char patronymic[20];
};
struct adress {
	char street[20];
	int house_number;
	int flat_number;
};
class Patient {
	name nam;
	adress adr;
	int card_number;
	char diagnosis[20];
public:
	Patient();
	char *getdiag();
	int getcard_number();
	void show();
};
using namespace std;
Patient::Patient() {
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "Input name, surname and patronymic :"; cin >> nam.name >> nam.surname >> nam.patronymic;
	cout << "Input street:"; cin >> adr.street;
	cout << "Input house number:"; cin >> adr.house_number;
	cout << "Input flat number:"; cin >> adr.flat_number;
	cout << "Input medical card number:"; cin >> card_number;
	cout << "Input diagnosis:"; cin >> diagnosis[20];
}
void Patient::show() {
	cout << "Name :" << nam.name << ' ' << nam.surname << ' ' << nam.patronymic << endl;
	cout << "Adress :" << adr.street << ' ' << adr.house_number << '-' << adr.flat_number << endl;
	cout << "Medical card number :"<< card_number;
	cout << "Diagnosis :" << diagnosis[20];
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
}
char *Patient::getdiag() { return diagnosis; }
int Patient::getcard_number() { return card_number; }
void DDiagnosis(Patient spis[], int n)
{
	char truediag[20];
	cout << "Input diagnosis you need : "; cin >> truediag;
	bool a = true;
	for (int i = 0; i<n; i++)
		if (strcmp(spis[i].getdiag(), truediag) == 0)
		{
			spis[i].show();
			a = false;
		}
	if (a) {
		cout << "Patients with such diagnosis don't exist" << endl;
	}
}
void RRange(Patient spis[], int n)
{
	int card_numbermax;
	cout << "Input card numbermax :"; cin >> card_numbermax;
	int card_numbermin;
	cout << "Input card numbermin :"; cin >> card_numbermin;
	bool a = true;
	for (int i = 0; i < n; i++)
		if (spis[i].getcard_number()<card_numbermax && spis[i].getcard_number() > card_numbermin)
		{
			spis[i].show();
			a = false;
		}
	if (a) {
		cout << "Patients with such card number don't exist" << endl;
	}
}
int main() {
	Patient* spis;
	int n;
	cout << "Enter number of patients : "; cin >> n;
	spis = new Patient[n];
	DDiagnosis(spis, n);
	RRange(spis, n);
	delete[] spis;
	cout << "Press any key!";
	while (!_kbhit());
	return 0;
}
