#include <iostream>
#include <locale.h>
#include <limits>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

void cabecera();
char menu();
void casoA();
void casoB();
void casoC();
int salida();

int main(){
	setlocale(LC_ALL,"");
	cabecera();
	char op;
	int sal;
	LineMenu:
	op = menu();
	LineSistema:
	switch (op){
		case 'a':
		case 'A':
			casoA();
			sal=salida();
			if(sal==1){
				goto LineMenu;
			}else if(sal==2){
				goto LineSistema;
			}else if(sal==3){
				cout<<endl<<"\t\tAdios"<<endl;
			}
			break;
		case 'b':
		case 'B':
			casoB();
			sal=salida();
			if(sal==1){
				goto LineMenu;
			}else if(sal==2){
				goto LineSistema;
			}else if(sal==3){
				cout<<endl<<"\t\tAdios"<<endl;
			}
			break;
		case 'c':
		case 'C':
			casoC();
			sal=salida();
			if(sal==1){
				goto LineMenu;
			}else if(sal==2){
				goto LineSistema;
			}else if(sal==3){
				cout<<endl<<"\t\tAdios"<<endl;
			}
			break;
		default:
			break;
	}
	return 0;
}
void cabecera(){
	cout<<endl<<endl<<"======================================================================================================================"<<endl;
	cout<<endl<<"\t\tPractica 2: Equipo NPC's";
	cout<<endl<<"\t\tIntegrantes: ";
	cout<<endl<<"\t\t1. Díaz Camacho Neythan Zaid";
	cout<<endl<<"\t\t2. Lara Rendón Oscar";
	cout<<endl<<"\t\t3. Leal Rangel Karla Rocío";
	cout<<endl<<"\t\t4. Sansón Pérez Duncan Ricardo";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. Vargas Cisneros José Andrés";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tMétodos numéricos";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<"\t\tSistema de ecuaciones no lineales por el método de Newton-Raphson basado en el Jacobiano.";
	cout<<endl<<endl<<"======================================================================================================================"<<endl;
}
char menu(){
	char op;
	cout<<endl<<"\t\tSistema de ecuaciones no lineales Disponible: "<<endl;
	cout<<endl<<"\t\ta)"<<endl;
	cout<<endl<<"\t\t4(x^2)(z^3)+4(x^2)+4(z^3)=41";
	cout<<endl<<"\t\t-8(x^2)+24x(z^3)-16(x^3)z=63"<<endl;
	cout<<endl<<"\t\tb)"<<endl;
	cout<<endl<<"\t\tln|2x(y^3)|-y(z^2)=-33.9206";
	cout<<endl<<"\t\t(((x^2)+(y^2))/z)+4xz=(85/6)";
	cout<<endl<<"\t\t(x^2)y(z^3)+4xz=-3552"<<endl;
	cout<<endl<<"\t\tc)"<<endl;
	cout<<endl<<"\t\t(w^2)xy-4(w^2)(x^2)+4(z^3)=(1401/2)";
	cout<<endl<<"\t\t-72(w^2)x-576(w^3)z+36wy=9";
	cout<<endl<<"\t\t((wx(y^2)z)/16)+(xy/8)=-(9/4)";
	cout<<endl<<"\t\t24(w^3)xy-20wx(y^3)+18(z^2)=607"<<endl;
	do{
		cout<<endl<<endl<<"\t\t¿Cuál opción decides?: ";
		cin>>op;
		if(op!='a' and op!='A' and op!='b' and op!='B' and op!='c' and op!='C'){
			cout<<endl<<"\t\tOpción inválida. Vuelve a elegir.";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(op!='a' and op!='A' and op!='b' and op!='B' and op!='c' and op!='C');
	return op;	
}
void casoA(){
	float tol;
	string g;
	cout<<endl<<"\t\tExcelente. Trabajaremos con las siguientes ecuaciones: "<<endl;
	cout<<endl<<"\t\tln|2x(y^3)|-y(z^2)=-33.9206";
	cout<<endl<<"\t\t(((x^2)+(y^2))/z)+4xz=(85/6)";
	cout<<endl<<"\t\t(x^2)y(z^3)+4xz=-3552"<<endl;
	do{
		cout<<endl<<"\t\tDime la tolerancia (0<tolerancia<1): ";
		cin>>g;
		tol=atof(g.c_str());
		if(tol<=0 || tol>=1){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
	}while(tol<=0 || tol>=1);
	float a[4][4], w, x, y, z, detj;
	int s, t;
	do{
		cout<<endl<<"\t\tDa valores para las siguientes variables:"<<endl;
		cout<<endl<<"\t\tw: ";
		cin>>g;
		w=atof(g.c_str());
		cout<<endl<<"\t\tx: ";
		cin>>g;
		x=atof(g.c_str());
		cout<<endl<<"\t\ty: ";
		cin>>g;
		y=atof(g.c_str());
		cout<<endl<<"\t\tz: ";
		cin>>g;
		z=atof(g.c_str());
		cout<<endl<<"\t\tValor de w = "<<w;
		cout<<endl<<"\t\tValor de x = "<<x;
		cout<<endl<<"\t\tValor de y = "<<y;
		cout<<endl<<"\t\tValor de z = "<<z;
		cout<<endl<<"\t\t¿Quieres continuar con estos valores?";
		cout<<endl<<"\t\t1. Sí";
		cout<<endl<<"\t\t2. No"<<endl;
		cout<<"\t\t";
		cin>>g;
		s=atoi(g.c_str());
		if(s<1 || s>2){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
		if(s==2){
			do{
				cout<<endl<<"\t\t¿Qué valor cambiaremos?";
				cout<<endl<<"\t\t1. Valor de w";
				cout<<endl<<"\t\t2. Valor de x";
				cout<<endl<<"\t\t3. Valor de y";
				cout<<endl<<"\t\t2. Valor de z"<<endl;
				cout<<"\t\t";
				cin>>g;
				t=atoi(g.c_str());
				if(t<1 || t>4){
					cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
				}
				if(t==1){
					cout<<endl<<"\t\tw: ";
					cin>>g;
					w=atof(g.c_str());
				}else if(t==2){
					cout<<endl<<"\t\tx: ";
					cin>>g;
					x=atof(g.c_str());
				}else if(t==3){
					cout<<endl<<"\t\ty: ";
					cin>>g;
					y=atof(g.c_str());
				}else if(t==4){
					cout<<endl<<"\t\tz: ";
					cin>>g;
					z=atof(g.c_str());
				}	
			}while(t<1 || t>4);
		}
		a[0][0]=;
		a[0][1]=;
		a[0][2]=;
		a[0][3]=;
		a[1][0]=;
		a[1][1]=;
		a[1][2]=;
		a[1][3]=;
		a[2][0]=;
		a[2][1]=;
		a[2][2]=;
		a[2][3]=;
		a[3][0]=;
		a[3][1]=;
		a[3][2]=;
		a[3][3]=;
		detj=;
		if(detj==0){
			cout<<endl<<"\t\tLa determinante debe ser diferente de 0. Ingresa otros valores."<<endl;
		}
	}while((s<1 || s>=4) || detj==0);
	cout<<endl<<"\t\tMuy bien. Comencemos."<<endl;
	int it, i, j;
	float aj[4][4], f1, f2, f4, f4, ew, ex, ey, ez, wc, xc, yc, zc, auxw=0, auxx=0, auxy=0, auxz=0, eM;
	it=0;
	do{
		cout<<endl<<endl<<"======================================================================================================================"<<endl;
		cout<<endl<<"\t\tIteración "<<it<<endl;
		it++;
		cout<<endl<<"\t\tValor de x = "<<x;
		cout<<endl<<"\t\tValor de z = "<<z;
		a[0][0]=;
		a[0][1]=;
		a[0][2]=;
		a[0][3]=;
		a[1][0]=;
		a[1][1]=;
		a[1][2]=;
		a[1][3]=;
		a[2][0]=;
		a[2][1]=;
		a[2][2]=;
		a[2][3]=;
		a[3][0]=;
		a[3][1]=;
		a[3][2]=;
		a[3][3]=;
		detj=;
		cout<<endl<<"\t\tLa matriz jacobina es: "<<endl;
		for(i=0; i<4; i++){
			cout<<endl<<"\t\t|";
			for(j=0; j<4; j++){
				cout<<"\t"<<a[i][j];
			}
			cout<<"\t|";
		}
		cout<<endl;
		aj[0][0]=;
		aj[0][1]=;
		aj[0][2]=;
		aj[0][3]=;
		aj[1][0]=;
		aj[1][1]=;
		aj[1][2]=;
		aj[1][3]=;
		aj[2][0]=;
		aj[2][1]=;
		aj[2][2]=;
		aj[2][3]=;
		aj[3][0]=;
		aj[3][1]=;
		aj[3][2]=;
		aj[3][3]=;
		cout<<endl<<"\t\tLa matriz inversa de la jacobina es: "<<endl;
		for(i=0; i<4; i++){
			cout<<endl<<"\t\t|";
			for(j=0; j<4; j++){
				cout<<"\t"<<aj[i][j];
			}
			cout<<"\t|";
		}
		cout<<endl;
		f1=;
		f2=;
		f3=;
		f4=;
		wc=w-();
		xc=x-();
		yc=y-();
		zc=z-();
		cout<<endl<<"\t\tValor de wc = "<<wc;
		cout<<endl<<"\t\tValor de xc = "<<xc;
		cout<<endl<<"\t\tValor de yc = "<<yc;
		cout<<endl<<"\t\tValor de zc = "<<zc<<endl;
		ew=fabs(xc-auxw);
		ex=fabs(xc-auxx);
		ey=fabs(zc-auxy);
		ez=fabs(zc-auxz);
		eM=max(ew,ex);
		eM=max(eM,ey);
		eM=max(eM,ez)
		cout<<endl<<"\t\tEl error de w = "<<ew;
		cout<<endl<<"\t\tEl error de x = "<<ex;
		cout<<endl<<"\t\tEl error de y = "<<ey;
		cout<<endl<<"\t\tEl error de z = "<<ez;
		cout<<endl<<"\t\tEl error máximo es = "<<eM<<endl;
		w=wc;
		auxw=wc;
		x=xc;
		auxx=xc;
		y=yc;
		auxy=yc;
		z=zc;
		auxz=zc;
	}while(tol<eM);
	cout<<endl<<endl<<"======================================================================================================================"<<endl;
	cout<<endl<<"\t\tResumen: ";
	cout<<endl<<"\t\tSe contro que w = "<<w<<"x = "<<x<<" y w = "<<w<<" y z = "<<z<<", en "<<it-1<<" iteaciones, con un error de "<<eM<<endl;
	cout<<endl<<endl<<"======================================================================================================================"<<endl;		
}
void casoB(){
	
}
void casoC(){
	string h;
	int s;
	cout<<endl<<"\t\t¿Qué desea hacer?";
	cout<<endl<<"\t\t1. Cambiar de sistema de ecuaciones";
	cout<<endl<<"\t\t2. Mismo sistema con diferentes valores";
	cout<<endl<<"\t\t3. Salir del programa"<<endl;
	do{
		cout<<"\t\t";
		cin>>h;
		s=atoi(h.c_str());
		if(s<1 || s>3){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
	}while(s<1 || s>3);
	return s;
}
void casoA(){
	float tol;
	string g;
	cout<<endl<<"\t\tExcelente. Trabajaremos con las siguientes ecuaciones: "<<endl;
	cout<<endl<<"\t\t4(x^2)(z^3)+4(x^2)+4(z^3)=41";
	cout<<endl<<"\t\t-8(x^2)+24x(z^3)-16(x^3)z=63"<<endl;
	do{
		cout<<endl<<"\t\tDime la tolerancia (0<tolerancia<1): ";
		cin>>g;
		tol=atof(g.c_str());
		if(tol<=0 || tol>=1){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
	}while(tol<=0 || tol>=1);
	float a[2][2], x, z, detj;
	int s, t;
	do{
		cout<<endl<<"\t\tDa valores para las siguientes variables:"<<endl;
		cout<<endl<<"\t\tx: ";
		cin>>g;
		x=atof(g.c_str());
		cout<<endl<<"\t\tz: ";
		cin>>g;
		z=atof(g.c_str());
		cout<<endl<<"\t\tValor de x = "<<x;
		cout<<endl<<"\t\tValor de z = "<<z;
		cout<<endl<<"\t\t¿Quieres continuar con estos valores?";
		cout<<endl<<"\t\t1. Sí";
		cout<<endl<<"\t\t2. No"<<endl;
		cout<<"\t\t";
		cin>>g;
		s=atoi(g.c_str());
		if(s<1 || s>2){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
		if(s==2){
			do{
				cout<<endl<<"\t\t¿Qué valor cambiaremos?";
				cout<<endl<<"\t\t1. Valor de x";
				cout<<endl<<"\t\t2. Valor de z"<<endl;
				cout<<"\t\t";
				cin>>g;
				t=atoi(g.c_str());
				if(t<1 || t>2){
					cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
				}
				if(t==1){
					cout<<endl<<"\t\tx: ";
					cin>>g;
					x=atof(g.c_str());
				}if(t==2){
					cout<<endl<<"\t\tz: ";
					cin>>g;
					z=atof(g.c_str());
				}	
			}while(t<1 || t>2);
		}
		a[0][0]=8.0*x*pow(z,3)+8.0*x;
		a[0][1]=12.0*pow(x,2)*pow(z,2)+12.0*pow(z,2);
		a[1][0]=-16.0*x+24.0*pow(z,3)-48.0*pow(x,2)*z;
		a[1][1]=72.0*x*pow(z,2)-16.0*pow(x,3);
		detj=a[0][0]*a[1][1]-a[0][1]*a[1][0];
		if(detj==0){
			cout<<endl<<"\t\tLa determinante debe ser diferente de 0. Ingresa otros valores."<<endl;
		}
	}while((s<1 || s>=2) || detj==0);
	cout<<endl<<"\t\tMuy bien. Comencemos."<<endl;
	int it, i, j;
	float aj[2][2], f1, f2, ex, ez, xc, zc, auxx, auxz, eM;
	it=0;
	do{
		cout<<endl<<endl<<"======================================================================================================================"<<endl;
		cout<<endl<<"\t\tIteración "<<it<<endl;
		it++;
		cout<<endl<<"\t\tValor de x = "<<x;
		cout<<endl<<"\t\tValor de z = "<<z;
		a[0][0]=8.0*x*pow(z,3)+8.0*x;
		a[0][1]=12.0*pow(x,2)*pow(z,2)+12.0*pow(z,2);
		a[1][0]=-16.0*x+24.0*pow(z,3)-48.0*pow(x,2)*z;
		a[1][1]=72.0*x*pow(z,2)-16.0*pow(x,3);
		detj=a[0][0]*a[1][1]-a[0][1]*a[1][0];
		cout<<endl<<"\t\tLa matriz jacobina es: "<<endl;
		for(i=0; i<2; i++){
			cout<<endl<<"\t\t|";
			for(j=0; j<2; j++){
				cout<<"\t"<<a[i][j];
			}
			cout<<"\t|";
		}
		cout<<endl;
		aj[0][0]=a[1][1]/detj;
		aj[0][1]=-a[0][1]/detj;
		aj[1][1]=a[0][0]/detj;
		aj[1][0]=-a[1][0]/detj;
		cout<<endl<<"\t\tLa matriz inversa de la jacobina es: "<<endl;
		for(i=0; i<2; i++){
			cout<<endl<<"\t\t|";
			for(j=0; j<2; j++){
				cout<<"\t"<<aj[i][j];
			}
			cout<<"\t|";
		}
		cout<<endl;
		f1=4*pow(x,2)*pow(z,3)+4*pow(x,2)+4*pow(z,3)-41;
		f2=-8*pow(x,2)+24*x*pow(z,3)-16*pow(x,3)*z-63;
		xc=x-(aj[0][0]*f1+aj[0][1]*f2);
		zc=z-(aj[1][0]*f1+aj[1][1]*f2);
		cout<<endl<<"\t\tValor de xc = "<<xc;
		cout<<endl<<"\t\tValor de zc = "<<zc<<endl;
		ex=fabs(xc-auxx);
		ez=fabs(zc-auxz);
		eM=max(ex,ez);
		cout<<endl<<"\t\tEl error de x = "<<ex;
		cout<<endl<<"\t\tEl error de z = "<<ez;
		cout<<endl<<"\t\tEl error máximo es = "<<eM<<endl;
		x=xc;
		auxx=xc;
		z=zc;
		auxz=zc;
	}while(tol<eM);
	cout<<endl<<endl<<"======================================================================================================================"<<endl;
	cout<<endl<<"\t\tResumen: ";
	cout<<endl<<"\t\tSe contro que x = "<<x<<" y z = "<<z<<", en "<<it-1<<" iteaciones, con un error de "<<eM<<endl;
	cout<<endl<<endl<<"======================================================================================================================"<<endl;			
}
int salida(){
	char h[]="";
	int s;
	cout<<endl<<"\t\t¿Qué desea hacer?";
	cout<<endl<<"\t\t1. Cambiar de sistema de ecuaciones";
	cout<<endl<<"\t\t2. Mismo sistema con diferentes valores";
	cout<<endl<<"\t\t3. Salir del programa"<<endl;
	do{
		cout<<"\t\t";
		cin>>h;
		s=atoi(h);
		if(s<1 or s>3){
			cout<<endl<<"\t\tValor inválido. Vuelve a ingresar"<<endl;
		}
	}while(s<1 or s>3);
	return s;
}
