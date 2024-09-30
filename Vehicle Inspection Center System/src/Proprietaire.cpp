#include "Proprietaire.h"

Proprietaire::Proprietaire()
{
    date d;
	id = 0;
	nom = "*";
	mail = "*";
	date_naissance = d;
	num_permis=0;

}
void Proprietaire::remplir()
   { char rep;
     Vehicule *q;
     int choix;
    do
    {
        cout<<"\n taper 1: voiture, 2:camion, 3:bus "<<endl;
        cin>>choix;
        if(choix==1)
            {
                 q=new voiture();
                 cin>>static_cast<voiture&> (*q);
            }
        else if(choix==2)
        {
              q=new camion();
              cin>>static_cast<camion&> (*q);
        }


        else if(choix ==3)
        {
            q=new bus();
            cin>>static_cast<bus&> (*q);
        }
        else break;

        vehicules.push_back(q);
        cout<<"\n rajouter ?"<<endl;
        cin>>rep;
    }
    while(rep=='o' || rep=='0');

   }

void Proprietaire::affiche() {
	cout << "id est " << id << endl;
	cout << "nom est " << nom << endl;
	cout << "maail est " << mail << endl;
	cout << "date de naissance est" << date_naissance << endl;
	cout<<"le nombre de telphone sont"<<endl;
	for (int i=0; i<telephonnes.size();i++)
    {
        cout<<*telephonnes[i]<<"\t";
    }
   cout<<endl;
  Proprietaire a=*this;
       cout << "num_permis est " << a.num_permis<<endl;
    int i;

    for (i=0;i< (a.vehicules).size();i++)
    {


        if(typeid(*((a.vehicules)[i]))==typeid(voiture))
            {
                 cout<<"le "<<i<<" vehicule est ";
                 cout<<static_cast<voiture&> (*((a.vehicules)[i]));
                 cout<<((a.vehicules)[i]);
                 cout<<endl;
            }
        else if (typeid(*((a.vehicules)[i]))==typeid(camion))
            {     cout<<"le "<<i<<" vehicule est ";

                 cout<<static_cast<camion&> (*((a.vehicules)[i]));
                 cout<<endl;
            }

        else if (typeid(*((a.vehicules)[i]))==typeid(bus))
            {
                 cout<<"le "<<i<<" vehicule est ";

                 cout<<static_cast<bus&> (*((a.vehicules)[i]));
                 cout<<endl;
            }
    }


}
istream& operator>> (istream& in, Proprietaire& a)
{   Personne *c=&a;
    in>>*c;
    cout << "donnez num_permis svp " <<endl;
    in>> a.num_permis;
    a.remplir();


}
ostream& operator<< (ostream& out, Proprietaire& a)
{
    Personne *c=&a;
    out<<*c;
    out << "num_permis est " << a.num_permis<<endl;
    int i;

    for (i=0;i< (a.vehicules).size();i++)
    {


        if(typeid(*((a.vehicules)[i]))==typeid(voiture))
            {
                 out<<"le "<<i<<" vehicule est ";
                 out<<static_cast<voiture&> (*((a.vehicules)[i]));
                 out<<((a.vehicules)[i]);
                 out<<endl;
            }
        else if (typeid(*((a.vehicules)[i]))==typeid(camion))
            {     out<<"le "<<i<<" vehicule est ";

                 out<<static_cast<camion&> (*((a.vehicules)[i]));
                 out<<endl;
            }

        else if (typeid(*((a.vehicules)[i]))==typeid(bus))
            {
                 out<<"le "<<i<<" vehicule est ";

                 out<<static_cast<bus&> (*((a.vehicules)[i]));
                 out<<endl;
            }
    }


}
Proprietaire::Proprietaire( const Proprietaire& a)
{
    id =a.id;
	nom = a.nom;
	mail = a.mail;
    date_naissance=a.date_naissance;
    num_permis=a.num_permis;
    int i;


    for (i=0;i< (a.telephonnes).size();i++)
    {   int* d=new int[1];
        *d=*a.telephonnes[i];

        telephonnes.push_back(d);

    }

    Vehicule* v;
    for (i=0;i< (a.vehicules).size();i++)
    {


        if(typeid(*((a.vehicules)[i]))==typeid(voiture))
            {
                 v =new voiture(static_cast<const voiture&>(*((a.vehicules)[i])));
                 vehicules.push_back(v);
                 cout<<((a.vehicules)[i]);


            }
        else if (typeid(*((a.vehicules)[i]))==typeid(camion))
            {
                 v =new camion(static_cast<const camion&>(*((a.vehicules)[i])));
                 vehicules.push_back(v);
            }

        else  if (typeid(*((a.vehicules)[i]))==typeid(bus))
            {
                 v =new bus(static_cast<const bus&>(*((a.vehicules)[i])));
                 vehicules.push_back(v);
            }
    }



}

