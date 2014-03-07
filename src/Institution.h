#ifndef __INSTITUTION_H__
#define __INSTITUTION_H__

typedef enum{Unknown, University, UniversityCollege, college}InstitutionType;

typedef struct Institution_t{
	char *name;
	char *address;
	char unsigned long postcode;
	char unsigned long int telephone;
	char InstitutionType type;
	char YearEstablished;

}Institution;

#endif