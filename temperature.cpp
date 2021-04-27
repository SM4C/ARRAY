//Caricare in una matrice T[N][4] le temperature rilevate da N centraline quattro volte al giorno.

//Costruire poi un programma per rispondere alle seguenti domande:

//	visualizzazione di tutti i dati
//	elenco di tutte le temperature registrate dalla centralina indicata dall'utente
//	elenco di tutte le temperature registrate nelle centraline nell'ora  indicata dall'utente
//	visualizzazione della temperatura media
//	elenco delle ore in cui la temperatura è scesa sotto il valore indicato dall'utente in almeno 3 centraline
//	per ciascuna centralina visualizzazione di: temperatura massima (con ora), temperatura minima (con ora) e escursione termica
//	elenco in ordine crescente delle temperature registrate in una centralina indicata dall'utente
//	visualizzazione della temperatura registrata nella centralina e nell'ora indicata dall'utente

//(per centralina si intende l’indice di riga da 0 a N-1, per ora si intende l’indice di colonna da 0 a 3)

#include <iostream>
using namespace std;
int main ()
{
	int n;
	bool change;
	cout<<"quante sono le centraline? "<<endl;
	cin>>n;
	int temperature[n][4], caseSwitch, trim, sort, sumSystem, medSystem, maxArray=0, minArray=99999999, maxo, mino, esc[n], app, name[n];
	for (int i=0; i<n; i++)
	{
		cout<<"inserisci il nome della centralina: "<<endl;
		cin>>name[i];
		for (int j=0; j<4; j++)
		{
			cout<<"inserisci la "<<j<<"° temperatura della centralina, "<<name[i]<<endl;
			cin>>temperature[i][j];
		}
	}
	do 
	{
		cout<<"1 - visualizzazione di tutti i dati"<<endl;
		cout<<"2 - elenco di tutte le temperature registrate dalla centralina indicata dall'utente"<<endl;
		cout<<"3 - elenco di tutte le temperature registrate nelle centraline nell'ora  indicata dall'utente"<<endl;
		cout<<"4 - visualizzazione della temperatura media"<<endl;
		cout<<"5 - elenco delle ore in cui la temperatura è scesa sotto il valore indicato dall'utente in almeno 3 centraline"<<endl;
		cout<<"6 - per ciascuna centralina visualizzazione di: temperatura massima (con ora), temperatura minima (con ora) e escursione termica"<<endl;
		cout<<"7 - elenco in ordine crescente delle temperature registrate in una centralina indicata dall'utente"<<endl;
		cout<<"8 - visualizzazione della temperatura registrata nella centralina e nell'ora indicata dall'utente"<<endl;
		cout<<"9 - EXIT"<<endl;
		cin>>caseSwitch;
		switch (caseSwitch)
		{
			case 1:
				for (int i=0; i<n; i++)
				{
					cout<<"Nome centralina: "<<name[i]<<endl;
					for (int j=0; j<4; j++)
					{
						cout<<temperature[i][j]<<"       ";
					}
				}
				break;
			case 2:
				cout<<"inserisci il numero della centralina: "<<endl;
				cin>>trim;
				cout<<endl;
				for (int j=0; j<4; j++)
				{
					cout<<temperature[trim][j]<<"     ";
				}
				cout<<endl;
				break;
			case 3:
				cout<<"inserire l'orario di controllo: "<<endl;
				cin>>trim;
				for (int i=0; i<n; i++)
				{
					cout<<temperature[i][trim]<<"      ";
				}
				break;
			case 4:
				for (int i=0; i<n; i++)
				{
					for (int j=0; j<4; j++)
					{
						sumSystem=sumSystem+temperature[i][j];
					}
				}
				trim=n*4;
				medSystem=sumSystem/trim;
				cout<<"Media totale delle centraline: "<<medSystem<<endl;
				break;
			case 5:
				cout<<"inserisci il valore di controllo: "<<endl;
				cin>>trim;
				for (int i=0; i<n; i++)
				{
					for (int j=0; j<4; j++)
					{
						cout<<endl;
						if (temperature[i][j]>=trim)
						{
							cout<<temperature[i][j]<<"      ";
						}
					}
				}
				break;
			case 6:
				for (int i=0; i<n; i++)
				{
					for (int j=0; j<4; j++)
					{
						if (temperature[i][j]>maxArray)
						{
							maxArray=temperature[i][j];
							maxo=j;
						}
						if (temperature[i][j]<minArray)
						{
							minArray=temperature[i][j];
							mino=j;
						}
						esc[i]=maxArray-minArray;
					}
				}
				for (int i=0; i<n; i++)
				{
					cout<<"MAX:  "<<maxArray<<endl;
					cout<<"MIN:  "<<minArray<<endl;
					cout<<"ESC. TERMICA:  "<<esc[i]<<endl;
				}
				break;
			case 7:
				cout<<"inserisci il nome della centralina"<<endl;
				cin>>trim;
				do 
				{
					change=false;
					for (int i=0; i<n; i++)
					{
						if (temperature[i][trim]>temperature[i+1][trim])
						{
							app=temperature[i][trim];
							temperature[i][trim]=temperature[i+1][trim];
							temperature[i+1][trim]=app;
							change=true;
						}
					}
				}
				while (change);
				for (int i=0; i<n; i++)
				{
					cout<<temperature[i][trim]<<"     ";
				}
				break;
			case 8:
				cout<<"inserisci il numero della centralina:"<<endl;
				cin>>trim;
				cout<<"inserisci l'orario desiderato: "<<endl;
				cin>>sort;
				cout<<"TEMPERATURA: "<<temperature[trim][sort];
				break;
			case 9:
				cout<<"chiusura programma in corso"<<endl;
				break;
		}
	}
	while (caseSwitch!=9);
	system ("pause");
	return 0;
}
