#include "Stack.h"
#include <stdio.h>
#include "CException.h"
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
	int count, i=0;
	
	/*
	** count: To count amount of elements reversed
	** i	: To keep track of the number of elements pushed
	*/
	
	institution = List_removeHead(inputList);
	
	for(count = 0 ; institution != NULL ; count++){
			if((*compare)((Institution*)institution , (InstitutionType*)criterion) == 1){
				Stack_push(&stack, institution);
				institution = List_removeHead(inputList);
				i++;
		}
			else {
				printf("Institute %d not match\n", count);
				institution = List_removeHead(inputList);
				}
	}
		
	for(; i != 0 ; i--){
		institution = Stack_pop(&stack);
		List_addTail(outputList, institution);
	}
	
	return count;
						
}
						
int isUniversityCollege(void *elem1, void *type){
	
	//to compare type from elem1 to type from InstitutionType
	if((((Institution *)elem1))->type == (*(InstitutionType *)type)){ 
		return 1;
	}
	
	else 
		return 0;

}

int wasEstablishedBefore(void *elem1, void *year){
	Institution *institution; 
	
	if((((Institution*)elem1)->YearEstablished) > 2014){
		Throw(ERR_INVALID_YEAR);
	}	
	
	else{
		if((((Institution*)elem1)->YearEstablished) == *(int *)year){
			return 1;
	}
		else
			return 0;	
	}
}