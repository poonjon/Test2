#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"
#include "CException.h"


void tearDown(){}

void setUp(){}



void test_reverse_add_institution_for_3_elements(){

 Institution institution[]={};

 LinkedList inputList = {};

 LinkedList outputList = {};



 List_removeHead_CMockExpectAndReturn(15, &inputList, &institution[0]);

 Stack_push_CMockExpect(16, &stack, &institution[0]);

 List_removeHead_CMockExpectAndReturn(17, &inputList, &institution[1]);

 Stack_push_CMockExpect(18, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(19, &inputList, &institution[2]);

 Stack_push_CMockExpect(20, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(21, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(23, &stack, &institution[2]);

 List_addTail_CMockExpect(24, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(25, &stack, &institution[1]);

 List_addTail_CMockExpect(26, &outputList, &institution[1]);

 Stack_pop_CMockExpectAndReturn(27, &stack, &institution[0]);

 List_addTail_CMockExpect(28, &outputList, &institution[0]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

}



void test_select_institute(){

 InstitutionType instiType = {UniversityCollege};

 Institution institution = {.type=UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isUniversityCollege(&institution, &instiType))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(52, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(53, &inputList, &institution[1]);

 List_removeHead_CMockExpectAndReturn(54, &inputList, &institution[2]);

 Stack_push_CMockExpect(55, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(56, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(58, &stack, &institution[2]);

 List_addTail_CMockExpect(59, &outputList, &institution[2]);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(78, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(79, &inputList, &institution[1]);

 Stack_push_CMockExpect(80, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(81, &inputList, &institution[2]);

 Stack_push_CMockExpect(82, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(83, &inputList, &institution[3]);

 List_removeHead_CMockExpectAndReturn(84, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(86, &stack, &institution[2]);

 List_addTail_CMockExpect(87, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(88, &stack, &institution[1]);

 List_addTail_CMockExpect(89, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);



}



void test_year_of_establishment(){

 Institution institution[] = { {.YearEstablished = 1920, .type = UniversityCollege},

          {.YearEstablished = 1980, .type = UniversityCollege},

          {.YearEstablished = 1990, .type = UniversityCollege}};

 int comparedYear = 1980;

 InstitutionType criterion = {UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishedBefore(&institution[1], &comparedYear))), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(116, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(117, &inputList, &institution[1]);

 Stack_push_CMockExpect(118, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(119, &inputList, &institution[2]);

 List_removeHead_CMockExpectAndReturn(120, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(122, &stack, &institution[1]);

 List_addTail_CMockExpect(123, &outputList, &institution[1]);



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



void test_institution_select_year_select_1_reverse_3_elements_with_exception(){

 Institution institution[]={ {.YearEstablished = 2015, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege},

        {.YearEstablished = 1990, .type = UniversityCollege}};

 int catchError;

 int criterion = 1980;

 LinkedList inputList = {};

 LinkedList outputList = {};

 int (*compare)(void *, void*);





 List_removeHead_CMockExpectAndReturn(166, &inputList, &institution[0]);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { catchError = CExceptionFrames[MY_ID].Exception; catchError=catchError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_YEAR)), (_U_SINT)((catchError)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

 }



}
