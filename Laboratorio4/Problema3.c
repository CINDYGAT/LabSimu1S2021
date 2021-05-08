/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc problema3.c -o problema3
Fecha: miercoles 5 mayo 2021 10:11:53 CST
Librerias: stdio (u otras)
Resumen: Desarrollar un programa que ordene ascendentemente el vector de 5 posiciones ingresado por el usuario
Salida: vector ordenado ascendentemente
*/
#include <stdio.h>
#include <math.h>
//prototipo de funciones
void MostrarVector(float vector[], int longitud);
float magnitud(float vector[]);
void suma(float vector1[], float vector2[]); //pues no se puede retornar un vector
float Productoescalar(float vector1[], float vector2[], int longitud); //si puede retornar un valor discreto
void Productovectorial(float vector1[], float vector2[]); //retorna un vector

int main(int argc, char const *argv[]) {
  //definiendo variables locales
  int i, longitud;
  float magnitud1,magnitud2,escalar;
  float vector1[3];
  float vector2[3];
  longitud=sizeof(vector1)/sizeof(vector1[0]);

  //Pidiendo ambos vectores
  puts("A continuacion debe ingresar dos vectores de la forma (x,y,z) para ser operados\n");
  puts("Ingrese los valores del vector 1");
  for(i=0; i<longitud; i++){
    scanf(" %f",&vector1[i]);
  }
  puts("Ingrese los valores del vector 2");
  for(i=0; i<longitud; i++){
    scanf(" %f",&vector2[i]);
  }
  //llamando a las funciones para desplegar el vector indicado
  puts("\nMostrando los vectores ingresado acontinuacion");
  puts("El vector 1 ingresado es:");
  MostrarVector(vector1,longitud);
  puts("El vector 2 ingresado es:");
  MostrarVector(vector2,longitud);

  //Ejecutando las operaciones a realizar
  //puts("La magnitud del vector 1 y 2, son respectivamente :");
  magnitud1=magnitud(vector1);
  magnitud2=magnitud(vector2);
  printf("\nLa magnitud del vector 1 es: %.2f\n",magnitud1);
  printf("La magnitud del vector 2 es: %.2f\n",magnitud2);
//suma
  suma(vector1,vector2);
  escalar=Productoescalar(vector1,vector2,longitud); //pues retorna un valor
  printf("El producto escalar es: %.2f", escalar);
//Producto vectorial
  Productovectorial(vector1,vector2);
  return 0;
}
//Motrando el vector especificado
void MostrarVector(float vector[], int longitud){
  printf("[");
  for(int i=0; i<longitud; i++){
    printf("%.1f",vector[i]);
    if(i<longitud-1)
          printf(","); //para imprimir con comas
  }
  printf("]\n");
}

//Operando las magnitudes
float magnitud(float vector[]){
  float norma;
  norma=sqrt((vector[0]*vector[0])+(vector[1]*vector[1])+(vector[2]*vector[2]));
  return norma;
}

//Operando la suma
void suma(float vector1[], float vector2[]){
  float x,y,z;
  x=vector1[0]+vector2[0]; //se suman las componentes x
  y=vector1[1]+vector2[1]; //se suman las componentes y
  z=vector1[2]+vector2[2]; //se suman las componentes z
  printf("La suma de los vectores es: [%.2f,%.2f,%.2f]\n",x,y,z);
}

//Operando el producto escalar
float Productoescalar(float vector1[], float vector2[], int longitud)
{
	float resultado = 0;
	for (int i=0; i < longitud; i++) {
		resultado += vector1[i] * vector2[i]; //multiplicamos las componentes x con x, y con y, z con z. Y sumarlas
	}
	return resultado;
}

//Operando el producto Productovectorial
void Productovectorial(float vector1[], float vector2[]){
  float x,y,z;
  x=(vector1[1]*vector2[2])-(vector1[2]*vector2[1]); //componentes x
  y=(vector1[2]*vector2[0])-(vector1[0]*vector2[2]); //componentes y
  z=(vector1[0]*vector2[1])-(vector1[1]*vector2[0]); //componentes z
  printf("\nEl producto vectorial de los vectores es: [%.2f,%.2f,%.2f]\n",x,y,z);
}
