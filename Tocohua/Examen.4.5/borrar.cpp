#include <iostream>
#include <cmath>
#include <cstdio> 
#include <stdio.h>
#include <iostream>
#include <locale.h>

// Función de regresión senoidal
double regresionSenoidal(double x, double a0, double a1, double a2, double a3) {
    return a2 * sin(a1 * x + a3) + a0;
}

// Implementación de la regla de Simpson 3/8
double simpson38(double(*f)(double, double, double, double, double), double a0, double a1, double a2, double a3, double a, double b, int n) {
    if (n % 3 != 0) {
        std::cerr << "n debe ser múltiplo de 3." << std::endl;
        return -1;
    }
    
    double h = (b - a) / n;
    double sum = f(a, a0, a1, a2, a3) + f(b, a0, a1, a2, a3);
    
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h, a0, a1, a2, a3);
        } else {
            sum += 3 * f(a + i * h, a0, a1, a2, a3);
        }
    }
    
    return (3 * h / 8) * sum;
}

int main() {
    // Datos de la tabla proporcionada
    double x[] = {2.20, 12.50, 25.00, 3.50, 0.10, 4.40, 6.10, 7.80, 9.50, 23.00, 10.00, 11.50, 18.00, 19.50, 21.00, 22.50, 24.00, 12.00};
    double y[] = {13, 11, 20, 5, 12, 1, 3, 4, 6, 15, 8, 9, 10, 12, 14, 16, 18, 7};
    int n = sizeof(x) / sizeof(x[0]);
    
setlocale(LC_ALL, "");


    printf("=========================================\n");
    printf("Examen Tema 4 Integración numérica y Tema 5 Ajuste de funciones\n");
    printf("Alumno: Carlos Isaac Méndez Davila\n");
    printf("Modelos de regresión :\n");
    printf("=========================================\n\n");
    

    // Mostrar la tabla de datos
   printf("Datos proporcionados:\n"); 
   printf("n\t\tx\t\ty\n"); 
   for (int i = 0; i < n; i++) { 
   printf("%d\t\t%lf\t%lf\n", i+1, x[i], y[i]);
    }

    // Aquí deberíamos realizar el ajuste de los coeficientes (a0, a1, a2, a3)
    // Para simplificar, vamos a usar coeficientes de ejemplo
    double a0 = 0, a1 = 1, a2 = 1, a3 = 0;

    // Mostrar el método de regresión
    printf("\nMétodo de regresión: y = %lf * sin(%lf * x + %lf) + %lf\n", a2, a1, a3, a0);

    getchar(); // Pausa para que el usuario pueda ver el modelo y la tabla

    // Límite de integración
    double a, b;
    int subintervalos;

    // Solicitar valores de a, b y n al usuario
    printf("Introduce el valor de a: ");
    scanf("%lf", &a);
    printf("Introduce el valor de b: ");
    scanf("%lf", &b);
    printf("Introduce el número de subintervalos (múltiplo de 3): ");
    scanf("%d", &subintervalos);
    
    // Validar que n sea múltiplo de 3
    if (subintervalos % 3 != 0) {
        printf("Error: El número de subintervalos debe ser múltiplo de 3.\n");
        return -1;
    }

    double area = simpson38(regresionSenoidal, a0, a1, a2, a3, a, b, subintervalos);
    printf("El área bajo la curva es: %lf\n", area);
    
    return 0;
}
