#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;



int main(){
    speed;
    
    //Lectura de archivo:

    ifstream file("dataset_casi_ordenado.txt");
    vector<int> numeros((istream_iterator<int>(file)), istream_iterator<int>());
    file.close();

    //Inicio del algoritmo y de reloj:

    auto start = chrono::high_resolution_clock::now();

    sort(numeros.begin(), numeros.end());

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<float, milli> duration = end - start;

    //Fin de algoritmo y de reloj:

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    return 0;
}