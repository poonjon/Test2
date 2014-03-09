#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"
#include "CException.h"


void tearDown(){}

void setUp(){}



void test_reverse_add_institution_for_2_elements(){

 Institution institution[]={};

 LinkedList inputList = {};

 LinkedList outputList = {};



 List_removeHead_CMockExpectAndReturn(15, &inputList, &institution[0]);

 Stack_push_CMockExpect(16, &stack, &institution[0]);

 List_removeHead_CMockExpectAndReturn(17, &inputList, &institution[1]);

 Stack_push_CMockExpect(18, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(19, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(21, &stack, &institution[1]);

 List_addTail_CMockExpect(22, &outputList, &institution[1]);

 Stack_pop_CMockExpectAndReturn(23, &stack, &institution[0]);

 List_addTail_CMockExpect(24, &outputList, &institution[0]);



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_reverse_add_institution_for_3_elements(){

 Institution institution[]={};

 LinkedList inputList = {};

 LinkedList outputList = {};



 List_removeHead_CMockExpectAndReturn(34, &inputList, &institution[0]);

 Stack_push_CMockExpect(35, &stack, &institution[0]);

 List_removeHead_CMockExpectAndReturn(36, &inputList, &institution[1]);

 Stack_push_CMockExpect(37, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(38, &inputList, &institution[2]);

 Stack_push_CMockExpect(39, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(40, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(42, &stack, &institution[2]);

 List_addTail_CMockExpect(43, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(44, &stack, &institution[1]);

 List_addTail_CMockExpect(45, &outputList, &institution[1]);

 Stack_pop_CMockExpectAndReturn(46, &stack, &institution[0]);

 List_addTail_CMockExpect(47, &outputList, &institution[0]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_reverse_add_institution_for_4_elements(){

 Institution institution[]={};

 LinkedList inputList = {};

 LinkedList outputList = {};



 List_removeHead_CMockExpectAndReturn(57, &inputList, &institution[0]);

 Stack_push_CMockExpect(58, &stack, &institution[0]);

 List_removeHead_CMockExpectAndReturn(59, &inputList, &institution[1]);

 Stack_push_CMockExpect(60, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(61, &inputList, &institution[2]);

 Stack_push_CMockExpect(62, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(63, &inputList, &institution[3]);

 Stack_push_CMockExpect(64, &stack, &institution[3]);

 List_removeHead_CMockExpectAndReturn(65, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(67, &stack, &institution[3]);

 List_addTail_CMockExpect(68, &outputList, &institution[3]);

 Stack_pop_CMockExpectAndReturn(69, &stack, &institution[2]);

 List_addTail_CMockExpect(70, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(71, &stack, &institution[1]);

 List_addTail_CMockExpect(72, &outputList, &institution[1]);

 Stack_pop_CMockExpectAndReturn(73, &stack, &institution[0]);

 List_addTail_CMockExpect(74, &outputList, &institution[0]);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((Institution_reverse(&inputList, &outputList))), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

}



void test_select_institute(){

 InstitutionType instiType = {UniversityCollege};

 Institution institution = {.type=UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((isUniversityCollege(&institution, &instiType))), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(98, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(99, &inputList, &institution[1]);

 List_removeHead_CMockExpectAndReturn(100, &inputList, &institution[2]);

 Stack_push_CMockExpect(101, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(102, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(104, &stack, &institution[2]);

 List_addTail_CMockExpect(105, &outputList, &institution[2]);





 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(124, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(125, &inputList, &institution[1]);

 Stack_push_CMockExpect(126, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(127, &inputList, &institution[2]);

 Stack_push_CMockExpect(128, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(129, &inputList, &institution[3]);

 List_removeHead_CMockExpectAndReturn(130, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(132, &stack, &institution[2]);

 List_addTail_CMockExpect(133, &outputList, &institution[2]);

 Stack_pop_CMockExpectAndReturn(134, &stack, &institution[1]);

 List_addTail_CMockExpect(135, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, isUniversityCollege))), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);



}



void test_year_of_establishment(){

 Institution institution[] = { {.YearEstablished = 1920, .type = UniversityCollege},

          {.YearEstablished = 1980, .type = UniversityCollege},

          {.YearEstablished = 1990, .type = UniversityCollege}};

 int comparedYear = 1980;

 InstitutionType criterion = {UniversityCollege};



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((wasEstablishedBefore(&institution[1], &comparedYear))), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(162, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(163, &inputList, &institution[1]);

 Stack_push_CMockExpect(164, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(165, &inputList, &institution[2]);

 List_removeHead_CMockExpectAndReturn(166, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(168, &stack, &institution[1]);

 List_addTail_CMockExpect(169, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);



}



void test_institution_select_year_select_2_reverse_3_elements(){

 Institution institution[]={ {.YearEstablished = 1920, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege},

        {.YearEstablished = 1980, .type = UniversityCollege}};



 int criterion = 1980;

 LinkedList inputList = {};

 LinkedList outputList = {};

 int (*compare)(void *, void*);



 List_removeHead_CMockExpectAndReturn(185, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(186, &inputList, &institution[1]);

 Stack_push_CMockExpect(187, &stack, &institution[1]);

 List_removeHead_CMockExpectAndReturn(188, &inputList, &institution[2]);

 Stack_push_CMockExpect(189, &stack, &institution[2]);

 List_removeHead_CMockExpectAndReturn(190, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(192, &stack, &institution[2]);

 List_addTail_CMockExpect(193, &outputList, &institution[2]);

  Stack_pop_CMockExpectAndReturn(194, &stack, &institution[1]);

 List_addTail_CMockExpect(195, &outputList, &institution[1]);



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);



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



 List_removeHead_CMockExpectAndReturn(211, &inputList, &institution[0]);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { catchError = CExceptionFrames[MY_ID].Exception; catchError=catchError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Error, year more than 2014");

  UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_YEAR)), (_U_SINT)((catchError)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

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



 List_removeHead_CMockExpectAndReturn(232, &inputList, &institution[0]);

 List_removeHead_CMockExpectAndReturn(233, &inputList, &institution[1]);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((Institution_select(&inputList, &outputList, &criterion, wasEstablishedBefore))), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { catchError = CExceptionFrames[MY_ID].Exception; catchError=catchError; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  printf("Error, year more than 2014");

  UnityAssertEqualNumber((_U_SINT)((ERR_INVALID_YEAR)), (_U_SINT)((catchError)), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

 }



}
