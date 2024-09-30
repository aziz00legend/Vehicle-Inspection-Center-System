#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std ;
#include <string>
class date
{
    int jour;
    int mois ;
    int annee;
    public:
        date(int=0,int=0,int=0);
        void affiche();
        void saisir_date(string ="donnez date");
        friend ostream& operator<< (ostream& , const date& );
        friend ostream& operator<< (ostream& , const date* );
        friend istream& operator>> (istream& , date& );
        friend istream& operator>> (istream& , date* );
        date operator + (date& ) ;
        bool operator == (const date& ) ;
        bool operator < (date& ) ;
        bool operator > (date& ) ;
        virtual ~date();
        int get_jour();
        int get_mois() ;
        int get_annee();
        void  set_jour(int);
        void  set_mois(int) ;
        void  set_annee(int);
        bool  egale(date);


    protected:

    private:
};

#endif // DATE_H
