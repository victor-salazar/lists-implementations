#include "array-list.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	ArrayList *list = arraylist_create(10, sizeof(int));
	
	int age = 17;
	int engineering_students = 80; 
	int subjects = 6;
	int semester = 1;
	int age_popayan = 488;
	int index = 4;
	int remove1 = 0;
	int remove2 = 1;
	
	arraylist_add(list, &age);
	arraylist_add(list, &engineering_students);
	arraylist_add(list, &subjects);
	arraylist_add(list, &semester);
	
	arraylist_insert(list, &age_popayan, index);
	
	int obtained = *(int*)arraylist_get(list, index);
	printf("Popayan tiene %d anios\n", obtained);
	
	arraylist_remove(list, remove1);
	arraylist_remove(list, remove2);
	
	
	arraylist_destroy(list);
	
	return 0;
}
