/*
    Instituto Tecnológico y de Estudios Superiores de Monterrey
    
    Maestría en Inteligencia Artificial Aplicada
    
    Cómputo en la nube
    
    Tarea 1. Programación de una solución paralela
    
    Andre Zaragoza Bonilla - A01797076
    
    01-02-2026

*/

#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int tid;

    double start = omp_get_wtime();

    cout << "Estableciendo la cantidad de Hilos\n";
    int nHilos;
    cout << "Cuantos hilos quieres trabajar: ";
    cin >> nHilos;

    #ifdef _OPENMP
        omp_set_num_threads(nHilos);
    #endif

    int N;
    cout << "Cuantos elementos tendran los arreglos: ";
    cin >> N;

    int* A = new int[N];
    
    int* B = new int[N];
    int* R = new int[N];

    for (int i = 0; i < N; i++) {
        A[i] = (i + 1);
        B[i] = (i + 11);
    }

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();

        #pragma omp master
        {
            cout << "Hay " << omp_get_num_threads() << " hilos\n";
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        R[i] = A[i] + B[i];
    }

    cout << "\nMostrando primeros 10 elementos:\n";
    for (int i = 0; i < 10 && i < N; i++) {
        cout << "A[" << i << "]=" << A[i]
             << "  B[" << i << "]=" << B[i]
             << "  R[" << i << "]=" << R[i] << endl;
    }

    cout << "\nMostrando ultimos 10 elementos:\n";
    int inicio = N - 10;
    if (inicio < 0) inicio = 0;
    for (int i = inicio; i < N; i++) {
        cout << "A[" << i << "]=" << A[i]
             << "  B[" << i << "]=" << B[i]
             << "  R[" << i << "]=" << R[i] << endl;
    }

    double end = omp_get_wtime();

    cout << "\nTiempo transcurrido: " << end - start << " segundos\n";

    delete[] A;
    delete[] B;
    delete[] R;

    return 0;
}