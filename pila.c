#include "pila.h"


void inicpila(P_Pila p)
{
       int *aux;
       aux = (int *)malloc(50*sizeof(int));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int elementosPila(P_Pila p){

    int cont = 0;
    while (cont < (*p).postope){
        cont++;
    }

    //printf("\nCalculando los elementos de la pila...\n");
    printf("\nLos elementos de la pila son %d", cont);
    return cont;
}

void cargarElementosCantidad(P_Pila p, int dato){

    int i;

    for (i = 0; i < dato; i++){
        (*p).valores[(*p).postope]=rand()%12+1;
        (*p).postope = (*p).postope + 1;
    }

}

void apilarVariosDatos(P_Pila p, int dato, int dato2, int dato3, int dato4, int dato5)
{
    int i, lista[5] = {dato,dato2,dato3,dato4,dato5};

    for (i=0; i <5; i++){
        (*p).valores[(*p).postope]=lista[i];
        (*p).postope ++ ;
    }
}

int desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

int tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

void ordenarSeleccion(P_Pila p){
    int i,j, aux;

    for (i =0; i <p->postope -1; i++){
        for (j = i + 1; j < p->postope; j++ ){
            if (p->valores[i] > p->valores[j]){
                aux = p->valores[i];
                p->valores[i] = p->valores[j];
                p->valores[j] = aux;
            }
        }
    }
}
