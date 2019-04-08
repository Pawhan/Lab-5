#include<iostream>
#include<string>
using namespace std;
class Dziecko
{
	friend class Rodzic;
		string imie;
		string nazwisko;
		string szkola;
		int wiek;
	public:
		Dziecko(string i,string n,string s,int w)
		{
			imie=i;
			nazwisko=n;
			szkola=s;
			wiek=w;
		}
		void WypiszDane()
		{
			cout<<imie<<" "<<nazwisko<<" "<<szkola<<" "<<wiek<<endl;
		}
};
class Rodzic
{
	public:
		string imie;
		string nazwisko;
		int wiek;
		void PrzypiszDoInnejSzkoly(Dziecko &bachor)
		{
			bachor.szkola="AGH";
		}
};

int main(void)
{
	Dziecko bachor("Pawel","Hanzlik","Zerom",18);
	Rodzic stary;
	bachor.WypiszDane();
	stary.PrzypiszDoInnejSzkoly(bachor);
	bachor.WypiszDane();
	return 0;
}
