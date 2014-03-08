#ifndef __INSTITUTION_H__
#define __INSTITUTION_H__

extern Stack stack; 

typedef enum{Unknown, University, UniversityCollege, college}InstitutionType;

typedef struct Institution_t{
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int YearEstablished;

}Institution;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList);

#endif