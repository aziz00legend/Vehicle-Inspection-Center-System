#ifndef VOITURE_POID_LOURD _H
#define VOITURE_POID_LOURD _H

#include <Vehicule.h>


class voiture_Poid_lourd  : public Vehicule
{
    protected :
    int largeurs ;
    int longueur ;
    int hauteur ;
    int nb_essieux;

    public:

        voiture_Poid_lourd (Vehicule,int=0,int=0,int=0,int=0);
        voiture_Poid_lourd();
        friend ostream& operator<< (ostream& ,  voiture_Poid_lourd& );
        friend istream& operator>> (istream&  ,  voiture_Poid_lourd& );
        virtual ~voiture_Poid_lourd ();
        int get_largeurs() ;
        int get_longueur() ;
        int get_hauteur() ;
        int get_nb_essieux();

        void set_largeurs(int) ;
        void set_longueur(int) ;
        void set_hauteur(int) ;
        void set_nb_essieux(int);

    protected:

    private:
};

#endif // VOITURE_POID_LOURD _H
