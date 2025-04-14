#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main() {
	float xi, uxi, wxi, wpxi, eA;
	int k=1;
	system("color b1");
	setlocale(LC_ALL,"");
	cout<<"Valverde Palacios Raúl Miguel"<<endl<<"Ingeniería en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnológico  Nacional de México"<<endl<<"Instituto Tecnólogico de Iztapalapa"<<endl<<"231080023"<<endl;
	cout<<"===========================================================";
	cout<<endl<<"Programa que calcula la raiz solución de la función:";
	cout<<endl<<endl<<"f(x)=-3/4x-71/3-x^3e^0.3x";
	cout<<endl<<endl<<"Por el método de punto fijo con una tolerancia variable";
	cout<<endl<<endl<<"Con valor xi y con una tolerancia variable.";
	cout<<endl<<"==========================================================="<<endl;
	do{
		cout<<endl<<"Ingrese el valor inicial para xi: ";
		cin>>xi;
		wpxi=(1.0/120.0)*((942.0*xi*exp((xi*-3.0)/10.0)+27.0*pow(xi,2)*exp((xi*-3.0)/10.0)+5680*exp((xi*-3.0)/10.0))/pow(xi,3));
		cout<<endl<<wpxi<<endl;
	}while(fabs(wpxi)>1);
	do{
		cout<<endl<<"Ingrese el valor de la tolerancia en decimales:";
		cin>>eA;
	}while(eA>=1 and eA<0);
	cout<<endl<<"\t\tIteraciones\t\txi\t\tu(xi)\t\tw(xi)\t\tError absoluto"<<endl;
	do{
		uxi=xi;
		wxi=pow(xi,-2)*exp(-xi*0.3)*(-0.75*xi-(71.0/3.0));
		cout<<endl<<"\t\t"<<k<<"\t\t"<<xi<<"\t\t"<<uxi<<"\t\t"<<wxi<<"\t\t"<<fabs(xi-wxi)<<endl;
		k++;
		xi=wxi;
	}while(fabs(uxi-wxi)>eA);
	cout<<endl<<"Se encontró la raíz solución";
	
	return 0;
}
