#ifndef CAMION_H
#define CAMION_H

#include <voiture_Poid_lourd .h>


class camion : public voiture_Poid_lourd
{  string type_charge ;
   int capacite_charge ;
   vector<string*> utilisateurs;
   triple<string,string,string> signe_danger;
    public:
        camion (voiture_Poid_lourd,string=" ",int=0);
        camion();
        friend ostream& operator<< (ostream& ,  camion& );
        friend istream& operator>> (istream&  ,  camion& );
        friend ostream& operator<< (ostream& ,  camion* ) ;
        friend istream& operator>> (istream& ,  camion* ) ;
        virtual ~camion();
         string get_type_charge() ;

         int get_capacite_charge() ;
         void set_type_charge(string) ;
         void set_capacite_charge(int) ;


    protected:

    private:
};

#endif // CAMION_H
