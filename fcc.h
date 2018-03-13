#ifndef FCC_H_
#define FCC_H_

#include "uthash.h"

typedef struct {
    char name[3];
    int id;
    UT_hash_handle hh;
} dict_struct;

const char* opcode[] = {"add",
                        "sub",
                        "orr",
                        "and",
                        "xor",
                        "not",
                        "rdr",
                        "wrr",
                        "ldr",
                        "cmp",
                        "shl",
                        "shr",
                        "jmp",
                        "jeq"};

const char* reglist[] = {"rg0",
                         "rg1",
                         "rg2",
                         "rg3",
                         "rg4",
                         "rg5",
                         "rg6",
                         "rg7"};
#endif /* FCC_H_ */
