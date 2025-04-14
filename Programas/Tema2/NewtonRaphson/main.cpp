#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	system("color b1");
	setlocale(LC_ALL,"");
	cout<<"Valverde Palacios Raúl Miguel"<<endl<<"Ingeniería en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnológico  Nacional de México"<<endl<<"Instituto Tecnólogico de Iztapalapa"<<endl<<"231080023"<<endl;
	cout<<"===========================================================";
	cout<<endl<<"Programa que calcula la raiz solución de la función:";
	cout<<endl<<endl<<"f(x)=-3/4x-71/3-x^3e^0.3x";
	cout<<endl<<endl<<"Por el método de Newton-Raphson";
	cout<<endl<<endl<<"Con valor inicial y con una tolerancia variable.";
	cout<<endl<<"==========================================================="<<endl;
	float xi, fxi, fpxi, xr, fxr, ea, er, aux=0;
	int k=1;
	char resp;
	Line19:
	do{
		cout<<endl<<"Dime el valor inicial: ";
		cin>>xi;
		fpxi=(-3.0/4.0)-(0.3*pow(xi,3)*exp(0.3*xi))-(3*pow(xi,2)*exp(0.3*xi));
		if(fpxi==0){
			cout<<"Ingrese otro valor para xi";
		}
	}while(fpxi==0);
	do{
		cout<<endl<<"Ingresa el error aceptado en decimales: ";
		cin>>ea;
		if(ea>1 or ea<0){
			cout<<"Ingrese otro valor para el error aceptado";
		}
	}while(ea>1 or ea<0);
	cout<<endl<<"Iteraciones\t\txi\t\tf(xi)\t\tf'(xi)\t\txr\t\t|f(xr)|\t\tError absoluto"<<endl;
	
	do{
		fxi=-3.0/4.0*xi-71.0/3.0-pow(xi,3)*exp(0.3*xi);
		fpxi=(-3.0/4.0)-(0.3*pow(xi,3)*exp(0.3*xi))-(3*pow(xi,2)*exp(0.3*xi));
		xr=xi-(fxi/fpxi);
		fxr=fabs(-3.0/4.0*xr-(71.0/3.0)-pow(xr,3)*exp(0.3*xr));
		er=100*fabs((xr-aux)/xr);
		cout<<endl<<"\t"<<k<<"\t\t"<<xi<<"\t\t"<<fxi<<"\t"<<fpxi<<"\t"<<xr<<"\t\t"<<fxr<<"\t\t"<<er<<endl;
		if(fxr==0){
			cout<<endl<<"Se encontró la raíz solución"<<endl;
		}else{
			aux=xr;
			xi=xr;
			
		}
		k++;
	}while(ea<=er);
	cout<<endl<<"\t\t=====================================";
	cout<<endl<<"\t\tResumen:"<<endl;
	cout<<endl<<"\t\tLa raiz solución es:"<<xr<<endl;
	cout<<endl<<"\t\tcon "<<k-1<<" iteraciones, con un error del"<<er<<endl;
	cout<<endl<<"\t\t====================================="<<endl;
	cout<<endl<<"\t\t¿Desea ejecutar de nuevo el programa?(S/N): ";
	cin>>resp;
	if(resp=='S'||resp=='s'){
		goto Line19;
	}else{
		cout<<endl<<"\t\tBye";
	}
	return 0;
}
