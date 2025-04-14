#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	char N[]="";
	int n, i;
	string g;
	setlocale(LC_ALL, "");
	cout<<endl<<endl<<"\t\tPrograma que calcula la diferenciación numérica de un conjunto de datos.";
	do{
		cout<<endl<<endl<<"\t\tIngrese el número de datos a ingresar: ";
		cin>>N;
		n=atoi(N);
		if(n<3){
			cout<<endl<<endl<<"\t\tValor inválido. Debe ser al menos 3. Vuelve a intentarlo.";
		}
	}while(n<3);
	float X[n], Y[n], Y1[n], Y2[n], Y3[n], d[n], h;
	int j=1;
	for(i=1; i<=n; i++){
		cout<<endl<<endl<<"\t\tDime el "<<i<<"° valor de X: ";
		cin>>g;
        X[i]=atof(g.c_str());
        cout<<endl<<endl<<"\t\tDime el "<<i<<"° valor de Y: ";
		cin>>g;
        Y[i]=atof(g.c_str());
	}
        /*if(i>=3 and (X[i-2]-X[i-1]!=X[i-1]-X[i])){
        	cout<<endl<<endl<<"\t\tEl valor no es uniforme. Ingrese otro";
        	i--;
		}
		
	}
	for(i=1; i<n; i++){
		if(i>=2 and (X[i-1]-X[i]!=X[i]-X[i+1])){
        	d[j]=i;
			j++;
		}
	}
	cout<<endl<<endl<<"\t\tLa diferencia entre los valores es "<<X[1]-X[2]<<", salvo en la posición: ";
	
	for (i=1; i<j; i++){
		cout<<d[i]<<", ";
	}
	*/ //Ver lo de la diferencia al calcular la diferencia.
	//Calcular la diferenciación numérica.
	h=X[2]-X[1];
	for(i=1; i<=n-1; i++){
		Y1[i]=(Y[i+1]-Y[i])/h;
	}for(i=1; i<=n-2; i++){
		Y2[i]=(Y1[i+1]-Y1[i])/h;
	}for(i=1; i<=n-2; i++){
		Y3[i]=(Y2[i+1]-Y2[i])/h;
	}
	cout<<endl<<endl<<"\t\tLa diferenciación numerica hasta la tercera derivada es: ";
	cout<<endl<<endl<<"\t\tn\t\tX\t\tY\t\tY'\t\tY''\t\tY'''";
	cout<<endl;
	for(i=1; i<=n; i++){
		cout<<endl<<"\t\t"<<i<<"\t\t"<<X[i]<<"\t\t"<<Y[i]<<"\t\t"<<Y1[i]<<"\t\t"<<Y2[i]<<"\t\t"<<Y3[i];
		
	}
	
	
	
	
	return 0;
}
