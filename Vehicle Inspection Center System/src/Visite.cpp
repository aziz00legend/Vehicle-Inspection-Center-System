#include "Visite.h"

Visite::Visite()
{
    marticule=0 ;
    resultat="en_attend" ;
    montant=0  ;
    date d;
    v_d=d;
    Proprietaire  p;
    v_p=p;
    Employee e ;
    v_e =e;
}
istream& operator>> (istream& in, Visite& v)
{

     cout << "donner visite date " << endl;
    in>>v.v_d;

    cout << "donner montant " << endl;
    in>>v.montant;

    cout << "donner le donnes de Proprietaire " << endl;
    in>>v.v_p;
    cout << "donner le donnes de  Employee" << endl;
    in>>v.v_e;
    /*do
    {

        int i;
        for ( i=0;i<(v.v_p).get_size();i++)

            {
                if ((((v.v_p).get_vehicule(i))->get_matricule())==v.marticule)


            }

             if ((((v.v_p).get_vehicule(i-1))->get_matricule())==v.marticule)
                    break;

    }
    while(1);*/
    cout << "donner marticule " << endl;
    in>>v.marticule;
    return(in);


}
ostream& operator<< (ostream& out, Visite& v)
{   cout<<"***************les données de la visite******************"<<endl;
    out << "le  marticule est" <<v.marticule<< endl;
    out << "le  montant est" <<v.montant<< endl;
    out << "le  date visite  est" <<v.v_d<< endl;


    out << "le donnes de Employee est :" <<v.v_e<< endl;
    out << " le donnes de Proprietaire est :" ;
    out<<static_cast<Proprietaire&> (v.v_p);
    return(out);




}
        bool Visite::test_mec()
        {
            cout<<"taper oui si test mecanique est valide non si non"<<endl;
            {
              string a;
              do

              {
               cin>>a;
               if (a=="oui" )
                return(true);
              }
              while(a!="non");
            }
            return(false);
        }
        bool Visite::test_elect()
        {
            cout<<"taper oui si test elecrique est valide non si non"<<endl;
            {
              string a;
              do

              {
               cin>>a;
               if (a=="oui" )
                return(true);
              }
              while(a!="non");
            }
            return(false);
        }
        bool Visite::test_peneus()
        {
            cout<<"taper oui si test peneus est valide non si non"<<endl;
            {
              string a;
              do

              {
               cin>>a;
               if (a=="oui" )
                return(true);
              }
              while(a!="non");
            }
            return(false);
        }
        void Visite::test_general()
        {
            bool a,b,c;
            a=this->test_mec();
            b=this->test_elect();
            c=this->test_peneus();
            if (a&&b&&c)
                {
                    resultat="valide";
                int i;
                for ( i=0;i<(v_p).get_size();i++)

                {
                   if ((((v_p).get_vehicule(i))->get_matricule())==marticule)

                    break;
                }
                date h;
                h= ((v_p).get_vehicule(i))->get_date_expiree();
                cout<<"donnez valide de visite"<<endl;
                date j;
                cin>>j;
                h=h+j;
                ((v_p).get_vehicule(i))->set_date_expiree(h);


                }
            else
                {
                      resultat="refuse";
                      if (a==false)
                      resultat+="_test_mecanique";
                      if (b==false)
                      resultat+="_test_electrique";
                      if (c==false)
                      resultat+="_test_peneus";

                }

        }

date Visite::get_v_d()
{
    return(v_d);
}
void Visite::set_v_d(date d)
{
    v_d=d;
}
Visite::Visite( const Visite& a)
{
     Proprietaire c(a.v_p) ;
     v_p=c;
     v_d=a.v_d ;

     marticule=a.marticule ;
     resultat=a.resultat ;
     montant=a.montant  ;
    v_e=a.v_e  ;
}
        int Visite::get_marticule()
        {
            return(marticule);
        }
        void Visite::set_marticule(int a)
        {
            marticule=a;

        }
        string Visite::get_resultat()
        {
            return(resultat);
        }
        void Visite::set_resultat(string a)
        {
            resultat=a;
        }
        float Visite::get_montant()
        {
            return(montant);
        }
        void Visite::set_montant(float a)
        {
            montant=a;
        }
 ostream& operator<< (ostream& out , Visite* w)
 {
     out<<" "<<&(w->v_p)<<endl;
     out<<" "<<&(w->v_d)<<endl;
     out<<" "<<(w->marticule)<<endl;
     out<<" "<<(w->resultat)<<endl;
     out<<" "<<(w->montant)<<endl;
     out<<" "<<&(w->v_e)<<endl;



     return(out);



 }
  istream& operator>> (istream& in , Visite* w)
 {
     in>>&(w->v_p);
     in>>&(w->v_d);
     in>>(w->marticule);
     in>>(w->resultat);
     in>>(w->montant);
     in>>&(w->v_e);
     return(in);



 }

Visite::~Visite()
{
    //dtor
}

