#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <check.h>
#include "convert.h"

START_TEST (modify_fieldNotExist_NotFoundNoChanges)
{
    const int fieldNotFound = 1;
    University* self = University_newFromString("BMSTU Russia 85.5 85 6500");
    ck_assert(University_setField(self,"funcproto", "smth") == fieldNotFound);
    University_free(&self);
}
END_TEST

START_TEST (modify_existingField_FoundAndChanged)
{
    const int fieldFound = 0;
    University* self = University_newFromString("BMSTU Russia 85.5 85 6500");
    ck_assert(University_setField(self,"name", "BMSTU") == fieldFound);
    University_free(&self);
}
END_TEST



START_TEST (reset_correctString_successfulChanges)
{
    University* self = University_new("BMSTU", "Russia", 4.5, 34, 45);
    University_set(self,"MIT US 87.5 97 76500");
    ck_assert_str_eq(University_getName(self), "MIT");
    ck_assert_str_eq(University_getLocation(self), "US");
    ck_assert_double_eq(University_getRank(self), 87.5);
    ck_assert_int_eq(University_getmatanPoints(self),97);
    ck_assert_int_eq(University_getStudents(self),76500);
    University_free(&self);
}
END_TEST

START_TEST (reset_incompleteString_incompleteChanges)
{
    University* self = University_new("BMSTU", "Russia", 4.5, 34, 45);
    University_set(self,"MIT US 87.5 97");
    ck_assert_str_eq(University_getName(self), "MIT");
    ck_assert_str_eq(University_getLocation(self), "US");
    ck_assert_double_eq(University_getRank(self), 87.5);
    ck_assert_int_eq(University_getmatanPoints(self),97);
    ck_assert_int_eq(University_getStudents(self),45);
    University_free(&self);
}
END_TEST

START_TEST (new_emptyString_emptyStruct)
{
    University* self = University_newFromString("");
    ck_assert_str_eq(University_getName(self), "");
    ck_assert_str_eq(University_getLocation(self), "");
    ck_assert_double_eq(University_getRank(self), 0.0);
    ck_assert_int_eq(University_getmatanPoints(self),0);
    ck_assert_int_eq(University_getStudents(self),0);
    University_free(&self);
}
END_TEST

START_TEST (new_correctString_filledStruct)
{
    University* self = University_newFromString("MIT US 87.5 97 76500");
    ck_assert_str_eq(University_getName(self), "MIT");
    ck_assert_str_eq(University_getLocation(self), "US");
    ck_assert_double_eq(University_getRank(self), 87.5);
    ck_assert_int_eq(University_getmatanPoints(self),97);
    ck_assert_int_eq(University_getStudents(self),76500);
    University_free(&self);
}
END_TEST

START_TEST (reset_emptyString_noChangesInStruct)
{
    University* self = University_new("BMSTU", "Russia", 4.5, 34, 45);
    University_set(self,"");
    ck_assert_str_eq(University_getName(self), "BMSTU");
    ck_assert_str_eq(University_getLocation(self), "Russia");
    ck_assert_double_eq(University_getRank(self), 4.5);
    ck_assert_int_eq(University_getmatanPoints(self),34);
    ck_assert_int_eq(University_getStudents(self),45);
    University_free(&self);
}
END_TEST

START_TEST (new_incompleteString_incompleteStruct)
{
    University* self = University_newFromString("MIT US 87.5");
    ck_assert_str_eq(University_getName(self), "MIT");
    ck_assert_str_eq(University_getLocation(self), "US");
    ck_assert_double_eq(University_getRank(self), 87.5);
    ck_assert_int_eq(University_getmatanPoints(self),0);
    ck_assert_int_eq(University_getStudents(self),0);
    University_free(&self);
}
END_TEST

START_TEST (convert_university_thatString)
{
    const char result[] = "BMSTU Russia 4.5 34 45";
    char buffer[40] = "";
    University* self = University_new("BMSTU", "Russia", 4.5, 34, 45);
    University_toString(self, buffer);
    University_free(&self);
    ck_assert_str_eq(buffer, result);
}
END_TEST

START_TEST (convert_emptyUniversity_emptyString)
{
    const char result[] = "  0.0 0 0";
    char buffer[40] = "";
    University* self = University_new("", "", 0.0, 0, 0);
    University_toString(self, buffer);
    University_free(&self);
    ck_assert_str_eq(buffer, result);
}
END_TEST

START_TEST (next_emptyUniversity_NULL)
{
    University* self = University_new("","",0.0,0,0);
    ck_assert(University_getNext(self) == NULL);
    University_free(&self);
}
END_TEST

Suite *test_suite() {

  Suite *s = suite_create("Convert");

  TCase *tc_sample;

  tc_sample = tcase_create("TestCase");

  tcase_add_test(tc_sample, modify_existingField_FoundAndChanged);
  tcase_add_test(tc_sample, modify_fieldNotExist_NotFoundNoChanges);
  tcase_add_test(tc_sample, reset_emptyString_noChangesInStruct);
  tcase_add_test(tc_sample, reset_correctString_successfulChanges);
  tcase_add_test(tc_sample, reset_incompleteString_incompleteChanges);
  tcase_add_test(tc_sample, new_emptyString_emptyStruct);
  tcase_add_test(tc_sample, new_correctString_filledStruct);
  tcase_add_test(tc_sample, new_incompleteString_incompleteStruct);
  tcase_add_test(tc_sample, convert_university_thatString);
  tcase_add_test(tc_sample, convert_emptyUniversity_emptyString);
  tcase_add_test(tc_sample, next_emptyUniversity_NULL);
  suite_add_tcase(s, tc_sample);

  return s;
}

int testing() {
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_VERBOSE);

  int failedTest = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failedTest;
}
