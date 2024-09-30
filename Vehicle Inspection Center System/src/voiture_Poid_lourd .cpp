#include "voiture_Poid_lourd .h"

voiture_Poid_lourd ::voiture_Poid_lourd (Vehicule a,int b,int c,int d,int e):Vehicule(a),largeurs(b),longueur(c),hauteur (d),nb_essieux(e)
{
    //ctor
}
voiture_Poid_lourd::voiture_Poid_lourd()
{
        date a ;
    this->matricule=0;
    this->date_expiree=a;
    this->date_utilis=a;
    this->model="*";
    this->marque="*";
    this->Num_chasis=0;
    this->hauteur=0;
    this->largeurs=0;
    this->longueur=0;
    this->nb_essieux=0;
    this->largeurs=0;
}
ostream& operator<< (ostream& out ,  voiture_Poid_lourd& a)
{
    Vehicule *c=&a;
    out<<*c;
    out<<"largeurs est "<<a.largeurs<<endl ;
    out<<"longueur est "<<a.longueur<<endl ;
    out<<"hauteur est "<<a.hauteur<<endl ;
    out<<"nb_essieux est "<<a.nb_essieux<<endl;
}
istream& operator>> (istream& in ,  voiture_Poid_lourd& a)
{
    Vehicule *c=&a;
    in>>*c;
    cout<<"donnez le largeurs"<<endl;
    in>>a.largeurs ;
    cout<<"donnez le longueur"<<endl;
    in>>a.longueur ;
    cout<<"donnez le hauteur"<<endl;
    in>>a.hauteur ;
    cout<<"donnez le nb_essieux"<<endl;
    in>>a.nb_essieux;
}
        int voiture_Poid_lourd::get_largeurs()
        {
           return(largeurs);
        }
        int voiture_Poid_lourd::get_longueur()
        {
            return(longueur);
        }
        int voiture_Poid_lourd::get_hauteur()
        {
            return(hauteur);
        }
        int voiture_Poid_lourd::get_nb_essieux()
        {
            return(nb_essieux);
        }
        void voiture_Poid_lourd::set_largeurs(int a)
        {
            largeurs=a;
        }
        void voiture_Poid_lourd::set_longueur(int a)
        {
            longueur=a;
        }
        void voiture_Poid_lourd::set_hauteur(int a)
        {
            hauteur=a;
        }
        void voiture_Poid_lourd::set_nb_essieux(int a)
        {
            nb_essieux=a;
        }
voiture_Poid_lourd ::~voiture_Poid_lourd ()
{
    //dtor
}
