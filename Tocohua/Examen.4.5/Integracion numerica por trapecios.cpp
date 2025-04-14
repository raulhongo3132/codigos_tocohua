#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	char N[]="";
	int n, j;
	string g;
	float a, b, h;
	cout<<endl<<endl<<"\t\tPrograma que calcula	 la integración numérica de la función:";
	cout<<endl<<endl<<"\t\t\tf(x)=-0.2x^6+1.4x^2+0.8x+6"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de trapecios.";
	cout<<endl<<"\t\tPara diferencia de áreas y para área real.";
	cout<<endl<<"\t\t======================================================================"<<endl;
	do{
		cout<<endl<<"\t\tIngrese el valor del límite inferior: ";
		cin>>g;
        a=atof(g.c_str());
		cout<<endl<<"\t\tIngrese el valor del límite superior: ";
		cin>>g;
        b=atof(g.c_str());
		if(a>=b){
			cout<<endl<<"\t\tEl límire superior debe ser mayor al inferior.";
		}
	}while(a>=b);
	do{
		cout<<endl<<"\t\tIngrese el números de rectangulos a dividir el intervalo: ";
		cin>>N;
		n=atoi(N);
		if(n<5){
			cout<<endl<<"\t\tValor inválido. Debe ser por lo menos 5";
		}
	}while(n<5);
	float x[n+1], y[n+1], ai[n], ad[n], df, ar;
	h=(b-a)/(n);
	for(j=0; j<=n; j++){
		x[j]=a;
		y[j]=-0.2*pow(x[j],6)+1.4*pow(x[j],2)+0.8*x[j]+6;
		a=a+h;
	}
	float sumat=0, sumae=0;
	for(j=0; j<=n; j++){
		if(j==0 or j==n){
			sumae=sumae+y[j];
		}else{
			sumat=sumat+y[j];
		}	
	}
	df=((sumae/2)*h)+(sumat*h);
	cout<<endl<<"\t\tLa diferencia con trapecios es: ";
	cout<<endl<<"\t\tIteración\t\tx\t\ty\t\tExtremos\t\tInternos";
	cout<<endl<<"\t\t========================================================================";
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t"<<j+1<<"\t\t"<<x[j]<<"\t\t"<<y[j]<<"\t\t";
		if(j==0 || j==n){
			cout<<y[j]<<"\t\t"<<0;
		}else{
			cout<<0<<"\t\t"<<y[j];
		}
	}
	cout<<endl<<endl<<"\t\tLos trapecios extremos son "<<sumae<<" unidades cuadradas.";
	cout<<endl<<"\t\tLos trapecios internos son "<<sumat<<" unidades cuadradas.";
	cout<<endl<<"\t\tLa diferencia con trapecios: "<<df<<" unidades cuadradas.";
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
	cout<<endl<<endl<<"\t\t========================================================================";
	cout<<endl<<endl<<"\t\tEl área con trapecios es: ";
	cout<<endl<<"\t\tIteración\t\tx\t\ty\t\tExtremos\t\tInternos";
	cout<<endl<<"\t\t======================================================================-=";
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t"<<j+1<<"\t\t"<<x[j]<<"\t\t"<<y[j]<<"\t\t";
		if(j==0 || j==n){
			cout<<fabs(y[j])<<"\t\t"<<0;
		}else{
			cout<<0<<"\t\t"<<fabs(y[j])	;
		}
	}
	cout<<endl<<endl<<"\t\tLos trapecios extremos son "<<sumae<<" unidades cuadradas.";
	cout<<endl<<"\t\tLos trapecios internos son "<<sumat<<" unidades cuadradas.";
	cout<<endl<<"\t\tEl área con trapecios: "<<ar<<" unidades cuadradas.";
	cout<<endl<<"\t\t=======================================================================";
	cout<<endl<<endl<<"\t\tResumen: ";
	cout<<endl<<endl<<"\t\tLa diferencia con trapecios: "<<df<<" unidades cuadradas.";
	cout<<endl<<"\t\tEl área con trapecios: "<<ar<<" unidades cuadradas.";
	cout<<endl<<"\t\t=======================================================================";
	return 0;
}
