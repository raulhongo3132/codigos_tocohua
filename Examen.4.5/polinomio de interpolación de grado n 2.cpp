#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 10; // Ajusta el tamaño máximo según sea necesario

// Función para aplicar el método de Gauss-Jordan
void gaussJordan(double matrix[][MAX_SIZE + 2], int n) {
    for (int i = 0; i < n; i++) {
        double maxElement = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(matrix[k][i]) > maxElement) {
                maxElement = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Intercambiar filas
        for (int k = i; k <= n; k++) {
            swap(matrix[maxRow][k], matrix[i][k]);
        }

        // Hacer ceros en la columna actual para otras filas
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double coefficient = matrix[k][i] / matrix[i][i];
                for (int j = i; j <= n; j++) {
                    matrix[k][j] -= coefficient * matrix[i][j];
                }
            }
        }
    }

    // Normalizar la diagonal principal a 1
    for (int i = 0; i < n; i++) {
        double diagElement = matrix[i][i];
        for (int j = i; j <= n; j++) {
            matrix[i][j] /= diagElement;
        }
    }
}

int main() {
    int n;
    string g;

    cout << "\t\tPrograma que calcula el modelo de interpolación de grado n e interpola diferentes valores." << endl << endl;

    // Validación de la entrada para el grado del polinomio
    do {
        cout << "\t\tIngrese el grado del polinomio (n): ";
        cin >> g;
        n = atoi(g.c_str());
        if (n < 1 || n > MAX_SIZE) {
            cout << "\t\tPor favor, ingrese un grado válido entre 1 y " << MAX_SIZE << "." << endl;
        }
    } while (n < 1 || n > MAX_SIZE);

    double x[MAX_SIZE + 1], y[MAX_SIZE + 1];

    // Lectura de los puntos (x, y) con validación
    for (int i = 0; i <= n; i++) {
        cout << "\t\tIngrese el valor de x" << i + 1 << ": ";
        cin >> g;
        x[i] = atof(g.c_str());
        cout << "\t\tIngrese el valor de y" << i + 1 << ": ";
        cin >> g;
        y[i] = atof(g.c_str());
    }

    // Verificar que no haya puntos x repetidos
    bool repetir;
    do {
        repetir = false;
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (x[i] == x[j]) {
                    repetir = true;
                    cout << "\t\tNo es posible encontrar el modelo de interpolación debido a puntos x repetidos." << endl;
                    cout << "\t\tIngrese nuevamente el valor de x" << j + 1 << ": ";
                    cin >> g;
                    x[j] = atof(g.c_str());
                    cout << "\t\tIngrese nuevamente el valor de y" << j + 1 << ": ";
                    cin >> g;
                    y[j] = atof(g.c_str());
                }
            }
        }
    } while (repetir);

    double matrix[MAX_SIZE + 1][MAX_SIZE + 2];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = pow(x[i], n - j);
        }
        matrix[i][n + 1] = y[i];
    }

    gaussJordan(matrix, n + 1);

    // Mostrar los coeficientes del polinomio interpolador
    cout << "\t\tEl modelo de interpolación de grado " << n << " es: y = ";
    for (int i = 0; i <= n; i++) {
        cout << matrix[i][n + 1];
        if (n - i > 0) {
            cout << "x^" << (n - i) << " + ";
        }
    }
    cout << endl;

    // Validación de la entrada para el número de datos a interpolar
    int m;
    do {
        cout << "\t\tDígame cuántos datos desea interpolar: ";
        cin >> g;
        m = atoi(g.c_str());
        if (m < 1 || m > MAX_SIZE) {
            cout << "\t\tPor favor, ingrese una cantidad válida de datos a interpolar entre 1 y " << MAX_SIZE << "." << endl;
        }
    } while (m < 1 || m > MAX_SIZE);

    double X[MAX_SIZE], Y[MAX_SIZE];
    for (int i = 0; i < m; i++) {
        cout << "\t\tIngrese el valor de x a interpolar: ";
        cin >> g;
        X[i] = atof(g.c_str());

        Y[i] = 0;
        for (int j = 0; j <= n; j++) {
            Y[i] += matrix[j][n + 1] * pow(X[i], n - j);
        }
    }

    cout << "\t\tLos valores de la tabla interpolada son:" << endl;
    cout << "\t\tx\t|\ty" << endl;
    cout << "\t\t===================" << endl;
    for (int i = 0; i < m; i++) {
        cout << "\t\t" << X[i] << "\t|\t" << Y[i] << endl;
    }

    return 0;
}

