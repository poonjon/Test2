#include "unity.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "Institution.h"

void tearDown(){}
void setUp(){}

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