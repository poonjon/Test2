/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_reverse_add_institution_for_2_elements(void);
extern void test_reverse_add_institution_for_3_elements(void);
extern void test_reverse_add_institution_for_4_elements(void);
extern void test_select_institute(void);
extern void test_institution_select_1_reverse_3_elements(void);
extern void test_institution_select_2_elements_reverse_4_elements(void);
extern void test_year_of_establishment(void);
extern void test_institution_select_year_select_1_reverse_3_elements(void);
extern void test_institution_select_year_select_2_reverse_3_elements(void);
extern void test_institution_select_year_throws_exception_on_first_element(void);
extern void test_institution_select_year_throws_exception_on_second_element(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_LinkedList_Init();
  mock_Stack_Init();
}
static void CMock_Verify(void)
{
  mock_LinkedList_Verify();
  mock_Stack_Verify();
}
static void CMock_Destroy(void)
{
  mock_LinkedList_Destroy();
  mock_Stack_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_Institution.c";
  UnityBegin();
  RUN_TEST(test_reverse_add_institution_for_2_elements, 10);
  RUN_TEST(test_reverse_add_institution_for_3_elements, 29);
  RUN_TEST(test_reverse_add_institution_for_4_elements, 52);
  RUN_TEST(test_select_institute, 79);
  RUN_TEST(test_institution_select_1_reverse_3_elements, 87);
  RUN_TEST(test_institution_select_2_elements_reverse_4_elements, 112);
  RUN_TEST(test_year_of_establishment, 141);
  RUN_TEST(test_institution_select_year_select_1_reverse_3_elements, 152);
  RUN_TEST(test_institution_select_year_select_2_reverse_3_elements, 175);
  RUN_TEST(test_institution_select_year_throws_exception_on_first_element, 201);
  RUN_TEST(test_institution_select_year_throws_exception_on_second_element, 222);

  return (UnityEnd());
}
