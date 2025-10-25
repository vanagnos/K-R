#include <stdio.h>
#include <limits.h>

int main() {
    printf("Using standard headers:\n\n");

    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("UCHAR_MAX: %u\n\n", UCHAR_MAX);

    printf("SHRT_MIN: %d\n", SHRT_MIN);
    printf("SHRT_MAX: %d\n", SHRT_MAX);
    printf("USHRT_MAX: %u\n\n", USHRT_MAX);

    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n\n", UINT_MAX);

    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("ULONG_MAX: %lu\n\n", ULONG_MAX);

    printf("By direct computation:\n\n");

    signed char sc_min = 0, sc_max = 0;
    unsigned char uc_max = 0;
    while ((signed char)(sc_max + 1) > sc_max) sc_max++;
    sc_min = sc_max + 1;
    while ((unsigned char)(uc_max + 1) > uc_max) uc_max++;
    printf("Signed char range: %d to %d\n", sc_min, sc_max);
    printf("Unsigned char max: %u\n\n", uc_max);

    short s_min = 0, s_max = 0;
    unsigned short us_max = 0;
    while ((short)(s_max + 1) > s_max) s_max++;
    s_min = s_max + 1;
    while ((unsigned short)(us_max + 1) > us_max) us_max++;
    printf("Signed short range: %d to %d\n", s_min, s_max);
    printf("Unsigned short max: %u\n\n", us_max);

    int i_min = 0, i_max = 0;
    unsigned int ui_max = 0;
    while ((int)(i_max + 1) > i_max) i_max++;
    i_min = i_max + 1;
    while ((unsigned int)(ui_max + 1) > ui_max) ui_max++;
    printf("Signed int range: %d to %d\n", i_min, i_max);
    printf("Unsigned int max: %u\n\n", ui_max);

    long l_min = 0, l_max = 0;
    unsigned long ul_max = 0;
    while ((long)(l_max + 1) > l_max) l_max++;
    l_min = l_max + 1;
    while ((unsigned long)(ul_max + 1) > ul_max) ul_max++;
    printf("Signed long range: %ld to %ld\n", l_min, l_max);
    printf("Unsigned long max: %lu\n", ul_max);

    return 0;
}
