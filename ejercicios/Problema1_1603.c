/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc Problema1_1603.c -o Problema1_1603
Fecha: vier 19 mar 2021 19:16:58 CST
Librerias: stdio (u otras)
Resumen:Desarrolle un programa que lea un numero indeterminado de alturas, que
pare cuando se ingrese una negativa y calcule la media, maximo y mınimo.
Entrada: max, min, med, ingreso, media
Salida: media, max, min o no positivos
*/
#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[]){
  //ingreso de variables
float max,min,med,ingreso,media;
int i;
        //Inicializando variables
        i=0;
        med=0;

        printf("Ingrese una altura:"); //indicando al usuario que debe ingresar una altura
        scanf("%f",&ingreso ); //ingreso de valores y almacenamiento en ingreso
        max=ingreso;
        min=ingreso;


            while (ingreso>=0) {
                i=i+1;     //aumentando ciclo
              med=med+ingreso; //sumatoria de todos los ingresos

                if(ingreso>max){ //si el valor de ingreso anterior es mayor al presente, se cambia max
                  max=ingreso;
                }
                if(ingreso<min){ //si el valor de ingreso actual es menor al anterior, se cambia min
                  min=ingreso;
                }
                printf("Ingrese una altura:"); //indicar al usuario que debe ingresar una altura nuecamente
                scanf("%f",&ingreso ); //ingreso de valores y almacenamiento en ingreso
            }

        if(i==0){ //si ingreso fue <0 en la primera iteracion, el usuario ingreso una altura negativa
              printf("No positivos\n");
            }
        else{ //si el ingreso<0 en cualquier otra iteracion, se imprime media, max,min
          media=med/i; //definiendo la media de todos los datos ingresados
            printf("La media es: %f \n", media);
            printf("El maximo es: %f \n", max);
            printf("El minimo es %f \n: ",min);
          }

  return 0;
}
