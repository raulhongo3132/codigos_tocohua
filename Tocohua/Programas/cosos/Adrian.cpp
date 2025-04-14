#include <iostream>
#include <stdlib.h>

using namespace std;

int menu();
int salida();
void suma();
void resta();
void multiplicacion();
void identidad();
void transpuesta();
void determinantes();
void llenadoMatriz(int ancho, int largo, float matriz[50][50]);
void mostrarMatrizI(int ancho, int largo, float matriz[50][50]);
void llenadoMatrizI(int ancho, int largo, float matriz[50][50]);
void mostrarMatrizT(int ancho, int largo, float matriz[50][50]);
void mostrarMatriz(int ancho, int largo, float matriz[50][50]);
void sumadeMatriz(int ancho, int largo, float matrizA[50][50], float matrizB[50][50]);
void restadeMatriz(int ancho, int largo, float matrizA[50][50], float matrizB[50][50]);
void multiplicaciondeMatriz(int anchoA, int largoA, int anchoB, int largoB, float matrizA[50][50], float matrizB[50][50]);
void matrizIdentidad(int ancho, int largo, float matriz[50][50]);
float calcularDeterminante(float matriz[50][50], int n);

int main(){
	int op, salir;
	LineMenu:
	op=menu();
	LineMismaOp:
	switch (op){
		case 1:
			suma();
			break;
		case 2:
			resta();
			break;
		case 3:
			multiplicacion();
			break;
		case 4:
			identidad();
			break;
		case 5:
			transpuesta();
			break;
		case 6:
			determinantes();
			break;
	}
	salir=salida();
	if(salir==1){
		goto LineMenu;
	}else if(salir==2){
		goto LineMismaOp;
	}
	cout<<endl<<endl<<"============================================================";
	cout<<endl<<endl<<"Adios";
	cout<<endl<<endl<<"============================================================";
	return 0;
}

int menu(){
	int op;
	char N[]="";
	cout<<endl<<endl<<"============================================================";
	cout<<endl<<endl<<"Programa que realiza los siguientes calculos de matrices: ";
	cout<<endl<<"1. Suma";
	cout<<endl<<"2. Resta";
	cout<<endl<<"3. Multiplicacion";
	cout<<endl<<"4. Identidad";
	cout<<endl<<"5. Transpuesta";
	cout<<endl<<"6. Determinantes";
	cout<<endl<<"7. Salir";
	cout<<endl;
	do{
		cout<<endl<<"Dime que metodo quieres: ";
		cin>>N;
		op=atoi(N);
		if(op<1 or op>7){
			cout<<endl<<"Valor invalido.";
		}
	}while(op<1 or op>7);
	cout<<endl<<endl<<"============================================================";
	return op;
}

void llenadoMatriz(int ancho, int largo, float matriz[50][50]){
	int i, j;
	cout<<endl;
	for(i=0; i<largo; i++){
		for(j=0; j<ancho; j++){
			cout<<endl<<"Dime el valor de la posicion a"<<i+1<<j+1<<": ";
			cin>>matriz[i][j];
		}
	}
}

void mostrarMatriz(int ancho, int largo, float matriz[50][50]){
	int i, j;
	cout<<endl;
	for(i=0; i<largo; i++){
		cout<<"\t\t|";
		for(j=0; j<ancho; j++){
			cout<<"\t"<<matriz[i][j];
		}
		cout<<"\t|"<<endl;
	}
}

void mostrarMatrizT(int ancho, int largo, float matriz[50][50]){
	int i, j;
	cout<<endl;
	for(j=0; j<ancho; j++){
		cout<<"\t\t|";
		for(i=0; i<largo; i++){
			cout<<"\t"<<matriz[i][j];
		}
		cout<<"\t|"<<endl;
	}
}

