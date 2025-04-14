#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	float x1, y1, x2, y2, m, b;
	char N[]="";
	string g;
	setlocale(LC_ALL, "");
	cout<<endl<<endl<<"\t\tPrograma que calcula el modelo de interpolación lineal e interpola diferentes valores.";
	cout<<endl<<endl;
	do{
		cout<<endl<<"\t\tIngrese el valor de x1: ";
		cin>>g;
		x1=atof(g.c_str());
		cout<<endl<<"\t\tIngrese el valor de y1: ";
		cin>>g;
		y1=atof(g.c_str());
		cout<<endl<<"\t\tIngrese el valor de x2: ";
		cin>>g;
		x2=atof(g.c_str());
		cout<<endl<<"\t\tIngrese el valor de y2: ";
		cin>>g;
		y2=atof(g.c_str());
		if(x1==x2){
			cout<<endl<<"\t\tNo es posible encontrar el modelo de interpolación lineal.";
		}
		if(y1==y2){
			cout<<endl<<"\t\tEl modelo de interpolación linea es constante.";
			cout<<endl<<"\t\ty = "<<y1;
			b=-m*x1+y1;
			if(b>0){
				cout<<"x + "<<b;
			}else{
				if(b==0){
					cout<<"x ";
				}else{
					cout<<"x - "<<b*-1;
				}	
			}
			return 0;
		}
	}while(x1==x2);
	
	m=(y2-y1)/(x2-x1);
	b=-m*x1+y1;
	
	cout<<endl<<"\t\tEl modelo de interpolación lineal es:"<<endl<<endl<<"\t\ty = "<<m;
	
	if(b>0){
		cout<<"x + "<<b;
	}else{
		if(b==0){
			cout<<"x";
		}else{
			cout<<"x - "<<b*-1;
		}	
	}
	int i, n;
	do{
		cout<<endl<<endl<<"\t\tDigame cuantos datos desea interpolar: ";
		cin>>N;
		n=atoi(N);
	}while(n<=1);
	
	float X[n+1], Y[n+1];
	if(x1<x2){
		X[0]=x1;
		Y[0]=y1;
		X[n+1]=x2;
		Y[n+1]=y2;
	}else{
		X[0]=x2;
		Y[0]=y2;
		X[n+1]=x1;
		Y[n+1]=y1;
	}
	int j;
	float x;
	bool vf;
	for(i=1; i<=n; i++){
		do{
			vf=true;
			cout<<endl<<"\t\tIngrese el valor de x"<<i<<" a interpolar: ";
			cin>>g;
			x=atof(g.c_str());
			if(x<X[0] or x>X[n+1]){
				cout<<endl<<"\t\tEste valor no se puede interpolar, no sen encuentra entre "<<X[0]<<" y "<<X[n+1]<<". Vuelve a intentarlo.";
			}else{
				if(x==X[0] or x==X[n+1]){
					cout<<endl<<"\t\tEl valor que ingresasta ya existe. Forma parte de los datos.";
				}else{
					for(j=1; j<i; j++){
						if(x==X[j]){
							cout<<endl<<"\t\tEl valor que ingresasta ya existe. Forma parte de los datos.";
							vf=false;
						}
					}
				}
			}
			X[i]=x;
		}while((x<X[0] or x>X[n+1]) or (x==X[0] or x==X[n+1]) or (vf==false));
	}
	
	cout<<endl<<"\t\tLos valores de la tablas sin ordenar son:"<<endl;
	cout<<endl<<"\t\tx\t|\ty"<<endl<<"\t\t===================";
	for(i=0; i<=n+1; i++){
		if(i>0 or i<=n){
			Y[i]=m*X[i]+b;
		}
		cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
	}
	float auxx, auxy;
	for(i=0; i<=n; i++){
		for(j=0; j<=n; j++){
			if(X[j]>X[j+1]){
				auxx=X[j];
				auxy=Y[j];
				X[j]=X[j+1];
				Y[j]=Y[j+1];
				X[j+1]=auxx;
				Y[j+1]=auxy;	
			}
		}
	}
	cout<<endl<<"\t\tLos valores de la tabla (ya orndenada) son:"<<endl;
	cout<<endl<<"\t\tx\t|\ty"<<endl<<"\t\t===================";
	for(i=0; i<=n+1; i++){
		cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
	}
	
	
	return 0;
}
