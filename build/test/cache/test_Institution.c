#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"


void tearDown(){}

void setUp(){}



void test_reverse_add_institution(){

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





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

}
