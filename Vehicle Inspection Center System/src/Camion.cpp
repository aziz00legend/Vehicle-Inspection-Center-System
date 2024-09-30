#include "Camion.h"

camion::camion(voiture_Poid_lourd a,string b,int c):voiture_Poid_lourd(a),type_charge(b),capacite_charge (c)
{
    //ctor
}
camion::camion()
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
    this->largeurs=0;
    signe_danger.set_x1("*");
    signe_danger.set_x2("*");
    signe_danger.set_x3("*");

    this->type_charge=" ";
    this->capacite_charge=0;

}
ostream& operator<< (ostream& out ,  camion& a)
{
    Vehicule *c=&a;
    out<<static_cast<voiture_Poid_lourd&>(*c);

    out<<"type_charge est "<<a.type_charge<<endl ;
    out<<"capacite_charge  est "<<a.capacite_charge <<endl ;
    int i;
    for (i=0;i< (a.utilisateurs).size();i++)
    {
        out<<"le "<<i<<" conducteur est "<<*((a.utilisateurs)[i])<<endl;

    }
    string b;
    b=(a.signe_danger).get_x1() ;
    if (b!="*")
    {
        string x1=(a.signe_danger).get_x1();
        string x2=(a.signe_danger).get_x2();
        string x3=(a.signe_danger).get_x3();
        out<<"la forme de signe est "<<x1<<endl;
        out<<"la colore de signe est "<<x2<<endl;
        out<<"le nom de signe est "<<x3<<endl;

    }
    return(out);


}

istream& operator>> (istream&  in,  camion* a)
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
    in >> a->nb_essieux;
    in>>(a->type_charge) ;
    in>>(a->capacite_charge) ;
    int taille;
    in>>taille;
    for (int i=0;i< taille;i++)

    {   date* d ;
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

        string x1,x2,x3;

         in>>x1;

        in>>x2;

        in>>x3;
        (a->signe_danger).set_x1(x1);
        (a->signe_danger).set_x2(x2);
        (a->signe_danger).set_x3(x3);
    return(in);
}

istream& operator>> (istream& in ,  camion& a)
{
    Vehicule *c=&a;
    in>>static_cast<voiture_Poid_lourd&>(*c);
    cout<<"donnez le type_charge "<<endl;
    in>>a.type_charge ;
    cout<<"donnez le capacite_charge "<<endl;
    in>>a.capacite_charge  ;
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
     cout<<"est ce que le camion posséde un signe de danger si oui taper 1"<<endl;
     cin>>choix;
     if(choix==1)
        {

        string x1,x2,x3;
         cout<<"donnez la forme de signe  "<<endl;
         cin>>x1;
        cout<<"donnez la colore de signe  "<<endl;
        cin>>x2;
        cout<<"donnez la nom de signe "<<endl;
        cin>>x3;
        (a.signe_danger).set_x1(x1);
        (a.signe_danger).set_x2(x2);
        (a.signe_danger).set_x3(x3);



        }
     return (in);


}
         string camion::get_type_charge()
         {
             return(type_charge);
         }
         int camion::get_capacite_charge()
         {
             return(capacite_charge);
         }
         void camion::set_type_charge(string a)
         {
             type_charge=a;
         }
         void camion::set_capacite_charge(int a)
         {
             capacite_charge=a;
         }
ostream& operator<< (ostream& out,  camion* a)
{

    out<<" "<<(a->matricule);
    out<<" "<<(&a->date_expiree);
    out<<" "<<(&a->date_utilis);
    out<<" "<<(a->model);
    out<<" "<<(a->marque);
    out<<" "<<(a->Num_chasis);

    out<<" "<<(a->hauteur);
    out<<" "<<(a->largeurs);
    out<<" "<<(a->longueur) ;
    out << " " << a->nb_essieux;
    out<<" "<<(a->type_charge) ;
    out<<" "<<(a->capacite_charge) ;
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

        string x1=(a->signe_danger).get_x1();
        string x2=(a->signe_danger).get_x2();
        string x3=(a->signe_danger).get_x3();
        out<<" "<<x1<<endl;
        out<<" "<<x2<<endl;
        out<<" "<<x3<<endl;
    return(out);
}
camion ::~camion ()
{
    //dtor
}
