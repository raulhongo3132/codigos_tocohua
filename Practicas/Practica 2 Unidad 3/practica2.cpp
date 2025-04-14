#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>

using namespace std;

void cabeceras();
int metodos();
int metodo1();
void adios();
void determinantes(int z);
void imprimimirSistemaEcuaciones(float a[50][51], int op2);
void cambiar (float a[50][51], int z);
void det2x2(float a[50][51]);
void det3x3(float a[50][51]);
void det4x4(float a[50][51]);
int menuSaida();

int main(){
	setlocale(LC_ALL,"");
	cabeceras();
	int op1, op2, salida;
	LineMetodos:
	do{
		op1=metodos();
		if(op1<1 or op1>5){
			cout<<endl<<"\t\tOpción inválida. Vuelve a elegir.";
		}
	}while(op1<1 or op1>5);
	
	MismoMetodo:
	switch (op1){
		case 1:
			op2= metodo1();
			switch (op2){
				case 1:
				case 2:
				case 3:
					determinantes(op2+1);
					break;
				case 4:
					goto LineMetodos;
					break;
				default:
					break;
			}
			break;
		case 2:
			cout<<endl<<"\t\t2. Método de eliminación Gaussiana";
			break;
		case 3:
			cout<<endl<<"\t\t3. Método de Gauss-Jordán";
			break;
		case 4:
			cout<<endl<<"\t\t4. Método de la matriz Adjunta";
			break;
		case 5:
			cout<<endl<<"\t\t5. Otros";
			break;
		default:
			break;
	}
	salida=menuSaida();
	if(salida==1){
		goto MismoMetodo;
	}else if(salida==2){
		goto LineMetodos;
	}else{
		adios();
	}
	return 0;
}
void cabeceras(){
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tPractica 2: Equipo NPC's";
	cout<<endl<<"\t\tIntegrantes: ";
	cout<<endl<<"\t\t1. Díaz Camacho Neythan Zaid";
	cout<<endl<<"\t\t2. Lara Rendón Oscar";
	cout<<endl<<"\t\t3. Leal Rangel Karla Rocío";
	cout<<endl<<"\t\t4. Sansón Pérez Duncan Ricardo";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. Vargas Cisneros José Andrés";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
}

int metodos(){
	cout<<endl<<endl<<"\t\tPrograma que resuelve un sistema de ecuaciones lineales de orden n x n, ";
	cout<<endl<<endl<<"\t\ta partir de la forma general estandar: ";
	cout<<endl<<"\t\ta11x1 + a12x2 + ...  + a1nxn = b1  --- ( 1 )";
	cout<<endl<<"\t\ta21x1 + a22x2 + ...  + a2nxn = b2  --- ( 2 )";
	cout<<endl<<"\t\t ...  + ...   + ...  +  ...  = ... --- (...)";
	cout<<endl<<"\t\tan1x1 + an2x2 + ...  + annx3 = bn  --- ( n )";
	cout<<endl<<"\t\tpor los métodos: "<<endl;
	cout<<endl<<"\t\t1. Método de determinantes";
	cout<<endl<<"\t\t2. Método de eliminación Gaussiana";
	cout<<endl<<"\t\t3. Método de Gauss-Jordán";
	cout<<endl<<"\t\t4. Método de la matriz Adjunta";
	cout<<endl<<"\t\t5. Otros";
	cout<<endl<<"\t\t9. Salir";
	cout<<endl<<"\t\tElige la opción deseada: ";
	char f[]="";
	cin>>f;
	int op=atoi(f);
	return op;
}

