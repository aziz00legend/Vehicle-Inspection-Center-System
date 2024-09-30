#ifndef VISITE_H
#define VISITE_H
#include "Employee.h"
#include "Proprietaire.h"

using namespace std;

class Visite
{   Proprietaire v_p ;
    date v_d ;
    int marticule ;
    string resultat ;
    float montant  ;
    Employee v_e  ;
    public:
        Visite();
        Visite(const Visite&);
        friend istream& operator>> (istream& , Visite& );
        friend ostream& operator<< (ostream& , Visite& ) ;
        friend ostream& operator<< (ostream& , Visite* ) ;
        friend istream& operator>> (istream&  , Visite* ) ;
        static bool test_mec();
        static bool test_elect();
        static bool test_peneus();
        void test_general();

        date get_v_d() ;
        int get_marticule() ;
        void set_marticule(int) ;
        string get_resultat() ;
        void set_resultat(string) ;
        float get_montant()  ;
        void set_montant(float)  ;
        void set_v_d(date d) ;
        virtual ~Visite();

    protected:

    private:
};

#endif // VISITE_H
