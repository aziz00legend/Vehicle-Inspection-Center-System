#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once
#include <iostream>
#include "Personne.h"
#include"date.h"
#include <map>
#include "couple.h"
using namespace std;
#include "string"
class Employee : public Personne
{
protected:
	float heure_travaille;
	int salaire;
	date date_embauche;
	string fonction;
	map<int,couple<date,int>> vacance_emp;






public:
	Employee(int ,string,string, float, int, string);
	Employee();
    virtual void affiche();
	friend istream& operator>> (istream&, Employee&);
	friend ostream& operator<< (ostream&, Employee&);
	friend ostream& operator<< (ostream& , Employee* );
	friend  istream& operator>> (istream& , Employee* ) ;

	float get_heure_travaille();
	int get_salaire();
	date get_date_embauche();
	string get_fonction();

	void set_heure_travaille(float);
	void set_salaire(int);
	void set_date_embauche(date);
	void set_fonction(string);

	virtual ~Employee();
};

#endif // EMPLOYEE_H
