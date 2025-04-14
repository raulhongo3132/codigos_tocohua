#import <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main(){
	setlocale(LC_ALL,"");
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tPractica 1: Equipo NPC's";
	cout<<endl<<"\t\tIntegrantes: ";
	cout<<endl<<"\t\t1. ";
	cout<<endl<<"\t\t2. Lara";
	cout<<endl<<"\t\t3. Leal";
	cout<<endl<<"\t\t4. Sanson Duncan";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. Vargas José";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
	double a, b, fa, fb, xm, fxm, ep, erp, aux=1, rf, frf, xi, fxi, dxi, fdxi, xr, fxr, c, fc, absxifxi;
	int contador=0, iteracion=1;
	char metodo, formato, salida;
	bool salir=true;
	LineMenu:
	do{
		salir=true;
		cout<<endl<<"\tPrograma que calcula la raíz solución de la función";
		cout<<endl<<endl<<"\tf(x)=(x+23)^2*e^((-9/20)*(x+23))-((33/10)*(x+23)^2)-((3/5)*(x+23))+29";
		cout<<endl<<endl<<"\tpor los métodos: "<<endl;
		cout<<endl<<"\tA. Método de la Bisección.";
		cout<<endl<<"\tB. Método de la Regla Falsa.";
		cout<<endl<<"\tC. Método de Punto Fijo (aún no está listo). ";
		cout<<endl<<"\tD. Método de Newton-Raphson. ";
		cout<<endl<<"\tE. Método de la Secante.";
		cout<<endl<<"\tF. Salir del programa. ";
		cout<<endl<<"\tElige la opción deseada: ";
		cin>>metodo;
		LineSubmenu:
		if(metodo=='a' or metodo=='A' or metodo=='b' or metodo=='B' or metodo=='c' or metodo=='C' or metodo=='d' or metodo=='D' or metodo=='e' or metodo=='E'){
			do{
				cout<<endl<<endl<<"\tPara la función: ";
				cout<<endl<<endl<<"\tf(x)=(x+23)^2*e^((-9/20)*(x+23))-((33/10)*(x+23)^2)-((3/5)*(x+23))+29";
				cout<<endl<<endl<<"\t¿Cómo desea que se muestren los resultados?"<<endl;
				cout<<endl<<"\tA. Resultados en forma de bloque.";
				cout<<endl<<"\tB. Resultados en forma de tabla.";
				cout<<endl<<"\tC. Regresar al menú principal. ";
				cout<<endl<<"\tD. Finalizar el programa. ";
				cout<<endl<<"\tElige la opción deseada: ";
				cin>>formato;
				if(formato=='a' or formato=='A' or formato=='b' or formato=='B'){
					salir=false;
				}
				else if (formato=='c' or formato=='C'){
					goto LineMenu;
				}
				else if(formato=='d' or formato=='D'){
					cout<<endl<<endl<<"Adios";
					return 0;
				}
				else{
					cout<<endl<<"\tElige una opción valida."<<endl;
				}
			}while(salir==true);
		}
		else if(metodo=='f' or metodo=='F'){
			cout<<endl<<endl<<"Adios";
			return 0;
		}
		else{
			cout<<endl<<"\tElige una opción valida."<<endl;
		}
	}while(salir==true);

	switch (metodo){
		case 'a':
		case 'A':
			iteracion=1;
			aux=0;
			do{
				if (contador>=3){
					cout<<endl<<endl<<"\tRecomendación: prueba con un límite inferior menor a -25 y un limite superior positivo.";
				}
				cout<<endl<<"\tIngrese el valor inicial o límite inferior[a]: ";
				cin>>a;
				cout<<endl<<"\tIngrese el valor final o límite superior[b]: ";
				cin>>b;
				fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
				fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
				if (a>=b or fa*fb>0){
					cout<<endl<<"\tEste intervalo no contiene la raíz solución. Prueba otro rango. Recuerda que el valor de a debe ser mayor que b."<<endl;
					contador++;
				}
			}while(a>=b or fa*fb>0);
			do{
				cout<<endl<<"\tIngrese la tolerancia en decimales: ";
				cin>>ep;
				if(ep<=0 or ep>1){
					cout<<endl<<"\tTolerancia no válida"<<endl;
				}
			}while(ep<=0 or ep>1);
			
			if(formato=='a' or formato=='A'){
				do{
					cout<<endl<<endl<<"Iteración #"<<iteracion;
					iteracion++;
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					xm=(a+b)/2;
					fxm=pow(xm+23,2)*exp((-9.0/20.0)*(xm+23))-((33.0/10.0)*pow(xm+23,2))-((3.0/5.0)*(xm+23))+29;
					if(xm==0){
						cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
						return 0;
					}
					erp=100*fabs((xm-aux)/xm);
					cout<<endl<<"a="<<a;
					cout<<endl<<"f(a)="<<fa;
					cout<<endl<<"b="<<b;
					cout<<endl<<"f(b)="<<fb;
					cout<<endl<<"Xm="<<xm;
					cout<<endl<<"f(Xm)="<<fxm;
					cout<<endl<<"ER="<<erp;
					if(fa*fxm<0){
						a=a;
						b=xm;	
					}else{
						a=xm;
						b=b;
					}
					aux=xm;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<xm<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;				
			}else if(formato=='b' or formato=='B'){
				cout<<endl<<endl<<"Itera\ta\tf(a)\tb\tf(b)\txm\tf(xm)\ter%"<<endl;
				do{
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					xm=(a+b)/2;
					fxm=pow(xm+23,2)*exp((-9.0/20.0)*(xm+23))-((33.0/10.0)*pow(xm+23,2))-((3.0/5.0)*(xm+23))+29;
					erp=100*fabs((xm-aux)/xm);
					if(xm==0){
						cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
						return 0;
					}
					
					cout<<endl<<iteracion<<"\t"<<a<<"\t"<<fa<<"\t"<<b<<"\t"<<fb<<"\t"<<xm<<"\t"<<fxm<<"\t"<<erp;
					if(fa*fxm<0){
						a=a;
						b=xm;	
					}else{
						a=xm;
						b=b;
					}
					aux=xm;
					iteracion++;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<xm<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;
			}
			break;
		case 'b':
		case 'B':
			iteracion=1;
			aux=0;
			do{
				if (contador>=3){
					cout<<endl<<endl<<"\tRecomendación: prueba con un límite inferior menor a -25 y un limite superior positivo.";
				}
				cout<<endl<<"\tIngrese el valor inicial o límite inferior[a]: ";
				cin>>a;
				cout<<endl<<"\tIngrese el valor final o límite superior[b]: ";
				cin>>b;
				fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
				fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
				if (a>=b or fa*fb>0){
					cout<<endl<<"\tEste intervalo no contiene la raíz solución. Prueba otro rango. Recuerda que el valor de a debe ser mayor que b."<<endl;
					contador++;
				}
			}while(a>=b or fa*fb>0);
			do{
				cout<<endl<<"\tIngrese la tolerancia en decimales: ";
				cin>>ep;
				if(ep<=0 or ep>1){
					cout<<endl<<"\tTolerancia no válida"<<endl;
				}
			}while(ep<=0 or ep>1);
			
			if(formato=='a' or formato=='A'){
				do{
					cout<<endl<<endl<<"Iteración #"<<iteracion;
					iteracion++;
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					rf=a-((fa*(b-a))/(fb-fa));
					frf=pow(rf+23,2)*exp((-9.0/20.0)*(rf+23))-((33.0/10.0)*pow(rf+23,2))-((3.0/5.0)*(rf+23))+29;
					if(rf==0){
						cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
						return 0;
					}
					erp=100*fabs((rf-aux)/rf);
					cout<<endl<<"a="<<a;
					cout<<endl<<"f(a)="<<fa;
					cout<<endl<<"b="<<b;
					cout<<endl<<"f(b)="<<fb;
					cout<<endl<<"Xm="<<rf;
					cout<<endl<<"f(Xm)="<<frf;
					cout<<endl<<"ER="<<erp;
					if(fa*frf<0){
						a=a;
						b=rf;	
					}else{
						a=rf;
						b=b;
					}
					aux=rf;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<rf<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;
			}else if(formato=='b' or formato=='B'){
				cout<<endl<<endl<<"Itera\ta\tf(a)\tb\tf(b)\trf\tf(rf)\ter%"<<endl;
				do{
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					rf=a-((fa*(b-a))/(fb-fa));
					frf=pow(rf+23,2)*exp((-9.0/20.0)*(rf+23))-((33.0/10.0)*pow(rf+23,2))-((3.0/5.0)*(rf+23))+29;
					erp=100*fabs((rf-aux)/rf);
					if(rf==0){
						cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
						return 0;
					}
					
					cout<<endl<<iteracion<<"\t"<<a<<"\t"<<fa<<"\t"<<b<<"\t"<<fb<<"\t"<<rf<<"\t"<<frf<<"\t"<<erp;
					if(fa*frf<0){
						a=a;
						b=rf;	
					}else{
						a=rf;
						b=b;
					}
					aux=rf;
					iteracion++;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<rf<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;	
			}
			break;
		case 'c':
		case 'C':
			iteracion=1;
			aux=0;
			do{
				cout<<endl<<"\tDime el valor inicial: ";
				cin>>xi;
				fdxi=-(exp(-(9.0/20.0)*(xi+23.0)) * (12*exp((9.0/20.0)*(xi+23.0)) + 9*pow(xi, 2) + 374*xi + 3841)) /(132 * pow((10.0/33.0)*pow(xi+23.0, 2)*exp(-(9.0/20.0)*(xi+23.0)) - (2.0/11.0)*(xi+23.0) + (290.0/33.0), 0.5));
				if(fabs(fdxi)>1){
					cout<<endl<<"\tIngrese otro valor para xi"<<endl;
				}
			}while(fabs(fdxi)>1);
			if(formato=='a' or formato=='A'){
				do{
					cout<<endl<<endl<<"Iteración #"<<iteracion;
					iteracion++;
					fxi=pow((10.0/33.0)*pow((xi+23),2)*exp((-9.0/20.0)*(xi+23))-(2.0/11.0)*(xi+23)+(290.0/33.0),(1.0/2.0))-23;
					absxifxi=fabs(xi-fxi);
					cout<<endl<<"xi="<<xi;
					cout<<endl<<"u(xi)="<<xi;
					cout<<endl<<"f(xi)="<<fxi;
					cout<<endl<<"|uxi-fxi|="<<absxifxi;				
					if(fxi==0){
						cout<<endl<<"Se encontró la raíz solución"<<endl;
					}else{
						xi=fxi;	
					}
				}while(absxifxi!=0);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<fxi<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<absxifxi;
				cout<<endl<<endl<<"=================================================================================="<<endl;
			}else if(formato=='b' or formato=='B'){
				cout<<endl<<endl<<"Itera\txi\tu(xi)\tw(xi)\t|uxi-fxi|"<<endl;
				do{
					fxi=pow((10.0/33.0)*pow((xi+23),2)*exp((-9.0/20.0)*(xi+23))-(2.0/11.0)*(xi+23)+(290.0/33.0),(1.0/2.0))-23;
					absxifxi=fabs(xi-fxi);
					cout<<endl<<iteracion<<"\t"<<xi<<"\t"<<fxi<<"\t"<<fxi<<"\t"<<absxifxi<<"\t";
					iteracion++;			
					if(fxi==0){
						cout<<endl<<"Se encontró la raíz solución"<<endl;
					}else{
						xi=fxi;	
					}
				}while(absxifxi!=0);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<xi<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<absxifxi;
				cout<<endl<<endl<<"=================================================================================="<<endl;	
			}
			
			
			
			
			break;
		case 'd':
		case 'D':
			iteracion=1;
			aux=0;
			do{
				cout<<endl<<"\tDime el valor inicial: ";
				cin>>xi;
				fdxi=(exp((-9.0/20.0)*(xi+23))*(-374*xi-3841-9*pow(xi,2))/20.0)-(39.0/5.0)*xi-(897.0/5.0);
				if(fdxi==0){
					cout<<endl<<"\tIngrese otro valor para xi"<<endl;
				}
			}while(fdxi==0);
			do{
				cout<<endl<<"\tIngrese la tolerancia en decimales: ";
				cin>>ep;
				if(ep<=0 or ep>1){
					cout<<endl<<"\tTolerancia no válida"<<endl;
				}
			}while(ep<=0 or ep>1);
			if(formato=='a' or formato=='A'){
				do{
					cout<<endl<<endl<<"Iteración #"<<iteracion;
					iteracion++;
					fxi=pow(xi+23,2)*exp((-9.0/20.0)*(xi+23))-(33.0/10.0)*pow(xi+23,2)-(3.0/5.0)*(xi+23)+29;
					fdxi=(exp((-9.0/20.0)*(xi+23))*(-374*xi-3841-9*pow(xi,2))/20.0)-(39.0/5.0)*xi-(897.0/5.0);
					xr=xi-(fxi/fdxi);
					fxr=fabs(pow(xr+23,2)*exp((-9.0/20.0)*(xr+23))-(33.0/10.0)*pow(xr+23,2)-(3.0/5.0)*(xr+23)+29);
					erp=100*fabs((xr-aux)/xr);
					cout<<endl<<"xi="<<xi;
					cout<<endl<<"f(xi)="<<fxi;
					cout<<endl<<"f'(xi)="<<fdxi;
					cout<<endl<<"Xr="<<xr;
					cout<<endl<<"f(Xr)="<<fxr;
					cout<<endl<<"ER="<<erp;					
					if(fxr==0){
						cout<<endl<<"Se encontró la raíz solución"<<endl;
					}else{
						aux=xr;
						xi=xr;	
					}
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<xr<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;
			}else if(formato=='b' or formato=='B'){
				cout<<endl<<endl<<"Itera\txi\tf(xi)\tb\tf'(xi)\tXr\tf(Xr)\tER"<<endl;
				do{
					fxi=pow(xi+23,2)*exp((-9.0/20.0)*(xi+23))-(33.0/10.0)*pow(xi+23,2)-(3.0/5.0)*(xi+23)+29;
					fdxi=(exp((-9.0/20.0)*(xi+23))*(-374*xi-3841-9*pow(xi,2))/20.0)-(39.0/5.0)*xi-(897.0/5.0);
					xr=xi-(fxi/fdxi);
					fxr=fabs(pow(xr+23,2)*exp((-9.0/20.0)*(xr+23))-(33.0/10.0)*pow(xr+23,2)-(3.0/5.0)*(xr+23)+29);
					erp=100*fabs((xr-aux)/xr);
					if(rf==0){
						cout<<endl<<"Se ha encontrado la raiz solución"<<endl;
						return 0;
					}
					cout<<endl<<iteracion<<"\t"<<xi<<"\t"<<fxi<<"\t"<<fdxi<<"\t"<<xr<<"\t"<<fxr<<"\t"<<erp;
					if(fxr==0){
						cout<<endl<<"Se encontró la raíz solución"<<endl;
					}else{
						aux=xr;
						xi=xr;	
					}
					iteracion++;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<xi<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;	
			}
			break;			
		case 'e':
		case 'E':
			iteracion=1;
			aux=0;	
			do{
				cout<<endl<<"Dime el valor para x1: ";
				cin>>a;
				cout<<endl<<"Dime el valor para x2: ";
				cin>>b;
				fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
				fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
				c=a-(((b-a)*fa)/(fb-fa));
				fc=fabs(pow(c+23,2)*exp((-9.0/20.0)*(c+23))-((33.0/10.0)*pow(c+23,2))-((3.0/5.0)*(c+23))+29);
				if(a==b){
					cout<<endl<<"El valor de x1 y x2 deben ser diferentes";
				}
			}while(a==b);
			do{
				cout<<endl<<"\tIngrese la tolerancia en decimales: ";
				cin>>ep;
				if(ep<=0 or ep>1){
					cout<<endl<<"\tTolerancia no válida"<<endl;
				}
			}while(ep<=0 or ep>1);
			if(formato=='a' or formato=='A'){
				do{
					cout<<endl<<endl<<"Iteración #"<<iteracion;
					iteracion++;
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					c=a-(((b-a)*fa)/(fb-fa));
					fc=fabs(pow(c+23,2)*exp((-9.0/20.0)*(c+23))-((33.0/10.0)*pow(c+23,2))-((3.0/5.0)*(c+23))+29);
					erp=100*fabs((c-aux)/c);
					cout<<endl<<"a="<<a;
					cout<<endl<<"f(a)="<<fa;
					cout<<endl<<"b="<<b;
					cout<<endl<<"f(b)="<<fb;
					cout<<endl<<"c="<<c;
					cout<<endl<<"|f(c)|="<<fc;
					cout<<endl<<"ER="<<erp;
					a=b;
					b=c;
					aux=c;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<c<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;				
			}
			if(formato=='b' or formato=='B'){
				cout<<endl<<endl<<"Itera\ta\tf(a)\tb\tf(b)\tc\t|f(c)|\ter%"<<endl;
				do{
					
					fa=pow(a+23,2)*exp((-9.0/20.0)*(a+23))-((33.0/10.0)*pow(a+23,2))-((3.0/5.0)*(a+23))+29;
					fb=pow(b+23,2)*exp((-9.0/20.0)*(b+23))-((33.0/10.0)*pow(b+23,2))-((3.0/5.0)*(b+23))+29;
					c=a-(((b-a)*fa)/(fb-fa));
					fc=fabs(pow(c+23,2)*exp((-9.0/20.0)*(c+23))-((33.0/10.0)*pow(c+23,2))-((3.0/5.0)*(c+23))+29);
					erp=100*fabs((c-aux)/c);
					cout<<endl<<iteracion<<"\t"<<a<<"\t"<<fa<<"\t"<<b<<"\t"<<fb<<"\t"<<c<<"\t"<<fc<<"\t"<<erp;
					a=b;
					b=c;
					aux=c;
					iteracion++;
				}while(ep<erp);
				cout<<endl<<endl<<"=================================================================================="<<endl;
				cout<<endl<<endl<<"\tLa raíz solucíon es: "<<c<<",se encontró en la iteración #"<<iteracion-1<<", con un error de "<<erp;
				cout<<endl<<endl<<"=================================================================================="<<endl;				
			}
	}
	cout<<endl<<endl<<"\tDesea regresar al menú de métodos (a), menú de formato (b) o salir (c): ";
	cin>>salida;
	switch (salida){
		case 'a':
		case 'A':
			goto LineMenu;
			break;
		case 'b':
		case 'B':
			goto LineSubmenu;
			break;
		case 'c':
		case 'C':
			cout<<endl<<endl<<"\tAdioooooos.";
			break;
		default:
			break;
	}
	return 0;
}
