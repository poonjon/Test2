#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"


void tearDown(){}

void setUp(){}



void test_reverse_add_institution_for_3_elements(){

 Institution institution[]={};

 LinkedList inputList = {};

 LinkedList outputList = {};



 List_removeHead_CMockExpectAndReturn(14, &inputList, &institution[0]);

 Stack_push_CMockExpect(15, &stack, &institution[0]);

 List_removeHead_CMockExpectAndReturn(16, &inputList, &institution[1]);

 Stack_push_CMockExpect(17, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(18, &inputList, &institution[2]);

 Stack_push_CMockExpect(19, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(20, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(22, &stack, &institution[2]);

 List_addTail_CMockExpect(23, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(24, &stack, &institution[1]);

 List_addTail_CMockExpect(25, &outputList, &institution[1]);

 Stack_pop_CMockExpectAndReturn(26, &stack, &institution[0]);

 List_addTail_CMockExpect(27, &outputList, &institution[0]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}





void test_select_institute(){

 InstitutionType instiType = {UniversityCollege};

 Institution institution = {.type=UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isUniversityCollege(&institution, &instiType))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);



}



void test_institution_select_3(){

 Institution institution[]={ {.type = Unknown},

        {.type = University},

        {.type = UniversityCollege},

        {.type = College}};



 InstitutionType criterion = {UniversityCollege};

 LinkedList inputList = {};

 LinkedList outputList = {};

 int (*compare)(void *, void*);



 List_removeHead_CMockExpectAndReturn(52, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(53, &inputList, &institution[1]);

 List_removeHead_CMockExpectAndReturn(54, &inputList, &institution[2]);

 Stack_push_CMockExpect(55, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(56, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(58, &stack, &institution[2]);

 List_addTail_CMockExpect(59, &outputList, &institution[2]);





 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);



}
