/*
Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc Minimoscuadrados2.c -o Minimoscuadrados2
Fecha: Domingo, 2 de mayo 2021 08:10:58 CST
Librerias: stdio, math
Resumen: Desarrollar un programa que compare los valores tabulados y la recta que mejor aproxima el crecimiento.
Estimar la población que existirá en dos años.
Salida: gráfica de los datos dados, función del comportamiento
*/
#include <stdio.h>
#include <math.h>

//Declaracion e inicializacion de variables globales
int tiempo[]={2010,2011,2012,2013,2014,2015,2016,2017,2018,2019,2020};  //año considerado
int poblacion[]={152,166,181,194,205,216,228,238,250,263,270}; //poblacion en mil habitantes
int n = sizeof(tiempo)/sizeof(tiempo[0]);

//prototipo de funciones
void Bienvenida();
float sumdata(int datos[]);
float sumdatamul(int datos1[], int datos2[]); //suma valores multiplicados
void grafica(float m,float b, float r);

int main(){
    //se inicializa las variables necesarias
    float b, m, r;
    //impresion de los datos
    Bienvenida();
    //valores de cada parte de la ecuacion lineal
    m=(n*sumdatamul(tiempo, poblacion)-sumdata(tiempo)*sumdata(poblacion))/(n*sumdatamul(tiempo,tiempo)-sumdata(tiempo)*sumdata(tiempo));
    b=(sumdata(poblacion)-m*sumdata(tiempo))/n;
    //se obtiene el coeficiente de correlacion
    r=(n*sumdatamul(tiempo,poblacion)-(sumdata(tiempo)*sumdata(poblacion)))/sqrt((n*sumdatamul(tiempo,tiempo)-sumdata(tiempo)*sumdata(tiempo))*(n*sumdatamul(poblacion,poblacion)-sumdata(poblacion)*sumdata(poblacion)));
    puts("El comportamiento de la población de Antigua Guatemala con el paso de los años se modela mediante: \n");
    printf("y = %.4f x + %.4f\n",m,b);
    //el coeficiente de determinacion es el cuadrado de r
    printf("Coeficciente de determinacion: %f\n",r*r);
    puts("________________________________________________________________________________\nLa población estimada en 10 años es:");
    printf("y = %.4f mil habitantes\n",2030*m+b);
    //para calcular el valor en 10 años considerariamos el 2030

    //graficando los datos
    grafica(m,b,r); //se envían los valores de m,b y r para desplegarlos en la gráfica

    return 0;
}

//Dialogo introductorio
void Bienvenida(){
  puts("El crecimiento de la poblacion de Antigua Guatemala se comporta de una forma peculiar, como se presenta a continuación \n");
  puts("________________________________________________________________________________");
}

//se realiza la suma de un vector determinado. Realiza sum x, sum y
float sumdata(int datos[]){
    float rep=0;
    for (int i = 0; i <n; i++)
    {
        rep = rep + datos[i]; //suma iterada
    }
    return rep;
}

//se realiza la suma de dos vectores, multiplicando cada uno de sus valores  de forma consecurtiva. sum xx, sum yy, sum xy
float sumdatamul(int datos1[], int datos2[]){
    float rep=0;
    for (int i = 0; i < n; i++)
    {
        rep = rep+ (datos1[i]*datos2[i]);  //suma iterada
    }
    return rep;
}
//graficando la información Población vs anualidad
void grafica(float m,float b, float r){
  //abriendo el gnuplot enviroment
  FILE * pipe = popen("gnuplot -persist","w");
  fprintf(pipe, "set label 'y = %.4f x + %.4f' at 2015,70\n", m,b); //indicando la raiz del grafico
  fprintf(pipe, "set label 'r^2=%.3f' at 2015,50\n",r);
  fprintf(pipe, "load 'prueba1.txt'\n"); //cargando el archivo con las instrucciones de la grafica
//fin del ingreso de informacion al gnuplot enviroment
  pclose(pipe);
}
