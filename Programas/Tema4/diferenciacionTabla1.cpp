#include <iostream>
#include <locale.h>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(){
	char N[]="";
	string g;
	int n, i;
	float a, b, h;
	setlocale(LC_ALL, "");
	cout<<endl<<endl<<"\t\tPrograma que calcula la diferenciación numérica de la tercerra derivada de la función: ";
	cout<<endl<<endl<<"\t\ty=-7.7415x^4-32.805^3-56.813x^2-47.809x-9.7361";
	cout<<endl<<endl<<"\t\tEn un intervalo [a,b]";
	do{
		cout<<endl<<endl<<"\t\tIngrese límite inferior: ";
		cin>>g;
		a=atof(g.c_str());
		cout<<endl<<endl<<"\t\tIngrese límite superior: ";
		cin>>g;
		b=atof(g.c_str());
		if(a>=b){
			cout<<endl<<endl<<"\t\tEl límite superior debe ser mayor a el límite inferior";
		}
	}while(a>=b);
	do{
		cout<<endl<<endl<<"\t\tIngrese el número de puntos a dividir el invervalo:";
		cin>>N;
		n=atoi(N);
		if(n<5){
			cout<<endl<<endl<<"\t\tValor inválido. Debe ser al menos 5. Vuelve a intentarlo.";
		}
	}while(n<5);
	
	float X[n],Y[n],Y1[n],Y2[n],Y3[n];
	h=(b-a)/(n-1);
	for(i=1; i<=n; i++){
		X[i]=a;
		Y[i]=-7.7415*pow(X[i],4)-32.805*pow(X[i],3)-56.813*pow(X[i],2)-47.809*X[i]-9.7361;
		a=a+h;
	}
	// y=-7.7415x^4-32.805^3-56.813x^2-47.809x-9.7361
	h=X[2]-X[1];
	for(i=1; i<=n-1; i++){
		Y1[i]=(Y[i+1]-Y[i])/h;
	}for(i=1; i<=n-2; i++){
		Y2[i]=(Y1[i+1]-Y1[i])/h;
	}for(i=1; i<=n-3; i++){
		Y3[i]=(Y2[i+1]-Y2[i])/h;
	}
	cout<<endl<<endl<<"\t\tLa diferenciación numerica hasta la tercera derivada es: ";
	cout<<endl<<endl<<"\t\tn\t\tX\t\tY\t\tY'\t\tY''\t\tY'''";
	cout<<endl;
	for(i=1; i<=n; i++){
		cout<<endl<<"\t\t"<<i<<"\t\t"<<X[i]<<"\t\t"<<Y[i]<<"\t\t"<<Y1[i]<<"\t\t"<<Y2[i]<<"\t\t"<<Y3[i];
		
	}
	
	
	
	
	return 0;
}
