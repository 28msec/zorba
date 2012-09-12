/*
 * Copyright 2006-2012 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "compiler/expression/mem_manager.h"
#include <iostream>

// Assertion and Testing macros and functions

static int failures;

static bool assert_true(char const *expr, char const *testName, bool result) {
  if ( !result ) {
    std::cout << "FAILED " << testName << ": " << expr << std::endl;
    ++failures;
  }
  return result;
}

static void print_exception( char const *expr, char const *testName,
        std::exception const &e ) {
    std::cout << "FAILED " << testName << ": exception: " << e.what() <<
        std::endl;
  ++failures;
}

#define ASSERT_TRUE( EXPR ) assert_true( #EXPR, testName, !!(EXPR) )

#define ASSERT_EXCEPTION( EXPR, EXCEPTION ) \
  try { EXPR; assert_true( #EXPR, testName, false); } \
  catch (EXCEPTION const& ) { } \
  catch ( std::exception const &e ){ print_exception( #EXPR, testName, e ); } \
  catch ( ... ) { assert_true ( #EXPR, testName, false ); }

#define ASSERT_NO_EXCEPTION( EXPR ) \
  try {EXPR; } \
  catch ( std::exception const &e ){ print_exception( #EXPR, testName, e ); } \
  catch ( ... ) { assert_true (#EXPR, testName, false ); }

#define ASSERT_TRUE_AND_NO_EXCEPTION( EXPR ) \
  try { ASSERT_TRUE ( EXPR ); } \
  catch ( std::exception const &e ) { print_exception( #EXPR, testName, e ); } \
  catch ( ... ) {assert_true( #EXPR, testName, false ); }

#define TEST( TESTNAME ) \
static void TESTNAME () { \
  const char *testName = #TESTNAME ; \
  int prev_failures = failures ;

#define END_TEST \
  if ( prev_failures == failures ) \
    std::cout << "PASSED " << testName << std::endl ; \
}

///////////////////////////////////////////////////////////////////////////////

using namespace zorba;

/*
 * Memory Page tests
 */

//Impostors for malloc and free
static const size_t DEFSIZE = MemPage::DEFAULT_PAGE_SIZE;
static const size_t HUGESIZE = DEFSIZE + 2;
static char defaultPage[DEFSIZE], hugePage[HUGESIZE];
static int defPageAlloc, hugePageAlloc;

void* malloc_impostor(size_t size)
{
  if(size > DEFSIZE)
  {
    ++hugePageAlloc;
    return (void*) hugePage;
  }
  ++defPageAlloc;
  return (void*) defaultPage;
}

void free_impostor(void* ptr)
{
  if(ptr = (void*)defaultPage)
    --defPageAlloc;
  if(ptr = (void*)hugePage)
    --hugePageAlloc;
}

void* malloc_fail_alloc(size_t size)
{
  return NULL;
}

TEST(PageCreationAllocatesMemoryDeletionFreesIt)
  //block to force deletion of testPage
  {
    MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
    ASSERT_TRUE(defPageAlloc == 1);
  }
  ASSERT_TRUE(defPageAlloc == 0);
END_TEST

TEST(FailedPageCreationThrowsBadAlloc)
    ASSERT_EXCEPTION(MemPage(DEFSIZE, &malloc_fail_alloc, &free_impostor),
                    std::bad_alloc);
END_TEST

TEST(NewPageHasFullSpace)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  ASSERT_TRUE(testPage.space() == DEFSIZE);
END_TEST

TEST(PageGivesValidAllocationAndLoosesSpace)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem = (char*)testPage.allocate(sizeof(char) * 2);
  ASSERT_TRUE(defaultPage <= mem && defaultPage + DEFSIZE > mem);
  ASSERT_TRUE(DEFSIZE - 2 == testPage.space());
END_TEST

TEST(AllocationSizeZeroReturnsNull)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem = (char*)testPage.allocate(0);
  ASSERT_TRUE(NULL == mem);
END_TEST

TEST(PageGivesSeparateAllocations)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem1 = (char*)testPage.allocate(sizeof(char) * 2);
  char* mem2 = (char*)testPage.allocate(sizeof(char) * 3);
  ASSERT_TRUE(mem1 >= (mem2 + 3) || (mem1 + 2) <= mem2);
  ASSERT_TRUE(NULL != mem1 && NULL != mem2);
  ASSERT_TRUE(testPage.space() == DEFSIZE - 5);
END_TEST

TEST(PageWillNotAllocateSpaceBiggerThanSize)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem = (char*)testPage.allocate(HUGESIZE);
  ASSERT_TRUE(NULL == mem);
END_TEST

TEST(PageWillNotAllocateSpaceBiggerThanSpaceAvailable)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem1 = (char*)testPage.allocate(sizeof(char) * 10);
  char* mem2 = (char*)testPage.allocate(testPage.space()+2);
  ASSERT_TRUE(mem1 != NULL);
  ASSERT_TRUE(mem2 == NULL);
END_TEST

TEST(FailedAllocationHasNoEffectOnPage)
  MemPage testPage(DEFSIZE, &malloc_impostor, &free_impostor);
  char* mem1 = (char*)testPage.allocate(sizeof(char) * 5);
  size_t orig_space = testPage.space();
  char* mem2 = (char*)testPage.allocate(testPage.space()+2);
  ASSERT_TRUE(testPage.space() == orig_space);
  char* mem3 = (char*)testPage.allocate(sizeof(char) * 5);
  ASSERT_TRUE(defaultPage <= mem3 && defaultPage + DEFSIZE >= mem3 + 5);
  ASSERT_TRUE(testPage.space() == DEFSIZE - 10);
END_TEST

TEST(BiggerPagesAllowForBiggerSpaceAndAllocation)
  MemPage testPage(HUGESIZE, &malloc_impostor, &free_impostor);
  ASSERT_TRUE(testPage.space() == HUGESIZE);
  char* mem = (char*)testPage.allocate(HUGESIZE);
  ASSERT_TRUE(NULL != mem);
  //this would be the only valid allocation
  ASSERT_TRUE(hugePage == mem);
END_TEST

namespace zorba { namespace UnitTests{

///////////////////////////////////////////////////////////////////////////////
int test_mem_manager( int, char*[] )
{
  PageCreationAllocatesMemoryDeletionFreesIt();
  FailedPageCreationThrowsBadAlloc();
  NewPageHasFullSpace();
  PageGivesValidAllocationAndLoosesSpace();
  AllocationSizeZeroReturnsNull();
  PageGivesSeparateAllocations();
  PageWillNotAllocateSpaceBiggerThanSize();
  PageWillNotAllocateSpaceBiggerThanSpaceAvailable();
  FailedAllocationHasNoEffectOnPage();
  BiggerPagesAllowForBiggerSpaceAndAllocation();

  if(failures > 0)
    std::cout << failures << " Memory Manager test(s) failed.\n";
  else
    std::cout << "All Memory Manager tests passed.\n";

  return failures ? 1 : 0;
}

}} //namespace zorba::UnitTests
