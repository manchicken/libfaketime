/*
 *  Copyright (C) 2018 Michael D. Stemle, Jr.
 *
 *  This file is part of the FakeTime Preload Library.
 *
 *  The FakeTime Preload Library is free software; you can redistribute it
 *  and/or modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  The FakeTime Preload Library is distributed in the hope that it will
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the FakeTime Preload Library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * We're using this header just to collect simple testing utilities
 */

#ifndef __TESTUTIL_H__
#define __TESTUTIL_H__

#include <CUnit/Basic.h>

#define T_MAKE_SUITE(suite,name,setup,teardown) \
  do \
  { \
    suite = CU_add_suite(name, setup, teardown); \
    if (NULL == suite) \
    { \
      CU_cleanup_registry(); \
      return CU_get_error(); \
    } \
  } while (0)

/**
 * Add a test function to the suite
 * @param  suite The CUnit suite
 * @param  name  The name of the test
 * @param  fun   The function to test
 * @return       Cause the test to die if there was an error.
 */
#define T_ADD_TEST(suite,name,fun) \
  do \
  { \
    if (!CU_add_test(suite, "Verify " name "()...", fun)) \
    { \
      CU_cleanup_registry(); \
      return CU_get_error(); \
    } \
  } while (0)

#else

/**
 * Run the test Suite
 * @param  suite The CUnit test suite
 * @return       Returns whether or not CUnit has errors
 */
#define T_RUN_SUITE(suite) \
  do \
  { \
    CU_basic_set_mode(CU_BRM_VERBOSE); \
    CU_basic_run_suite(suite); \
    CU_basic_show_failures(CU_get_failure_list()); \
    CU_cleanup_registry(); \
    printf("\n"); /* Just add a little extra space */ \
    return CU_get_error(); \
  } while (0)

#endif /* __TESTUTIL_H__ */
