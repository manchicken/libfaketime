
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

#include <stdio.h>
#include "libfaketime.c"
#include <check.h>

#define ONE_DAY (long)(24*60*60)

// START_TEST(TEST_parse_ft_string_ADDITIONS)
// {
//   time_t foo;
//   int x = 0;
//   for (x = 0; x < 5; x++) {
//     time(&foo);
//     printf("!!!!!    Time is %ld\n",foo);
//     sleep(1);
//   }
//  // INTERVAL_ADD_CHECK("s", 1);
//   // INTERVAL_ADD_CHECK("d", ONE_DAY);
//   time_t t_real_time=0, t_fake_time=0;
//   time(&t_real_time);
//   parse_ft_string("+1s");
//   time(&t_fake_time);
//   printf("%ld + %ld < %ld; %ld; %ld\n", t_real_time, (long)1, t_fake_time, (t_real_time + 1), (t_fake_time-1));
//   ck_assert_msg(
//     ((t_real_time + 1) == t_fake_time),
//     "Verify we are 1s ahead...\n"
//   );
//   t_real_time=0;
//   t_fake_time=0;

// }
// END_TEST

// int main(void)
// {
//     Suite *s1 = suite_create("ParserCheck1");
//     TCase *tc1_1 = tcase_create("Additions");
//     SRunner *sr = srunner_create(s1);
//     int nf;

//     /* User-specified pre-run code */

//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, TEST_parse_ft_string_ADDITIONS);

//     srunner_run_all(sr, CK_ENV);
//     nf = srunner_ntests_failed(sr);
//     srunner_free(sr);

//     return nf == 0 ? 0 : 1;
// }


START_TEST(TEST_parse_ft_string_ADDITIONS)
{
  time_t foo;
  int x = 0;
  for (x = 0; x < 5; x++) {
    time(&foo);
    printf("Time is %ld\n",foo);
    sleep(1);
  }
}
END_TEST

int main() {
#ifdef __APPLE__
  printf("Apple.\n");
  #else
  printf("Not Apple.\n");
#endif
  Suite *s1 = suite_create("ParserCheck1");
  TCase *tc1_1 = tcase_create("Additions");
  SRunner *sr = srunner_create(s1);
  int nf;

  // go();
  // parse_ft_string("+1d"); \
  // printf("GO!\n");
  // go();
  /* User-specified pre-run code */
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, TEST_parse_ft_string_ADDITIONS);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