void Proprietaire::cree(ifstream& f)
{
    f.open("D:\fff.txt",ios::out|ios::in|ios::trunc);
    if(!f.is_open())
        exit(-1);
}
 ostream& operator<< (ostream& out, Proprietaire* w)
 {
    out<<" "<<w->id<<endl;
    out<<" "<<w->nom<<endl;
    out<<" "<<w->mail<<endl;
    out<<" "<<&(w->date_naissance)<<endl;
     out<<" "<<(w->telephonnes).size();

    for (int i=0;i< (w->telephonnes).size();i++)
    {
        out<<" "<<*((w->telephonnes)[i])<<endl;
    }

    out<<" "<<w->num_permis<<endl;







out<<" "<<(w->vehicules).size();
for(int i=0; i<w->vehicules.size(); i++)
{if (typeid(*w->vehicules[i])==typeid(voiture))
out<<" "<<"voiture "<<&(static_cast< voiture&>(*w->vehicules[i]))<<endl;
else if (typeid(*w->vehicules[i])==typeid(bus))
out<<" "<<"bus "<< &(static_cast< bus&>(*w->vehicules[i]))<<endl;
else if(typeid(*w->vehicules[i])==typeid(camion))
 out<<" "<<"camion "<< &(static_cast< camion&>(*w->vehicules[i]))<<endl;

 }




 return out;
 }
 istream& operator>> (istream& in, Proprietaire* w)
 {

    in>>w->id;
    in>>w->nom;
    in>>w->mail;
    in>>&(w->date_naissance);
    int c;
in>>c;
for (int i=0;i< c;i++)

    {
        int* d ;
        int k;
        in>>k;

        d=new int(k);

        w->telephonnes.push_back(d);
    }

    in>>w->num_permis;
string choix,b;



in>>b;
int x = std::stoi(b);

if(b!="0")
{


 int i=0;



 do


{in>>choix;


if ((choix)=="voiture")

  {
      voiture* v;
       v =new voiture;
        in>>((v));
         (w->vehicules).push_back(v);

  }

else if (choix=="bus")
{
      bus* v;
       v =new bus;
        in>>(v);
         (w->vehicules).push_back(v);
}


else if(choix=="camion")


 {
      camion* v;
      v =new camion;
      in>>(v);
      (w->vehicules).push_back(v);
}
i+=1;


}
while(i<x);

}




 }

int Proprietaire::get_size() {

		return(vehicules.size() ) ;
}


Vehicule* Proprietaire::get_vehicule(int i) {

		return(vehicules[i] ) ;
}


int Proprietaire::get_num_permis(){
	return num_permis;
}
void Proprietaire::set_num_permis(int a) {
	num_permis = a;
}
int Proprietaire::recharhe(int c)
{   int i;
    for (i=0;i< (vehicules).size();i++)
    {
        if (c== (vehicules[i])->get_matricule())
        return(i);
    }
    return(-1);

}
Proprietaire::~Proprietaire()
{
     vehicules.clear();

}
