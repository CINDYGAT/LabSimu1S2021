/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc problema2.c -o problema2
Fecha: miercoles 5 mayo 2021 08:10:58 CST
Librerias: stdio (u otras)
Resumen: Desarrollar un programa que ordene ascendentemente el vector de 5 posiciones ingresado por el usuario
Salida: vector ordenado ascendentemente
*/
#include<stdio.h>
//prototipo de funciones
void SolicitarVector();
void MostrarVector(int vector[], int longitud);
void OrdenarVector(int vector[], int longitud);

int main(int argc, char const *argv[]) {
  SolicitarVector();
  return 0;
}

//funcion que solicitara al usuario el vector
void SolicitarVector(){
  //declarando variables locales
    int vector[5];
    int longitud, i;
    longitud=sizeof(vector)/sizeof(vector[0]);

    //mensaje al usuario
    puts("Está a punto de ingresar 5 numeros enteros que conformarán el vector deseado:");
    //ingreso del vector
    for (i = 0; i < longitud; i++) {
      printf("Ingrese el vector de la posición %d: ",i);
      scanf("%d",&vector[i]);
    }
    puts("\nEl vector desordenado es:");
    MostrarVector(vector, longitud); //dirigirse a la funcion para mostrar el vector ingresado
    OrdenarVector(vector, longitud); //dirigirse a la funcion para ordenar el vector

}
//se mostrara el vector desordenado y ordenado
void MostrarVector(int vector[], int longitud){
  printf("[");
  for(int i=0; i<longitud; i++){
    printf("%d",vector[i]);
    if(i<longitud-1)
          printf(","); //para imprimir con comas
  }
  printf("]\n");
}
//ordenando el vector ascendentemente
void OrdenarVector(int vector[], int longitud){
  //declarando variables locales
  int i,j,temp;

 for (i = 0; i < longitud; i++) {
  j=i;
  temp=vector[i];
  while ((j>0) && (temp<vector[j-1])) {
    vector[j]=vector[j-1];
    j--;
  }
  vector[j]=temp;
  }
  puts("\nEl vector ordenado ascendentemente es:");
  MostrarVector(vector, longitud);
}
