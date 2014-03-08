#include "Stack.h"
#include <stdio.h>
#include "LinkedList.h"
#include "Institution.h"

Stack stack; 

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	Institution *institution; 
	int count, i;
	
	institution = List_removeHead(inputList);
	
	for(count = 0 ; institution != NULL ; count++){
	
	Stack_push(&stack, institution);
	institution = List_removeHead(inputList);
	}	
	
	for(i = 0 ; i<count ; i++){
	institution = Stack_pop(&stack);
	List_addTail(outputList, institution);
	}
	
	
	return count;
}