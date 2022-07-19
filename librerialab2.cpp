#include <iostream>
#include "librerialab2.h"
#include <ctime>
using namespace std;
// archivo fuente




void inicializarCine(char **matriz)
{
    for(int i=0;i<15;i++)
         *(matriz+i)=new char[20]{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};

}

void mostrarPuestos(char **matriz)
{
    for(int i=0;i<15;i++){
        for(int j=0;j<20;j++){
            cout<<*(*(matriz+i)+j);
        }
        cout<<endl;
     }
}

void reservaSilla(char **matriz)
{
    int x,y;
    cout<<"ingrese la silla a reservar"<<endl;
    cout<<"fila: ";cin>>y;
    cout<<"columna: ";cin>>x;
    *(*(matriz+(y-1))+(x-1))='+';

}

void cancelarSilla(char **matriz)
{
    int x,y;
    cout<<"ingrese la silla a cancelar"<<endl;
    cout<<"fila: ";cin>>y;
    cout<<"columna: ";cin>>x;
    *(*(matriz+(y-1))+(x-1))='-';
}


void cuadradoMagico(int tam)
{
    int **a=NULL;
    a=new int*[tam]{NULL};
    for(int i=0;i<tam;i++){
        a[i]=new int [tam];
    }

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<"ingrese numeros de fila "<<i+1<<" : "<<endl;//enter en cada numero ingresado
        for(int j=0;j<tam;j++){
            cin>>a[i][j];
        }
    }

    cout<<"impresion de matiz de datos"<<endl;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            cout<<"["<<a[i][j]<<"]";
            cout.flush();
        }
            cout<<endl;
    }

    //determinar si es cuadrado magico

    int sumatoria=0;
    int aux=0;
    bool correcto=true;

    for(int i=0;i<((tam+tam)+2);i++){

        if(i<tam){
            for(int j=0;j<tam;j++){//sumatoria por filas
                sumatoria+=(a[i][j]);
                if(i==0 && j==(tam-1)){
                    aux=sumatoria;
                }
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;
        }

        else if (i>=tam && i<(tam+tam)) {//sumatoria por columnas

            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][i-tam]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;

        }

        else if(i==(tam*2)){//sumatoria por diagonal negativa
            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][j]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;

        }

        else {//sumatoria diagonal positiva

            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][tam-(j+1)]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;
        }


        if(correcto==false){
            cout<<"no es cuadro magico"<<endl;
            break;
        }

    }

    if(correcto==true){
        cout<<"****es cuadro magrico ****"<<endl;
    }

    delete []a;
}
//crear matriz
void matrix_random(int m[][5]){
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            *(*(m+j)+i)=random(26,1);
        }
    }
}
int random(int max,int min){
    int numero;
    numero= rand() % (max-min) + min;
    return numero;
}
//fin creacion de matriz

void mostrar_matrix_random(int c[5][5]){
    cout<<endl;
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            cout<<*(*(c+j)+i)<<"\t";
        }
        cout<<endl<<endl;
    }
}
void girar_matrix(int c[5][5]){
    int mTem[5][5];
    int t;
    //este for usa la matriz temporal para copiar de la original y a su vez girar a la derecha.
        for(int i = 0; i < 5; i++){//fila
            t = 0;
            for(int j = 5-1; j >= 0;j--){//fila nueva
                mTem[i][t] = c[j][i];//inferior izquierda sera superior izquierda en la primera iteración
                t++;
            }
        }
     //la matriz original copia los elementos de la temporal.
        for(int i = 0; i < 5; i++){//fila
            for(int j = 0; j < 5; j++){//columna
                c[i][j] = mTem[i][j];
            }
        }

}

void menu(int matrix[][5])
{

    int opcion;
    do {

        cout<<"menu:\n1-mostrar matriz.\n2-girar 90 grados.\n3-girar 180 grados.\n4-girar 270 grados.\n-5nueva matriz random.\n0-salir.\n";
        cin>>opcion;
        switch (opcion) {
        case 0:
            break;
        case 1:
            mostrar_matrix_random(matrix);//imprime matriz
            break;
        case 2:
            girar_matrix(matrix);//gira 90ª negativos
            break;
        case 3:
            girar_matrix(matrix);//llama función 2 veces para giro de 180ª
            girar_matrix(matrix);
            break;
        case 4:
            girar_matrix(matrix);//llama función 3 veces para giro de 270ª
            girar_matrix(matrix);
            girar_matrix(matrix);
            break;
        case 5:
            matrix_random(matrix);//generar nueva matriz aleatoria
        default:
            cout<<"error******"<<endl;
        }

    } while (opcion!=0);
}