int metodo1(){
	cout<<endl<<"\t\tCon el método de determinantes podemos resulver un sistema lineal de: ";
	cout<<endl<<endl<<"\t\t1. 2 ecuaciones con 2 incognitas";
	cout<<endl<<"\t\t\ta11x1 + a12x2 = b1 --- (1)";
	cout<<endl<<"\t\t\ta21x1 + a22x2 = b2 --- (2)";
	cout<<endl<<endl<<"\t\t2. 3 ecuaciones con 3 incognitas";
	cout<<endl<<"\t\t\ta11x1 + a12x2 + a13x3 = b1 --- (1)";
	cout<<endl<<"\t\t\ta21x1 + a22x2 + a23x3 = b2 --- (2)";
	cout<<endl<<"\t\t\ta31x1 + a22x2 + a33x3 = b3 --- (3)";
	cout<<endl<<endl<<"\t\t3. 4 ecuaciones con 4 incognitas";
	cout<<endl<<"\t\t\ta11x1 + a12x2 + a13x3 + a14x4 = b1 --- (1)";
	cout<<endl<<"\t\t\ta21x1 + a22x2 + a23x3 + a24x4 = b2 --- (2)";
	cout<<endl<<"\t\t\ta31x1 + a32x2 + a33x3 + a44x4 = b3 --- (3)";
	cout<<endl<<"\t\t\ta41x1 + a42x2 + a43x3 + a44x4 = b4 --- (4)";
	cout<<endl<<endl<<"\t\t5. Regresar al menú principal";
	cout<<endl<<endl<<"\t\t6. Salir";
	cout<<endl<<endl<<"\t\tElige la opción deseada: ";
	char f[]="";
	cin>>f;
	int op=atoi(f);
	return op;
}

void adios(){
	cout<<endl<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tAdios";
	cout<<endl<<endl<<"=================================================================================="<<endl;
}

void determinantes(int z){
	float a[50][51];
	char f[]="";
	string g;
	int i, j, k;
	for (i=0; i<z; i++){
		cout<<endl<<"\t\tPara la ecuación #"<<i+1<<": ";
		for (j=0; j<=z; j++){
			if(j<z){
				cout<<endl<<"\t\tDime el valor de a"<<i+1<<j+1<<": ";
				cin>>g;
				a[i][j]=atof(g.c_str());
			}else{
				cout<<endl<<"\t\tDime el valor de b"<<i+1<<": ";
				cin>>g;
				a[i][j]=atof(g.c_str());
			}	
		}
	}
	do{
		imprimimirSistemaEcuaciones(a, z);
		cout<<endl<<endl<<"\t\t¿Quieres cambiar algun valor?";
		cout<<endl<<"\t\t1. Si";
		cout<<endl<<"\t\t2. No"<<endl<<"\t\t";
		cin>>f;
		k=atoi(f);
		if (k==1){
			cambiar(a, z);
		}else if(k<1 or k>2){
			cout<<endl<<"\t\tValor inválido";
		}
	}while(k<=1 or k>2);
	if(z==2){
		det2x2(a);
	}else if (z==3){
		det3x3(a);
	}else if (z==4){
		det4x4(a);
	}
	
}

void imprimimirSistemaEcuaciones(float a[50][51], int op2){
	int i, j;
	cout<<endl<<endl<<"\t\tEl sistemas de ecuaciones es: ";
	for(i=0; i<op2; i++){
		cout<<endl<<"\t\t";
		for(j=0; j<=op2; j++){
			if(j==0){
				cout<<a[i][j]<<" a"<<i+1<<j+1<<" ";
			}else if(j<op2 and j>0){
				if(a[i][j]>=0){
					cout<<"+ "<<a[i][j]<<" a"<<i+1<<j+1<<" ";
				}else{
					cout<<"- "<<fabs(a[i][j])<<" a"<<i+1<<j+1<<" ";
				}		
			}else{
				cout<<"= "<<a[i][j]<<" b"<<i+1;
			}	
		}
	}
}

void cambiar (float a[50][51], int z){
	int x, y;
	char f[]="";
	string g;
	do{
		cout<<endl<<endl<<"\t\tDime la ecuación donde se encuentre el valor a cambiar: ";
		cin>>f;
		x=atoi(f);
		if(x<1 or x>z){
			cout<<endl<<endl<<"\t\tRango inválido";
		}
	}while(x<1 or x>z);
	do{
		cout<<endl<<endl<<"\t\tDime el coeficiente a cambiar (si es b, diga "<<z+1<<"): ";
		cin>>f;
		y=atoi(f);
		if(y<1 or y>z+1){
			cout<<endl<<endl<<"\t\tRango inválido";
		}
	}while(y<1 or y>z+1);
	cout<<endl<<endl<<"\t\tDime el valor del nuevo coeficiente: ";
	cin>>g;
	a[x-1][y-1]=atof(g.c_str());
}

