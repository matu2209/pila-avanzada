#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int ejercicio1(), ejercicio2(), ejercicio3(), ejercicio4(), ejercicio5(),
    ejercicio6(), ejercicio7(), ejercicio8(), ejercicio9(),
    ejercicio10(),ejercicio11(), ejercicio12(), ejercicio13();

int main()
{
    srand(time(NULL));
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //ejercicio4();
    //ejercicio5();
    //ejercicio6();
    //ejercicio7();
    //ejercicio8();
    //ejercicio9();
    //ejercicio10();
    //ejercicio11();
    //ejercicio12();
    //ejercicio13();
    return 0;
}

/*1. Sumar los elementos de una pila (usar variables enteras)*/

int ejercicio1(){

    //VARIABLES A USAR
    Pila pila, auxpila; int acu = 0;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&auxpila);

    //CARGAMOS ELEMENTOS A LA PILA Y MOSTRAMOS COMO ESTA AL FINALIZAR LA CARGA
    cargarElementosCantidad(&pila, 15);//FUNCION PROTOTIPADO QUE CARGA EN CANTADIDAD VARIABLE
    printf("\n\n La pila luego de la carga\n");
    mostrar(&pila);

    //MIENTRAS QUE LA PILA NO ESTA VACIA VA A ACUMULAR SUS VALORES
    while (!pilavacia(&pila)) {
        acu += tope(&pila);
        apilar(&auxpila, desapilar(&pila));
    }

    //DEJAMOS LA PILA COMO ESTABA
    while (!pilavacia(&auxpila)){
        apilar(&pila, desapilar(&auxpila));
    }

    //SE MUESTRA EL RESULTADO
    printf("\n\nLa suma de todos los elementos de la pila es %d", acu);

    return 0;

}

/*2. Contar los elementos de una pila (usar variables enteras)*/

int ejercicio2() {

    //VARIABLES A USAR
    Pila pila, auxpila; int cont = 0;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&auxpila);

    //CARGAMOS LA PILA CON ELEMENTOS Y MOSTRAMOS
    cargarElementosCantidad(&pila, 37);
    mostrar(&pila);

    //CONTAMOS LOS ELEMENTOS DE LA PILA
    while (!pilavacia(&pila)){
        cont++;
        apilar(&auxpila, desapilar(&pila));
    }

    //DEJAMOS LA PILA COMO ESTABA AL PRINCIPIO
    while (!pilavacia(&auxpila)){
        apilar(&pila, desapilar(&auxpila));
    }

    printf("\nLa cantidad de elementos de la pila es %d", cont);
    //O UTILIMAZOS FUNCION PARA CONTAR ELEMENTOS DE PILAS, ALOJADO EN PROTOTIPADO
    elementosPila(&pila);//FUNCION EN EL PROTOTIPADO DEVUELVE ENTERO CON LA CANTIDAD DE ELEMENTOS

    return 0;

}

/*3. Calcular el promedio de los valores de una pila (usar variables)*/

int ejercicio3() {

    //VARIABLES A USAR
    int acu = 0, cont = 0;
    Pila pila, auxpila;
    float promedio;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&auxpila);

    //CARGAR PILA Y MOSTRAR AL MOMENTO COMO ESTA
    cargarElementosCantidad(&pila, 15);
    mostrar(&pila);

    //SUMATORIA Y CONTADOR PARA EL PROMEDIO (HACER FUNCION PARA CALCULAR SUMATORIA)
    while (!pilavacia(&pila)) {
        acu += tope(&pila);
        apilar(&auxpila, desapilar(&pila));
        cont++;
    }

    //DEJAMOS LA PILA COMO ESTABA
    while (!pilavacia(&auxpila)){
        apilar(&pila, desapilar(&auxpila));
    }

    //CALCULAR PROMEDIO MOSTRAR POR PANTALLA
    promedio = acu / cont;
    printf("\n\nEl promedio de los elementos de la pila es %.2f", promedio);
    return 0;
}

/*4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)*/

