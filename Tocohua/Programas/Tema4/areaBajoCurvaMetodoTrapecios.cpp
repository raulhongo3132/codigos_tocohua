#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	char N[]="";
	int n, j;
	float a, b, h;
	cout<<endl<<endl<<"\t\tPrograma que calcula la integración numérica de la integración:";
	cout<<endl<<endl<<"\t\t\tf(x)=(20cos((5/2)(x^2)+1))/((x^2)+2)"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de trapecios.";
	cout<<endl<<"\t\tPara diferencia de áreas y para área real.";
	cout<<endl<<"\t\t======================================================================"<<endl;
	do{
		cout<<endl<<"\t\tIngrese el valor del límite inferior: ";
		cin>>a;
		cout<<endl<<"\t\tIngrese el valor del límite superior: ";
		cin>>b;
		if(a>=b){
			cout<<endl<<"\t\tEl límire superior debe ser mayor al inferior.";
		}
	}while(a>=b);
	do{
		cout<<endl<<"\t\tIngrese el números de trapecios a dividir el intervalo: ";
		cin>>N;
		n=atoi(N);
	}while(n<5);
	float x[n+1], y[n+1], ai[n], ad[n], sumai=0, sumad=0, df, ar;
	h=(b-a)/(n);
	cout<<endl<<h<<endl;
	for(j=0; j<=n; j++){
		x[j]=a;
		y[j]=(20.0*cos((5.0/2.0)*pow(x[j],2)+1.0))/(pow(x[j],2)+2.0);
		a=a+h;
	}
	float sumat=0, sumae=0;
	for(j=0; j<=n; j++){
		if(j==0 or j==n){
			sumae=sumae+(y[j]);
		}else{
			sumat=sumat+(y[j]);
		}	
	}
	float da=((sumae/2)*h)+(sumat*h);
	cout<<endl<<"\t\tLa diferencia de áreas con trapecios es: ";
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t=================================";
		cout<<endl<<"\t\tIteración: "<<j+1;
		cout<<endl<<"\t\tx: "<<x[j];
		cout<<endl<<"\t\ty: "<<y[j];
	}
	cout<<endl<<"\t\t================================="<<endl;
	cout<<endl<<"\t\tLa diferencia de áreas con trapecios: "<<da<<" unidades cuadradas.";
	cout<<endl;
	sumat=0;
	sumae=0;
	for(j=0; j<=n; j++){
		if(j==0 or j==n){
			sumae=sumae+fabs(y[j]);
		}else{
			sumat=sumat+fabs(y[j]);
		}	
	}
	ar=((sumae/2)*h)+(sumat*h);
	cout<<endl<<"\t\tEl área con trapecios: "<<ar<<" unidades cuadradas."<<endl<<endl<<endl;
	return 0;
}
