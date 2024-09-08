#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

//Credito: https://www.geeksforgeeks.org/merge-sort/

void merge(vector<int> &numeros, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = numeros[l + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = numeros[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            numeros[k] = L[i];
            i++;
        }else{
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        numeros[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        numeros[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &numeros, int l, int r){
    if(l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(numeros, l, m);
    mergeSort(numeros, m + 1, r);
    merge(numeros, l, m, r);
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

    mergeSort(numeros, 0, n-1);

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, milli> duration = end - start;

    //Fin de algoritmo y de reloj:

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    return 0;
}