#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	char N[]="";
	int n, i;
	string g;
	setlocale(LC_ALL, "");
	cout<<endl<<endl<<"\t\tPrograma que calcula la diferenciación numérica de un conjunto de datos.";
	do{
		cout<<endl<<endl<<"\t\tIngrese el número de datos a ingresar: ";
		cin>>N;
		n=atoi(N);
		if(n<3){
			cout<<endl<<endl<<"\t\tValor inválido. Debe ser al menos 3. Vuelve a intentarlo.";
		}
	}while(n<3);
	float X[n], Y[n], Y1[n], Y2[n], Y3[n];
	for(i=0; i<n; i++){
		cout<<endl<<endl<<"\t\tDime el "<<i+1<<"° valor de X: ";
		cin>>g;
        X[i]=atof(g.c_str());
        cout<<endl<<endl<<"\t\tDime el "<<i+1<<"° valor de Y: ";
		cin>>g;
        Y[i]=atof(g.c_str());
	}
	for(i=0; i<n-1; i++){
		Y1[i]=(Y[i+1]-Y[i])/(X[i+1]-X[i]);
	}for(i=0; i<n-2; i++){
		Y2[i]=(Y1[i+1]-Y1[i])/(X[i+1]-X[i]);
	}for(i=0; i<n-3; i++){
		Y3[i]=(Y2[i+1]-Y2[i])/(X[i+1]-X[i]);
	}
	cout<<endl<<endl<<"\t\tLa diferenciación numerica hasta la tercera derivada es: ";
	cout<<endl<<endl<<"\t\tn\t\tX\t\tY\t\tY'\t\tY''\t\tY'''";
	cout<<endl;
	for(i=0; i<n; i++){
		cout<<endl<<"\t\t"<<i+1<<"\t\t"<<X[i]<<"\t\t"<<Y[i];
		if(i==n-3){
			cout<<"\t\t"<<Y1[i]<<"\t\t"<<Y2[i];
		}else if(i==n-2){
			cout<<"\t\t"<<Y1[i];
		}else if(i<n-3){
			cout<<"\t\t"<<Y1[i]<<"\t\t"<<Y2[i]<<"\t\t"<<Y3[i];
		}
			
		
	}
	return 0;
}
