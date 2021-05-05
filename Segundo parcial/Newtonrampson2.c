/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc NewtonRaphson2.c -o NewtonRaphson2
Fecha: lunes, 3 de mayo 2021 02:10:58 CST
Librerias: stdio, math
Resumen: Utilizando un metodo numérico, encuentre una raíz de la ecuación f(x) = x−2^(−x).
Realizar la grafica de la ecuaci  ́ on y comparar el resultado obtenido con el programa realizado en C.
Salida: gráfica f(x) = x−2^(−x), solución de la función
*/
#include <stdio.h>
#include <math.h>

//definiendo los prototipos de las funciones a utilizar
double f(double x);
double df(double x);
void NewtonRaphson(double x0, float tol, int maxiter, int *actiter, double *sol);
void graph(double sol);

//funcion main
int main(int argc, char const *argv[]) {
  //definir variables locales
  double x_inicial, xS;
  float tolerancia;
  int iteraciones, Aiteracion;
  //Despliegue de ingreso de informacion e ingreso de datos por parte del usuario
  puts("Ingrese el valor aproximado de x");
  scanf("%lf", &x_inicial);
  puts("Ingrese el valor de la tolerancia");
  scanf("%f", &tolerancia);
  puts("Ingrese el numero maximo de iteraciones");
  scanf("%d", &iteraciones);

  //funcion que encontrara la raiz de la función
  NewtonRaphson(x_inicial, tolerancia, iteraciones, &Aiteracion, &xS);
  //si las iteraciones utilizadas en NR es igual al numero maximo de iteraciones, no existe solucion
  if(Aiteracion == iteraciones){
    printf("No hay solucion despues de %d iteraciones \n",iteraciones);
  }
  //si el numero maximo de iteraciones aún no se ha alcanzado, y se ha encontrado la raiz, desplegar la solución
  else{
    printf("Luego de %d iteraciones, la solucion es %.4lf\n",Aiteracion, xS);
  }
  //graficando la funcion y los puntos aproximados a la raiz
 graph(xS); //solo ingresamos el valor de la solución para ser agregada a la función
  return 0;
}
//ecuacion inicial
double f(double x){
  double res=0;
  res=x-1/pow(2,x);
  return res;
}

//primera derivada de la función
double df(double x){
  double res=0;
  res=1+log(2)/pow(2,x);
  return res;
}

//función de la solucion del problema
void NewtonRaphson(double x0, float tol, int maxiter, int *actiter, double *sol){ //*actiter numeros de iteraciones actual
  //definiendo variables locales
  double xant, x, dif, y;
  int i=1;
  xant=x0;
  y=x0-1/pow(2,x0);
  //solucionar primera iteracion
  x=xant-f(xant)/df(xant);
  //verificar si la resta es menor a 0
  dif=x-xant;
  (dif<0)?dif=-dif:dif; //si la diferencia es <0 entonces dif=-dif-->hacemos positiva, sino dejamos dif como estaba

  FILE *fptr; //se crea una variable de tipo FILE
  //creando el archivo
  fptr = fopen("datos.txt", "w"); //se crea el archivo dato.txt automaticamente y se le da permisos de escritura
  if (fptr == NULL){ //revisando que que el archivo se haya creado correctamente
      printf("Archivo no existe \n"); //si Null-> no se abrió
  }
  //imprimiendo informacion del valor ingresado en la funcion
  fprintf(fptr, "#X          Y\n");
  fprintf(fptr,"%lf %lf \n",x0,y);
//realizando el resto de las iteraciones para encontrar la raiz
  while (dif>tol && i<maxiter) { //verificando que no se haya alcanzado el numero max de iter ni sea menor a tol
    y=x-1/pow(2,x);
    fprintf(fptr, "%lf %lf \n",x,y);
    xant=x;
    x=xant-f(xant)/df(xant);
    printf("%lf\n",x);
    dif=x-xant;
    (dif<0)?dif=-dif:dif; //verificando que se tome solamente la parte positiva
    i++;
  }
  //fin del ingreso de datos al archivo de texto
    fclose(fptr);
  //apuntar a la memoria para la respuesta
  *sol=x;
  *actiter=i;
}

void graph(double sol){
  //abriendo el gnuplot enviroment
  FILE * pipe = popen("gnuplot -persist","w");
  fprintf(pipe, "set label 'Raiz en x = %.4f' at 1,-1\n", sol); //indicando la raiz del grafico
  fprintf(pipe, "load 'prueba.txt'\n"); //cargando el archivo con las instrucciones de la grafica
//fin del ingreso de informacion al gnuplot enviroment
pclose(pipe);
}