void det2x2(float a[50][51]){
	float deta=(a[0][0]*a[1][1]-a[1][0]*a[0][1]);
	float deta1=(a[0][2]*a[1][1]-a[1][2]*a[0][1]);
	float deta2=(a[0][0]*a[1][2]-a[1][0]*a[0][2]);
	float x1=deta1/deta;
	float x2=deta2/deta;
	cout<<endl<<endl<<"\t\tEl valor de x1= "<<x1;
	cout<<endl<<endl<<"\t\tEl valor de x2= "<<x2;
}

void det3x3(float a[50][51]){
	float x1, x2, x3, t;
	float deta=(a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[2][0]*a[0][1]*a[1][2])-
	(a[2][0]*a[1][1]*a[0][2]+a[0][0]*a[2][1]*a[1][2]+a[1][0]*a[0][1]*a[2][2]);
	cout<<deta;
	if(fabs(deta)>0){
		float deta1=(a[0][3]*a[1][1]*a[2][2]+a[1][3]*a[2][1]*a[0][2]+a[2][3]*a[0][1]*a[1][2])-
		(a[2][3]*a[1][1]*a[0][2]+a[0][3]*a[2][1]*a[1][2]+a[1][3]*a[0][1]*a[2][2]);
		float deta2=(a[0][0]*a[1][3]*a[2][2]+a[1][0]*a[2][3]*a[0][2]+a[2][0]*a[0][3]*a[1][2])-
		(a[2][0]*a[1][3]*a[0][2]+a[0][0]*a[2][3]*a[1][2]+a[1][0]*a[0][3]*a[2][2]);
		float deta3=(a[0][0]*a[1][1]*a[2][3]+a[1][0]*a[2][1]*a[0][3]+a[2][0]*a[0][1]*a[1][3])-
		(a[2][0]*a[1][1]*a[0][3]+a[0][0]*a[2][1]*a[1][3]+a[1][0]*a[0][1]*a[2][3]);
		x1=deta1/deta;
		x2=deta2/deta;
		x3=deta3/deta;
		cout<<endl<<endl<<"\t\tEl valor de x1= "<<x1;
		cout<<endl<<endl<<"\t\tEl valor de x2= "<<x2;
		cout<<endl<<endl<<"\t\tEl valor de x3= "<<x3;
	}else{
		float w, x, y, z;
		float mc1, mc2, mc3, mc4;
		float r11, r21, r31;
		float r12, r22, r32;
		float r13, r23, r33;
		float r1, r2, r3;
		float pe1, pe2, pe3;
		
		w=min(fabs(a[0][0]),fabs(a[1][0]));
		mc1=min(fabs(w),fabs(a[2][0]));
		x=min(fabs(a[0][1]),fabs(a[1][1]));
		mc2=min(fabs(x),fabs(a[2][1]));
		y=min(fabs(a[0][2]),fabs(a[1][2]));
		mc3=min(fabs(y),fabs(a[2][2]));
		z=min(fabs(a[0][3]),fabs(a[1][3]));
		mc4=min(fabs(z),fabs(a[2][3]));
		
		r11=fabs(a[0][0])/mc1;
		r21=fabs(a[1][0])/mc1;
		r31=fabs(a[2][0])/mc1;
		
		r12=fabs(a[0][1])/mc2;
		r22=fabs(a[1][1])/mc2;
		r32=fabs(a[2][1])/mc2;
		
		r13=fabs(a[0][2])/mc3;
		r23=fabs(a[1][2])/mc3;
		r33=fabs(a[2][2])/mc3;
		
		r1=fabs(a[0][3])/mc4;
		r2=fabs(a[1][3])/mc4;
		r3=fabs(a[2][3])/mc4;
		
		pe1=(r11-r12+r13-r1);
		pe2=(r21-r22+r23-r2);
		pe3=(r31-r32+r33-r3);
		
		cout<<endl<<endl<<r11<<"   "<<r12<<"   "<<r13<<"   "<<r1;
		cout<<endl<<endl<<r21<<"   "<<r22<<"   "<<r23<<"   "<<r2;
		cout<<endl<<endl<<r31<<"   "<<r32<<"   "<<r33<<"   "<<r3;		
		
		if(pe1==0&&pe2==0&&pe3==0){
		    cout<<endl<<endl<<"Existen soluciones infinitas para este sistema de ecuaciones.";
		    cout<<endl<<endl<<"Ingrese un valor para el parametro t: ";
		    cin>>t;
		    
		    float x1=a[0][0]*t+a[0][3];
		    float x2=a[0][1]*t+a[1][3];
		    float x3=a[0][2]*t+a[2][3];
		
		    cout<<"Las soluciones del sistema son:"<<endl;
		    cout<<"x1 = "<<x1<<endl;
		    cout<<"x2 = "<<x2<<endl;
		    cout<<"x3 = "<<x3<<endl;
		}else{
			cout<<endl<<endl<<"No hay solución.";
		}
	}
}

