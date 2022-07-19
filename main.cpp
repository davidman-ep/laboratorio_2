#include <iostream>
#include "librerialab2.h"
#include <ctime>

using namespace std;

#define CASE 16
//  11, 12, 14 y 16
int main()
{
#if CASE==11
    //programa que permita manejar las reservas de asientos en una sala de cine,
    //estos están organizados en 15 filas con 20 (asientos) cada una.
    char opcion='-';
    char **pmatriz=new char*[15];
    inicializarCine(pmatriz);

    do {
        cout<<"menu:\nA.reservar silla.\nO.cancelar silla.\nM.mostrar sala.\nS.salir"<<endl;
        cin>>opcion;
        switch (opcion) {
        case 'A':reservaSilla(pmatriz);
            break;
        case 'O':cancelarSilla(pmatriz);
            break;
        case 'M':mostrarPuestos(pmatriz);
        case 'S':break;
        default:cout<<"opcion incorrecta"<<endl;

        }

    } while (opcion!='S');



   #endif

#if CASE==12
       //    Un cuadrado mágico es una matriz de números enteros sin repetir,
       //    en la que la suma de los números
       //    en cada columna, cada fila y cada diagonal principal tienen
       //    como resultado la misma constante

       cout<<"programa para determinar si es un cuadrado magico."<<endl;
       int dimension=3;
       cout<<"\ningrese la dimension del cuadrado: ";cin>>dimension;
       cuadradoMagico(dimension);

#endif

#if CASE==14

       srand(time(NULL));
       int matrix[5][5];
       matrix_random(matrix);
       menu(matrix);

#endif

#if CASE==16
       //    En una malla de 2x2, realizando únicamente movimientos hacia la derecha y
       //    hacia abajo hay 6 posibles caminos para llegar de la esquina superior izquierda
       //    a la inferior derecha:
       //    Escriba un programa que reciba un numero n y calcule el número de caminos
       //    posibles en una cuadricula de nxn.


       long long int n,numerador=1,divisor=1;
       cout<<"ingrese un numero para su maya de orden nxn: ";cin>>n;
       //el factorial de la suma de dos de sus lados (l+l)!
       //dividido con la multiplicacion de sus lados factoriales l! x l!
       //no superar un n>10

       for(int i=1;i<=(n*2);i++){
           numerador*=i;
           if(i<=n){
               divisor*=i;
           }
       }
       cout<<"una maya de "<<n<<"x"<<n<<" puntos hay "<<numerador/(divisor*divisor)<<" caminos"<<endl;


#endif

    return 0;
}

