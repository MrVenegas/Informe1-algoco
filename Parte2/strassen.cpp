#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

//Creditos a: https://github.com/rangelak/Strassen-Matrix-Multiplication/blob/master/strassen.cpp

// Función para leer una matriz desde un archivo
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz;
    string linea;

    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return matriz;
    }

    // Leer línea por línea
    while (getline(archivo, linea)) {
        istringstream stream(linea);
        vector<int> fila;
        int numero;
        // Leer los números de una línea y agregarlos a la fila
        while (stream >> numero) {
            fila.push_back(numero);
        }
        matriz.push_back(fila);
    }

    archivo.close();
    return matriz;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filas = A.size();
    int columnas = A[0].size();
    vector<vector<int>> resultado(filas, vector<int>(columnas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    return resultado;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filas = A.size();
    int columnas = A[0].size();
    vector<vector<int>> resultado(filas, vector<int>(columnas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
    return resultado;
}

// Función para dividir una matriz en submatrices
tuple<vector<vector<int>>, vector<vector<int>>, vector<vector<int>>, vector<vector<int>>> dividirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    int m = matriz[0].size();
    int mitadN = n / 2;
    int mitadM = m / 2;

    vector<vector<int>> A11(mitadN, vector<int>(mitadM));
    vector<vector<int>> A12(mitadN, vector<int>(mitadM));
    vector<vector<int>> A21(mitadN, vector<int>(mitadM));
    vector<vector<int>> A22(mitadN, vector<int>(mitadM));

    for (int i = 0; i < mitadN; ++i) {
        for (int j = 0; j < mitadM; ++j) {
            A11[i][j] = matriz[i][j];
            A12[i][j] = matriz[i][j + mitadM];
            A21[i][j] = matriz[i + mitadN][j];
            A22[i][j] = matriz[i + mitadN][j + mitadM];
        }
    }

    return {A11, A12, A21, A22};
}

// Función para recomponer una matriz a partir de submatrices
vector<vector<int>> recomponerMatriz(const vector<vector<int>>& C11, const vector<vector<int>>& C12, const vector<vector<int>>& C21, const vector<vector<int>>& C22) {
    int n = C11.size();
    int m = C11[0].size();
    vector<vector<int>> resultado(2 * n, vector<int>(2 * m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + m] = C12[i][j];
            resultado[i + n][j] = C21[i][j];
            resultado[i + n][j + m] = C22[i][j];
        }
    }

    return resultado;
}

// Implementación del algoritmo de Strassen para multiplicar matrices
vector<vector<int>> multiplicarMatricesStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Dividir las matrices A y B en submatrices
    auto [A11, A12, A21, A22] = dividirMatriz(A);
    auto [B11, B12, B21, B22] = dividirMatriz(B);

    // Calcular las matrices intermedias
    auto M1 = multiplicarMatricesStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    auto M2 = multiplicarMatricesStrassen(sumarMatrices(A21, A22), B11);
    auto M3 = multiplicarMatricesStrassen(A11, restarMatrices(B12, B22));
    auto M4 = multiplicarMatricesStrassen(A22, restarMatrices(B21, B11));
    auto M5 = multiplicarMatricesStrassen(sumarMatrices(A11, A12), B22);
    auto M6 = multiplicarMatricesStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    auto M7 = multiplicarMatricesStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Calcular las submatrices del resultado
    auto C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    auto C12 = sumarMatrices(M3, M5);
    auto C21 = sumarMatrices(M2, M4);
    auto C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    // Recomponer la matriz final
    return recomponerMatriz(C11, C12, C21, C22);
}

int main() {
    speed;

    // Leer las matrices desde los archivos
    vector<vector<int>> matrizA = leerMatrizDesdeArchivo("matriz_A.txt");
    vector<vector<int>> matrizB = leerMatrizDesdeArchivo("matriz_B.txt");

    // Verificar que las matrices fueron leídas correctamente
    if (matrizA.empty() || matrizB.empty()) {
        cerr << "Error al leer las matrices desde los archivos." << endl;
        return 1;
    }

    // Verificar que las matrices tienen dimensiones compatibles para la multiplicación
    int filasA = matrizA.size();
    int columnasA = matrizA[0].size();
    int filasB = matrizB.size();
    int columnasB = matrizB[0].size();

    if (columnasA != filasB) {
        cerr << "Error: Las matrices no se pueden multiplicar debido a dimensiones incompatibles." << endl;
        return 1;
    }

    // Iniciar el reloj para medir el tiempo de ejecución
    auto start = chrono::high_resolution_clock::now();

    // Multiplicar las matrices usando el algoritmo de Strassen
    vector<vector<int>> matrizC = multiplicarMatricesStrassen(matrizA, matrizB);

    // Finalizar el reloj para medir el tiempo de ejecución
    auto end = chrono::high_resolution_clock::now();

    // Calcular la duración en milisegundos
    chrono::duration<float, milli> duration = end - start;

    // Imprimir la matriz resultante

    // Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}