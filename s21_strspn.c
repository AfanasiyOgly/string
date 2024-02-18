 
 #include "../s21_string.h"
 
 s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t count =  0;
    const char *p;

    for (; *str1; str1++, count++) {
        for (p = str2; *p && *p != *str1; p++)
            ;
        if (!*p)
            break;
    }
    return count;
}
