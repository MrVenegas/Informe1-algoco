#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


void selectionSort(vector<int> &numeros, int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(numeros[j] < numeros[min]){
                min = j;
            }
        }
        swap(numeros[min], numeros[i]);
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

    selectionSort(numeros, n);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, milli> duration = end - start;

    //Fin de algoritmo y de reloj:

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    
    return 0;
}