int ejercicio4() {

    //VARIABLES A USAR
    Pila pila, aux, aux2;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&aux2);

    //CARGA ELEMENTOS A LA PILA Y MOSTRAR COMO ESTA HASTA EL MOMENTO
    cargarElementosCantidad(&pila, 15);
    printf("\n\n La pila luego de la carga\n");
    mostrar(&pila);

    //SE SACA EL VALOR A COMPARAR, LO SACO AFUERA PORQUE ADENTRO ROMPE, PREGUNTAR AL PROFE
    apilar(&aux, desapilar(&pila));

    while (!pilavacia(&pila)) {

        //SE BUSCA EL MENOR VALOR
        if (tope(&pila) < tope(&aux)) {
            apilar(&aux2, desapilar(&aux));
            apilar(&aux, desapilar(&pila));
        } else {
            apilar(&aux2,desapilar(&pila));
        }
    }

    //SE CARGA DE NUEVO LA PILA..SOLO SE SACA EL MENOR VALOR
    while (!pilavacia(&aux2)){
        apilar(&pila,desapilar(&aux2));
    }

    //MOSTRAMOS EL MENOR ELEMENTO
    printf("\n\nUna pila con el menor elemento\n");
    mostrar(&aux);
    return 0;
}

/*5. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
que se conserve el orden. (sin variables enteras, solo pilas)*/

int ejercicio5()
{

    //VARIABLES A USAR
    Pila pila, aux, dato;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&dato);

    //CARGA DE DATOS EN LA PILA Y MOSTRAMOS COMO ESTA AL MOMENTO
    cargarElementosCantidad(&pila,15); //FUNCION DEL PROTOTIPADO PARAMETROS PILA Y VALORES QUE VA A TENER LA PILA
    ordenarSeleccion(&pila);//FUNCION DEL PROTOTIPADO QUE ORDENA LA PILA DE MENOR(BASE) A MAYOR(TOPE) POR SELECCIOON

    //MOSTRAMOS COMO QUEDO LA PILA
    mostrar(&pila);
    cargarElementosCantidad(&dato,1);

    //MOSTRAMOS EL DATO A AGREGAR
    mostrar(&dato);

    //SE BUSCA EL HUECO
    while (!pilavacia(&pila) && tope(&dato) < tope(&pila)){
        apilar(&aux, desapilar(&pila));
    }

    //SE APILA EL DATO
    apilar(&pila,desapilar(&dato));

    //VOLVEMOS A RELLENAR LA PILA CON LOS DATOS QUE SACAMOS
    while(!pilavacia(&aux)){
        apilar(&pila, desapilar(&aux));
    }

    //MOSTRAMOS LA PILA COMO QUEDO
    mostrar(&pila);

    return 0;
}

/*6. Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que
la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
ordenación por selección.*/

