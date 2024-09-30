#ifndef VEHICULE_H
#define VEHICULE_H
#include <iostream>
#include <vector>
using namespace std ;
#include <string>
#include "date.h"
#include "triple.h"

class Vehicule

{
        friend class date;
        protected :
        int Num_chasis ;
        string marque ;
        string model ;
        int matricule ;
        date date_utilis ;

        date date_expiree ;
        vector <date*> historique;
    public:

       //  Vehicule(const Vehicule &);
        Vehicule(int,string,string,int) ;
       Vehicule() ;
       Vehicule(const Vehicule& );
        friend istream& operator>> (istream& , Vehicule& );
        friend ostream& operator<< (ostream& , const Vehicule& );




        int get_Num_chasis() ;
        string get_marque() ;
        string get_model() ;
        int get_matricule() ;
        date get_date_utilis() ;
        date get_date_expiree() ;



        void set_Num_chasis(int) ;
        void set_marque(string ) ;
        void set_model(string) ;
        void set_matricule(int) ;
        void set_date_utilis(date ) ;
        void set_date_expiree(date) ;

        virtual ~Vehicule();

    protected:

    private:
};

#endif // VEHICULE_H
