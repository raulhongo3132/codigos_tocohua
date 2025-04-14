#include <iostream>
#include <locale.h>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;
void cabecera();
void imprimimirSistemaEcuaciones(float a[4][4], float b[4], int op);
void crearMatriz();
void jacobi(float a[4][4], float b[4], int z);


int main(){
	setlocale(LC_ALL,"");
	int op;
	cabecera();
	crearMatriz();
	return 0;
}

void cabecera(){
	cout<<endl<<endl<<"\t\tPrograma que resuelve un sistema de ecuaciones lineales de orden 3 x 3, ";
	cout<<endl<<endl<<"\t\ta partir de la forma general estandar: ";
	cout<<endl<<"\t\ta11x1 + a12x2 + a1nxn = b1  --- ( 1 )";
	cout<<endl<<"\t\ta21x1 + a22x2 + a2nxn = b2  --- ( 2 )";
	cout<<endl<<"\t\ta31x1 + a32x2 + a33x3 = b3  --- ( 3 )";
	cout<<endl<<"\t\tpor el método de Jacobi, hasta 4 ecuaciones"<<endl;
}
void crearMatriz(){
	float a[4][4];
	float b[4];
	float x;
	char f[]="";
	int z;
	string g;
	do{
		cout<<endl<<endl<<"\t\tDime el tamaño de la ecuación (2x2, 3x3 o 4x4): ";
		cin>>f;
		z=atoi(f);
		if(z<2 or z>4){
			cout<<endl<<endl<<"\t\tValor inválido. Vuelve a intentarlo.";
		}
	}while(z<2 or z>4);
	int i, j, k;
	for (i=0; i<z; i++){
		x=0;
		cout<<endl<<"\t\tPara la ecuación #"<<i+1<<": ";
		for (j=0; j<=z; j++){
			if(j<z){
				cout<<endl<<"\t\tDime el valor de a"<<i+1<<j+1<<": ";
				cin>>g;
				a[i][j]=atof(g.c_str());
			}else{
				cout<<endl<<"\t\tDime el valor de b"<<i+1<<": ";
				cin>>g;
				b[i]=atof(g.c_str());
			}
			if(i!=j){
				x=x+fabs(a[i][j]);
			}
		}
		if(x>=fabs(a[i][i])){
			cout<<endl<<endl<<"\t\tLa ecuación no está en diagonal fuerte";
			i=i-1;
		}
	}
	imprimimirSistemaEcuaciones(a, b, z);
	jacobi(a, b, z);
}

void imprimimirSistemaEcuaciones(float a[4][4], float b[4], int op){
	int i, j;
	cout<<endl<<endl<<"\t\tEl sistemas de ecuaciones es: ";
	for(i=0; i<op; i++){
		cout<<endl<<"\t\t";
		for(j=0; j<=op; j++){
			if(j==0){
				cout<<a[i][j]<<" a"<<i+1<<j+1<<" ";
			}else if(j<op and j>0){
				if(a[i][j]>=0){
					cout<<"+ "<<a[i][j]<<" a"<<i+1<<j+1<<" ";
				}else{
					cout<<"- "<<fabs(a[i][j])<<" a"<<i+1<<j+1<<" ";
				}		
			}else{
				cout<<"= "<<b[i]<<" b"<<i+1;
			}	
		}
	}
}
void jacobi(float a[4][4], float b[4], int z){
	float x1[4], xdf[4], y, ex[4], algo;
	string g;
	int i, j;
	for(i=0; i<z; i++){
		cout<<endl<<endl<<"\t\tDime el valor para x"<<i+1<<": ";
		cin>>g;
		x1[i]=atof(g.c_str());
	}
	do{
		cout<<endl<<endl<<"\t\tDime el valor para la toleranacia: ";
		cin>>g;
		y=atof(g.c_str());
		if (y>=1 or y<=0){
			cout<<endl<<endl<<"\t\tLa tolerancia debe ser menor a 1. ";
		}
	}while (y>=1 or y<=0);
	j=1;
	do{
		algo=0;
		xdf[0]=(b[0]-a[0][1]*x1[1]-a[0][2]*x1[2])/a[0][0];
		xdf[1]=(b[1]-a[1][0]*x1[0]-a[1][2]*x1[2])/a[1][1];
		xdf[2]=(b[2]-a[2][0]*x1[0]-a[2][1]*x1[1])/a[2][2];
		for(i=0; i<z; i++){
			ex[i]=fabs(xdf[i]-x1[i]);
			x1[i]=xdf[i];
		}
		for(i=0; i<z; i++){
			algo=max(algo, ex[i]);
		}
		j++;
	}while(algo>y);
	cout<<endl<<endl<<"\t\tEn "<<j-1<<" iteraciones encontramos que: ";
	cout<<endl<<endl<<"\t\tx1= "<<xdf[0];
	cout<<endl<<endl<<"\t\tx2= "<<xdf[1];
	cout<<endl<<endl<<"\t\tx3= "<<xdf[2];
	
}
