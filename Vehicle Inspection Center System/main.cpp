#include <iostream>
#include "Vehicule.h"
#include "voiture_Poid_lourd .h"
#include "voiture.h"
#include "Camion.h"
#include "bus.h"
#include "Personne.h"
#include "Proprietaire.h"
#include "Employee.h"
#include "Visite.h"
#include "Centre_visite.h"
#include "couple.h"
#include "triple.h"

#include "date.h"
#include <fstream>


using namespace std;

int main()
{
fstream f;
Centre_visite b;

  f.open("D:\projet c++.txt",ios::out|ios::in);

  f>>&b;

  do
  {   menu:
      cout<<endl;
      cout<<"1) mode utilisateur "<<endl;
      cout <<"2) mode administatreur "<<endl;
      cout <<"3) quitter"<<endl;

      int choix;
      cin >>choix;
      if(choix == 3)
        break;
      else if (choix == 1)
      {       menu1:
              cout <<"*****************vous etes en mode utlisateur**************"<<endl;
              cout<<"1) ajouter une visite  "<<endl;
               cout<<"2) la resultat de la visite  "<<endl;
              cout <<"3) retour "<<endl;
                    int choix1;
                    cin>>choix1;
                    if(choix1 == 1)
                  {      cout<<endl<<"donner les donnes du nouvelle visite"<<endl;
                         b.ajouter_visite();
                        f.close();
                        f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                        f.seekg(0);
                        f<<&b;

                      goto menu1;
                  }
                  if(choix1 == 2)
                  {     cout<<endl<<"donner les coordonnees de la visite"<<endl;
                        b.affiche_resultat();
                        cout<<"\n";
                        f.close();
                        f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                        f.seekg(0);
                        f<<&b;

                      goto menu1;
                  }
                   else if(choix1 == 3) goto menu;
                   else goto menu1;

      }
            else if (choix == 2)
      {
          kafteji:
          cout<<"saisir un mot de passe"<<endl;
          string x;
          cin>>x;
          if (b.verfie_m_d_p(x)==true)



              {       menu2:
              cout<<"***************vous etes en mode administrateur*************"<<endl;
              cout<<"1) ajouter une employee  "<<endl;
              cout<<"2)  ajouter mot passe   "<<endl;
              cout<<"3)  supprimer les visites  eronees  "<<endl;
              cout<<"4)  changer la resultat d une visite  "<<endl;
              cout<<"5)  afficher les donnees du centre "<<endl;
              cout<<"6) retour "<<endl;
                    int choix2;
                    cin>>choix2;
                    if(choix2 == 1)
                  {    cout<<endl<<"donner les donnes du nouveau employee"<<endl;
                       b.ajouter_emp();
                       f.close();
                       f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                       f.seekg(0);
                       f<<&b;
                      goto menu2;
                  }
                      else if(choix2 == 2)
                  {     cout<<endl<<"donner le nouveau mot de passe"<<endl;
                       b.ajouter_mdp();
                       f.close();
                       f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                       f.seekg(0);
                       f<<&b;
                      goto menu2;
                  }
                     else if(choix2 == 3)
                  {
                      b.supprimer_erone();
                      f.close();
                      f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                      f.seekg(0);
                      f<<&b;
                      goto menu2;
                  }
                     else if(choix2 == 4)
                  {   cout<<endl<<"donner les coordonnees de la visite"<<endl;
                      b.test_jour();
                      f.close();
                      f.open("D:\projet c++.txt",ios::out|ios::in | ios::trunc);
                      f.seekg(0);
                      f<<&b;
                      goto menu2;
                  }
                 else if(choix2 == 5)
                 {cout<<b;
                 goto menu2;
                 }


                   else if(choix2 == 6) goto menu;
                   else goto menu2;

      }
          else
          {
              cout << "taper 1 pour resaisir le mot de passe "<<endl;
              int k;
              cin>>k;
              if (k== 1)
                goto kafteji ;
          }

      }


  }
  while(1);























    return 0;
}
