#include <stdlib.h>
#include <stdio.h>
#include "LinkedLists.h"
#include "DoubleLinkedLists.h"


int main(){

	DoubleLinkedList *lista = doubleLinkedList();
	LinkedList *lista2 = linkedList();
		
	for(int i = 0; i <= 5; addDLinkedNode(lista, (void*)i),i++);
	printDLinkedList(lista);
	printDLinkedListRev(lista);
	freeDLinkedList(lista);
	
	for(int i = 0; i <= 5; addLinkedNode(lista2, (void*)i),i++);
	printLinkedList(lista2);
	freeLinkedList(lista2);
	
	
	return 0;


}