int ejercicio6()
{

    //VAIABLES A USAR
    Pila pila, aux, aux2;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&aux2);

    //SE CARGA LA PILA Y SE MUESTRA COMO ESTA
    cargarElementosCantidad(&pila, 20);
    mostrar(&pila);

    while (!pilavacia(&pila)){

        //APILO EL TOPE DEL MOMENTO EN AUX
        apilar(&aux, desapilar(&pila));

        //MIENTRAS QUE LAS PILAS ESTEN CARGADAS HACE EL CICLO
        while (!pilavacia(&aux) && !pilavacia(&pila)){

            //COMPARO TOPES
            if (tope(&aux) > tope(&pila)){

                //SI EL TOPE PILA ES MENOR LO CAMBIO Y SIGO
                apilar(&aux2,desapilar(&aux));
                apilar(&aux,desapilar(&pila));
            } else
                //SINO APILO EN OTRA PILA AUXILIAR QUE VA ACOMODANDO LOS QUE SON MAS GRANDES
                apilar(&aux2,desapilar(&pila));
        }

        //SI SE ME VACIO LA PILA Y LA PILA AUXILIAR2 TIENE DATOS LA VA LLENAR SINO YA ESTA TODO ACOMODADO
        while (!pilavacia(&aux2)){
            apilar(&pila, desapilar(&aux2));
        }
    }

    //PILA ACOMODADA
    mostrar(&aux);
    return 0;

}
//int ejercicio6(){             ESTO ES BURBUJEO!
//
//    //INICIALIZAR PILAS!!
//    Pila pila,aux,aux2;
//
//    //INICIALIZAR PILAS!!
//    inicpila(&pila);
//    inicpila(&aux);
//    inicpila(&aux2);
//
//    //CARGA DE DATOS EN LA PILA Y MOSTRAMOS COMO ESTA AL MOMENTO
//    cargarElementosCantidad(&pila,20);
//    mostrar(&pila);
//
//    //VALOR DE REFERENCIA PARA COMPARAR DENTRO DEL CICLO, PREGUNTAR AL PROFESOR TEMA DE LOGICA
//    apilar(&aux, desapilar(&pila));
//
//    while (!pilavacia(&pila)){
//
//            //COMPARAMOS VALORES Y DAMOS VUELTA LOS ELEMENTOS, PARA MI ES BURBUJEO PORQUE VOY TIRANDO LOS ELEMENTOS PARA
//            //ARRIBA O ABAJO DEPENDIENDO EL SIGNO... O TAMBIEN VOY COMPARANDO Y DANDO VUELTA LOS VALORES
//            if (tope(&pila) < tope(&aux)){
//                apilar(&aux, desapilar(&pila));
//            } else {
//                apilar(&aux2, desapilar(&aux));
//                apilar(&aux, desapilar(&pila));
//                apilar(&aux, desapilar(&aux2));
//            }
//
//            //PREGUNTAR AL PROFE SI ESTA BIEN CARGAR LA PILA EN TODAS LAS VUELTAS.. PERO SOLO SE USA UN WHILE
//            if(pilavacia(&pila)){
//                apilar(&aux2,desapilar(&aux));
//                while (!pilavacia(&aux)){
//                    apilar(&pila,desapilar(&aux));
//                }
//            }
//    }
//
//    //LUEGO DE ORDENAR MOSTRAMOS LA PILA
//    mostrar(&aux2);
//    return 0;
//}

/*7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la
búsqueda.*/

int ejercicio7()
{

    //VARIABLES A USAR
    int encontrado = 0;
    Pila pila, dato, auxPila;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&dato);
    inicpila(&auxPila);

    //CARGA DE DATOS EN LA PILA Y MOSTRAMOS COMO ESTA AL MOMENTO
    cargarElementosCantidad(&pila, 20);
    mostrar(&pila);

    //DATO A BUSCAR HARCODEADO Y TESTEADO PARA ENCONTRAR O NO ENCONTRAR EL ELEMENTO
    apilar(&dato, 2);

    while(!pilavacia(&pila) && encontrado == 0){

        //BUSQUEDA Y FRENO PARA SALIR
        if (tope(&pila) == tope(&dato))
            encontrado = 1;
        else
            apilar(&auxPila, desapilar(&pila));
    }

    //DEJAMOS LA PILA IGUAL A COMO ESTABA SOLO SE SACA EL DATO A BUSCAR
    while (!pilavacia(&auxPila)){
        apilar(&pila, desapilar(&auxPila));
    }

    //VEMOS ESTADO FINAL INFORMAMOS QUE PASO
    if (!encontrado)
        printf("\n El elemento %d, no se encuentra en la pila principal\n", tope(&dato));
    else
        printf("\n El elemento %d, se encuentra en la pila principal\n", tope(&dato));

    return 0;
}

/*8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el
mismo orden.*/

int ejercicio8()
{

    //VARIABLES A USAR
    int encontrado = 0;
    Pila pila, auxPila, dato;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&dato);
    inicpila(&auxPila);

    //CARGA DE DATOS EN LA PILA Y MOSTRAMOS COMO ESTA AL MOMENTO
    cargarElementosCantidad(&pila, 40);
    apilar(&dato, 5);
    printf("\n\nLa pila luego de terminar la carga\n");
    mostrar(&pila);
    printf("\n\nEl dato a elminar de la pila..\n");
    mostrar(&dato);

    while (!pilavacia(&pila)&&encontrado == 0){

        //PEDIA SOLO ELIMINAR EL DATO, PERO.. SI HAY MAS DE UNO LOS SACA A TODOS!
        if (tope(&pila) == tope(&dato)){
            encontrado = 1;
            desapilar(&pila);
        }
        else
            apilar(&auxPila, desapilar(&pila));
    }

    //VOLVEMOS A ACOMODAR LA PILA Y MOSTRAMOS EL RESULTADO FINAL
    while (!pilavacia(&auxPila)){
        apilar(&pila, desapilar(&auxPila));
    }
    printf("\n\nLa pila luego de unos instantes\n\n");
    mostrar(&pila);

    return 0;

}

