//
// Created by Usuario on 10/9/2023.
//

#ifndef CACHELRU_CACHE_H
#define CACHELRU_CACHE_H
#define  MAX 5
#define NUMERODEPAGINAS 100

typedef struct pagina{

    int numeroDePagina;
    struct pagina * ant;
    struct pagina *sig;

}Pagina;

typedef struct cache{

    int capacidad;
    int tam;
    Pagina  * cache;

}Cache;

Pagina * newPagina(int numeroDePagina);
Cache * newCache ();
void inicializarHash();

Pagina * solicitarPagina(Cache * cache, int numeroDePagina);
void apilar(Cache * cache, Pagina * paginaAInsertar);
void eliminarUltimaPagina(Cache * cache);

void imprimir(Cache * cache);

#endif //CACHELRU_CACHE_H
