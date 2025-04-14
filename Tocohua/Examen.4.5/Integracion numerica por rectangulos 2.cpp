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
	cout<<endl<<endl<<"\t\tPrograma que calcula la integración numérica de la función:";
	cout<<endl<<"\tf(x)=(3x^2-4x(sen(1.4x^3)^2)/((0.4x+1)^(1/4))";
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de rectangulos.";
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
	}while(n<5);
	float x[n+1], y[n+1], ai[n], ad[n], sumai=0, sumad=0, df, ar;
	h=(b-a)/(n);
	cout<<endl<<h<<endl;
	for(j=0; j<=n; j++){
		x[j]=a;
		y[j]=((3 * pow(x[j], 2)) - (4 * x[j]) * pow(sin(1.4 * pow(x[j], 3)), 2)) / pow((0.4 * pow(x[j], 2) + 1), 0.25);
		a=a+h;
	}
	for(j=0; j<n; j++){
		ai[j]=h*y[j];
		sumai=sumai+ai[j];
	}
	for(j=1; j<=n; j++){
		ad[j]=h*y[j];
		sumad=sumad+ad[j];
	}
	df=(sumai+sumad)/2;
	cout<<endl<<"\t\tLa dieferencia de areas es: ";
	cout<<endl<<"\t\ttIteración\t\tx\t\ty\t\tarea a izq\t\tarea a der";
	cout<<endl<<"\t\t================================================================================";
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t"<<j+1<<"\t\t"<<x[j]<<"\t\t"<<y[j];
		if(j==0){
			cout<<"\t\t"<<ai[j]<<"\t\t"<<0;
		}else if(j==n){
			cout<<"\t\t"<<0<<"\t\t"<<ad[j];
		}else{
			cout<<"\t\t"<<ai[j]<<"\t\t"<<ad[j];
		}
	}
	cout<<endl<<endl<<"\t\tDiferencia de área: "<<df<<" unidades caudradas."<<endl<<endl;
	sumai=0;
	sumad=0;
	for(j=0; j<=n; j++){
		ai[j]=h*fabs(y[j]);
		sumai=sumai+ai[j];
	}
	for(j=1; j<n; j++){
		ad[j]=h*fabs(y[j]);
		sumad=sumad+ad[j];
	}
	ar=(sumai+sumad)/2;
	cout<<endl<<"\t\tEl área real es: ";
	cout<<endl<<"\t\ttIteración\t\tx\t\ty\t\tarea a izq\t\tarea a der";
	cout<<endl<<"\t\t================================================================================";
	
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t"<<j+1<<"\t\t"<<x[j]<<"\t\t"<<y[j];
		if(j==0){
			cout<<"\t\t"<<fabs(ai[j])<<"\t\t"<<0;
		}else if(j==n){
			cout<<"\t\t"<<0<<"\t\t"<<fabs(ad[j]);
		}else{
			cout<<"\t\t"<<fabs(ai[j])<<"\t\t"<<fabs(ad[j]);
		}
	}
	cout<<endl<<endl<<"\t\tEl área real: "<<ar<<" unidades cuadradas."<<endl<<endl;
	cout<<endl<<"\t\t================================================================================";
	cout<<endl<<endl<<"\t\tResumen: ";
	cout<<endl<<endl<<"\t\tDiferencia de área: "<<df<<" unidades caudradas.";
	cout<<endl<<endl<<"\t\tEl área real: "<<ar<<" unidades cuadradas."<<endl<<endl;
	return 0;
}
