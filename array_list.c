#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

//Los array list empiezan con un numero minimo de elementos que seria esta constante
#define DEFAULT_CAPACITY 10
//Cada que se llene la lista, esta va a crecer, pero no sumandole su capacidad por defecto
//Sino que va creciendo linealmente segun las necesidades
#define GROWH_FACTOR 2

ArrayList* arraylist_create(int initial_capacity, int element_size){
	//El desarrollador puede escoger una capacidad inicial custom, pero si no la define 
	//Se va con la capacidad por defecto
	if(initial_capacity <= 0){
		initial_capacity =DEFAULT_CAPACITY;
	}
	
	ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));
	if(list == NULL){
		printf("No se pudo asignar memoria\n");
		return NULL;	
	}
	
	list->data = (void***)mallo(sizeof(void*) * initial_capacity);
	if(list->data == NULL){
		free(list);
		printf("No se pudo solicitar memoria para los datos de la lista\n");
		return NULL;
	}
	
	list->size = 0;
	list->capacity = initial_capacity;
	list->element_size = element_size;
}
	