/*9. Verificar si una pila DADA es capicúa.*/

int ejercicio9()
{

    //VARIABLES A USAR
    Pila pila, auxPila, copiaPila;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&auxPila);
    inicpila(&copiaPila);

    //HARDCODEAMOS LA CAPICUA, SINO VA AESTAR DIFICIL ENCONTRAR UNA CON LA CARGA RANDOM
    apilar(&pila,9);
    apilar(&pila,2);
    apilar(&pila,0);
    apilar(&pila,2);
    apilar(&pila,9);

    //HACEMOS UNA COPIA EXACTA DE LA PILA
    while (!pilavacia(&pila)){
        apilar(&copiaPila, tope(&pila));
        apilar(&auxPila, desapilar(&pila));
    }

    //DAMOS VUELTA LA PILA PARA COMPARAR PRIMER VALOR CON EL ULTIMO, EL 2DO CON EL ANTEULTIMO Y ASI...
    while (!pilavacia(&auxPila)){
        apilar(&pila, desapilar(&auxPila));
    }

    //DESAPILAMOS Y PREGUNTAMOS
    while (!pilavacia(&pila) && tope(&pila) == tope(&copiaPila)){

        apilar(&auxPila, desapilar(&pila));
        desapilar(&copiaPila);//SE PIERDE EL VALOR PERO ES LA COPIA
    }

    while (!pilavacia(&auxPila)){
        apilar(&pila, desapilar(&auxPila));
    }

    //EN CAMBIO SI LA PILA SE VACIO SIGNIFICA QUE ES CAPICUA SINO.. NO, LOS DATOS DE LAS PILAS NO SE MANTUVIERON
    if (pilavacia(&copiaPila))
        printf("\n\nLa pila era capicua");
    else
        printf("\n\nLa pila no era capicua");

    return 0;
}

/*10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos
sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
A : base 1 2 3 tope
B: base 2 3 5 7 tope
Pila AUB = base 3 2 1 7 5 tope*/

int ejercicio10()
{

    //INICIALIZAR PILAS!!
    Pila conjuntoA, conjuntoB, unionAyB, auxConjuntoB;

    //INICIALIZAR PILAS!!
    inicpila(&conjuntoA);
    inicpila(&conjuntoB);
    inicpila(&unionAyB);//ESTE CONJUNTO VA A TENER LA UNION DE LOS DOS
    inicpila(&auxConjuntoB);

    //CARGAMOS LOS CONJUNTOS EN LAS PILAS Y LOS MOSTRAMOS A LOS DOS CONJUNTOS(DESCOMENTAR LINEAS PARA IR PROBANDO)
    //cargarElementosCantidad(&conjuntoA,10);
    //cargarElementosCantidad(&conjuntoB,5);
    apilarVariosDatos(&conjuntoA,2,4,6,8,10);
    apilarVariosDatos(&conjuntoB,1,3,5,7,9);
    //apilarVariosDatos(&conjuntoA,1,3,5,7,9);
    apilarVariosDatos(&conjuntoB,6,8,11,12,13);
    mostrar(&conjuntoA);
    mostrar(&conjuntoB);

    while (!pilavacia(&conjuntoA)){

        while (!pilavacia(&conjuntoB)){

            //COMPARAMOS LOS ELEMENTOS DE LOS CONJUNTOS SI SON IGUALES LOS DESCARTA
            if (tope(&conjuntoB) == tope(&conjuntoA))
                //VAN LOS QUE SE DESCARTAN
                desapilar(&conjuntoB);
            else
                //VAN LOS QUE NO SE DESCARTAN
                apilar(&auxConjuntoB, desapilar(&conjuntoB));
        }

        //LLENAMOS DE NUEVO EL CONJUNTO B CON LOS DATOS QUE NO SE DESCARTARON PARA COMPARAR DE NUEVO
        while (!pilavacia(&auxConjuntoB)){
            apilar(&conjuntoB,desapilar(&auxConjuntoB));
        }
        //SI LLEGO HASTA ACA SIGNIFICA QUE ESE DATO NO ESTA EN EL CONJUNTO B POR LO TANTO QUEDA EN LA PILA FINAL
        apilar(&unionAyB, desapilar(&conjuntoA));
    }

    //SE CARGAN LOS ELEMENTOS DE B QUE NO ESTAN EN A
    while (!pilavacia(&conjuntoB)){
        apilar(&unionAyB,desapilar(&conjuntoB));
    }

    //ORDENAMOS LA UNION PARA QUE QUEDE MAS PROLIJO Y MOSTRAMOS LA UNION
    ordenarSeleccion(&unionAyB);
    printf("\n\nLa union de los conjuntos.\n");
    mostrar(&unionAyB);
    return 0;
}

