#ifndef VOITURE_H
#define VOITURE_H

#include <Vehicule.h>


class voiture : public Vehicule
{   int nb_porte ;
    int nb_cylindre ;
    string carburant ;
    string type_transmis ;
    vector<string*> utilisateurs;
    public:
        voiture (Vehicule,int=0,int=0,string=" ",string=" ");
        voiture (const voiture&) ;
        voiture();
        friend ostream& operator<< (ostream& ,  voiture& );
        friend ostream& operator<< (ostream& ,  voiture* );
        friend istream& operator>> (istream&  ,  voiture& );
        friend istream& operator>> (istream&  ,  voiture* );
        virtual ~voiture();
        int get_nb_porte() ;
        int get_nb_cylindre() ;
        string get_carburant() ;
        string get_type_transmis() ;

        void set_nb_porte(int) ;
        void set_nb_cylindre(int) ;
        void set_carburant(string) ;
        void set_type_transmis(string) ;

    protected:

    private:
};

#endif // VOITURE_H