void det4x4(float a[50][51]){
	float deta, detax1, detax2, detax3, detax4;
	deta=((a[0][0]*a[1][1]-a[1][0]*a[0][1])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[3][3]-a[3][0]*a[0][3])+
	(a[0][0]*a[1][2]-a[1][0]*a[0][2])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[3][1]-a[3][0]*a[0][1])+
	(a[0][0]*a[1][3]-a[1][0]*a[0][3])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[3][2]-a[3][0]*a[0][2]))-
	((a[0][0]*a[3][1]-a[3][0]*a[0][1])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[1][3]-a[1][0]*a[0][3])+
	(a[0][0]*a[3][2]-a[3][0]*a[0][2])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[1][1]-a[1][0]*a[0][1])+
	(a[0][0]*a[3][3]-a[3][0]*a[0][3])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[1][2]-a[1][0]*a[0][2]));
	deta=pow(-1,1-1)*(1/pow(a[0][0],4-2))*deta;

	if(fabs(deta)>0){
		detax1=((a[0][4]*a[1][1]-a[1][4]*a[0][1])*(a[0][4]*a[2][2]-a[2][4]*a[0][2])*(a[0][4]*a[3][3]-a[3][4]*a[0][3])+
		(a[0][4]*a[1][2]-a[1][4]*a[0][2])*(a[0][4]*a[2][3]-a[2][4]*a[0][3])*(a[0][4]*a[3][1]-a[3][4]*a[0][1])+
		(a[0][4]*a[1][3]-a[1][4]*a[0][3])*(a[0][4]*a[2][1]-a[2][4]*a[0][1])*(a[0][4]*a[3][2]-a[3][4]*a[0][2]))-
		((a[0][4]*a[3][1]-a[3][4]*a[0][1])*(a[0][4]*a[2][2]-a[2][4]*a[0][2])*(a[0][4]*a[1][3]-a[1][4]*a[0][3])+
		(a[0][4]*a[3][2]-a[3][4]*a[0][2])*(a[0][4]*a[2][3]-a[2][4]*a[0][3])*(a[0][4]*a[1][1]-a[1][4]*a[0][1])+
		(a[0][4]*a[3][3]-a[3][4]*a[0][3])*(a[0][4]*a[2][1]-a[2][4]*a[0][1])*(a[0][4]*a[1][2]-a[1][4]*a[0][2]));
		detax1=pow(-1,1-1)*(1/pow(a[0][4],4-2))*detax1;
	
	
		detax2=((a[0][0]*a[1][4]-a[1][0]*a[0][4])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[3][3]-a[3][0]*a[0][3])+
		(a[0][0]*a[1][2]-a[1][0]*a[0][2])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[3][4]-a[3][0]*a[0][4])+
		(a[0][0]*a[1][3]-a[1][0]*a[0][4])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[3][2]-a[3][0]*a[0][2]))-
		((a[0][0]*a[3][4]-a[3][0]*a[0][4])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[1][3]-a[1][0]*a[0][3])+
		(a[0][0]*a[3][2]-a[3][0]*a[0][2])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[1][4]-a[1][0]*a[0][4])+
		(a[0][0]*a[3][3]-a[3][0]*a[0][3])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[1][2]-a[1][0]*a[0][2]));
		detax2=pow(-1,1-1)*(1/pow(a[0][0],4-2))*detax2;
	
		detax3=((a[0][0]*a[1][1]-a[1][0]*a[0][1])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[3][3]-a[3][0]*a[0][3])+
		(a[0][0]*a[1][4]-a[1][0]*a[0][4])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[3][1]-a[3][0]*a[0][1])+
		(a[0][0]*a[1][3]-a[1][0]*a[0][3])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[3][4]-a[3][0]*a[0][4]))-
		((a[0][0]*a[3][1]-a[3][0]*a[0][1])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[1][3]-a[1][0]*a[0][3])+
		(a[0][0]*a[3][4]-a[3][0]*a[0][4])*(a[0][0]*a[2][3]-a[2][0]*a[0][3])*(a[0][0]*a[1][1]-a[1][0]*a[0][1])+
		(a[0][0]*a[3][3]-a[3][0]*a[0][3])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[1][4]-a[1][0]*a[0][4]));
		detax3=pow(-1,1-1)*(1/pow(a[0][0],4-2))*detax3;
		
		detax4=((a[0][0]*a[1][1]-a[1][0]*a[0][1])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[3][4]-a[3][0]*a[0][4])+
		(a[0][0]*a[1][2]-a[1][0]*a[0][2])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[3][1]-a[3][0]*a[0][1])+
		(a[0][0]*a[1][4]-a[1][0]*a[0][4])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[3][2]-a[3][0]*a[0][2]))-
		((a[0][0]*a[3][1]-a[3][0]*a[0][1])*(a[0][0]*a[2][2]-a[2][0]*a[0][2])*(a[0][0]*a[1][4]-a[1][0]*a[0][4])+
		(a[0][0]*a[3][2]-a[3][0]*a[0][2])*(a[0][0]*a[2][4]-a[2][0]*a[0][4])*(a[0][0]*a[1][1]-a[1][0]*a[0][1])+
		(a[0][0]*a[3][4]-a[3][0]*a[0][4])*(a[0][0]*a[2][1]-a[2][0]*a[0][1])*(a[0][0]*a[1][2]-a[1][0]*a[0][2]));
		detax4=pow(-1,1-1)*(1/pow(a[0][0],4-2))*detax4;
		
		cout<<endl<<endl<<"La determinante de a es: "<<deta;
		cout<<endl<<endl<<"La determinante de ax1 es: "<<detax1;
		cout<<endl<<endl<<"La determinante de ax2 es: "<<detax2;
		cout<<endl<<endl<<"La determinante de ax3 es: "<<detax3;
		cout<<endl<<endl<<"La determinante de ax4 es: "<<detax4;
		cout<<endl<<endl<<"X1= : "<<detax1/deta;
		cout<<endl<<endl<<"X2= : "<<detax2/deta;
		cout<<endl<<endl<<"X3= : "<<detax3/deta;
		cout<<endl<<endl<<"X4= : "<<detax4/deta;	
	}else{
		cout<<endl<<endl<<"Existen soluciones infinitas para este sistema de ecuaciones.";
		float w, x, y, z, v, t;
		float mc1, mc2, mc3, mc4, mc5;
		float r11, r21, r31, r41;
		float r12, r22, r32, r42;
		float r13, r23, r33, r43;
		float r14, r24, r34, r44;
		float r1, r2, r3, r4;
		bool pe1, pe2, pe3, pe4;
		
		w = min(fabs(a[0][0]), fabs(a[1][0]));
		w = min(fabs(w), fabs(a[2][0]));
		mc1 = min(fabs(w), fabs(a[3][0]));
		x = min(fabs(a[0][1]), fabs(a[1][1]));
		x = min(fabs(x), fabs(a[2][1]));
		mc2 = min(fabs(x), fabs(a[3][1]));
		y = min(fabs(a[0][2]), fabs(a[1][2]));
		y = min(fabs(y), fabs(a[2][2]));
		mc3 = min(fabs(y), fabs(a[3][2]));
		z = min(fabs(a[0][3]), fabs(a[1][3]));
		z = min(fabs(z), fabs(a[2][3]));
		mc4 = min(fabs(z), fabs(a[3][3]));
		v = min(fabs(a[0][4]), fabs(a[1][4]));
		v = min(fabs(v), fabs(a[2][4]));
		mc5 = min(fabs(v), fabs(a[3][4]));
		
		r11 = fabs(a[0][0]) / mc1;
		r21 = fabs(a[1][0]) / mc1;
		r31 = fabs(a[2][0]) / mc1;
		r41 = fabs(a[3][0]) / mc1;
		
		r12 = fabs(a[0][1]) / mc2;
		r22 = fabs(a[1][1]) / mc2;
		r32 = fabs(a[2][1]) / mc2;
		r42 = fabs(a[3][1]) / mc2;
		
		r13 = fabs(a[0][2]) / mc3;
		r23 = fabs(a[1][2]) / mc3;
		r33 = fabs(a[2][2]) / mc3;
		r43 = fabs(a[3][2]) / mc3;
		
		r14 = fabs(a[0][3]) / mc4;
		r24 = fabs(a[1][3]) / mc4;
		r34 = fabs(a[2][3]) / mc4;
		r44 = fabs(a[3][3]) / mc4;
		
		r1 = fabs(a[0][4]) / mc5;
		r2 = fabs(a[1][4]) / mc5;
		r3 = fabs(a[2][4]) / mc5;
		r4 = fabs(a[3][4]) / mc5;
		
		pe1 = (r11==r12 && r12==r13 && r13==r14 && r14==r1);
		pe2 = (r21==r22 && r22==r23 && r23==r24 && r24==r2);
		pe3 = (r31==r32 && r32==r33 && r33==r34 && r34==r3);
		pe4 = (r41==r42 && r42==r43 && r43==r44 && r44==r4);
		
		cout << endl << endl << r11 << "   " << r12 << "   " << r13 << "   " << r14 << "   " << r1;
		cout << endl << endl << r21 << "   " << r22 << "   " << r23 << "   " << r24 << "   " << r2;
		cout << endl << endl << r31 << "   " << r32 << "   " << r33 << "   " << r34 << "   " << r3;
		cout << endl << endl << r41 << "   " << r42 << "   " << r43 << "   " << r44 << "   " << r4;

		if(pe1 && pe2  && pe3 && pe4){
		    cout<<endl<<endl<<"Existen soluciones infinitas para este sistema de ecuaciones.";
		    cout<<endl<<endl<<"Ingrese un valor para el parametro t: ";
		    cin>>t;
		    
		    float x1=a[0][0]*t+a[0][4];
		    float x2=a[0][1]*t+a[1][4];
		    float x3=a[0][2]*t+a[2][4];
		    float x4=a[0][3]*t+a[3][4];
		
		    cout<<"Las soluciones del sistema son:"<<endl;
		    cout<<"x1 = "<<x1<<endl;
		    cout<<"x2 = "<<x2<<endl;
		    cout<<"x3 = "<<x3<<endl;
		    cout<<"x4 = "<<x4<<endl;
		}
	}
	
}

int menuSaida(){
	int x;
	char f[]="";
	do{
		cout<<endl<<endl<<"\t\t¿Qué desea hacer?";
		cout<<endl<<endl<<"\t\t1. Calcular otro sistema de ecuaciones con el mismo método";
		cout<<endl<<endl<<"\t\t2. Usar otro método";
		cout<<endl<<endl<<"\t\t3. Salir"<<endl<<endl<<"\t\t";
		cin>>f;
		x=atoi(f);
		if(x<1 or x>3){
			cout<<endl<<endl<<"\t\tRango inválido";
		}
	}while(x<1 or x>3);
	return x;
}
