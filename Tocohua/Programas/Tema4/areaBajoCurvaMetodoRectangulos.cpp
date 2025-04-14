#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	char N[]="";
	int n, j;
	float a, b, h;
	cout<<endl<<endl<<"\t\tPrograma que calcula la integración numérica de la integración:";
	cout<<endl<<endl<<"\t\t\tf(x)=-0.2x^6+1.4x^2+0.8x+6"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de rectangulos.";
	cout<<endl<<"\t\tPara diferencia de áreas y para área real.";
	cout<<endl<<"\t\t======================================================================"<<endl;
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
	}while(n<5);
	float x[n+1], y[n+1], ai[n], ad[n], sumai=0, sumad=0, df, ar;
	h=(b-a)/(n);
	cout<<endl<<h<<endl;
	for(j=0; j<=n; j++){
		x[j]=a;
		y[j]=-0.2*pow(x[j],6)+1.4*pow(x[j],2)+0.8*x[j]+6;
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
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t=================================";
		cout<<endl<<"\t\tIteración: "<<j+1;
		cout<<endl<<"\t\tx: "<<x[j];
		cout<<endl<<"\t\ty: "<<y[j];
		cout<<endl<<"\t\tai: "<<ai[j];
		cout<<endl<<"\t\tad: "<<ad[j];
	}
	cout<<endl<<"\t\tDiferencia de área: "<<df<<" unidades caudradas."<<endl<<endl;
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
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t=================================";
		cout<<endl<<"\t\tIteración: "<<j+1;
		cout<<endl<<"\t\tx: "<<x[j];
		cout<<endl<<"\t\ty: "<<y[j];
		cout<<endl<<"\t\tai: "<<ai[j];
		cout<<endl<<"\t\tad: "<<ad[j];
	}
	cout<<endl<<"\t\tEl área real: "<<ar<<" unidades cuadradas."<<endl<<endl;
	float sumat=0, sumae=0;
	for(j=0; j<=n; j++){
		if(j==0 or j==n){
			sumae=sumae+fabs(y[j]);
		}else{
			sumat=sumat+fabs(y[j]);
		}	
	}
	ar=((sumae/2)*h)+(sumat*h);
	cout<<endl<<"\t\tEl área con trapecios es: ";
	for(j=0; j<=n; j++){
		cout<<endl<<"\t\t=================================";
		cout<<endl<<"\t\tIteración: "<<j+1;
		cout<<endl<<"\t\tx: "<<x[j];
		cout<<endl<<"\t\ty: "<<y[j];
	}
	cout<<endl<<"\t\tEl área con trapecios: "<<ar<<" unidades cuadradas.";
	return 0;
}
