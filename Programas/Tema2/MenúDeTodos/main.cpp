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
	Line16:
	int op;
	cout<<endl<<"=================================";
	cout<<endl<<"Menú principal";
	cout<<endl<<endl<<"1) Método de la bisección";
	cout<<endl<<endl<<"2) Método de la regla falsa";
	cout<<endl<<endl<<"3) Método del punto fijo";
	cout<<endl<<endl<<"4) Método de Newton-Rapson";
	cout<<endl<<endl<<"5) Método de la secante";
	cout<<endl<<endl<<"0) Salir del menú";
	cout<<endl<<endl<<"Seleccione una opción: ";
	cin>>op;
	switch (op){
		case 1:
			cout<<endl<<endl<<"Ingreso al método de la bisección";
			break;
		case 2:
			cout<<endl<<endl<<"Ingreso al método de la regla falsa";
			break;
		case 3:
			cout<<endl<<endl<<"Ingreso al método del punto fijo";
			break;
		case 4:
			cout<<endl<<endl<<"Ingreso al método de Newton-Rapson";
			break;
		case 5:
			cout<<endl<<endl<<"Ingreso al método de la secante";
			break;
		case 0:
			cout<<endl<<endl<<"Bye";
			return 0;
		default:
			cout<<endl<<endl<<"Vuelve a intentarlo";
			goto Line16;
	}
	




}
