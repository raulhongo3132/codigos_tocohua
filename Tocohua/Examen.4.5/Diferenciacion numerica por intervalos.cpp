#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

int main(){
	char N[]="";
	int n, i;
	float a, b;
	string g;
	setlocale(LC_ALL, "");
	cout<<endl<<endl<<"\tPrograma que emplea la diferenciación numérica para calcular la primera, segunda";
	cout<<endl<<"\ty tercera derivada en un intervalo cerrado [-2,3] con 'n' valores para la función:";
	cout<<endl<<"\tf(x)=(3x^2-4x(sen(1.4x^3)^2)/((0.4x+1)^(1/4))";
	do{
		cout<<endl<<endl<<"\tIngrese el número de datos a ingresar: ";
		cin>>N;
		n=atoi(N);
		if(n<3){
			cout<<endl<<endl<<"\tValor inválido. Debe ser al menos 3. Vuelve a intentarlo.";
		}
	}while(n<3);
	do{
		cout<<endl<<endl<<"\tIngrese el límite inferior [a]: ";
		cin>>g;
        a=atof(g.c_str());
        cout<<endl<<endl<<"\tIngrese el límite superior [b]: ";
		cin>>g;
        b=atof(g.c_str());
		if(a>b){
			cout<<endl<<endl<<"\tValores inválido. [a] debe ser menos a [b]. Vuelve a intentarlo.";
		}
	}while(a>b);
	float X[n], Y[n], Y1[n-1], Y2[n-2], Y3[n-2], h;
	h=(b-a)/(n-1);
	for(i=0; i<n; i++){
		X[i]=a;
		a+=h;
		Y[i]=((3 * pow(X[i], 2)) - (4 * X[i]) * pow(sin(1.4 * pow(X[i], 3)), 2)) / pow((0.4 * pow(X[i], 2) + 1), 0.25);
	}
	for(i=0; i<n-1; i++){
		Y1[i]=(Y[i+1]-Y[i])/(X[i+1]-X[i]);
	}for(i=0; i<n-2; i++){
		Y2[i]=(Y1[i+1]-Y1[i])/(X[i+1]-X[i]);
	}for(i=0; i<n-3; i++){
		Y3[i]=(Y2[i+1]-Y2[i])/(X[i+1]-X[i]);
	}
	cout<<endl<<endl<<"\tLa diferenciación numerica hasta la tercera derivada es: ";
	cout<<endl<<endl<<"\tn\t\tX\t\tY\t\tY'\t\tY''\t\tY'''";
	cout<<endl;
	for(i=0; i<n; i++){
		cout<<endl<<"\t"<<i+1<<"\t\t"<<X[i]<<"\t\t"<<Y[i];
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