void llenadoMatrizI(int ancho, int largo, float matriz[50][50]){
	int i, j;
	cout<<endl<<"Suponiendo que la matriz es para resolver un sistema de ecuaones: "<<endl;
	for(i=0; i<largo; i++){
		for(j=0; j<ancho; j++){
			if(j==ancho-1){
				cout<<endl<<"Dime el valor de b"<<i+1<<": ";
				cin>>matriz[i][j];
			}else{
				cout<<endl<<"Dime el valor de la posicion a"<<i+1<<j+1<<": ";
				cin>>matriz[i][j];
			}
		}
	}
}

void mostrarMatrizI(int ancho, int largo, float matriz[50][50]){
	int i, j;
	cout<<endl;
	for(i=0; i<largo; i++){
		cout<<"\t\t|";
		for(j=0; j<ancho; j++){
			if(j==ancho-1){
				cout<<"\t|  |\t"<<matriz[i][j];
			}else{
				cout<<"\t"<<matriz[i][j];
			}
			
		}
		cout<<"\t|"<<endl;
	}
}

void sumadeMatriz(int ancho, int largo, float matrizA[50][50], float matrizB[50][50]){
	int i, j;
	float matrizResultado[50][50];
	for(i=0; i<largo; i++){
		for(j=0; j<ancho; j++){
			matrizResultado[i][j]=matrizA[i][j]+matrizB[i][j];
		}
	}
	mostrarMatriz(ancho, largo, matrizResultado);
}

void restadeMatriz(int ancho, int largo, float matrizA[50][50], float matrizB[50][50]){
	int i, j;
	float matrizResultado[50][50];
	for(i=0; i<largo; i++){
		for(j=0; j<ancho; j++){
			matrizResultado[i][j]=matrizA[i][j]-matrizB[i][j];
		}
	}
	mostrarMatriz(ancho, largo, matrizResultado);
}

void multiplicaciondeMatriz(int anchoA, int largoA, int anchoB, int largoB, float matrizA[50][50], float matrizB[50][50]){
	int i, j, k;
	float matrizResultado[50][50]={0};
	for(i=0; i<largoA; i++){
		for(j=0; j<anchoB; j++){
			for(k=0; k<anchoA; k++){
				matrizResultado[i][j]+=(matrizA[i][k]*matrizB[k][j]);
			}
		}
	}
	mostrarMatriz(anchoB, largoA, matrizResultado); 
}

void matrizIdentidad(int ancho, int largo, float matriz[50][50]) {
    int i, j, k, l;
    float diag, factor, matrizResultado[50][50];
    for (i=0; i<largo; i++) {
        for (j=0; j<ancho+1; j++) {
            matrizResultado[i][j]=matriz[i][j];
        }
    }
    for (i=0; i<largo; i++) {
        diag=matrizResultado[i][i];
        if (diag==0) {
            cout<<endl<<"Error, la matriz es singular o tiene soluciones infinitas."<<endl;
            return;
        }
        for (j=0; j<ancho+1; j++) {
            matrizResultado[i][j]=matrizResultado[i][j]/diag;
        }
        for (k=0; k<largo; k++) {
            if (k!=i) {
                factor=matrizResultado[k][i];
                for (l=0; l<ancho+1; l++) {
                    matrizResultado[k][l]=matrizResultado[k][l]-factor*matrizResultado[i][l];
                }
            }
        }
    }
    mostrarMatrizI(ancho, largo, matrizResultado);
}

