#include <stdlib.h>
#include <stdio.h>
#include "LinkedLists.h"
#include "DoubleLinkedLists.h"
#include "CyclicLinkedLists.h"


int main(){

	DoubleLinkedList *lista = doubleLinkedList();
	LinkedList *lista2 = linkedList();
	CyclicLinkedList *lista3 = cyclicLinkedList();

	for(int i = 0; i <= 5; addDLinkedNode(lista, (void*)i),i++);
	printDLinkedList(lista);
	printDLinkedListRev(lista);
	freeDLinkedList(lista);
	
	for(int i = 0; i <= 5; addLinkedNode(lista2, (void*)i),i++);
	printLinkedList(lista2);
	freeLinkedList(lista2);

	for(int i = 0; i <= 5; addCLinkedNode(lista3, (void*)i),i++);
	
	printCLinkedList(lista3,3);
	printCLinkedListRev(lista3,3);
	freeCLinkedList(lista3);
	
	return 0;


}

