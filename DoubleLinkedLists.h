#ifndef DOUBLE_LINKED_LISTS_H_
#define DOUBLE_LINKED_LISTS_H_

#include <stdlib.h>
#include <stdio.h>


typedef struct DoubleLinkedList {
	
	struct DoubleLinkedList *previous;
	void *value;
	struct DoubleLinkedList *next;
	
} DoubleLinkedList;

DoubleLinkedList *doubleLinkedList();
void addDLinkedNode(DoubleLinkedList *lista, void* node);
void printDLinkedList(DoubleLinkedList *lista);
void printDLinkedListRev(DoubleLinkedList *lista);
void freeDLinkedList(DoubleLinkedList *lista);


DoubleLinkedList *doubleLinkedList(){

	DoubleLinkedList *lista = malloc(sizeof(DoubleLinkedList));
	lista->previous = NULL;
	lista->value = NULL;
	lista->next = NULL;

	return lista;
}

void addDLinkedNode(DoubleLinkedList *lista, void* node){


	if(lista->value == NULL){
		lista->value = node;
	} else {
		
	
		void *firstNode = lista;
		
		for(;lista->next != NULL;lista = lista->next);	
		lista->next = doubleLinkedList();
		lista->next->value = node;
		lista->next->previous = lista;
		
		lista = firstNode;
	
	}


}


void printDLinkedList(DoubleLinkedList *lista){


	
	if(lista->value == NULL) return;
	
	DoubleLinkedList *aux = lista;
	
	printf("%d,",aux->value);
	for(;aux->next != NULL;aux = aux->next,printf("%d,",aux->value));
	printf("\n");
	
	return;

}

void printDLinkedListRev(DoubleLinkedList *lista){

	if(lista->value == NULL) return;
	DoubleLinkedList *aux = lista;
	for(;aux->next != NULL;aux = aux->next);
	printf("%d,",aux->value);
	for(;aux->previous != NULL;aux = aux->previous,printf("%d,",aux->value));
	printf("\n");
	return;
}

void freeDLinkedList(DoubleLinkedList *lista){
	
	
	DoubleLinkedList *prevNode;
	DoubleLinkedList *currNode = lista;
	
	while(currNode->next != NULL){
		prevNode = currNode;
		currNode = currNode->next;
		free(prevNode);
	}
	free(currNode);
	
	return;

}

#endif