void suma(){
	int largo, ancho;
	char N[]="";
	do{
		cout<<endl<<endl<<"Dime el ancho de las matrices: ";
		cin>>N;
		ancho=atoi(N);
		cout<<endl<<endl<<"Dime el largo de las matrices: ";
		cin>>N;
		largo=atoi(N);
		if((largo<0 or largo>50) and (ancho<0 or ancho>50)){
				cout<<endl<<endl<<"Valor inválido (el largo y ancho debe ser por lo menos 1 y maximo 50)";
		}
	}while((largo<0 or largo>50) and (ancho<0 or ancho>50));
	float matrizA[50][50], matrizB[50][50];
	cout<<endl<<endl<<"Para la matriz A:";
	llenadoMatriz(ancho, largo, matrizA);
	cout<<endl<<endl<<"Para la matriz B:";
	llenadoMatriz(ancho, largo, matrizB);
	cout<<endl<<endl<<"La matriz A es: ";
	mostrarMatriz(ancho, largo, matrizA);
	cout<<endl<<endl<<"La matriz B es: ";
	mostrarMatriz(ancho, largo, matrizB);
	cout<<endl<<endl<<"La suma de las matrices es:";
	sumadeMatriz(ancho, largo, matrizA, matrizB);	
}

int salida (){
	int opcionSalida;
	char N[]="";
	cout<<endl<<endl<<"Sigueinte paso deseado:";
	cout<<endl<<"1. Otra operación";
	cout<<endl<<"2. Misma operación";
	cout<<endl<<"3. Salir"<<endl;
	cin>>N;
	opcionSalida=atoi(N);
	do{
		if(opcionSalida<1 or opcionSalida>3){
			cout<<endl<<"Valor invalido";
		}
	}while(opcionSalida<1 or opcionSalida>3);
	return opcionSalida;
}

void resta(){
	int largo, ancho;
	char N[]="";
	do{
		cout<<endl<<endl<<"Dime el ancho de las matrices: ";
		cin>>N;
		ancho=atoi(N);
		cout<<endl<<endl<<"Dime el largo de las matrices: ";
		cin>>N;
		largo=atoi(N);
		if((largo<0 or largo>50) and (ancho<0 or ancho>50)){
				cout<<endl<<endl<<"Valor inválido (el largo y ancho debe ser por lo menos 1 y maximo 50)";
		}
	}while((largo<0 or largo>50) and (ancho<0 or ancho>50));
	float matrizA[50][50], matrizB[50][50];
	cout<<endl<<endl<<"Para la matriz A:";
	llenadoMatriz(ancho, largo, matrizA);
	cout<<endl<<endl<<"Para la matriz B:";
	llenadoMatriz(ancho, largo, matrizB);
	cout<<endl<<endl<<"La matriz A es: ";
	mostrarMatriz(ancho, largo, matrizA);
	cout<<endl<<endl<<"La matriz B es: ";
	mostrarMatriz(ancho, largo, matrizB);
	cout<<endl<<endl<<"La resta de las matrices es:";
	restadeMatriz(ancho, largo, matrizA, matrizB);
	
}

void multiplicacion(){
	int anchoA, largoA, anchoB, largoB;
	char N[]="";
	do{
		cout<<endl<<endl<<"Dime el ancho de las matriz A: ";
		cin>>N;
		anchoA=atoi(N);
		cout<<endl<<endl<<"Dime el largo de las matriz A: ";
		cin>>N;
		largoA=atoi(N);
		cout<<endl<<endl<<"Dime el ancho de las matriz B: ";
		cin>>N;
		anchoB=atoi(N);
		largoB=anchoA;
		cout<<endl<<endl<<"El largo de la matriz B es:  "<<largoB<<". Requisito para que se pueda multiplicar con A";
		if(((largoA<0 or largoA>50) and (anchoA<0 or anchoA>50)) and ((largoB<0 or largoB>50) and (anchoB<0 or anchoB>50))){
				cout<<endl<<endl<<"Valor inválido (el largo y ancho debe ser por lo menos 1 y maximo 50)";
		}
	}while(((largoA<0 or largoA>50) and (anchoA<0 or anchoA>50)) and ((largoB<0 or largoB>50) and (anchoB<0 or anchoB>50)));
	float matrizA[50][50], matrizB[50][50];
	cout<<endl<<endl<<"Para la matriz A:";
	llenadoMatriz(anchoA, largoA, matrizA);
	cout<<endl<<endl<<"Para la matriz B:";
	llenadoMatriz(anchoB, largoB, matrizB);
	cout<<endl<<endl<<"La matriz A es: ";
	mostrarMatriz(anchoA, largoA, matrizA);
	cout<<endl<<endl<<"La matriz B es: ";
	mostrarMatriz(anchoB, largoB, matrizB);
	cout<<endl<<endl<<"La multiplicacion de las matrices es:";
	multiplicaciondeMatriz(anchoA, largoA, anchoB, largoB, matrizA, matrizB);
}

