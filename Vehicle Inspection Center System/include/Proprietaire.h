#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H
#include "Personne.h"
#include "bus.h"
#include "voiture.h"
#include "camion.h"
#include <fstream>
using namespace std;
#include <vector>
class Proprietaire :public Personne
{
	vector <Vehicule*> vehicules;
	int num_permis;


public:

	Proprietaire();
	Proprietaire(const Proprietaire&);
    void remplir();
    friend ostream& operator<< (ostream& , Proprietaire& );
    friend istream& operator>> (istream& , Proprietaire& );
    Vehicule* get_vehicule(int);
    static void cree(ifstream& ) ;
    friend ostream& operator<< (ostream& , Proprietaire* );
    friend istream& operator>> (istream& , Proprietaire* ) ;
    virtual void affiche();
    int recharhe(int ) ;

	int get_num_permis();
	void set_num_permis(int);
	void ajouter_vehicule(Vehicule);
    int get_size();
	virtual ~Proprietaire();
};

#endif // PROPRIETAIRE_H
