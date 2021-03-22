/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc Problema3_1603.c -o Problema3_1603
Fecha: vier 19 mar 2021 19:16:58 CST
Librerias: stdio (u otras)
Resumen:Desarrolle un programa que lea un numero mayor que 1 y determine si es
primo.
Entrada: Numero N mayor a 1
Salida: es primo o no es primo
*/
#include <stdio.h>
int main(int argc, char const *argv[]) {
  //ingreso de variables
  int N,i,primo;
  //indicando al usuario que ingrese un numero y este se almacena en la variable N
  printf("Ingrese un numero:");
  scanf("%d",&N);

  primo=1; //Inicializando variable

  for(i=2; (i<N-1 && primo==1) ; i++){
    if(N%i==0){ //verificando si N es divisible entre otro valor distinto de 1
      primo=0;  //si es divisible, primo 1->primo 0-> no es primo
    }
  }

  if(primo==0){ //N es divisible entre otros valores distintos a 1 y el mismo, no es primo
    printf("No es primo");
  }
  else{
    printf("Es primo"); //solo es divisible entre 1 y el mismo, es primo
  }

  return 0;
}
