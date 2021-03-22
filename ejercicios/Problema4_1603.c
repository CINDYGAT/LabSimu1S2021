/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc Problema4_1603.c -o Problema4_1603
Fecha: vier 19 mar 2021 19:16:58 CST
Librerias: stdio (u otras)
Resumen:Desarrolle un programa que lea dos n ́umeros enteros para generar un
rango y que muestre todos los n ́umeros primos en ese rango.
Entrada: Numero N1 y N2 enteros positivos
Salida: es primo o no es primo
*/
#include <stdio.h>
int main(int argc, char const *argv[]) {
  //ingreso de variables
  int N1,N2,i,primo,j;

//Indicando al usuario que debe ingresar dos numeros
  printf("Ingrese dos numeros enteros positivos:\n");
  scanf("%d",&N1);
  scanf("%d",&N2);
//se iniciara el procedimiento para calcular los primos dado un rango
  printf("Los numeros primos en el rango de %d y %d son",N1,N2);

  for (i = N1; i <= N2; i++) { //N1 es el limite inferior y N2 el superior
    j=2;
    primo=1; //flag
    while (j<i && primo==1) { //Asegurando numeros positivos y comprobando flag
      if(i%j==0){ //verificando si N1, valores subsiguientes y N2 son divisibles entre 2
        primo=0;  //si son divisibles
      }
      j++;
    }

    if(primo==1){ //imprimiendo solo los valores primos en el rango
      printf("%d\n",i);
    }
  }
  return 0;
}