/*11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).*/

int ejercicio11()
{

    //VARIABLES A USAR
    Pila pila, pila2, ordenadaFinal;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&pila2);
    inicpila(&ordenadaFinal);
    //inicpila(&aux2);

    //SE CARGAN LAS PILAS Y SE LAS ORDENA
    cargarElementosCantidad(&pila, 2);
    cargarElementosCantidad(&pila2, 30);
    ordenarSeleccion(&pila);
    ordenarSeleccion(&pila2);
    mostrar(&pila);
    mostrar(&pila2);

    //
    while (!pilavacia(&pila) && !pilavacia(&pila2))
    {
        if (tope(&pila) > tope(&pila2))
            apilar(&ordenadaFinal, desapilar(&pila));
        else
            apilar(&ordenadaFinal, desapilar(&pila2));
    }
    while (!pilavacia(&pila2)){
        apilar(&ordenadaFinal, desapilar(&pila2));
    }
    while (!pilavacia(&pila)){
        apilar(&ordenadaFinal, desapilar(&pila));
    }

    mostrar(&ordenadaFinal);
    return 0;
}

int ejercicio12()
{

    //INICIALIZAR PILAS!!
    Pila pila, aux, aux2;

    //INICIALIZAR PILAS!!
    inicpila(&pila);
    inicpila(&aux);
    inicpila(&aux2);

    //SE CARGA LA PILA Y SE MUESTRA COMO ESTA
    cargarElementosCantidad(&pila, 15);
    mostrar(&pila);
    //apilar(&aux,desapilar(&pila));
    while (!pilavacia(&pila))
    {

        while (!pilavacia(&pila) && tope(&aux) < tope(&pila))
        {

            apilar(&aux2, desapilar(&aux));
        }

        //SE APILA EL DATO
        apilar(&aux,desapilar(&pila));

        //VOLVEMOS A RELLENAR LA PILA CON LOS DATOS QUE SACAMOS
        while(!pilavacia(&aux2))
        {
            apilar(&pila, desapilar(&aux2));
        }
    }
//    apilar(&aux, desapilar(&pila));
//    while (!pilavacia(&pila) && tope(&aux) < tope(&pila)){
//
//        apilar(&aux2, desapilar(&pila));
//        while (!pilavacia(&aux2)){
//            apilar(&pila, desapilar(&aux2));
//        }
//
//    }
    //MOSTRAMOS LA PILA COMO QUEDO
    //mostrar(&pila);

    mostrar(&aux);
    return 0;

}

/*13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador. Un
jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al
hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos. En caso de
empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del juego de tal
manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro)
distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran
jugado. Utilizar las pilas auxiliares que crea conveniente.*/

