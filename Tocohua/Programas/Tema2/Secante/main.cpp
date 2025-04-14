#include <iostream>
#include <locale.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL,"");
	cout<<"Valverde Palacios Raul Miguel"<<endl<<"Ingenieria en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnologico  Nacional de Mexico"<<endl<<"Instituto Tecnológico de Iztapalapa"<<endl<<"231080023"<<endl;
	cout<<"===========================================================";
	cout<<endl<<"Programa que calcula la raiz solución de la funcion:"<<char(243) ;
	cout<<endl<<endl<<endl<<"f(x)=-3/4x-71/3-x^3e^0.3x, en un intervalo [a,b])";
	cout<<endl<<endl<<endl<<"Por el metodo de la secánte con una tolerancia variable)";
	cout<<endl<<"==========================================================="<<endl;
	Line15:
	float x1, x2, fx1, fx2, x3, fx3, eA, eRP, aux=0;
	int i=1;
	char op;
	do{
		cout<<endl<<"Dime el valor para x1: ";
		cin>>x1;
		cout<<endl<<"Dime el valor para x2: ";
		cin>>x2;
		fx1=(-3.0/4.0)*x1-(71.0/3.0)-pow(x1,3)*exp(x1*0.3);
		fx2=(-3.0/4.0)*x2-(71.0/3.0)-pow(x2,3)*exp(x2*0.3);
		x3=x1-(((x2-x1)*fx1)/(fx2-fx1));
		fx3=fabs((-3.0/4.0)*x3-(71.0/3.0)-pow(x3,3)*exp(x3*0.3));
		if(x1==x2){
			cout<<endl<<"El valor de x1 y x2 deben ser diferentes";
		}
	}while(x1==x2);
	do{
		cout<<endl<<"Dime el valor para la tolerancia en decimales: ";
		cin>>eA;
		if(eA>1||eA<0){
			cout<<"El valor del error aceptable está incorrecto";
		}
	}while(eA>1||eA<0);
	cout<<endl<<endl<<"Iteración \t x1 \t f(x1) \t x2 \t f(x2) \t x3 \t |f(x3)| \t Error Relativo"<<endl;
	do{
		fx1=(-3.0/4.0)*x1-(71.0/3.0)-pow(x1,3)*exp(x1*0.3);
		fx2=(-3.0/4.0)*x2-(71.0/3.0)-pow(x2,3)*exp(x2*0.3);
		x3=x1-(((x2-x1)*fx1)/(fx2-fx1));
		fx3=fabs((-3.0/4.0)*x3-(71.0/3.0)-pow(x3,3)*exp(x3*0.3));
		eRP=100*fabs((x3-aux)/x3);
		cout<<fixed<<setprecision(4)<<endl<<"\t "<<i<<"\t "<<x1<<"\t "<<fx1<<"\t "<<x2<<"\t "<<fx2<<"\t "<<x3<<"\t "<<fx3<<"\t "<<eRP;
		x1=x2;
		x2=x3;
		aux=x3;
		i++;
	}while(eA<eRP);
	cout<<endl<<endl<<"Resumen: ";
	cout<<endl<<"La raiz solución es "<<x3<<"en la iteración "<<i-1<<"con un error relativo de "<<eRP;
	cout<<endl<<endl<<"¿Desea volver a hacer una busqueda (s/n)?";
	cin>>op;
	if(op=='S'||op=='s'){
		goto Line15;
	}else{
		cout<<endl<<endl<<"Adios";
	}
	return 0;
}
