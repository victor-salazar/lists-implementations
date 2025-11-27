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
	
void arraylist_destroy(Arraylist * list){
	if(list == NULL){
		return;
	}
	
	arraylist_clear(list);
	free(list->data);
	free(list);
}
	
void arraylist_add(ArrayList *list, void element){
	if(list == NULL || element == NULL){
		return;
	}
	if(list->size >= list->capacity){
		arraylist_ensure_capacity(list, list->capacity * GROWH_FACTOR);
	}
	list->data[list->size] = malloc(list->element_size);
	if(list->data[list->size] == NULL){
		printf("Error al asignar memoria para el nuevo elemento\n");
		return;
	}
	
	memcpy(list->data[list->size], element, list->element_size);
	list->size++;
}
	
void arraylist_insert(ArrayList *list, void *element, int index){
	if(list == NULL || element == NULL || index < 0){
		return;
	}
	if(list->size >= list->capacity){
		arraylist_ensure_capacity(list, list->capacity * GROWH_FACTOR);
	}
	
	for(int i=list->size; i>index; i--){
		list->data[i] = list->data[i-1];
	}
	
	list->data[index] = malloc(list->element_size);
	if(list->data[index] == NULL){
		printf("Error al solicitar memoria en la insercion");
		return;
	}
	
	memcpy(list->data[index], element, list->element_size);
	list->size++;
}
	
void arraylist_clear(ArrayList * list){
	if(list == NULL){
		return;
	}
	
	for(int i=0; i<list->size; i++){
		free(list->data[i]);
		list->data[i] = NULL; 
	}
	
	list->size = 0;
}
	
