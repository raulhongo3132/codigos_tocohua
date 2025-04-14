#include <iostream>
#include <locale.h>

using namespace std;

int main(){
	int n, i, j, k, l=0, m;
	float inverso, factor, pivote;
	setlocale(LC_ALL,"");
	
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tDeterminante de Orden Superior";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. 231080023";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
	cout<<endl<<endl<<"\t\tPrograma que que calcula el determinante de una matriz de orden n x n: ";
	cout<<endl<<endl<<"\t\tpor reducción de filas. Donde 3<n<30"<<endl<<endl;
	cout<<endl<<endl<<"=================================================================================="<<endl;
	do{
		cout<<endl<<endl<<"\t\tIngrese el orden o tamaño de la matriz A n x n: ";
		cin>>n;
	}while(n>30 or n<3);
	
	
	float a[n][n];
	float b[n];
	float A[n][n][n];
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout<<"Dime el valor de a"<<i+1<<j+1<<": ";
			cin>>a[i][j];
		}	
	}
	for(i=0; i<n; i++){
		cout<<"Dime el valor de b"<<i+1<<": ";
		cin>>b[i];
	}
	
	cout<<endl<<endl;
	for(i=0; i<n; i++){
		cout<<"	|";
		for(j=0; j<n; j++){
			cout<<" "<<a[i][j]<<" ";
		}
		cout<<"|	"<<b[i]<<endl;	
	}
	
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(l==j){
					A[k][i][j]=b[i];	
				}else{
					A[k][i][j]=a[i][j];	
				}
			}
		}
		l++;	
	}	
	
	float detA=1;
	for(i=0; i<n; i++){
		pivote=a[i][i];
		for(j=i+1;j<n;j++){
			inverso=-1*a[j][i];
			factor=inverso/pivote;
			for(k=0;k<n;k++){
				a[j][k]=a[j][k]+a[i][k]*factor;
			}
		}
	}
	for(i=0; i<n; i++){
		detA=detA*a[i][i];
	}
	cout<<endl<<detA<<endl;
	
	float detAx[n];
	
	for(i=0; i<n; i++){
		detAx[i]=1;
	}
	
	for(m=0; m<n; m++){
		for(i=0; i<n; i++){
			pivote=A[m][i][i];
			for(j=i+1;j<n;j++){
				inverso=-1*A[m][j][i];
				factor=inverso/pivote;
				for(k=0;k<n;k++){
					A[m][j][k]=A[m][j][k]+A[m][i][k]*factor;
				}
			}
		}
		for(i=0; i<n; i++){
			detAx[m]=detAx[m]*A[m][i][i];
		}
		cout<<endl<<detAx[m]<<endl;
	}
	
	float x[n];
	for(i=0; i<n; i++){
		x[i]=detAx[i]/detA;
		cout<<endl<<"El valor de x"<<i<<"es: "<<x[i];
	}

	return 0;		
}
