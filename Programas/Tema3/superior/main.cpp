#import <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(){
	int i, j, k, n, aux1, aux2;
	string N; 
	float detA=1, factor, pivote, inverso;
	
	setlocale(LC_ALL,"");
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tDeterminante de Orden Superior";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. 231080023";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
	cout<<endl<<endl<<"\t\tPrograma que que calcula el determinante de una matriz de orden n x n: ";
	cout<<endl<<endl<<"\t\tpor reducción de filas"<<endl<<endl;
	cout<<endl<<endl<<"=================================================================================="<<endl;
	LineIngrese:
	do{
		cout<<endl<<endl<<"\t\tIngrese el orden o tamaño de la matriz A n x n: ";
		cin>>n;
		//n=atoi(N);
		if(n>30 or n<3){
			cout<<endl<<endl<<"\t\tMatriz fuera de rango o tamaño. Ingrese otro orden."<<endl<<endl;
			goto LineIngrese;
		}
	}while(n>30 or n<3);
	float A[n][n];
	for(i=1; i<=n;i++){
		for(j=1; j<=n;j++){
			cout<<endl<<endl<<"\t\tIngrese el el valor a"<<i<<j<<": ";
			cin>>A[i][j];
		}
	}
	
	while(A[1][1]==0){
		for(i=1;i<n;i++){
			for(j=1;j<=n;j++){
				aux1=A[i][j];
				A[i][j]=A[i+1][j];
				A[i+1][j]=aux1;				
			}
		}
	}
	cout<<endl<<endl<<"\t\tLa matriz que lleno es: "<<endl<<endl;
	//Agregar una opción para corregir un elemento;
	for(i=1; i<=n;i++){
		cout<<"\t\t| ";
		for(j=1; j<=n;j++){
			cout<<" "<<A[i][j];
		}
		cout<<" |"<<endl;
	}
	
	for(i=1; i<=n; i++){
		pivote=A[i][i];
		for(j=i+1;j<=n;j++){
			inverso=-1*A[j][i];
			factor=inverso/pivote;
			for(k=1;k<=n;k++){
				A[j][k]=A[j][k]+factor;
			}
		}
	}
	
	for(i=1; i<=n; i++){
		detA=detA*A[i][i];
	}
	cout<<endl<<detA<<endl;
	for(i=1; i<=n;i++){
		cout<<"\t\t| ";
		for(j=1; j<=n;j++){
			cout<<" "<<A[i][j];
		}
		cout<<" |"<<endl;
	}
	return 0;
}
