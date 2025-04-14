#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
	float a, fa, b, fb, rF, fRF, eA, eR, aux=0;
	int i=1;
	cout<<"Valverde Palacios Raul Miguel"<<endl<<"Ingenieria en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnologico  Nacional de Mexico"<<endl<<"Instituto Tecnológico de Iztapalapa"<<endl<<"231080023"<<endl;
	cout<<"===========================================================";
	cout<<endl<<"Programa que calcula la raiz solución de la funcion:"<<char(243) ;
	cout<<endl<<endl<<endl<<"f(x)=-3/4x-71/3-x^3e^0.3x, en un intervalo [a,b])";
	cout<<endl<<endl<<endl<<"Por el metodo de la bisescción con una tolerancia variable)";
	cout<<endl<<"==========================================================="<<endl;
	L13:
	do{
		cout<<"Ingresa el limite inferior [a]: ";
		cin>>a;
		cout<<"Ingresa el limite superior [b]: ";
		cin>>b;
		if(a>=b){
			cout<<"El valor de a debe ser menor que b"<<endl;
		}
	}while(a>=b);
	
	if(fa*fb>0){
		cout<<"No hay función raíz en este intervalo";
		goto L13;
	}
	
	do{
		cout<<endl<<"Dime el error admitido (tolerancia): ";
		cin>>eA;
		if(eA<0||eA>=1){
			cout<<"La tolerancia debe ser mayor a 0"<<endl;
		}
	}while(eA<0||eA>=1);
	do{
		fa=-((3.0/4.0)*a)-(71.0/3.0)-pow(a,3)*exp(a*0.3);
		fb=-((3.0/4.0)*b)-(71.0/3.0)-pow(b,3)*exp(b*0.3);
		rF=a-((fa*(b-a))/(fb-fa));
		fRF=((-3.0/4.0)*rF)-(71.0/3.0)-(pow(rF,3)*exp(0.3*rF));
		eR=100*fabs((rF-aux)/rF);
		cout<<endl<<"==== Iteración #"<<i<<" ===="<<endl;
		cout<<"Limite inferior: "<<a<<endl;
		cout<<"Funcion del limite inferior: "<<fa<<endl;
		cout<<"Limite superior: "<<b<<endl;
		cout<<"Funcion del limite superior: "<<fb<<endl;
		cout<<"La refla falsa: "<<rF<<endl;
		cout<<"Funcion de la refla falsa: "<<fRF<<endl;
		cout<<"Error relativo: "<<eR<<endl;
		if(fa*fRF<0){
			b=rF;
		}else{
			a=rF;
		}
		aux=rF;
		i++;
		
		
		
	}while(eR>eA);
	
	
	
	
	return 0;
}
