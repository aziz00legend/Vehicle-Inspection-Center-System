#include "date.h"

date::date(int a,int b,int c):jour(a),mois(b),annee(c)
{
    //ctor
}
 void date::saisir_date(string msg)
 {
     cout<<msg<<endl;
     cin>>jour;
     cin>>mois;
     cin>>annee;
 }
 void date::affiche()
 {
     cout<<jour<<":"<<mois<<":"<<annee<<endl;
 }
ostream& operator<< (ostream& out, const date& d)
{
out<<d.annee<<":"<<d.mois<<":"<<d.jour<<endl;


return out;
}
ostream& operator<< (ostream& out, const date* a)
{
    out<<" "<<(a->jour);
    out<<" "<<(a->mois);
    out<<" "<<(a->annee);
    return(out);

}
date date::operator + (date& a )
{date y;
  ;

y.jour=jour;
y.mois=(a.mois+mois)%12;
y.annee=annee+(a.mois+mois)/12+a.annee;
return (y);

}

istream& operator>> (istream& in, date& a)
{

 cout<<"donnez le date sous form A||M||J"<<endl;
      int tab[]={0,31,28,31,30,31,30,31,31,30,31,30,31}  ;
    in>>a.annee;
    do
   {try
           {
               in>>a.mois;
               if ((a.mois>12) || (a.mois<1) ) throw (-1);

           }

      catch (int e)
       {
         cout<<"le mois doit etre infrieure ou egale de 12 et superiur 0 \n";
       }
    }
    while ((a.mois>12) || (a.mois<1) );
    if (((a.annee)%4==0 && (a.annee)%100!=0 || (a.annee)%400==0))
           *(tab+2)=*(tab+2)+1;

   do
   {
       in>>a.jour;
       if (((a.jour)>tab[a.mois])||(a.jour<1))
        cout<<"le jour doit inferiur "<<tab[a.mois]<<" et superiur 0 "<<endl;
   }
   while (((a.jour)>tab[a.mois])||(a.jour<1));


return in;
}
        int date::get_jour()
        {
          return(jour);
        }
        int date::get_mois()
        {
            return(mois);
        }
        int date::get_annee()
        {
            return(annee);
        }
        void  date::set_jour(int a )
        {
            jour=a;
        }
        void  date::set_mois(int a)
        {
            mois=a;
        }
        void  date::set_annee(int a)
        {
            annee=a;
        }
        bool  date::egale(date d)
        {
            if((jour==d.jour)&&(mois==d.mois)&&(annee==d.annee))
            return(true);
            return(false);

        }
         istream& operator>> (istream& in, date* a)
        {
             in>>(a->jour);
             in>>(a->mois);
             in>>(a->annee);
    return(in);
        }
  bool date::operator == (const date& d)
       {
            if((jour==d.jour)&&(mois==d.mois)&&(annee==d.annee))
            return(true);
            return(false);

        }
  bool date::operator < (date& other)
  {
      if  ((other>*this))
        return(true) ;
      return(false);

  }
  bool date::operator > (date& other)
  {
    if (annee > other.annee)
        {return true;}
    else if (annee == other.annee && mois > other.mois) {
      return true;
    } else if (annee== other.annee&& mois== other.mois && jour > other.jour) {
      return true;
    }
    return false;
  }

date::~date()
{
    //dtor
}
