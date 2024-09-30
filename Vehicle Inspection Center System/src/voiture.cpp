#include "voiture.h"


voiture ::voiture (Vehicule a,int b,int c,string d,string e):Vehicule(a),nb_porte(b),nb_cylindre(c),carburant (d),type_transmis(e)
{
    //ctor
}
voiture::voiture()
{
        date a ;
    this->matricule=0;
    this->date_expiree=a;
    this->date_utilis=a;
    this->model="*";
    this->marque="*";
    this->Num_chasis=0;
    this->nb_porte=0 ;
    this->nb_cylindre=0 ;
    this->carburant="*" ;
    this->type_transmis="*" ;
}
ostream& operator<< (ostream& out,  voiture* a)
{

    out<<" "<<(a->matricule);
    out<<" "<<(&a->date_expiree);
    out<<" "<<(&a->date_utilis);
    out<<" "<<(a->model);
    out<<" "<<(a->marque);
    out<<" "<<(a->Num_chasis);
    out<<" "<<(a->nb_porte) ;
    out<<" "<<(a->nb_cylindre) ;
    out<<" "<<(a->carburant) ;
    out<<" "<<(a->type_transmis) ;
    out<<" "<<(a->historique).size();

    for (int i=0;i< (a->historique).size();i++)
    {
        out<<" "<<((a->historique)[i])<<endl;
    }

    out<<" "<<(a->utilisateurs).size();
    for (int i=0;i< (a->utilisateurs).size();i++)
    {
        out<<" "<<*((a->utilisateurs)[i])<<endl;
    }
    return(out);

}
ostream& operator<< (ostream& out ,  voiture& a)
{
    Vehicule *c=&a;
    out<<*c;
    out<<"nb_porte "<<a.nb_porte<<endl ;
    out<<"nb_cylindre est "<<a.nb_cylindre<<endl ;
    out<<"carburant est "<<a.carburant<<endl ;
    out<<"type_transmis est "<<a.type_transmis<<endl;
    int i;
    for (i=0;i< (a.utilisateurs).size();i++)
    {
        out<<"le "<<i<<" conducteur est "<<*((a.utilisateurs)[i])<<endl;

    }
}
istream& operator>> (istream& in ,  voiture& a)
{
    Vehicule *c=&a;
    in>>*c;
    cout<<"donnez le nb_porte"<<endl;
    in>>a.nb_porte ;
    cout<<"donnez le nb_cylindre"<<endl;
    in>>a.nb_cylindre ;
    cout<<"donnez le carburant"<<endl;
    in>>a.carburant ;
    cout<<"donnez le type_transmis"<<endl;
    in>>a.type_transmis;
    int choix;
    do
     {
        cout<<"\n il ya un conduteur   te veux ajouter ,taper 1 pour ajouter"<<endl;

        cin>>choix;

        if(choix==1 )
        {   string* S ;
            S=new string[1];
            cin>>*S;

            (a.utilisateurs).push_back(S);

        }
     }
     while(choix==1);

    return(in);
}
        int voiture::get_nb_porte()
        {
            return(nb_porte);
        }
        int voiture::get_nb_cylindre()
        {
           return(nb_cylindre);
        }
        string voiture::get_carburant()
        {
            return(carburant);
        }
        string voiture::get_type_transmis()
        {
            return(type_transmis);
        }

        void voiture::set_nb_porte(int a)
        {
            nb_porte=a;
        }
        void voiture::set_nb_cylindre(int a)
        {
            nb_cylindre=a;
        }
        void voiture::set_carburant(string a)
        {
            carburant=a;
        }
        void voiture::set_type_transmis(string a)
        {
            type_transmis=a;
        }
istream& operator>> (istream&  in,  voiture* a)
{

    in>>(a->matricule);
    in>>&(a->date_expiree);
    in>>&(a->date_utilis);
    in>>(a->model);
    in>>(a->marque);
    in>>(a->Num_chasis);
    in>>(a->nb_porte) ;
    in>>(a->nb_cylindre) ;
    in>>(a->carburant) ;
    in>>(a->type_transmis) ;
     int taille;
    in>>taille;
    for (int i=0;i< taille;i++)

    {
        date* d ;
        d=new date[1];
        in>>d;

        a->historique.push_back(d);
    }
    in>>taille;
    for (int i=0;i< taille;i++)

    {
        string* d ;
        d=new string[1];
        in>>*d;

        a->utilisateurs.push_back(d);
    }




    return(in);
}
voiture::voiture(const voiture& a)
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
    for (i=0;i< (a.utilisateurs).size();i++)
    {   string* d;
        d=new string(*(a.utilisateurs)[i]);

        utilisateurs.push_back(d);

    }
    nb_porte=a.nb_porte ;
    nb_cylindre=a.nb_cylindre ;
    carburant=a.carburant ;
    type_transmis=a.type_transmis ;
}
voiture ::~voiture ()
{
    //dtor
}
