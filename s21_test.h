#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

Suite *suite_strlen(void);
Suite *suite_memcpy(void);
Suite *suite_strcpy(void);
Suite *suite_strspn(void);


void run_tests(void);
void run_testcase(Suite *testcase);


#endif  // S21_TESTS_H_
