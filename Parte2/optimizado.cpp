#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

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


// Función para trasponer una matriz
vector<vector<int>> transponer(const vector<vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> transpuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    return transpuesta;
}

// Función para multiplicar dos matrices con transposición
vector<vector<int>> multiplicarConTransposicion(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    vector<vector<int>> B_t = transponer(B);
    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));

    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < columnasB; ++j) {
            for (int k = 0; k < columnasA; ++k) {
                resultado[i][j] += A[i][k] * B_t[j][k];
            }
        }
    }
    return resultado;
}

int main() {
    speed;
    vector<vector<int>> matrizA = leerMatrizDesdeArchivo("matriz_A.txt");
    vector<vector<int>> matrizB = leerMatrizDesdeArchivo("matriz_B.txt");

    //Inicio del algoritmo y de reloj:

    auto start = chrono::high_resolution_clock::now();

    multiplicarConTransposicion(matrizA, matrizB);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, milli> duration = end - start;

    //Fin del algoritmo y de reloj:

    cout << "Tiempo de ejecución: " << duration.count() << " ms" << endl;
    return 0;
}