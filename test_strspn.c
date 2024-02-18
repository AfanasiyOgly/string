 #include "../s21_test.h"

START_TEST(empty) {
    char src[] = "";
    char src2[] = "";
    
    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));
} END_TEST

START_TEST(abosal) {
    char src[] = "abosal";
    char src2[] = "s";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(abosal_no_char) {
    char src[] = "abosal";
    char src2[] = "m";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(abosal_i_nasral) {
    char src[] = "abosal i na sral";
    char src2[] = "r";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(zero) {
    char src[] = "normal normal";
    char src2[] = "0";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(empty1) {
    char src[] = "";
    char src2[] = "normal normal";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(empty2) {
    char src[] = "normal normal";
    char src2[] = "";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(number) {
    char src[] = "1w82sldk3489";
    char src2[] = "123";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(number2) {
    char src[] = "1w82sldk3489123";
    char src2[] = "123";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

START_TEST(number3) {
    char src[] = "1w82sldk34891_2_3";
    char src2[] = "123";

    ck_assert_int_eq(s21_strspn(src, src2),
                     strspn(src, src2));

} END_TEST

Suite *suite_strspn(void) {
    Suite *s = suite_create("suite_strlen");
    TCase *tc = tcase_create("strlen_tc");

    tcase_add_test(tc, empty);
    tcase_add_test(tc, abosal);
    tcase_add_test(tc, abosal_no_char);
    tcase_add_test(tc, abosal_i_nasral);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, empty1);
    tcase_add_test(tc, empty2);
    tcase_add_test(tc, number);
    tcase_add_test(tc, number2);
    tcase_add_test(tc, number3);

    suite_add_tcase(s, tc);
    return s;
}
