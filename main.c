#include <stdio.h>
#include "cache.h"

int main() {
    Cache * cache = newCache ();
    inicializarHash();

    solicitarPagina(cache, 10);
    imprimir(cache);
    solicitarPagina(cache, 25);
    imprimir(cache);
    solicitarPagina(cache, 35);
    imprimir(cache);
    solicitarPagina(cache, 10);
    imprimir(cache);
    solicitarPagina(cache, 15);
    imprimir(cache);
    solicitarPagina(cache, 30);
    imprimir(cache);
    solicitarPagina(cache, 5);
    imprimir(cache);
    solicitarPagina(cache, 60);
    imprimir(cache);


    return 0;
}