void identidad(){
	int tamano;
	char N[]="";
	do{
		cout<<endl<<endl<<"Dime el tamaño de la matriz (recuerda que es una matriz cuadrada n x n): ";
		cin>>N;
		tamano=atoi(N);
		if(tamano<1 or tamano>50){
				cout<<endl<<endl<<"Valor inválido (el largo y ancho debe ser por lo menos 2 y maximo 49)";
		}
	}while(tamano<1 or tamano>50);
	float matriz[50][50];
	cout<<endl<<endl<<"Para la matriz: ";
	llenadoMatrizI(tamano+1, tamano, matriz);
	cout<<endl<<endl<<"La matriz es: ";
	mostrarMatrizI(tamano+1, tamano, matriz);
	cout<<endl<<endl<<"La matriz identidad es:";
	matrizIdentidad(tamano+1, tamano, matriz);
	
}

void transpuesta(){
	int largo, ancho;
	char N[]="";
	do{
		cout<<endl<<endl<<"Dime el ancho de la matriz: ";
		cin>>N;
		ancho=atoi(N);
		cout<<endl<<endl<<"Dime el largo de la matriz: ";
		cin>>N;
		largo=atoi(N);
		if((largo<0 or largo>50) and (ancho<0 or ancho>50)){
				cout<<endl<<endl<<"Valor inválido (el largo y ancho debe ser por lo menos 1 y maximo 50)";
		}
	}while((largo<0 or largo>50) and (ancho<0 or ancho>50));
	float matriz[50][50];
	cout<<endl<<endl<<"Para la matriz:";
	llenadoMatriz(ancho, largo, matriz);
	cout<<endl<<endl<<"La matriz es: ";
	mostrarMatriz(ancho, largo, matriz);
	cout<<endl<<endl<<"La matriz transpuesta es:";
	mostrarMatrizT(ancho, largo, matriz);
}

void determinantes(){
	int tamano;
	char N[]="";
	float det;
	do{
		cout<<endl<<endl<<"Dime el tamaño de la matriz: ";
		cin>>N;
		tamano=atoi(N);
		if(tamano<0 or tamano>50){
				cout<<endl<<endl<<"Valor inválido (el tamaño debe ser por lo menos 1 y maximo 50)";
		}
	}while(tamano<0 or tamano>50);
	float matriz[50][50];
	llenadoMatriz(tamano, tamano, matriz);
	cout<<endl<<endl<<"La matriz es: ";
	mostrarMatriz(tamano, tamano, matriz);
	det=calcularDeterminante(matriz, tamano);
	cout<<endl<<endl<<"La matriz determinante es: "<<det;
	
}

float calcularDeterminante(float matriz[50][50], int n){
	float  det=0;
	int x, i, j, subi, subj;
	if (n==1){
        return matriz[0][0];
    }
    if (n==2) {
        return matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
    }
    float submatriz[50][50];
    for (x=0; x<n; x++) {
        subi=0;
        for (i=1; i<n; i++) {
            subj=0;
            for (j=0; j<n; j++) {
                if (j==x) continue;
                submatriz[subi][subj]=matriz[i][j];
                subj++;
            }
            subi++;
        }
        det+=(x%2==0? 1:-1)*matriz[0][x]*calcularDeterminante(submatriz, n - 1);
    }
	return det;
}

