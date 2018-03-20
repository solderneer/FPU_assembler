/*
 * ------------ FPU_assembler ----------------
 * A custom assembler coded to assemble for
 * the FPU Instruction Set Architecture. (FISA)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "uthash.h"
#include "fcc.h"

// Global Variable declarations
FILE *asm_fp;
FILE *out_fp;

char* input_file;
char* output_file;
const char **n;

dict_struct *s, *opcode_list, *reg_list, *del;

// Private Function prototypes
void freeAll(int status);
void setupDicts(void);
uint16_t getOpcode(char* opcode);
uint16_t getRegval(char* regnum);

// Main Loop
int main(int argc, const char* argv[]) {
    // Basic argument parsing and error checking
    int arg_len;
    int cnt;
    // dict_struct *s, *opcode_list, *reg_list;

    if(argc < 2) {
        printf("Invalid number of args passed : At least 1 argument required\n");
        return 0;
    }

    arg_len = strlen(argv[1]);
    input_file = (char*) malloc(arg_len);
    strcpy(input_file, argv[1]); // Assign second variable to be asm file location

    for(cnt = 0; cnt < (argc-1); cnt++) {
        if(!strcmp(argv[cnt], "-o")) {
            arg_len = strlen(argv[cnt+1]);
            output_file = (char*) malloc(arg_len);
            strcpy(output_file, argv[cnt+1]);
        }
    }

    asm_fp = fopen(input_file, "r");
    out_fp = fopen(output_file, "wb");

    // Check if file_location is valid
    if(asm_fp == NULL) {
        printf("Input file location invalid\n");
        freeAll(1);
        return 0;
    }

    if(out_fp == NULL) {
        printf("Output file location invalid\n");
        freeAll(1);
        return 0;
    }

    setupDicts();
    printf("%d\n", getOpcode("ldr.l"));
    printf("%d\n", getRegval("rg2"));

    freeAll(2);
    return 1;
}

void setupDicts(void) {
    int cnt;
    // Populate the dictionary with opcode values
    for (n = opcode; *n != NULL; n++) {
        s = (dict_struct*)malloc(sizeof(dict_struct));
        s -> name = *n;
        s -> id = opcode_val[cnt++];
        HASH_ADD_KEYPTR(hh, opcode_list, s->name, strlen(s->name), s);
    }

    cnt = 0; //Reset the counter

    // Populate the dictionary with reglist value
    for (n = reglist; *n != NULL; n++) {
        s = (dict_struct*)malloc(sizeof(dict_struct));
        s -> name = *n;
        s -> id = cnt++;
        HASH_ADD_KEYPTR(hh, reg_list, s->name, strlen(s->name), s);
    }
}

uint16_t getOpcode(char* opcode) {
    HASH_FIND_STR(opcode_list, opcode, s);
    return (uint16_t)s->id;
}

uint16_t getRegval(char* regnum) {
    HASH_FIND_STR(reg_list, regnum, s);
    return (uint16_t)s->id;
}

void freeAll(int status) {
    switch(status) {
        case 2:
            HASH_ITER(hh, opcode_list, s, del) {
                HASH_DEL(opcode_list, s);
                free(s);
            }

            HASH_ITER(hh, reg_list, s, del) {
                HASH_DEL(reg_list, s);
                free(s);
            }

        case 1:
            free(input_file);
            free(output_file);
    }
}
