#include "Centre_visite.h"


Centre_visite::Centre_visite()
{
    nom="*";
    nb_viste_max=2;
    m_d_p.push_back("0000");

}
void Centre_visite::ajouter_emp()
{ Employee* q;
      q=new Employee();
   cin>>static_cast<Employee&> (*q);

  employes.push_back(q);
}
void Centre_visite::remplir_emp()
{   string rep;
    do
    {

      this->ajouter_emp();
      cout<<"voulez vous ajoutes employee si oui taper o sinon taper n"<<endl;
      cin>>rep;
      if (rep=="n")
      {
          break;
      }
    }
    while(rep=="o");
}
void Centre_visite::ajouter_visite()
{
    Visite v;
    cin>>v;

    date d;
   d=v.get_v_d();
   int i;
   i=0 ;
   do
   {if (agenda.size()==0)
        {


          vector<Visite> c;
          c.push_back(v);
          agenda.push_back(c);




          break ;
          }

     else if (d.egale(((agenda[i])[0]).get_v_d()))
              {
                 if ((agenda[i]).size()<nb_viste_max)
                  {







                     //Visite a(v);

                     (agenda[i]).push_back(v);


                      break;
                  }
                  else
                    {
                        cout<<"date pas valide parce que la date que vous avez choisie est pleine"<<endl;
                        cin>>d;

                         ((agenda[i])[(agenda[i]).size()-1]).set_v_d(d);

                        i=-1;

                    }
              }
     i++;
     if (agenda.size()==i)
     {


          vector<Visite> c;

          c.push_back(v);

          agenda.push_back(c);

        break;
     }



   }
   while(true);



}
ostream& operator<< (ostream& out, Centre_visite& c)
{
    out << "le  nom est" <<c.nom<< endl;
    out << "le  nobre de visite  maximal par jour est" <<c.nb_viste_max<< endl;
    int i,j;
    for (i=0;i< (c.agenda).size();i++)
    {
        for(j=0;j< (c.agenda[i]).size();j++)
            out<<((c.agenda[i])[j]);
    }
    for (i=0;i< (c.employes).size();i++)
    {

            out<<(*(c.employes[i]));
    }
   list<string>::iterator it ;
   cout<<" "<<(c.m_d_p).size();
   for (it = c.m_d_p.begin(); it != c.m_d_p.end(); it++)
    {
       cout <<" " << *it<<endl;
    }
    return(out);
}
ostream& operator<< (ostream& out, Centre_visite* c)
{
    out << " " <<c->nom<< endl;
    out << " " <<c->nb_viste_max<< endl;
    int i,j;
    out<<" "<<(c->agenda).size();
    for (i=0;i< (c->agenda).size();i++)
    {   out<<" "<<((c->agenda)[i]).size();
        for(j=0;j< (c->agenda[i]).size();j++)

            out<<&((c->agenda[i])[j]);
    }
    out<<" "<<(c->employes).size();
    for (i=0;i< (c->employes).size();i++)
    {

            out<<((c->employes[i]));
    }
  list<string>::iterator it ;
   out<<" "<<(c->m_d_p).size();
   for (it = c->m_d_p.begin(); it != c->m_d_p.end(); ++it)
    {
       out <<" " << *it<<endl;
    }

    return(out);
}
istream& operator>> (istream& in, Centre_visite* c)
{   in.seekg(0);
    in>>c->nom;
    in>>c->nb_viste_max;
    int i,j;
    int k;
    in>>k;
    for (i=0;i< k;i++)
    {   int d;
        in>>d;
        vector<Visite> a;
        for(j=0;j< d;j++)


         {
              Visite V;
            in>>&V;
            a.push_back(V);
         }
         c->agenda.push_back(a);
    }
    in>>k;
    for (i=0;i< k;i++)
    {
          Employee *E ;
            E=new Employee[1];
            in>>E;
            (c->employes).push_back(E);
    }
    in>>k;
    (c->m_d_p).clear();
    for (i=0;i< k;i++)
    {
          string E ;

            in>>E;
            (c->m_d_p).push_back(E);
    }
    return(in);
}
istream& operator>> (istream& in, Centre_visite& c)
{
   cout << "donnez svp le nom de centre " <<endl;
   in>>c.nom;
   cout << "donnez nbre maximal de visite par jour " <<endl;
   in>>c.nb_viste_max;
   cout << "donnez le data de emploie " <<endl;
   c.remplir_emp() ;

   return(in);

}
string Centre_visite::get_nom()
{
    return(nom);
}
int Centre_visite::get_nb_viste_max()
{
    return(nb_viste_max);
}
void Centre_visite::set_nom(string a )
{
   nom=a;
}

