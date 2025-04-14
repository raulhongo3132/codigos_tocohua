#import <iostream>
#import <locale.h>
#import <math.h>
#include <stdlib.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	char N[]="";
	int n;
	double a, b;
	cout<<endl<<endl<<"\t\tPrograma que calcula la integración numérica de la integración:";
	cout<<endl<<endl<<"\t\t\tf(x)=(3x^2-4x(sen(1.4x^3)^2)/((0.4x+1)^(1/4))"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de Simpson 1/3.";
	cout<<endl<<"\t\t================================================================================="<<endl;
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
		cout<<endl<<"\t\tIngrese el números de rectangulos a dividir el intervalo: ";
		cin>>N;
		n=atoi(N);
		if(n<5 || n%2!=0){
			cout<<endl<<"\t\tValor inválido, ingrese un valor mayor a 5 y par.";
		}
	}while(n<5 || n%2!=0);
	double y[n+1], c, a1=0, a2=0, a3=0, total, h;
	int i;
	c=a;
	h=(b-a)/n;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\ta1\t\ta2\t\ta3";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=((3*pow(c,2))-(4*c)*pow(sin(1.4*pow(c,3)),2))/pow((0.4*pow(c,2)+1),0.25);
		if(i==0 || i==n){
			a1=a1+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<y[i]<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%2!=0){
			a2=a2+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<y[i]<<"\t\t"<<0;
		}else{
			a3=a3+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<y[i];
		}
		c=c+h;
	}
	a1=a1*h*(1.0/3.0);
	a2=(1.0/3.0)*4*h*a2;
	a3=(1.0/3.0)*2*h*a3;
	total=a1+a2+a3;
	float guardar=total;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\tDiferencia de áreas= "<<total;
	
	c=a;
	
	
	a1=0;
	a2=0;
	a3=0;
	total=0;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\tabs(a1)\t\tabs(a2)\t\tabs(a3)";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=((3*pow(c,2))-(4*c)*pow(sin(1.4*pow(c,3)),2))/pow((0.4*pow(c,2)+1),0.25);
		if(i==0 || i==n){
			a1=a1+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<fabs(y[i])<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%2!=0){
			a2=a2+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<fabs(y[i])<<"\t\t"<<0;
		}else{
			a3=a3+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<fabs(y[i]);
		}
		c=c+h;
	}
	a1=a1*h*(1.0/3.0);
	a2=(1.0/3.0)*4*h*a2;
	a3=(1.0/3.0)*2*h*a3;
	total=a1+a2+a3;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\tÁrea real= "<<total;
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tResumen: ";
	cout<<endl<<"\t\tDiferencia de áreas= "<<guardar;
	cout<<endl<<"\t\tÁrea real= "<<total;
	cout<<endl<<endl<<"\t\t=================================================================================";
	
}
