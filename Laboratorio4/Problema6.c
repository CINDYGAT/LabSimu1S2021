/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc problema1.c -o problema1
Fecha: miercoles 5 mayo 2021 02:10:58 CST
Librerias: stdio (u otras)
Resumen:Desarrollar un programa que ordene ascendentemente o descendentemente el programa, donde el usuario pueda elegir
el orden, salir del programa o volver a mostrar el menu en caso de que ingrese un valor no mostrado.
Salida: vector ordenado ascendentemente o descendentemente.
*/
#include<stdio.h>
#include<math.h>

//prototipo de funciones
float nIterar(float numero);
float nIterar2(float numero);

int main(int argc, char *argv[]){
  //declarando variables locales
  double answer=0;
  double n;
  int numero;
  printf("Ingresa el numero de iteraciones que quieras realiza: \n");
  scanf("%d",&numero);
  //EJERCICIO1
  double answer1=0;
  for (n=1;n<=numero;n++){
    answer1=answer1 +pow(n,2)*(n-3); //expresion dada
  }
  printf("\nLa solucion del primer problema es:%.2lf\n",answer1);

  //EJERCICIO2
  double resultado=0;
  if (numero==1) { //la serie diverge en n=1
    puts("\nLa serie diverge \n");
  }
  else{
    for (n=2;n<=numero;++n){//pero converge a un punto en cualquier otro
      resultado=resultado + 3/(n-1);//expresion dada
    }
    printf("\nLa solucion del problema 2 es: %.2lf",resultado);
  }

  //EJERCICIO 3
  for (n=1;n<=numero;++n){
    answer=answer + (1/sqrt(5))*nIterar(n)-(1/sqrt(5))*nIterar2(n); //expresion dada
  }
  printf("\nLa solucion del problema 3 es: %.2lf", answer);

  //Ejercicio4
  double sol=0;
  for (n=2;n<=numero;++n){
    sol=sol + 0.1*(3*pow(2,(n-2))+4);//expresion dada
  }
  printf("\nLa solucion del problema 4 es: %.2lf", sol);
  return 0;
}


float nIterar(float numero){//expresion que tambien itera
   double answer = 0;
   answer = answer+pow(((1+sqrt(5))/2),numero); //expresion dada
   return answer;
}

float nIterar2(float numero){//expresion que tambien itera
   double answer = 0;
   answer =answer+ pow(((1-sqrt(5))/2),numero);//expresion dada
   return answer;
}
