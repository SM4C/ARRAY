//riempire in una matrice quadrata MAT[r][r] (con r<=20) di numeri interi
//- calcolare e visualizzare la somma della diagonale principale
//- riempire un vettore inserendo negli elementi le somme degli elementi delle colonne corrispondendi della matrice; visualizzare gli elementi di tale vettore in ordine crescente

#include <iostream>
using namespace std;
int main()
{
	int ray, sc;
	do
	{
		cout<<"Dimensioni della matrice quadrata (<=20) ";
		cin>>ray;	
	}
	while (ray>20);
	int QuadraticArray[ray][ray], VirtualSum, SumVet[ray];
	for (int i=0; i<ray; i++)
	{
		for (int j=0; j<ray; j++)
		{
			cout<<"Elemento= ";
			cin>>QuadraticArray[i][j];
		}
	}
	do
	{
		cout<<endl;
		cout<<"1. Somma della diagonale principale"<<endl;
		cout<<"2. Vettore con le somme degli elementi di ogni colonna"<<endl;
		cout<<"3. Somma della diagonale secondaria"<<endl;
		cout<<"4. Fine"<<endl;
		cout<<"Scelta ";
		cin>>sc;
		cout<<endl;
		switch (sc)
		{
			case 1:
				VirtualSum=0;
				for (int i=0; i<ray; i++)
				{
					VirtualSum=VirtualSum+QuadraticArray[i][i];
				}
				cout<<"Somma della diagonale = "<<VirtualSum<<endl;
				break;
			case 2:
				for (int j=0; j<ray; j++)
				{
					VirtualSum=0;
					for (int i=0; i<0; i++)
					{
						VirtualSum=VirtualSum+QuadraticArray[j][i];
					}
					SumVet[j]=VirtualSum;
				}
				for (int i=0; i<ray; i++)
				{
					cout<<SumVet[i]<<"     ";
				}
				break;
			case 3:
				VirtualSum=0;
				for (int i=0; i<ray; i++)
					{
						VirtualSum=VirtualSum+QuadraticArray[i][ray-i-1];
					}
				cout<<"Somma della diagonale = "<<VirtualSum<<endl;
				break;
			case 4:
				cout<<"Fine"<<endl;
				break;
			default:
				cout<<"Errore"<<endl;	
				break;
			}
		}
	while (sc!=3);
	//system ("pause");
	return 0;
}
