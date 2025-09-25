#include <stdio.h>

int main() {
    char last_c = 0;
    short last_s = 0;
    int last_i = 0;
    long last_l = 0;
    // long long last_ll = 0;

    unsigned char last_cu = 0;
    unsigned short last_su = 0;
    unsigned int last_iu = 0;
    unsigned long last_lu = 0;
    // unsigned long long last_llu = 0;

    // s - signed
    // u - unsigned
    // d - default

    char char_d = 1;
    signed char char_s = 1;
    unsigned char char_u = 1;

    short short_d = 1;
    signed short short_s = 1;
    unsigned short short_u = 1;

    int int_d = 1;
    signed int int_s = 1;
    unsigned int int_u = 1;

    long long_d = 1;
    signed long long_s = 1;
    unsigned long long_u = 1;

    // C99
    // Miner mode)
    // long long llong_d = 1;
    // signed long long llong_s = 1;
    // unsigned long long llong_u = 1;


    printf("C language whole numbers data types bounds:\n");

// --------------------------------------------- chars

    while (char_d > last_c) {
        last_c = char_d;
        ++char_d;
    }
    printf("\nDefault char bounds [%d, %d]", char_d, last_c);

    last_c = 0;
    while (char_s > last_c) {
        last_c = char_s;
        ++char_s;
    }
    printf("\nSigned char bounds [%d, %d]", char_s, last_c);

    while (char_u > last_cu) {
        last_cu = char_u;
        ++char_u;
    }
    printf("\nUnsigned char bounds [%u, %u]\n", char_u, last_cu);


//  ---------------------------------------------------- shorts

    last_s = 0;
    while (short_d > last_s) {
        last_s = short_d;
        ++short_d;
    }
    printf("\nDefault short bounds [%d, %d]", short_d, last_s);

    last_s = 0;
    while (short_s > last_s) {
        last_s = short_s;
        ++short_s;
    }
    printf("\nSigned short bounds [%d, %d]", short_s, last_s);

    while (short_u > last_su) {
        last_su = short_u;
        ++short_u;
    }
    printf("\nUnsigned short bounds [%u, %u]\n", short_u, last_su);


// --------------------------------------------- ints

    while (int_d > last_i) {
        last_i = int_d;
        ++int_d;
    }
    printf("\nDefault int bounds [%d, %d]", int_d, last_i);

    last_i = 0;
    while (int_s > last_i) {
        last_i = int_s;
        ++int_s;
    }
    printf("\nSigned int bounds [%d, %d]", int_s, last_i);

    while (int_u > last_iu) {
        last_iu = int_u;
        ++int_u;
    }
    printf("\nUnsigned int bounds [%u, %u]\n", int_u, last_iu);


    // ------------------------------------------------- longs

    while (long_d > last_l) {
        last_l = long_d;
        ++long_d;
    }
    printf("\nDefault long bounds [%ld, %ld]", long_d, last_l);

    last_l = 0;
    while (long_s > last_l) {
        last_l = long_s;
        ++long_s;
    }
    printf("\nSigned long bounds [%ld, %ld]", long_s, last_l);

    while (long_u > last_lu) {
        last_lu = long_u;
        ++long_u;
    }
    printf("\nUnsigned long bounds [%lu, %lu]\n", long_u, last_lu);


    // ------------------------------------------------- long longs

    // while (llong_d > last_ll) {
    //     last_ll = llong_d;
    //     llong_d++;
    // }
    // printf("\nDefault long bounds [%ld, %ld]", llong_d, last_ll);

    // last_ll = 0;
    // while (llong_s > last_ll) {
    //     last_ll = llong_s;
    //     ++llong_s;
    // }
    // printf("\nSigned long bounds [%ld, %ld]", llong_s, last_ll);

    // while (llong_u > last_llu) {
    //     last_llu = llong_u;
    //     ++llong_u;
    // }
    // printf("\nUnsigned long bounds [%lu, %lu]\n", llong_u, last_llu);


    return 0;
}