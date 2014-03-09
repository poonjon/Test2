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

int Institution_select( LinkedList *inputList, 
						LinkedList *outputList,
						void *criterion,
						int (*compare)(void*, void *)){
						
	Institution *institution;
	int count, i;
	
	institution = List_removeHead(inputList);
	institution = List_removeHead(inputList);
	institution = List_removeHead(inputList);
	Stack_push(&stack, institution);
	institution = List_removeHead(inputList);
	institution = Stack_pop(&stack);
	List_addTail(outputList, institution);
	
	
	if((*compare)((InstitutionType*)criterion , (Institution*)institution) != 1){
		return 0;
	}
	
	else
		return 1;
}
						
					

int isUniversityCollege(void *elem1, void *type){
	
	//to compare type from elem1 to type from InstitutionType
	if((((Institution *)elem1))->type == (*(InstitutionType *)type)){ 
		return 1;
	}
	
	else 
		return 0;

}

