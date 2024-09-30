
#include "Vehicule.h"

Vehicule::Vehicule(int a,string b,string c,int d) : Num_chasis(a) ,marque(b) ,model(c) ,matricule(d)
{
{
    date_utilis.saisir_date("date_utilis");
    date_expiree.saisir_date("date_expiree");
}



    //ctor
}

ostream& operator<< (ostream& out, const Vehicule& a)
{

    out<<"Num_chasis est"<<a.Num_chasis <<endl;
    out<<"marque est"<<a.marque <<endl;
    out<<"model est"<<a.model <<endl;
    out<<"matricule est"<<a.matricule <<endl;
    out<<"date_utilis est"<<a.date_utilis <<endl;
    out<<"date_expiree est"<<a.date_expiree<<endl;
    int i;
    for (i=0;i< (a.historique).size();i++)
    {
        out<<"le "<<i<<" historique date est "<<*((a.historique)[i])<<endl;

    }

return out;
}

istream& operator>> (istream& in, Vehicule& a)
{
    cout<<"donnez le Num_chasis"<<endl;
    in>>a.Num_chasis ;
    cout<<"donnez la marque " <<endl;
    in>>a.marque ;
    cout<<"donnez la model "<<endl;
    in>>a.model ;
    cout<<"donnez le matricule " <<endl;
    in>>a.matricule ;
    cout<<"donnez le date_utilis "<<endl;
    in>>a.date_utilis ;
    cout<<"donnez le date_expiree "<<endl;
    in>>a.date_expiree;
    date S;
    int choix;

     do
     {
        cout<<"\n il ya un date  de historique_conduite te veux ajouter ,taper 1 pour ajouter"<<endl;
        cin>>choix;

        if(choix==1 )
        {   date* S ;
            S=new date[1];
            cin>>*S;

            (a.historique).push_back(S);

        }
     }
     while(choix==1);
return in;
}
Vehicule::Vehicule()
{
    date a ;
    this->matricule=0;
    this->date_expiree=a;
    this->date_utilis=a;
    this->model="*";
    this->marque="*";
    this->Num_chasis=0;
}
Vehicule::Vehicule(const Vehicule& a)

{
    Num_chasis=a.Num_chasis ;
    marque=a.marque;
    model=a.model;
    matricule=a.matricule ;
    date_utilis=a.date_utilis ;
    date_expiree=a.date_expiree ;
    int i;
    for (i=0;i< (a.historique).size();i++)
    {   date* d;
        d=new date(*(a.historique)[i]);

        historique.push_back(d);

    }
}

        int Vehicule::get_Num_chasis()
        {
            return(Num_chasis);
        }
        string Vehicule::get_marque()
        {
            return(marque);
        }
        string Vehicule::get_model()
        {
            return(model);
        }
        int Vehicule::get_matricule()
        {
            return(matricule);
        }
        date Vehicule::get_date_utilis()
        {
            return(date_utilis);
        }
        date Vehicule::get_date_expiree()
        {
            return(date_expiree);
        }
        void Vehicule::set_Num_chasis(int a)
        {
            Num_chasis=a;
        }
        void Vehicule::set_marque(string a)
        {
            marque=a;
        }
        void Vehicule::set_model(string a)
        {
           model=a;
        }
        void Vehicule::set_matricule(int a)
        {
            matricule=a;
        }
        void Vehicule::set_date_utilis(date a )
        {
            date_utilis=a;
        }
        void Vehicule::set_date_expiree(date a)
        {
          date_expiree=a;
        }

Vehicule::~Vehicule()
{
    //dtor
}
