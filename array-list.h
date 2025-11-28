#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct{
	void **data; //Aqui se almacenan los elementos genericos
	int size; //Numero de elementos que tiene la lista almacenados
	int capacity; //Capacidad máxima de la lista 
	int element_size; //Tamaño en byts de cada elemento
}ArrayList;

//Constructor y destructor

//Constructor -> Inicializa variables en sus valores por defecto y pide memoria para almacenarse
//Destructor -> Realiza las liberaciones de memoria para que el OS pueda voler a usarla

ArrayList* arraylist_create(int initial_capacity, int element_size);
void arraylist_destroy(ArrayList *list);

//Operaciones básicas que toda lista debe llevar
void arraylist_add(ArrayList *list, void *element); //Agrega un elemento al final de la lista 
void arraylist_insert(ArrayList *list, void *element, int index); //Agrega un elemento en la posición 
void *arraylist_get(ArrayList *list, int index); //Obtenemos el elemento en la posición index de la lista
int arraylist_remove(ArrayList *list, int index); //Se quita el elemento en la posición index de la lista
void arraylist_clear(ArrayList *list); //Se borran todos los elementos de la lista

//Funciones usadas para manipular los arreglos dinámicos
void arraylist_ensure_capacity(ArrayList *list, int min_capacity); //Pide más memoria si se está llenando

#endif
