#ifndef CYCLIC_LINKED_LISTS_H_
#define CYCLIC_LINKED_LISTS_H_

#include <stdlib.h>
#include <stdio.h>


typedef struct CyclicLinkedList {
	
	struct CyclicLinkedList *previous;
	void *value;
	struct CyclicLinkedList *next;
	int last;
	
} CyclicLinkedList;

CyclicLinkedList *cyclicLinkedList();
void addCLinkedNode(CyclicLinkedList *lista, void* node);
void printCLinkedList(CyclicLinkedList *lista, int iterations);
void printCLinkedListRev(CyclicLinkedList *lista, int iterations);
void freeCLinkedList(CyclicLinkedList *lista);


CyclicLinkedList *cyclicLinkedList(){

	CyclicLinkedList *list = malloc(sizeof(CyclicLinkedList));
	list->previous = list;
	list->value = NULL;
	list->next = list;
	list->last = 1;

}

void addCLinkedNode(CyclicLinkedList *lista, void* node){


	if(lista->value == NULL){
		lista->value = node;
	} else {
		
		CyclicLinkedList *firstNode = lista;
		for(;!lista->last;lista = lista->next);
		
		lista->next = cyclicLinkedList();
		lista->next->value = node;
		lista->next->previous = lista;
		lista->next->next = firstNode;
		lista->next->last = 1;	
		lista->last = 0;
		
		firstNode->previous = lista->next;
		
		lista = firstNode;

	
	}


	

	return;
}

void printCLinkedList(CyclicLinkedList *lista,int iterations){
	
	if(lista->value == NULL) return;
	
	CyclicLinkedList *aux = lista;
	while(iterations > 0){
		
		if(aux->last) iterations--;
		printf("%d,",aux->value);
		aux=aux->next;
	}	
	printf("\n");
	return;


}


void printCLinkedListRev(CyclicLinkedList *lista,int iterations){
	
	if(lista->value == NULL) return;
	
	CyclicLinkedList *aux = lista;
	for(;!aux->last;aux=aux->next);
	while(iterations > 0){
		
		if(aux->previous->last) iterations--;
		printf("%d,",aux->value);
		aux=aux->previous;
	}	
	printf("\n");
	return;


}

void freeCLinkedList(CyclicLinkedList *lista){
	
	
	CyclicLinkedList *prevNode;
	CyclicLinkedList *currNode = lista;
	
	while(!currNode->last){
		prevNode = currNode;
		currNode = currNode->next;
		free(prevNode);
	}
	free(currNode);
	
	return;


}


#endif
