#ifndef S21_STRING_H_
#define S21_STRING_H_


typedef long unsigned int s21_size_t;
typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)


s21_size_t s21_strlen(const char *str);
void *s21_memcpy(void *dst, const void *src, s21_size_t len);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strspn(const char *str1, const char *str2);

#endif  // SRC_S21_STRING_H_