void  Centre_visite::set_nb_viste_max(int a)
{
  nb_viste_max=a;
}
void Centre_visite::cree(ifstream& f,string a)
{
    f.open(a,ios::out|ios::in);
    if(!f.is_open())
        exit(-1);
}

map<string,date> Centre_visite::jour_ferie;
void Centre_visite::ajout_jourfer()
{   date a;
    cout<<"donnez le nom de jour ferie"<<endl;
    string m;
    cin>>m;
    cout<<"donnez le date de cette jour ferie"<<endl;
    cin>>a;
    jour_ferie[m]=a;
}
void Centre_visite::affiche_jourfer()
{   map<string,date> ::iterator it ;
    for (it = jour_ferie.begin(); it != jour_ferie.end(); ++it)
    {
       cout  << "nom de vacance "<< it->first  << " la date vacance"<< it->second << endl;
    }

}

void Centre_visite::ajouter_mdp()
{ string a;
cin>>a;
list<string>::iterator it ;
it=find(m_d_p.begin(),m_d_p.end(),a);
if(it==m_d_p.end())
    m_d_p.push_back(a);
else
    cout<<"ce mot de passe existe deja"<<endl;
}

bool Centre_visite::verfie_m_d_p(string a)
{
list<string>::iterator it ;
it=find(m_d_p.begin(),m_d_p.end(),a);
if(it==m_d_p.end())
    return(false);
else
    return(true);
}





void Centre_visite::supprimer_mdp()
{ string a;
cin>>a;
if(a.size()!=1)
    m_d_p.remove(a);

}

void Centre_visite:: supprimer_erone()
{
    cout <<"donner la date "<<endl;
    date d;
    cin>> d;
     for (int i = agenda.size() - 1; i >= 0; i--) {
        date a = (agenda[i][0]).get_v_d();
        if (d == a) {
            agenda.erase(agenda.begin() + i);
        }
     }


}
void Centre_visite::test_jour()
{cout<<"donnnez le date"<<endl;
date d;
cin>>d;
 for (int i=0; i<agenda.size();i++)
   { date a;
     a=(((agenda[i])[0]).get_v_d());
     if (d == a)
     {  cout<<"donnez de marticule de la voiture"<<endl;
        int l;
        cin>>l;
        for (int j=0;i<(agenda[i]).size();j++)
        {  int p;
            p=((agenda[i])[j]).get_marticule();
            if (l==p)

                {(agenda[i])[j].test_general();
                break;}
        }


        break;


     }
   }

}
void Centre_visite::affiche_resultat()
{cout<<"donnnez le date"<<endl;
date d;
cin>>d;
 for (int i=0; i<agenda.size();i++)
   { date a;
     a=(((agenda[i])[0]).get_v_d());
     if (d == a)
     {  cout<<"donnez de marticule de la voiture"<<endl;
        int l;
        cin>>l;
        for (int j=0;i<(agenda[i]).size();j++)
        {  int p;
            p=((agenda[i])[j]).get_marticule();
            if (l==p)

                {string f;
                f=(agenda[i])[j].get_resultat();
                cout<<f;
                break;}
        }


        break;


     }
   }

}
Centre_visite::~Centre_visite()
{
    //dtor
}
