#include "unity.h"
#include "CException.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "Institution.h"

void tearDown(){}
void setUp(){}

void test_reverse_add_institution_for_2_elements(){
	Institution institution[]={};
	LinkedList inputList = {};
	LinkedList outputList = {};
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&outputList, &institution[0]);
	
	TEST_ASSERT_EQUAL(2, Institution_reverse(&inputList, &outputList) );
}

void test_reverse_add_institution_for_3_elements(){
	Institution institution[]={};
	LinkedList inputList = {};
	LinkedList outputList = {};
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&outputList, &institution[2]);
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&outputList, &institution[0]);
	
	TEST_ASSERT_EQUAL(3, Institution_reverse(&inputList, &outputList) );
}

void test_reverse_add_institution_for_4_elements(){
	Institution institution[]={};
	LinkedList inputList = {};
	LinkedList outputList = {};
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	Stack_push_Expect(&stack, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[3]);
	Stack_push_Expect(&stack, &institution[3]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[3]);
	List_addTail_Expect(&outputList, &institution[3]);
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&outputList, &institution[2]);
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	Stack_pop_ExpectAndReturn(&stack, &institution[0]);
	List_addTail_Expect(&outputList, &institution[0]);
	
	TEST_ASSERT_EQUAL(4, Institution_reverse(&inputList, &outputList) );
}

void test_select_institute(){
	InstitutionType instiType = {UniversityCollege};
	Institution institution = {.type=UniversityCollege};
	
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institution, &instiType) );

}

void test_institution_select_1_reverse_3_elements(){
	Institution institution[]={ {.type = Unknown},
								{.type = University},
								{.type = UniversityCollege},
								{.type = College}};
	
	InstitutionType criterion = {UniversityCollege};
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&outputList, &institution[2]);
	
	
	TEST_ASSERT_EQUAL(3,Institution_select(&inputList, &outputList, &criterion, isUniversityCollege));
	
}

void test_institution_select_2_elements_reverse_4_elements(){

	Institution institution[]={ {.type = Unknown},
								{.type = UniversityCollege},
								{.type = UniversityCollege},
								{.type = College}};
	
	InstitutionType criterion = {UniversityCollege};
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);	
	List_removeHead_ExpectAndReturn(&inputList, &institution[3]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&outputList, &institution[2]);
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	
	TEST_ASSERT_EQUAL(4 , Institution_select(&inputList, &outputList, &criterion, isUniversityCollege));
	
}

void test_year_of_establishment(){
	Institution institution[] = { {.YearEstablished = 1920, .type = UniversityCollege},
								  {.YearEstablished = 1980, .type = UniversityCollege},
								  {.YearEstablished = 1990, .type = UniversityCollege}};
	int comparedYear = 1980;
	InstitutionType criterion = {UniversityCollege};
	
	TEST_ASSERT_EQUAL(1, wasEstablishedBefore(&institution[1], &comparedYear));
	
}

void test_institution_select_year_select_1_reverse_3_elements(){
	Institution institution[]={ {.YearEstablished = 1920, .type = UniversityCollege},
								{.YearEstablished = 1980, .type = UniversityCollege},
								{.YearEstablished = 1990, .type = UniversityCollege}};
	int catchError;
	int criterion = 1980;
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	
	TEST_ASSERT_EQUAL(3,Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore));
	
}

void test_institution_select_year_select_2_reverse_3_elements(){
	Institution institution[]={ {.YearEstablished = 1920, .type = UniversityCollege},
								{.YearEstablished = 1980, .type = UniversityCollege},
								{.YearEstablished = 1980, .type = UniversityCollege}};
	
	int criterion = 1980;
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);
	
	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);
	Stack_push_Expect(&stack, &institution[1]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[2]);
	Stack_push_Expect(&stack, &institution[2]);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institution[2]);
	List_addTail_Expect(&outputList, &institution[2]);
		Stack_pop_ExpectAndReturn(&stack, &institution[1]);
	List_addTail_Expect(&outputList, &institution[1]);
	
	TEST_ASSERT_EQUAL(3,Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore));
	
}

void test_institution_select_year_throws_exception_on_first_element(){
	Institution institution[]={ {.YearEstablished = 2015, .type = UniversityCollege},
								{.YearEstablished = 1980, .type = UniversityCollege},
								{.YearEstablished = 1990, .type = UniversityCollege}};
	int catchError;
	int criterion = 1980;
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);

	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);

	Try{
		TEST_ASSERT_EQUAL(3,Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore));
	}Catch(catchError){
		printf("Error, year more than 2014");
		TEST_ASSERT_EQUAL(ERR_INVALID_YEAR, catchError);
	}
	
}
	
void test_institution_select_year_throws_exception_on_second_element(){
	Institution institution[]={ {.YearEstablished = 1970, .type = UniversityCollege},
								{.YearEstablished = 2015, .type = UniversityCollege},
								{.YearEstablished = 1990, .type = UniversityCollege}};
	int catchError;
	int criterion = 1980;
	LinkedList inputList = {};
	LinkedList outputList = {};
	int (*compare)(void *, void*);

	List_removeHead_ExpectAndReturn(&inputList, &institution[0]);
	List_removeHead_ExpectAndReturn(&inputList, &institution[1]);

	Try{
		TEST_ASSERT_EQUAL(3,Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore));
	}Catch(catchError){
		printf("Error, year more than 2014");
		TEST_ASSERT_EQUAL(ERR_INVALID_YEAR, catchError);
	}
	
}
	
	