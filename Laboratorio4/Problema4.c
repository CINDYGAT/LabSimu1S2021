/*Autor: Cindy Gatica
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilado: gcc problema3.c -o problema3
Fecha: jueves 6 mayo 2021 11:08:30 CST
Librerias: stdio (u otras)
Resumen: Desarrollar un programa genere diferentes operaciones matermaticas
Salida: magnitud, suma, resta, determinante, inversa, transpuesta, solucion
*/
#include<stdio.h>
#include<math.h>
//prototipo de funciones
void MostrarMatriz(int matriz[3][3]);
void cMatriz(int matrizA[3][3]);
void Suma(int matrizA[3][3], int matrizB[3][3]);
void Resta(int matrizA[3][3], int matrizB[3][3]);
void Producto(int matrizA[3][3], int matrizB[3][3]);
int determinante(int matrizA[3][3]);
void transpuesta(int matrizB[3][3]);
void Inversa(int matrizA[3][3]);
void Gauss(int A[3][3]);
void GaussJordan(int B[3][3]);

int main(int argc, char const *argv[]) {
//definiendo las variables locales
int matrizA[3][3];
int matrizB[3][3];
//ingresando la matriz A
puts("Ingrese la matriz A:");
for (int i= 0; i < 3; i++) { //ingresando elementos de la matriz
  for (int j= 0; j < 3; j++) {
    printf("Ingrese el numero de la posicion %d %d: ", i,j);
    scanf("%d", &matrizA[i][j]);
  }
}
//Ingrese la matriz B
puts("\nIngrese la matriz B:");
for (int i= 0; i < 3; i++) { //ingresando elementos de la matriz
  for (int j= 0; j < 3; j++) {
    printf("Ingrese el numero de la posicion %d %d: ", i,j);
    scanf("%d", &matrizB[i][j]);
  }
}
//Mostrando las matrices ingresadas
puts("\nLa matriz A ingresada es:");
MostrarMatriz(matrizA);
puts("La matriz B ingresada es:");
MostrarMatriz(matrizB);
//multiplicacion por constante
cMatriz(matrizA);
//suma de matrices
Suma(matrizA,matrizB);
//resta de matrices
Resta(matrizA, matrizB);
//producto de Matrices
Producto(matrizA, matrizB);
//determinande de la matriz A
int deter= determinante(matrizA);
printf("\nEl determinante de la matriz A es: %d",deter);
//transpuesta de B
puts("\n \nLa matriz transpuesta de B es:");
transpuesta(matrizB);
//Inversa de A
Inversa(matrizA);
//reduccion de Gauss de la matriz A
Gauss(matrizA);
//reduccion de Gauss Jordan de la matriz B
GaussJordan(matrizB);
return 0;
}

void MostrarMatriz(int matriz[3][3]){
  //imprimiendo la matriz
  for (int i= 0; i < 3; i++) {
    for (int j= 0; j <3; j++) {
      printf("%d\t", matriz[i][j]);
    }
    puts(" ");
  }
}
//realizando la multiplicacion por constante
void cMatriz(int matrizA[3][3]){
  int c;
  int matrizN[3][3];
  puts("\nIngrese la constante que multiplicará la matriz A");
  scanf("%d",&c);
  for(int i=0; i<3 ; i++){
    for(int j=0; j<3; j++){
      matrizN[i][j]=c*matrizA[i][j]; //multiplicando cada componente de la matriz por la constante c
    }
  }
  puts("La matriz A multiplicada por la constante es:");
  MostrarMatriz(matrizN);
}
//Sumando matrices A y B
void Suma(int matrizA[3][3], int matrizB[3][3]) {
  //variables locales
  int matrizN[3][3];
  //recorriendo la matriz nueva generada por la suma de componentes
  for(int i=0; i<3 ; i++){
    for(int j=0; j<3; j++){
      matrizN[i][j]=matrizA[i][j]+matrizB[i][j]; //Sumando cada componente de la matrizA y matrizB
    }
  }
  puts("\nLa suma de matrices es:");
  MostrarMatriz(matrizN);
}

