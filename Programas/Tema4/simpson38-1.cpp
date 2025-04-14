#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	char N[]="";
	int n;
	double a, b, c;
	cout<<endl<<endl<<"\t\tPrograma que calcula la integración numérica de la integración:";
	cout<<endl<<endl<<"\t\t\tf(x)=(20*x*(cos((5/2)*x^2)+1)/((x^2)+2)"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de Simpson 3/8.";
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
		if(n<5 || n%3!=0){
			cout<<endl<<"\t\tValor inválido, ingrese un valor mayor a 5 y multiplo natural de 3.";
		}
	}while(n<5 || n%3!=0);
	double y[n+1], a1=0, a2=0, a3=0, a4=0, total, h;
	int i;
	c=a;
	h=(b-a)/n;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\tY";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=(20*cos((5.0/2.0)*pow(c,2)+1))/(pow(c,2)+2);
		if(i==0 || i==n){
			a1=a1+y[i];
		}else if(i>0 and i<n and i%3==1){
			a2=a2+y[i];
		}else if(i>0 and i<n and i%3==2){
			a3=a3+y[i];
		}else{
			a4=a4+y[i];
		}
		cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<y[i];
		c=c+h;
	}
	a1=(3.0/8.0)*h*a1;
	a2=(9.0/8.0)*h*a2;
	a3=(9.0/8.0)*h*a3;
	a4=(3.0/4.0)*h*a4;
	total=a1+a2+a3+a4;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\ta3= "<<a4;
	cout<<endl<<"\t\tDiferencia de áreas= "<<total;
	
	c=a;
	a1=0;
	a2=0;
	a3=0;
	a4=0;
	total=0;
	float x=0;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\ta1\t\ta2\t\ta3\t\ta4";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=(20*cos((5.0/2.0)*pow(c,2)+1))/(pow(c,2)+2);
		if(i==0 || i==n){
			a1=a1+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<y[i]<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==1){
			a2=a2+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<y[i]<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==2){
			a3=a3+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<y[i]<<"\t\t"<<0;
		}else{
			a4=a4+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<y[i];
			x+=fabs(y[i]);
		}
		c=c+h;
	}
	a1=(3.0/8.0)*h*a1;
	a2=(9.0/8.0)*h*a2;
	a3=(9.0/8.0)*h*a3;
	a4=(3.0/4.0)*h*a4;
	total=a1+a2+a3+a4;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\ta4= "<<a4;
	cout<<endl<<"\t\tÁrea real= "<<total;
	
}
