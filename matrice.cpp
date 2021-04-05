#include <iostream>
using namespace std;
int main ()
{
	int n,sc;
	cout<<"quanti sono gli studenti: "<<endl;
	cin>>n;
	int tab[n][5], somma, max, media, min;
	string name[10], mat[5], nomemax, matmin;
	mat[0]="Italiano";
	mat[1]="Storia";
	mat[2]="Inglese";
	mat[3]="Matematica";
	mat[4]="Informatica";
	for (int i=0; i<10; i++)
	{
		cout<<"Nome= "<<endl;
		cin>>name[i];
		for (int j=0; j<n; j++) 
		{
			cout<<"voto "<<mat[j]<<"= ";
			cin>>tab[i][j];
		}
	}
	do 
	{
		cout<<"1 - studente con media più alta"<<endl;;
		cout<<"2 - materia con media più bassa"<<endl;
		cout<<"3 - Esci ";
		cin>>sc;
		switch (sc)
		{
			case 1:
				for (int i=0; i<n; i++)
				{
					somma=0;
					for (int j=0; j<5; j++)
					{
						somma=somma+tab[n][j];
					}
					media=somma/5;
					if (media>max)
					{
						max=media;
						nomemax=name[i];
					}
				}
				cout<<"media più alta:   "<<max<<"ottenuta da:    "<<nomemax<<endl;
				break;
			case 2:
				min=11;
				for (int j=0; j<0; j++)
				{
					somma=0;
					for (int i=0; i<n; i++)
					{
						somma=somma+tab[i][j];
					}
					media=somma/n;
					if (media<min)
					{
						min=media;
						matmin=mat[j];
					}
				}
				cout<<"media più bassa:   "<<min<<"ottenuta nella materia:    "<<matmin<<endl;
				break;
			case 3:
				cout<<"chiusura programma"<<endl;
				break;
		}
	}
	while (sc!=3);
	system ("pause");
	return 0;
}
