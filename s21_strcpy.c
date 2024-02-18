 #include "../s21_string.h"
 
char *s21_strcpy(char *dest, const char *src) {
    char *start = dest;

    while ((*dest++ = *src++));

    return start;
}