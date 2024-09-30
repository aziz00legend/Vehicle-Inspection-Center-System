#ifndef BUS_H
#define BUS_H

#include <voiture_Poid_lourd .h>


class bus : public voiture_Poid_lourd
{   string type ;
    int nb_place ;
    vector<string*> utilisateurs;

    public:
        bus (voiture_Poid_lourd,string=" ",int=0);
        bus();
        friend ostream& operator<< (ostream& ,  bus& );
        friend istream& operator>> (istream&  ,  bus& );
        friend ostream& operator<< (ostream& ,  bus* ) ;
        friend istream& operator>> (istream&  ,  bus* ) ;
        //bus (const bus&) ;
        virtual ~bus();
        string get_type() ;
        int get_nb_place() ;
        void set_type(string) ;

        void set_nb_place(int) ;
    protected:

    private:
};

#endif // BUS_H
