#ifndef __INSTITUTION_H__
#define __INSTITUTION_H__

extern Stack stack; 

typedef enum {
				NO_ERROR,
				ERR_INVALID_YEAR
			} ExceptionError;

typedef enum{Unknown, University, UniversityCollege, College}InstitutionType;

typedef struct Institution_t{
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int YearEstablished;

}Institution;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList);
int isUniversityCollege(void *elem1, void *type);

int Institution_select( LinkedList *inputList, 
						LinkedList *outputList,
						void *criterion,
						int (*compare)(void*, void *));

int wasEstablishedBefore(void *elem1, void *year);
						
#endif