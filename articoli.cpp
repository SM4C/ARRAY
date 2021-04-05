#include <iostream>
using namespace std;
int main ()
{
	int n;
	cout<<"quante sono le vendite: "<<endl;
	cin>>n;
	int vend [n][5], cod[n], ch, somma[5], tot, maxvend=0;
	string sett[5], maxday;
	sett[0]="lunedì";
	sett[1]="martedì";
	sett[2]="mercoledì";
	sett[3]="giovedì";
	sett[4]="venerdì";
	for (int i=0; i<n; i++)
	{
		cout<<"CODICE:   "<<endl;
		cin>>cod[i];
		for (int j=0; j<5; j++)
		{
			cout<<"vendite di codice ("<<cod[i]<<") nel giorno "<<sett[j]<<":"<<endl;
			cin>>vend[i][j];
		}
	}
	do 
	{
		cout<<endl;
		cout<<"1 - totale vendite settimanali:"<<endl;
		cout<<"2 - Giorno dove ci sono state più vendite:"<<endl;
		cout<<"3 - Articolo più venduto di lunedì"<<endl;
		cout<<"4 - EXIT"<<endl;
		cout<<endl;
		cin>>ch;
		switch (ch)
		{
			case 1:
				for (int i=0; i<n; i++)
				{
					tot=0;
					for (int j=0; j<5; j++)
					{
						tot=tot+vend[i][j];
					}
				cout<<"totale vendite:   "<<tot<<endl;
				}
				break;
			case 2:
				for (int i=0; i<n; i++)
				{
					somma[i]=0;
					for (int j=0; j<n; j++)
					{
						somma[i]=somma[i]+vend[i][j];
					}
				}
				for (int i=0; i<5; i++)
				{
					if (somma[i]>maxvend)
					{
						maxvend=somma[i];
						maxday=sett[i];
					}
				}
				for (int i=0; i<5; i++)
				{
					if (maxvend==somma[i])
					{
						cout<<"vendite maggiori:   "<<sett[i]<<endl;
					}
				}
				break;
			case 3:
				for (int i=0; i<n; i++) 
				{
					if (vend[i][0]>maxvend)
					{
						maxvend=vend[i][0];
					}
				}
				cout<<"la vendita maggiore effettuata di lunedì è stata di: "<<maxvend<<" unità"<<endl;
				break;
			case 4:
				cout<<"chiusura programma in corso"<<endl;
				break;
			default:
				cout<<"errore nell'inserimento del percorso, selezionare un'altra variabile"<<endl;
				break;
		}
	} 
	while (ch!=4);
	system ("pause");
	return 0;
}
