#ifndef CENTRE_VISITE_H
#define CENTRE_VISITE_H
#include "Visite.h"
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;
class Centre_visite
{   string nom;
    int nb_viste_max ;
    vector<Employee*> employes;
    vector<vector<Visite>> agenda;
    static map<string,date> jour_ferie;
    list<string> m_d_p;
    public:

        Centre_visite();
        void ajouter_emp();
        void remplir_emp() ;
        void ajouter_visite() ;
        friend ostream& operator<< (ostream& , Centre_visite& );
        friend istream& operator>> (istream& , Centre_visite& );
        friend ostream& operator<< (ostream& , Centre_visite* );
        friend istream& operator>> (istream& , Centre_visite* );
        bool verfie_m_d_p(string );
        static void cree(ifstream& ,string) ;
        static void ajout_jourfer() ;
        void affiche_jourfer() ;
        void test_jour(void );
        void affiche_resultat() ;


        void ajouter_mdp();
        void supprimer_mdp();
        virtual ~Centre_visite();
        string get_nom();
        int get_nb_viste_max() ;
        void set_nom(string);
        void set_nb_viste_max(int) ;

        void supprimer_erone();

    protected:

    private:
};

#endif // CENTRE_VISITE_H
