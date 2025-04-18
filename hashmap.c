#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
    long pos = hash(key, map->capacity);
    Pair* par = createPair(key, value);
    if ((map->buckets)[pos] == NULL)
        (map->buckets)[pos] = par;
    else{
        while(pos != map->capacity){
            ++pos;
            /*if ((map->buckets)[pos] != NULL &&
                ){

            }*/

            if ((map->buckets)[pos] == NULL){
                (map->buckets)[pos] = par;
                break;
            }
        }
    }
    ++(map->size);

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
    HashMap* aux = (HashMap *) malloc(sizeof(HashMap));
    if (aux == NULL) exit(1);
    aux->buckets = (Pair **) calloc(capacity, sizeof(Pair *));
    if (aux->buckets == NULL) exit(1);
    aux->capacity = capacity;
    aux->size = 0;
    aux->current = -1;

    return aux;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
