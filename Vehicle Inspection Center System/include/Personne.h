#ifndef PERSONNE_H
#define PERSONNE_H
#include <vector>

#include <iostream>
using namespace std;
#include "string"
#include "date.h"

class Personne
{
protected:
	int id;
	string nom;
	string mail;
	date date_naissance;
	vector<int*> telephonnes;

public :
	Personne(int, string, string);
	Personne();
	Personne(const Personne& );
	friend istream& operator>> (istream&, Personne&);
	friend ostream& operator<< (ostream&, const Personne&);
	virtual void affiche()=0;

	int get_id();
    string get_nom();
	string get_mail();
	date get_date_naissance();

	void set_id(int);
	void set_nom(string);
	void set_mail(string);
	void set_date_naissance(date);

	virtual ~Personne();
};

#endif // PERSONNE_H
