#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

//Creditos: https://www.geeksforgeeks.org/quick-sort-algorithm/

int particion(vector <int> &numeros, int inicio, int fin){
    int pivote = numeros[fin];
    int i = inicio - 1;

    for(int j = inicio; j < fin; j++){
        if(numeros[j] < pivote){
            i++;
            swap(numeros[i], numeros[j]);
        }
    }
    swap(numeros[i+1], numeros[fin]);
    return i+1;
}

void quickSort(vector <int> &numeros, int inicio, int fin){
    if(inicio < fin){
        int pivote = particion(numeros, inicio, fin);
        quickSort(numeros, inicio, pivote - 1);
        quickSort(numeros, pivote + 1, fin);
    }
}

int main(){
    speed;
    
    //Lectura de archivo:

    ifstream file("dataset_casi_ordenado.txt");
    vector<int> numeros((istream_iterator<int>(file)), istream_iterator<int>());
    file.close();

    int n = numeros.size();
    
    //Inicio del algoritmo y de reloj:

    auto start = chrono::high_resolution_clock::now();

    quickSort(numeros, 0, n-1);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, milli> duration = end - start;

    //Fin de algoritmo y de reloj:

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    return 0;
    
}   
