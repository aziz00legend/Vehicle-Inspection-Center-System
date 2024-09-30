#include "Employee.h"



Employee:: Employee(int c, string n, string m, float h, int s, string f)
{   id=c;
    nom=n;
    mail=m;

	heure_travaille = h;
	salaire = s;
	date_embauche.saisir_date("date de l'embauche");
	fonction = f;
}

Employee::Employee() {
	date d;
	id = 0;
	nom = "*";
	mail = "*";
	date_naissance = d;
	heure_travaille = 0;
	salaire = 0;
	date_embauche = d;
	fonction = "*";
}

istream& operator>> (istream& in, Employee& emp) {
	Personne* p;
	p = &emp;
	in >> *p;
	cout << "donner les heures de travailles" << endl;
	in >> emp.heure_travaille;
	cout << "donner le saliare" << endl;
	in >> emp.salaire;
	cout << "donner la date de l'embauche" << endl;
	in >> emp.date_embauche;
	cout << "donner la fonction" << endl;
	in >> emp.fonction;
	int choix;
    do
     {
        cout<<"\n taper 1 pour ajouter pour ajouter vacance"<<endl;

        cin>>choix;

        if(choix==1 )
        {   date S ;

            cin>>S;
   int z;
   do
   {
       in>>z;
       if (z<1)
        cout<<"les nombres de jour de vacance doit  superiur 0 "<<endl;
   }
   while ((z<1));
   int id;
   do
   {
       in>>id;
       if (id<1)
        cout<<"les id de vacance doit  superiur 0 "<<endl;
   }
   while ((id<1));

           couple<date,int> c(S,z);

            emp.vacance_emp[id]=c;

        }
     }
     while(choix==1);
	return in;
}
 ostream& operator<< (ostream& out, Employee* w)
 {
    out<<" "<<w->id<<endl;
    out<<" "<<w->nom<<endl;
    out<<" "<<w->mail<<endl;
    out<<" "<<&(w->date_naissance)<<endl;
    out<<" "<<(w->telephonnes).size();

    for (int i=0;i< (w->telephonnes).size();i++)
    {
        out<<" "<<*((w->telephonnes)[i])<<endl;
    }
    out<<" "<<w->heure_travaille<<endl;
    out<<" "<<w->salaire<<endl;
    out<<" "<<&(w->date_embauche)<<endl;
    out<<" "<<w->fonction<<endl;
    out<<" "<<(w->vacance_emp).size();
    map<int,couple<date,int>> ::iterator it ;
    for (it = w->vacance_emp.begin(); it != w->vacance_emp.end(); ++it)
    {
        out<<" "<<it->first<<endl;
        couple<date,int> c =it->second;
        date x1=c.get_x1();
        out<<" "<<&x1<<endl;
        int x2=c.get_x2();
        out<<" "<<x2<<endl;



    }
    return(out);



 }
 void Employee::affiche() {
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
   Employee emp = *this;

	cout << "les heures de travaille sont" << emp.heure_travaille << endl;
	cout << "le salaire est" << emp.salaire << endl;
	cout << "la date d'embauche est" << emp.date_embauche << endl;
	cout << "la fonction est" << emp.fonction << endl;
    map<int,couple<date,int>> ::iterator it ;
    for (it = emp.vacance_emp.begin(); it != emp.vacance_emp.end(); ++it)
    {
       cout  << "l'identifier de vacance "<< it->first<<endl;
       cout  << "la date et nombre de jour"<< it->second << endl;
    }


}
 istream& operator>> (istream& in, Employee* w)
 {
    in>>w->id;
    in>>w->nom;
    in>>w->mail;
    in>>&(w->date_naissance);
    int c;
    in>>c;
    for (int i=0;i< c;i++)

    {
        int* d ;
        int k;
        in>>k;

        d=new int(k);

        w->telephonnes.push_back(d);
    }
    in>>w->heure_travaille;
    in>>w->salaire;
    in>>&(w->date_embauche);
    in>>w->fonction;

    in>>c;
    for (int i=0;i< c;i++)

    {
        int cle,jour;
        date d;
        in>>cle;
        in>>&d;
        in>>jour;
        couple<date,int> f(d,jour);
        w->vacance_emp[cle]=f;


    }
    return(in);



 }
ostream& operator<< (ostream& out, Employee& emp) {
	Personne* p;
	p = &emp;
	out << *p;
	out << "les heures de travaille sont" << emp.heure_travaille << endl;
	out << "le salaire est" << emp.salaire << endl;
	out << "la date d'embauche est" << emp.date_embauche << endl;
	out << "la fonction est" << emp.fonction << endl;
    map<int,couple<date,int>> ::iterator it ;
    for (it = emp.vacance_emp.begin(); it != emp.vacance_emp.end(); ++it)
    {
       cout  << "l'identifier de vacance "<< it->first<<endl;
       cout  << "la date et nombre de jour"<< it->second << endl;    }

	return out;
}
float Employee::get_heure_travaille()
{
	return heure_travaille;
}
int Employee::get_salaire() {
	return salaire;
}
date Employee::get_date_embauche() {
	return date_embauche;
}
string Employee::get_fonction() {
	return fonction;
}
void Employee::set_heure_travaille(float a) {
	id = a;
}
void Employee::set_salaire(int a) {
	salaire = a;
}
void Employee::set_date_embauche(date d) {
	date_embauche = d;
}
void Employee::set_fonction(string f) {
	fonction = f;
}

Employee::~Employee()
{
    //dtor
}
