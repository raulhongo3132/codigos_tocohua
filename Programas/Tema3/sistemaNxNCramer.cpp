#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main(){
	float detA, temp1, temp2, inverso, pivote, factor;
	int i, j, k, n;
	char N[]="";
	setlocale(LC_ALL,"");
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tSitema n x n con Crameer";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. 231080023";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
	cout<<endl<<endl<<"\t\tSistema lineal que resuelve un sistema de ecuaciones lineales de orden n x n, ";
	cout<<endl<<endl<<"\t\tpor el método de determinantes empleando la regla de Cramer. Donde 3<n<30";
	cout<<endl<<endl<<"\t\ta partir de la forma general estandar";
	cout<<endl<<endl<<"\t\ta11x1 + a12x2 + ...  + a1nxn = b1  --- ( 1 )";
	cout<<endl<<endl<<"\t\ta21x1 + a22x2 + ...  + a2nxn = b2  --- ( 2 )";
	cout<<endl<<endl<<"\t\t ...  + ...   + ...  +  ...  = ... --- (...)";
	cout<<endl<<endl<<"\t\tan1x1 + an2x2 + ...  + annx3 = bn  --- ( n )";
	cout<<endl<<endl;
	cout<<endl<<endl<<"=================================================================================="<<endl;
	do{
		cout<<endl<<endl<<"\t\tIngrese la cantidad de ecuaciones del sistema: ";
		cin>>N;
		n=atoi(N);
		if(n<3 or n>40){
			cout<<endl<<endl<<"\t\tDato invalido (fuera de rango) >:C";
		}
	}while(n<3 or n>40);
	float MC[n][n], D[n], detX[n], RMC[n][n], X[n];
	for(i=0; i<n; i++){
		cout<<endl<<endl<<"\t\tPara la ecuación #"<<i+1<<": ";
		for(j=0; j<n; j++){
			cout<<endl<<"\t\tIngrese el valor de a"<<i+1<<j+1<<": ";
			cin>>MC[i][j];
		}
		cout<<endl<<"\t\tIngrese el valor de b"<<i+1<<": ";
		cin>>D[i];	
	}
	while(MC[0][0]==0){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				temp2=MC[i][j];
				MC[i][j]=MC[i+1][j];	
				MC[i+1][j]=temp2;
				temp1=D[i];
				D[i]=D[i+1];	
				D[i+1]=temp1;
			}	
		}
		
	}
	cout<<endl<<endl;
	cout<<endl<<endl<<"\t\tEl sistema que usted ingresó es: "<<endl<<endl;
	for(i=0; i<n; i++){
		cout<<"	|";
		for(j=0; j<n; j++){
			cout<<" "<<MC[i][j]<<" ";
		}
		cout<<"|	| "<<D[i]<<" |"<<endl;	
	}
	float det=1;
	for(i=0; i<n; i++){
		pivote=-1*MC[i][i];
		for(j=i+1;j<n;j++){
			inverso=MC[j][i];
			factor=inverso/pivote;
			for(k=0;k<n;k++){
				MC[j][k]=MC[j][k]+MC[i][k]*factor;
			}
		}
	}
	for(i=0; i<n; i++){
		det=det*MC[i][i];
	}
	cout<<endl<<endl;
	for(i=0; i<n; i++){
		cout<<"	|";
		for(j=0; j<n; j++){
			cout<<" "<<MC[i][j]<<" ";
		}
		cout<<"|	| "<<D[i]<<" |"<<endl;	
	}
	cout<<endl<<det<<endl;
	
	cout<<endl<<endl;
	return 0;
}
