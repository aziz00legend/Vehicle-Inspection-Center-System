#include "Personne.h"

Personne::Personne (int c, string n, string m){
	id = c;
	nom = n;
	mail = m;
	date_naissance.saisir_date("date de naissance");
}

Personne::Personne() {
	date d;
	id = 0;
	nom = "*";
	mail = "*";
	date_naissance = d;
}
Personne::Personne(const Personne& a)
{
      id =a.id;
	nom = a.nom;
	mail = a.mail;
    date_naissance=a.date_naissance;

    int i;
    for (i=0;i< (a.telephonnes).size();i++)
    {   int* d=new int[1];
        *d=*a.telephonnes[i];

        telephonnes.push_back(d);

    }







}

istream& operator>> (istream& in, Personne& p) {
	cout << "donner le id personne " << endl;
	in >> p.id;
	cout << "donner le nom" << endl;
	in >> p.nom;
	cout << "donner le mail " << endl;
	in >> p.mail;
	cout << "donner la date de naissance " << endl;
	in >> p.date_naissance;
     int* S;
     int choix;

     do
     {
        cout<<"taper 1 pour ajouter un nemero de telphone"<<endl;
        cin>>choix;

        if(choix==1 )
        {   S =new int[1];
            cin>>*S;

            (p.telephonnes).push_back(S);

        }
     }
     while(choix==1);


}

ostream& operator<< (ostream& out, const Personne& p) {
	out << "id est " << p.id<<endl;
	out << "nom est " << p.nom << endl;
	out << "mail est" << p.mail << endl;
	out << "date de naissance est" << p.date_naissance << endl;
	cout<<"le nombre de telphone sont"<<endl;
	for (int i=0; i<p.telephonnes.size();i++)
    {
        out<<*p.telephonnes[i]<<endl;

    }
	return out;
}

void Personne::affiche() {
	cout << "id est " << id << endl;
	cout << "nom est " << nom << endl;
	cout << "maail est " << mail << endl;
	cout << "date de naissance est" << date_naissance << endl;
	cout<<"le nombre de telphone sont"<<endl;
	for (int i=0; i<telephonnes.size();i++)
    {
        cout<<*telephonnes[i]<<"\t";
    }
   cout<<endl;

}

int Personne::get_id() {
	return id;
}

string Personne::get_nom() {
	return nom;
}
string Personne::get_mail() {
	return mail;
}
date Personne::get_date_naissance() {
	return date_naissance;
}

void Personne::set_id(int a) {
	id = a;
}
void Personne::set_nom(string a) {
	nom = a;
}
void Personne::set_mail(string b) {
	mail = b;
}
void Personne::set_date_naissance(date d) {
	date_naissance = d;
}
Personne::~Personne()
{
    //dtor
}


