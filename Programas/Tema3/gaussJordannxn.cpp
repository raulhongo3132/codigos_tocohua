#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

//float determinante(float A[50][51], int n);

int main() {
    int n, i, j, k;
    float pivote, inverso, factor, det = 1;
    char N[]=""; // Espacio suficiente para la entrada
    float detA;

    setlocale(LC_ALL, "");
    do {
        cout<<endl<<endl<<"\t\tIngrese el orden o tamaño de la matriz A n x n: ";
        cin>>N;
        n=atoi(N);
        if(n>50 or n<3){
            cout<<endl<<endl<<"\t\tValor inválido";
        }
    }while(n>50 or n<3);

    float a[50][51];
    cout<<endl<<endl;
    for(i=0;i<n;i++){
        for (j=0;j<=n;j++){
            if(j<n){
            	cout<<"Dime el valor de a"<<i+1<<j+1<<": ";
            	cin >> a[i][j];
			}else{
				cout<<"Dime el valor de b"<<i+1<<": ";
        		cin>>a[i][j];
			}
        }
        
    }
    
    cout<<endl<<endl;
    for(i=0;i<n;i++){
        cout<<"	|";
        for(j=0;j<n;j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"|	"<<a[i][j]<<endl;
    }

    for(i=0;i<n;i++){
        pivote=a[i][i];
        for(k=0;k<=n;k++){
        	a[i][k]=a[i][k]/pivote;
		}
		for(j=0;j<=n;j++){
			inverso=-1*a[j][i];
			if(i!=j){
				a[j][k]=a[j][k]+inverso*a[i][k];
			}
		}
    }
    cout<<endl<<endl;
	for(i=0;i<n;i++){
        cout<<"	|";
        for(j=0;j<n;j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"|	"<<a[i][j]<<endl;
    }
    return 0;
}

/*float determinante(float A[50][51], int n){
    int i, j, k;
    float pivote, inverso, factor, det = 1;
    
    for(i=0;i<n;i++){
        pivote=A[i][i];
        for(j=i+1;j<n;j++){
            inverso=-1*A[j][i];
            factor=inverso/pivote;
            for(k=0;k<=n;k++){
                A[j][k]=A[j][k]+A[i][k]*factor;
            }
        }
    }
    
    for(i= 0;i<n;i++){
        det=det*A[i][i];
    }
    return det;
}
*/


