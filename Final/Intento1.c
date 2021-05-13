#include<stdio.h>
#include<math.h>
#include <stdlib.h>

//definiendo variables globales
float G=6.693e-11; //constante de gravitacion universal
float RT=6.378e6; //Radio de la tierra
float MT=5.9736e24; //masa de la tierra
float R=287.06;   //Constante ideal del gas
float L=6.5e-3;   //Constante termica de la atmosfera
float g0=9.81;   //Gravedad a nivel del mark
float T0=288.15; //temperatira a nivel del mark
float P0=101325; //Presion a nivel del mar
int n=20; //numero de iteraciones

//definiendo los prototipos de funciones
void recorrido(float delta, float mf0, float TSFC, float E0, float m0, float DC, float A); //funcion que devuelve la altura max, vel max tfinal
float mc(float tf,float mf0, float TSFC, float E0, float delta, float m0); //masa del cohete
float mf(float tf, float mf0, float TSFC, float E0, float delta); //la masa del combustible en el tiempo
float tsc(float mf0, float TSFC, float E0); //instante de tiempo en que se agota el combustible
float rho(float y); //calculando la densidad
float g(float y); //calculando la gravedad
float Fa(float CD,float A, float v, float y); //Calulando la friccion atmosferica
//void graficas();

//El main desplegara la informacion que se esta buscando
int main(int argc, char const *argv[]) {
  float E0,TSFC,CD,A,m0,mf0,delta,n;
  float E02,TSFC2,CD2,A2,m02,mf02;
  float E03,TSFC3,CD3,A3,m03,mf03;
  n=1500;
  delta=0.1;

  //constantes del cohete 1
  puts("Nombre:Ah Mun");
  E0=3*pow(10,7); //Empuje del cohete
  TSFC=3.248*pow(10,-4); //consumo especifico del empuje TSFC
  CD=61.27; //coeficiente de forma CD
  A=201.06; //Seccion transversal del cohete
  m0=1.1e5; //masa del propulsor
  mf0=1.5*pow(10,6); //masa inicial del combustible
  mc(n,mf0,TSFC,E0,delta,m0);
  //tsc(TSFC,E0,mf0);
  //Resultado cohete 1
  //Mostrando en pantalla: Nombre, caracteristicas, hmax, instante tiempo cuando se agota el combustible, instante del tiempo de impacto
  printf("\nEmpuje del cohete: %.2e",E0);
  printf("\nconsumo especifico del empuje TSFC: %.2e",TSFC);
  printf("\ncoeficiente de forma CD %.2f",CD);
  printf("\nSeccion transversal del cohete: %.2e",A);
  printf("\nmasa del propulsor: %.2e",m0);
  printf("\nmasa inicial del combustible: %.2e",mf0);
  printf("\nTiempo en segundos en que se agota el combustible es %.2f",tsc(mf0,TSFC,E0));
  //printf("La masa del cohete en el tiempo es: %f",mc(tf,mf0,TSFC,E0,delta,m0));
  recorrido(delta,mf0,TSFC,E0,m0,CD,A);

  //constantes del cohete 2
  puts("\nNombre: Ahau Kin");
  E02=2.7e7; //Empuje del cohete
  TSFC2=2.248e-4;//consumo especifico del empuje TSFC
  CD2=61.27;//coeficiente de forma CD
  A2=201.06; //Seccion transversal del cohete
  m02=1.1e5; //masa del propulsor
  mf02=1.5e6; //masa inicial del combustible
  //resultado cohete 2
  //Mostrando en pantalla Nombre, caracteristicas, hmax, instante tiempo cuando se agota el combustible, instante del tiempo de impacto
  printf("\nEmpuje del cohete: %.2e",E02);
  printf("\nconsumo especifico del empuje TSFC: %.2e",TSFC2);
  printf("\ncoeficiente de forma CD %.2f",CD2);
  printf("\nSeccion transversal del cohete: %.2e",A2);
  printf("\nmasa del propulsor: %.2e",m02);
  printf("\nmasa inicial del combustible: %.2e",mf02);
  printf("\nTiempo en segundos en que se agota el combustible es %.2f",tsc(mf02,TSFC2,E02));
  recorrido(delta,mf02,TSFC2,E02,m02,CD2,A2);

  //constantes del cohete 3.
  puts("\nNombre: Chac");
  E03=2.5e7; //Empuje del cohete
  TSFC3=2.248e-4;//consumo especifico del empuje TSFC
  CD3=70.25;//coeficiente de forma CD
  A3=215.00; //Seccion transversal del cohete
  m03=1.8e5; //masa del propulsor
  mf03=2.1e6;//masa inicial del combustible
  //Resultado cohete 3
  //Mostrando en pantalla Nombre, caracteristicas, hmax, instante tiempo cuando se agota el combustible, instante del tiempo de impacto
  printf("\nEmpuje del cohete: %.2e",E03);
  printf("\nconsumo especifico del empuje TSFC: %.2e",TSFC3);
  printf("\ncoeficiente de forma CD %.2f",CD3);
  printf("\nSeccion transversal del cohete: %.2e",A3);
  printf("\nmasa del propulsor: %.2e",m03);
  printf("\nmasa inicial del combustible: %.2e",mf03);
  printf("\nTiempo en segundos en que se agota el combustible es %.2f",tsc(mf03,TSFC3,E03));
  recorrido(delta,mf03,TSFC3,E03,m03,CD3,A3);

  return 0;
}
//esta funcion mostrara las variables finales e iteraciones de y,t,v
void recorrido(float delta, float mf0, float TSFC, float E0, float m0, float CD, float A){
  //calculo de la altura y la velocidad
  float v,y,m_c,t,fa,ymax,tfinal, m_f; //ymax como variable temporal
  int impacto=0;
  tfinal=1800;
  //tfinal=tsc(mf0,TSFC,E0);
  m_c=mc(tfinal,mf0,TSFC,E0,delta,m0);
  m_f=mf(1800,mf0,TSFC,E0,delta);
  v=0;
  ymax=0;
  y=0.92;
  t=0;
//Creando y escribiendo en el Archivo
FILE *cohete1,*cohete2, *cohete3;
cohete1 = fopen("cohete1.txt", "wt");
cohete2 = fopen("cohete2.txt", "wt");
cohete3 = fopen("cohete3.txt", "wt");
  fprintf(cohete1, "#T          Y      V\n");
  fprintf(cohete2, "#T          Y      V\n");
  fprintf(cohete3, "#T          Y      V\n");
//inicializando el metodo de euler para encontrar v,y,t
  for (int i = 0; i < tfinal; i++) {
    fa=Fa(CD,A,v,y);
    y+=delta*v; //la velocidad utilizando el metodo de euler
    v+=delta*((E0/m_c)-(fa/m_c)-g(y)); //la velocidad utilizando el metodo de Euler
    t+=delta;
    fprintf(cohete1, "%f %f %f\n",t,y,v);
    fprintf(cohete2, "%f %f %f\n",t,y,v);
    fprintf(cohete3, "%f %f %f\n",t,y,v);

    //indicador de altura maxima
    if(y>ymax){ //la altura ira aumentando, hasta que se termine el combustible, y la altura decaera
      ymax=y; //ymax solamente cuenta hasta que se llegue a la altura positiva mas alta
    }
    //indicador de impacto del cohete
    if(v<0 && y==0){
      impacto=1;
      break;
    }
  }
    printf("\nLa altura maxima es %.2f\n", ymax);
    printf("El tiempo final es: %.2f\n", t/60.0); //El tiempo final debe estar dado en minutos

    //cerrando los entornos de texto
    fclose(cohete1);
    fclose(cohete2);
    fclose(cohete3);
}
//para la masa del combustible a traves del tiempo
float mf(float tf, float mf0, float TSFC, float E0, float delta){
float t=0;
float m_f=mf0; //condicion inicial
//resolviendo la EDO para la masa mediante el metodo de euler

  for(int i=0; i<tf;i++){
//bandera necesaria cuando la nave se queda sin combustible, regresa mf=0
  if(m_f<=0 && t!=0){
    E0=0;
    m_f=0;
  //    printf("%f\n", t);
  }
  else{ //la masa va iterando respecto del tiempo
      m_f+=(-TSFC)*E0*delta;
      t+=delta;
  }
}
return m_f;
}
//para la masa del cohete a traves del tiempo
float mc(float tf,float mf0, float TSFC, float E0, float delta, float m0){
  float m_c;
  m_c=m0+mf(tf,mf0,TSFC,E0,delta);
  //printf("La masa del combustible es %f\n", mf(tf,mf0,TSFC,E0,delta));
  return m_c;
}
//Si tomamos la ecuacion de masa del combustible, se observa que la razon de cambio del combustible especificada es la cota superior
//pues este tiende a decrecer hasta llegar a cero
float tsc(float mf0, float TSFC, float E0){
  float tiempo=mf0/(E0*TSFC);
  return tiempo;
}
//calculando la densidad del aire
float rho(float y){
  float densidad;
  //la densidad es valida para alturas inferiores a T0/L
  if(y<T0/L){
    densidad=(P0/(R*T0))*pow((1-((L*y)/T0)), g0/(R*L));
  }
  else{//de lo contrario la densidad es 0
    densidad=0;
  }
  return densidad;
}
//Encontrando la Gravedad
float g(float y){
  float grav=(G*MT)/pow((RT+y),2.0);
return grav;
}
//calculando la fuerza de friccion atmosferica
float Fa(float CD,float A, float v,float y){
  float friccion;
  friccion=(1/2)*rho(y)*CD*A*v*abs(v);
  return friccion;
}

/*
void graph(double sol){
  //cohete1
  //tiempo vs altura
  FILE * pipe = popen("gnuplot -persist","w");
  fprintf(pipe, "load 'prueba1.txt'\n"); //cargando el archivo con las instrucciones de la grafica
//fin del ingreso de informacion al gnuplot enviroment
  pclose(pipe);

  FILE * pipee = popen("gnuplot -persist","w");
  fprintf(pipee, "load 'TvsV1.txt'\n"); //cargando el archivo con las instrucciones de la grafica

  FILE * pipeee = popen("gnuplot -persist","w");
  fprintf(pipeee, "load 'VvsY1.txt'\n"); //cargando el archivo con las instrucciones de la grafica
//fin del ingreso de informacion al gnuplot enviroment
pclose(pipe);
}*/