//restando matriz
void Resta(int matrizA[3][3], int matrizB[3][3]){
  //variables locales
  int matrizN[3][3];
  //recorriendo la matriz nueva generada por la suma de componentes
  for(int i=0; i<3 ; i++){
    for(int j=0; j<3; j++){
      matrizN[i][j]=matrizA[i][j]-matrizB[i][j]; //Sumando cada componente de la matrizA y matrizB
    }
  }
  puts("\nLa resta de matrices, matA-matB es:");
  MostrarMatriz(matrizN);
}

//multiplicacion de matrices
void Producto(int matrizA[3][3], int matrizB[3][3]) {
//int sum=0;
  int producto[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        int sum=0; //damos valor inicial cero
      for (int g = 0; g < 3; g++) {
        sum +=  matrizA[i][g]*matrizB[g][j]; //multiplicamos f1c1, f2c2, f1c2,...
      }
      producto[i][j] = sum;
    }
  }
  puts("\nEl producto de las matrices es:");
  MostrarMatriz(producto);
}

//calculando el determinante de la matriz A
int determinante(int matrizA[3][3]){
  int det=0;
  for(int i=0;i<3;i++){//manualmente el determinante calculado matrizA[0][0](matriz[2][2]*matriz[3][3]-matriz[3][2]*matriz[2][3]) para las otras componentes tmb
  det = det + (matrizA[0][i]*(matrizA[1][(i+1)%3]*matrizA[2][(i+2)%3] - matrizA[1][(i+2)%3]*matrizA[2][(i+1)%3]));
}
  return det;
}

//calculando la transpuesta de B
void transpuesta(int matrizB[3][3]){
  for (int i= 0; i < 3; i++) {
    for (int j= 0; j <3; j++) {
      printf("%d  ", matrizB[j][i]); //cambiamos las filas por columnas
    }
    puts(" ");
  }
}

//calculando la inversa
void Inversa(int matrizA[3][3]){
  int d,i,j;
  int A[3][3],B[3][3],C[3][3];
  //int MatrizN[3][3];
  d=determinante(matrizA);
  if (d==0) {
    puts("No existe inversa\n"); //toda matriz cuyo determinante=0, no tiene inversa
  }
  else{
    printf("\nLa matriz inversa de A es: \n\n");
    for(i=0;i<3;i++){
       for(j=0;j<3;j++){
           A[i][j]=matrizA[(i+1)%3][(j+1)%3]*matrizA[(i+2)%3][(j+2)%3]; //cofactores
           B[i][j]=-(matrizA[(i+1)%3][(j+2)%3]*matrizA[(i+2)%3][(j+1)%3]); //cofactores
          }
    }
  for (int g= 0; g < 3; g++) {
    for (int k = 0; k < 3; k++) {
      C[g][k]=A[g][k]+B[g][k]/d;  //reescribiendo la matriz con los cofactores
    }
  }
  MostrarMatriz(C);
}
}

//Reduccion de Gauss de la matriz A
void Gauss(int A[3][3]){
  int i,j;
  int c,x[10];
  for(j=0; j<2; j++) //para la matriz triangular
    {
        for(i=0; i<3; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(int k=0; k<3; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[i]=A[i][2]/A[i][i];

    for(i=1; i>=0; i--)
    {
      int sum=0;
        sum=sum+A[i][2]*x[2];
        x[i]=(A[i][2]-sum)/A[i][i];
    }
      printf("\nLa solucion de A es:\n");
    for(i=0; i<2; i++){
      printf("x%d=%d\t",i,x[i]);
    }
}

//Gauss Jordan para la matriz B
void GaussJordan(int B[3][3]){
  int i,j;
  int c,x[10];
  for(j=0; j<2; j++) //para la matriz triangular
    {
        for(i=0; i<3; i++)
        {
            if(i>j)
            {
                c=B[i][j]/B[j][j];
                for(int k=0; k<3; k++)
                {
                    B[i][k]=B[i][k]-c*B[j][k];
                }
            }
        }
    }
    x[i]=B[i][2]/B[i][i];

    for(i=1; i>=0; i--)
    {
      int sum=0;
        sum=sum+B[i][2]*x[2];
        x[i]=(B[i][2]-sum)/B[i][i];
    }
      printf("\nla solucion de B es:\n");
    for(i=0; i<2; i++){
      printf("x%d=%d\t",i,x[i]);
    }
}
