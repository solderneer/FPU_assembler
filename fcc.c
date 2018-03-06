/*
 * ------------ FPU_assembler ----------------
 * A custom assembler coded to assemble for
 * the FPU Instruction Set Architecture. (FISA)
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Global Variable declarations
FILE *asm_fp;
// Private Function prototypes

// Main Loop
int main(int argc, const char* argv[]) {
    // Basic argument parsing and error checking
    char* file_location;
    int arg_len;

    if(argc < 2) {
        printf("Invalid number of args passed : At least 1 argument required");
        return 0;
    }

    arg_len = strlen(argv[1]);
    file_location = (char*) malloc(arg_len);
    strcpy(file_location, argv[1]); // Assign second variable to be asm file location

    asm_fp = fopen(file_location, "r");
    // Check if file_location is valid
    if(asm_fp == NULL) {
        printf("No such file found");
        return 0;
    }
    else
        printf("%s", file_location);

    return 0;
}
