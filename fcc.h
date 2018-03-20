#ifndef FCC_H_
#define FCC_H_

#include "uthash.h"

typedef struct {
    const char *name;
    int id;
    UT_hash_handle hh;
} dict_struct;

const char* opcode[] = {"add.u",
                        "add.s",
                        "sub.u",
                        "sub.s",
                        "or",
                        "and",
                        "xor",
                        "not",
                        "read",
                        "write",
                        "ldr.h",
                        "ldr.l",
                        "cmp.u",
                        "cmp.s",
                        "shftl",
                        "shftr",
                        "jmp.i",
                        "jmp.r",
                        "jeq"};

const int opcode_val[] = {0b00000, 0b00001, 0b00010, 0b00011, 0b00100,
                          0b00110, 0b01000, 0b01010, 0b01100, 0b01110,
                          0b10001, 0b10000, 0b10011, 0b10100, 0b10110,
                          0b11000, 0b11001};
const char* reglist[] = {"rg0",
                         "rg1",
                         "rg2",
                         "rg3",
                         "rg4",
                         "rg5",
                         "rg6",
                         "rg7"};
#endif /* FCC_H_ */