int ejercicio13()
{
    int contJugador1 = 0, contJugador2 = 0;
    Pila mazo, jugador1, jugador2, puntosJugador1, puntosJugador2, aux1, aux2;

    //INICIALIZO LAS PILAS QUE VOY A USAR, PODRIA HABER USADO SOLO 4 PERO, PERDERIA CARTAS EN LAS MANOS DE LOS JUGADORES
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&puntosJugador1);
    inicpila(&puntosJugador2);

    //CARGA ELEMENTOS PARAMETRO (&NOMBREPILA, CANTIDAD ELEMENTOS A CARGAR)
    cargarElementosCantidad(&mazo, 12);
    //mostrar(&mazo);//SOLO PARA COBORRAR QUE LOS VALORES VAN DEL 1 AL 12 Y NO INCLUYE EL 0

    //INSTRUCCIONES PARA USUARIOS
    printf("\n\n\nEl juego va a comenzar!\n");
    printf("\n\nEl juego consiste en repartir cartas por ronda (2 para cada jugador), el jugador que sumadas sus cartas tiene mas puntos, se lleva\n las 4 cartas a su pozo, el juego finaliza cuando se termina el mazo de cartas\n\n");
    printf("\n\nPresiona una tecla para continuar..\n");
    getch();

    //MIENTRAS QUE EL MAZO TENGA CARTAS...
    while (!pilavacia(&mazo)){

        //APILO LAS 4 CARTAS EN UN JUGADOR Y UN AUX DE ESE JUGADOR
        apilar(&jugador1,desapilar(&mazo));
        apilar(&aux1,desapilar(&mazo));
        apilar(&jugador2,desapilar(&mazo));
        apilar(&aux2,desapilar(&mazo));

        //AVISO QUE CARTAS TIENE CADA UNO PARA NO HACER "TRAMPA" SIN MOSTRAR QUE CARTAS LE TOCO
        printf("\n\n\n\nLas cartas en esta ronda para el jugador 1 son %d y %d\n", tope(&jugador1), tope(&aux1));
        printf("\n\n\nLas cartas en esta ronda para jugador 2 son %d y %d\n", tope(&jugador2), tope(&aux2));
        printf("\n\nEn esta mano los puntos de los jugadores son Jugador 1: %d, y Jugador 2: %d\n",tope(&jugador1) + tope(&aux1), tope(&jugador2) + tope(&aux2));

        //LA LOGICA PARA VER A QUIEN LE CORRESPONDE GANAR LA MANO
        if ((tope(&jugador1) + tope(&aux1)) >= (tope(&jugador2) + tope(&aux2))){

            //CASO 1 LE DAMOS TODAS LAS CARTAS AL JUGADOR 1
            printf("\n\nEl jugador con mas puntos es Jugador 1, con %d puntos ", tope(&jugador1) + tope(&aux1));
            apilar(&puntosJugador1, desapilar(&jugador1));
            apilar(&puntosJugador1, desapilar(&aux1));
            apilar(&puntosJugador1, desapilar(&jugador2));
            apilar(&puntosJugador1, desapilar(&aux2));
        } else {

            //CASO 2 SE LO DAMOS AL JUGADOR 2
            printf("\n\nEl jugador con mas puntos es Jugador 2, con %d puntos ", tope(&jugador2) + tope(&aux2));
            apilar(&puntosJugador2, desapilar(&jugador1));
            apilar(&puntosJugador2, desapilar(&aux1));
            apilar(&puntosJugador2, desapilar(&jugador2));
            apilar(&puntosJugador2, desapilar(&aux2));
        }

        //MANEJO DE CONTROL PARA DAR INSTRUCCIONES AL USUARIO
        if (!pilavacia(&mazo))
            printf("\n\n Presione una tecla para continuar con la proxima mano\n\n");
        else
            printf("\n\n Se terminaron las cartas vamos a ver quien gano!\n presionar una tecla para continuar...");
        getch();

        //LIMPIAMOS LA PANTALLA ENTRE MANO Y MANO
        system("cls");
    }

    //ACA VOLVEMOS A LLENAR EL MAZO, ESTO ESTA BUENO PORQUE SI TUVIERA UNA CLASE DE CARTA PODRIA JUGAR TODO EL DIA!
    while (!pilavacia(&puntosJugador1)){
        contJugador1 += tope(&puntosJugador1);
        apilar(&mazo, desapilar(&puntosJugador1));
    }
    while (!pilavacia(&puntosJugador2)){
        contJugador2 += tope(&puntosJugador2);
        apilar(&mazo, desapilar(&puntosJugador2));
    }

    //MOSTRAMOS QUIEN FUE EL JUGADOR CON MAS PUNTOS
    if(contJugador1 > contJugador2)
        printf("\nEl jugador con mas puntos fue el Jugador 1 con %d puntos\n", contJugador1);
    else
        printf("\nEl jugador con mas puntos fue el Jugador 2 con %d puntos\n", contJugador2);

    return 0;
}
