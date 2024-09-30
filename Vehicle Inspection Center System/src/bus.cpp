#include "bus.h"

bus::bus(voiture_Poid_lourd a,string b,int c):voiture_Poid_lourd(a),type(b),nb_place (c)
{
    //ctor
}
bus::bus()
{
        date a ;
    this->matricule=0;
    this->date_expiree=a;
    this->date_utilis=a;
    this->model="*";
    this->marque="*";
    this->Num_chasis=0;
    this->hauteur=0;
    this->longueur=0;
    this->type="*";
    this->nb_place=0;
    this->largeurs=0;

}
istream& operator>> (istream&  in,  bus* a)
{

    in>>(a->matricule);
    in>>&(a->date_expiree);
    in>>&(a->date_utilis);
    in>>(a->model);
    in>>(a->marque);
    in>>(a->Num_chasis);
    in>>(a->hauteur) ;
    in>>(a->largeurs) ;
    in>>(a->longueur) ;
    in >> a->nb_essieux ;
    in>>(a->type) ;
    in>>(a->nb_place) ;
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
ostream& operator<< (ostream& out ,  bus& a)
{
    Vehicule *c=&a;
    out<<static_cast<voiture_Poid_lourd&>(*c);
    out<<"type est "<<a.type<<endl ;
    out<<"nb_place est "<<a.nb_place<<endl ;
    int i;
    for (i=0;i< (a.utilisateurs).size();i++)
    {
        out<<"le "<<i<<" conducteur est "<<*((a.utilisateurs)[i])<<endl;

    }
    return(out);

}

istream& operator>> (istream& in ,  bus& a)
{
    Vehicule *c=&a;
    in>>static_cast<voiture_Poid_lourd&>(*c);
    cout<<"donnez le type"<<endl;
    in>>a.type ;
    cout<<"donnez le nb_place "<<endl;
    in>>a.nb_place ;
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
         string bus::get_type()
         {
             return(type);
         }
         int bus::get_nb_place()
         {
             return(nb_place);
         }
         void bus::set_type(string a)
         {
             type=a;
         }
         void bus::set_nb_place(int a)
         {
             nb_place=a;
         }
ostream& operator<< (ostream& out,  bus* a)
{

    out<<" "<<(a->matricule);
    out<<" "<<(&a->date_expiree);
    out<<" "<<(&a->date_utilis);
    out<<" "<<(a->model);
    out<<" "<<(a->marque);
    out<<" "<<(a->Num_chasis);
    out<<" "<<(a->hauteur);
    out<<" "<<(a->largeurs) ;
    out<<" "<<(a->longueur) ;
    out <<" "<< a->nb_essieux ;
    out<<" "<<(a->type) ;
    out<<" "<<(a->nb_place) ;
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

bus ::~bus ()
{
    //dtor
}
