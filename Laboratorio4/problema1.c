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
//declarando variables globales
int vector[]={8,10,6,20,2,4,16,18,12,14};
int longitud=sizeof(vector)/sizeof(vector[0]);

//prototipo de funciones
void desplegar();
void menu();
void ascendente();
void descendente();

//funcion princial
int main(int argc, char const *argv[]) {
  puts("El vector desordenado es");
  desplegar(); //despliega unicamente el vector desordenado
  menu(); //depliega el menu

  //ascendente();
  //descendente();
  return 0;
}

//mostrando el vector desordenado
void desplegar(){
  printf("[");
  for(int i=0; i<longitud; i++){
    printf("%d",vector[i]);
    if(i<longitud-1)
          printf(","); //para imprimir con comas
  }
  printf("]");
    //menu();
}

//mostrando el menu con las opciones
void menu(){
  char eleccion;
  puts("\n");
  puts("Seleccione el método de ordenación \nordenaciones disponibles: \na) Ascendete \nd) Descendente \ns) Salir del menú\n");
  scanf(" %c",&eleccion);

  //creando las opciones disponibles
  switch (eleccion) {
    case 'a': puts("El vector ordenado ascendentemente es:"); ascendente(); break;   //opcion para ordenacion ascendente
    case 'd': puts("El vector ordenado descendentemente es:"); descendente(); break;   //opcion para ordenacion descendente
    case 's': puts("Ha salido del menú"); break;  //opcion para salir del menu
    default:
      puts("Intente de nuevo ingresando una opcion válida. \n"); menu(); break; //opcion para cualquier otra opcion ingresada
  }
}

void ascendente(){
  int i,j,temp, min;
//ordenando por seleccion
  for (i = 0; i < longitud ; i++) {
    min=i;
    for (j=i+1 ; j < longitud; j++) {
      if(vector[j]<vector[min]){
        min=j;
      }
    }
    temp=vector[i];
    vector[i]=vector[min];
    vector[min]=temp;
  }
  //imprimiendo el vector ordenado
  printf("[");
  for(i=0; i<longitud; i++){
    printf("%d",vector[i]);
    if(i<longitud-1)
          printf(","); //para imprimir con comas
  }
  printf("]");
}

void descendente(){
  int i,j,temp, min;
//ordenando por seleccion
  for (i = 0; i < longitud ; ++i) {
    min=i;
    for (j=i+1 ; j < longitud; ++j) {
      if(vector[j]>vector[min]){
        min=j;
      }
    }
    temp=vector[i];
    vector[i]=vector[min];
    vector[min]=temp;
  }
  //imprimiendo el vector ordenado
  printf("[");
  for(i=0; i<longitud; i++){
    printf("%d",vector[i]);
    if(i<longitud-1)
          printf(","); //para imprimir con comas
  }
  printf("]");
}
