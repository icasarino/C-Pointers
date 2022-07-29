#ifndef LINKED_LISTS_H_
#define LINKED_LISTS_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList {
	
	void *value;
	struct LinkedList *next;
	
} LinkedList;

LinkedList *linkedList();
void addLinkedNode(LinkedList *lista, void* node);
void printLinkedList(LinkedList *lista);
void freeLinkedList(LinkedList *lista);

LinkedList *linkedList(){

	LinkedList *lista = malloc(sizeof(LinkedList));
	lista->value = NULL;
	lista->next = NULL;

	return lista;

}

void addLinkedNode(LinkedList *lista, void* node){

	
	if(lista->value == NULL){
		lista->value = node;
	} else {
	
		void *firstNode = lista;
		for(;lista->next != NULL;lista = lista->next);	
		lista->next = linkedList();
		lista->next->value = node;
		
		lista = firstNode;
	}
	
	return;

}

void printLinkedList(LinkedList *lista){


	
	if(lista->value == NULL) return;
	
	LinkedList *aux = lista;
	
	printf("%d,",aux->value);
	for(;aux->next != NULL;aux = aux->next,printf("%d,",aux->value));
	printf("\n");

	return;


}

void freeLinkedList(LinkedList *lista){
	
	LinkedList *prevNode;
	LinkedList *currNode = lista;
	while(currNode->next != NULL){
		prevNode = currNode;
		currNode = currNode->next;
		free(prevNode);
	}
	free(currNode);
	return;
	
	

}








#endif
