 #include "../s21_string.h"

void *s21_memcpy(void *dst, const void *src, s21_size_t len){


        unsigned char *d = (unsigned char *)dst;
        unsigned char *s = (unsigned char *)src;

        for (s21_size_t i =  0; i < len; i++) {
            d[i] = s[i];
        }


    return dst;
}
