//
// Created by Usuario on 10/9/2023.
//

#include "cache.h"
#include "malloc.h"
#include "stdio.h"

Pagina * hash[NUMERODEPAGINAS];

Pagina * newPagina(int numeroDePagina){// asigno espacio de memoria para una nueva pagina

    Pagina * aux = NULL;
    aux = malloc(sizeof(Pagina));

    if (aux == NULL){
        printf ("No hay espacio de memoria disponible.");
        exit (-1);
    }
    else {
        aux->numeroDePagina = numeroDePagina;
        aux->sig = NULL;
        aux->ant = NULL;
    }
    return aux;
}
Cache * newCache (){//asigno espacio de memoria para una nueva cache

    Cache * aux = NULL;
    aux = malloc (sizeof(Cache));

    if (aux == NULL){
        printf ("No hay espacio de memoria disponible.");
        exit (-1);
    }
    else{
        aux->capacidad = MAX;
        aux->tam = 0;
        aux->cache = NULL;
    }
    return aux;
}
void inicializarHash(){// inicializo el hash

    for (int i = 0 ; i < NUMERODEPAGINAS ; i++){
        hash[i] = NULL;
    }

}

Pagina * solicitarPagina(Cache * cache, int numeroDePagina){//solicita una pagina a la cache

    Pagina * pagina = hash[MAX]; // la busca dentro de hash

    if (pagina == NULL){//si no esta, inicializa la pagina

        pagina = newPagina(numeroDePagina);

        if (cache->capacidad == cache->tam){//si la cache esta llena elimina la ultima pagina
            eliminarUltimaPagina(cache);
        }
        apilar(cache, pagina);//agrega la nueva pagina a la cache
    }else{

        if (cache->cache != pagina){//insertarla a la cache
            pagina->ant->sig = pagina->sig;
            if (pagina->sig!=NULL){//si es la ultima
                pagina->sig->ant = pagina->ant;
            }

            cache->cache = pagina; //asigno el puntero de la cache a la pagina
        }
    }
    return pagina;//devuelvo la pagina
}

void apilar(Cache *cache, Pagina * paginaAInsertar){//agrega la nueva pagina a la cache
    if (cache->cache != NULL){
        cache->cache->ant= paginaAInsertar;
    }

    paginaAInsertar->sig = cache->cache;
    paginaAInsertar->ant = NULL;
    cache->cache=paginaAInsertar;
    hash[paginaAInsertar->numeroDePagina]=paginaAInsertar;
    cache->tam ++;
}

void eliminarUltimaPagina(Cache * cache){//elimina la ultima pagina de la cache

    Pagina * aux = cache->cache;

    if (aux != NULL){//mientras cache no termina

        for (;aux->sig != NULL; aux=aux->sig){}//recorre la cache
        aux->ant->sig=NULL;
        hash[aux->numeroDePagina]=NULL;//vacia el numero de la pagina

        free(aux);
        cache->tam --;//disminuye el tamanio
    }

}

void imprimir(Cache * cache){

    Pagina * aux = cache->cache;

    printf("\nPaginas de la cache: \n");
    for (;aux!= NULL; aux=aux->sig){//recorre la cache
        printf("\t%d", aux->numeroDePagina);
    }
}