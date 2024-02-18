 #include "../s21_test.h"
 
 START_TEST(hate_test) {
    char src[] = "I don't like ctrcpy";
    char res[40] = "";
    char res2[40] = "";
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST


 START_TEST(zero_test_string) {
    char src[] = "";
    char res[40];
    char res2[40];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

 START_TEST(any_empty) { 
    char src[] = "          ";
    char res[40];
    char res2[40];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

 START_TEST(shielded_zero) {
    char src[] = "\0";
    char res[40];
    char res2[40];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

 START_TEST(number) {
    char src[] = "12989234792 9237";
    char res[40];
    char res2[40];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

 START_TEST(long_str) {
    char src[] = "12989234792 9237 ASEF ewfWE ";
    char res[20];
    char res2[20];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

 START_TEST(special_char) {
    char src[] = "!@#$^&*()_+~!?><";
    char res[40];
    char res2[40];
    
    s21_strcpy(res, src);
    strcpy(res2, src);

    ck_assert_str_eq(res2, res);
} END_TEST

Suite *suite_strcpy(void) {
    Suite *s = suite_create("suite_ctrcpy");
    TCase *tc = tcase_create("ctrcpy_tc");

    tcase_add_test(tc, hate_test);
    tcase_add_test(tc, zero_test_string);
    tcase_add_test(tc, any_empty);
    tcase_add_test(tc, shielded_zero);
    tcase_add_test(tc, number);
    tcase_add_test(tc, long_str);
    tcase_add_test(tc, special_char);
    //tcase_add_test(tc, one_byte_num);
    //tcase_add_test(tc, basic_long_string);
    //tcase_add_test(tc, long_string_with_register);
    //tcase_add_test(tc, long_string_with_register_and_num);
    //tcase_add_test(tc, long_string_with_register_and_num_and_simbol);

    suite_add_tcase(s, tc);
    return s;
}