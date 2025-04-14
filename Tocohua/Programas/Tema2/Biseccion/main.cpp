#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float a, b, fa, fb, Xm, fXm, ER, aux=0, tol;
	int j=1;
	cout<<"Valverde Palacios Raul Miguel"<<endl<<"Ingenieria en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnologico  Nacional de Mexico"<<endl<<"Instituto Tecnológico de Iztapalapa"<<endl<<"231080023"<<endl;
	cout<<"===========================================================";
	cout<<endl<<"Programa que calcula la raiz solucion de la funcion:"<<char(243) ;
	cout<<endl<<endl<<endl<<"f(x)=-3/4x-71/3-x^3e^0.3x, en un intervalo [a,b])";
	cout<<endl<<endl<<endl<<"Por el metodo de la bisescción con una tolerancia variable)";
	cout<<endl<<"==========================================================="<<endl;
	do{
		cout<<endl<<"Ingrese el valor inicial o límite inferior[a]: ";
		cin>>a;
		cout<<"Ingrese el valor final o límite superior[b]: ";
		cin>>b;
		if (a>=b){
			cout<<endl<<"El valor de a no debe ser mayor que b."<<endl;
		}
	}while(a>=b);
	do{
		cout<<endl<<"Ingrese la tolerancia: ";
		cin>>tol;
	}while(tol<=0);
	do{
		cout<<endl<<endl<<"I T E R A C I O N #"<<j;
		fa=(-(3.0/4.0)*a)-(71.0/3.0)-(pow(a,3)*exp(0.3*a));
		fb=(-(3.0/4.0)*b)-(71.0/3.0)-(pow(b,3)*exp(0.3*b));
		Xm=(a+b)/2.0;
		fXm=((-3.0/4.0)*Xm)-(71.0/3.0)-(pow(Xm,3)*exp(0.3*Xm));
		if(Xm==0){
			cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
			return 0;
		}
		ER=100*fabs((Xm-aux)/Xm);
		
		cout<<endl<<"a="<<a;
		cout<<endl<<"f(a)="<<fa;
		cout<<endl<<"b="<<b;
		cout<<endl<<"f(b)="<<fb;
		cout<<endl<<"Xm="<<Xm;
		cout<<endl<<"f(Xm)="<<fXm;
		cout<<endl<<"ER="<<ER;
		
		if(fa*fXm<0){
			a=a;
			b=Xm;	
		}else{
			a=Xm;
			b=b;
		}
		aux=Xm;
		j++;
	}while(ER>tol);
	
}
