#ifndef FCC_H_
#define FCC_H_

#include "uthash.h"

struct dict_struct {
    char mnemonic[3];
    int opcode;
    UT_hash_handle hh;
}

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
                        "jmpeq"}
#endif /* FCC_H_ */
