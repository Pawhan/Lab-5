#include<iostream>
#include<string>
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;
class Marsjanin
{
	public:
		static int liczba_marsjan;
		int indeks;
		Marsjanin(int ind)
		{
			indeks=ind;
			liczba_marsjan++;
		}
		~Marsjanin()
		{
			liczba_marsjan--;
		}
		static string Atakuj(int ilosc)
		{
			if(Marsjanin::liczba_marsjan<=5)
				return "ukrycie";
			else
				return "wojna";
		}
};
int Marsjanin::liczba_marsjan = 0;
int main(void)
{
	int x;
	string stan;
	list <Marsjanin*> lista;
	srand(time(NULL));
	while(true)
	{
		stan = Marsjanin::Atakuj(Marsjanin::liczba_marsjan);
		if(stan == "ukrycie")
		{
			cout<<stan<<endl;
			lista.push_back(new Marsjanin(Marsjanin::liczba_marsjan));
		}
		else if(stan == "wojna")
		{
			cout<<stan<<endl;
			x=rand()%5+1;
			for(int i=0; i<x;i++)
			{
				delete *lista.begin();
				lista.pop_front();
			}
			if(x!=1)
				cout<<"Ale byla wojna zginelo "<<x<<"  marsjan"<<endl;
			else
				cout<<"slaba ta wojna, zginal "<<x<<"  marsjanin"<<endl;
		}
		cout<<"zyje  "<<Marsjanin::liczba_marsjan<<"  marsjan"<<endl;
	}
	return 0;
}
