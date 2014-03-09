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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isUniversityCollege(&institution, &instiType))), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(51, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(52, &inputList, &institution[1]);

 List_removeHead_CMockExpectAndReturn(53, &inputList, &institution[2]);

 Stack_push_CMockExpect(54, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(55, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(57, &stack, &institution[2]);

 List_addTail_CMockExpect(58, &outputList, &institution[2]);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(77, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(78, &inputList, &institution[1]);

 Stack_push_CMockExpect(79, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(80, &inputList, &institution[2]);

 Stack_push_CMockExpect(81, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(82, &inputList, &institution[3]);

 List_removeHead_CMockExpectAndReturn(83, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(85, &stack, &institution[2]);

 List_addTail_CMockExpect(86, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(87, &stack, &institution[1]);

 List_addTail_CMockExpect(88, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);



}



void test_year_of_establishment(){

 Institution institution[] = { {.YearEstablished = 1920, .type = UniversityCollege},

          {.YearEstablished = 1980, .type = UniversityCollege},

          {.YearEstablished = 1990, .type = UniversityCollege}};

 int comparedYear = 1980;

 InstitutionType criterion = {UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishedBefore(&institution[1], &comparedYear))), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);



}



void test_institution_select_year_select_1_reverse_3_elements(){

 Institution institution[]={ {.YearEstablished = 1920, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege},

        {.YearEstablished = 1990, .type = UniversityCollege}};



 int criterion = 1980;

 LinkedList inputList = {};

 LinkedList outputList = {};

 int (*compare)(void *, void*);



 List_removeHead_CMockExpectAndReturn(115, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(116, &inputList, &institution[1]);

 Stack_push_CMockExpect(117, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(118, &inputList, &institution[2]);

 List_removeHead_CMockExpectAndReturn(119, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(121, &stack, &institution[1]);

 List_addTail_CMockExpect(122, &outputList, &institution[1]);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);



}



void test_institution_select_year_select_2_reverse_3_elements(){

 Institution institution[]={ {.YearEstablished = 1920, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege}};



 int criterion = 1980;

 LinkedList inputList = {};

 LinkedList outputList = {};

 int (*compare)(void *, void*);



 List_removeHead_CMockExpectAndReturn(139, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(140, &inputList, &institution[1]);

 Stack_push_CMockExpect(141, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(142, &inputList, &institution[2]);

 Stack_push_CMockExpect(143, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(144, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(146, &stack, &institution[2]);

 List_addTail_CMockExpect(147, &outputList, &institution[2]);

  Stack_pop_CMockExpectAndReturn(148, &stack, &institution[1]);

 List_addTail_CMockExpect(149, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);



}
