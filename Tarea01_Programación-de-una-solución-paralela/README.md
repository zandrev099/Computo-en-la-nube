# Tarea 1 – Programación de una solución paralela

## Descripción
En esta tarea se implementa la suma de dos arreglos utilizando programación paralela
con la librería OpenMP en C++.

Se crean dos arreglos A y B de N elementos y un tercer arreglo R, donde cada elemento
R[i] es el resultado de la suma A[i] + B[i].

## Programación paralela
La suma de los arreglos se realiza utilizando un ciclo `for` paralelo con OpenMP,
aprovechando que cada operación es independiente y puede ejecutarse en distintos hilos.

Se permite al usuario definir la cantidad de hilos a utilizar durante la ejecución.

## Archivos
- `main.cpp`: Código fuente de la solución paralela.

## Ejecución
El programa solicita:
- Número de hilos
- Número de elementos de los arreglos

Posteriormente muestra parte de los arreglos A, B y R para verificar el resultado,
así como el tiempo de ejecución.

