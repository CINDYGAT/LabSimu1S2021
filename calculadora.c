/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc calculadora.c -o calculadora
Fecha: miercoles 7 abril 2021 02:10:58 CST
Librerias: stdio (u otras)
Resumen:Desarrolle una calculadora
Salida: operaciones
*/
#include <stdio.h>
int operacion;
int salir=0;
float primer_numero, segundo_numero;
float sumar(float, float);
float restar(float,float);
float multiplicar(float,float);
float dividir(float,float);
void operaciones();

int main(){
  printf("Seleccione la operacion a realizar \noperaciones disponibles:\n1.suma \n2.resta \n3.multiplicacion\n4.division\n5.salir\n");
  scanf("%d",&operacion);
  printf("Ingrese el primer valor :\n");
  scanf("%f",&primer_numero);
  printf("Ingrese el segundo valor:\n");
  scanf("%f",&segundo_numero);
  operaciones();

return 0;
}

void operaciones() {
  switch (operacion){
        case 1:
            sumar(primer_numero, segundo_numero);
            break;
        case 2:
            restar(primer_numero,segundo_numero);
            break;
        case 3:
            multiplicar(primer_numero,segundo_numero);
            break;
        case 4:
            dividir(primer_numero,segundo_numero);
            break;
        case 5:
            salir=0;
            break;
        default:
            printf("No existe ninguna opcion:");
            break;
  }
}

float sumar(float a, float b){
     return printf("Resultado de la suma: %f ", a+b);
}

float restar(float a, float b) {
    return printf("Resultado de la resta es: %f ",a-b);
}

float multiplicar(float a, float b) {
    return printf("Resultado de la multiplicacion es: %f ",a*b);
}

float dividir(float a, float b) {
    return printf("Resultado de la division es: %f",a/b);
}
