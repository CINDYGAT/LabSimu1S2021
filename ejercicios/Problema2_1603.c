/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc Problema2_1603.c -o Problema2_1603
Fecha: vier 19 mar 2021 19:16:58 CST
Librerias: stdio (u otras)
Resumen:DDesarrolle un programa que calcule la raiz cuadrada entera por defecto de
un numero N positivo dado, R > 0, tal que R^2 <= N.
Entrada: numero N positivo
Salida: raiz de N
*/
#include <stdio.h>
int main(int argc, char const *argv[]) {
  //ingreso de variables
  int N,i;
  //indicando al usuario que ingrese un numero y este se almacena en la variable N
  printf("Ingrese un numero positivo:");
  scanf("%d",&N);

  for(i=1; i*i<=N; i++) { //ciclo para almacenar valores en i
  }

  i=i-1; //raiz de N
  printf("La raiz cuadrada entera de %d es %d",N,i);

  return 0;
}
