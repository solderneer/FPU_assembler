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
FILE *out_fp;
// Private Function prototypes

// Main Loop
int main(int argc, const char* argv[]) {
    // Basic argument parsing and error checking
    char* input_file;
    char* output_file;
    int arg_len;
    int cnt;

    if(argc < 2) {
        printf("Invalid number of args passed : At least 1 argument required\n");
        return 0;
    }

    arg_len = strlen(argv[1]);
    input_file = (char*) malloc(arg_len);
    strcpy(input_file, argv[1]); // Assign second variable to be asm file location

    asm_fp = fopen(input_file, "r");
    // Check if file_location is valid
    if(asm_fp == NULL) {
        printf("No such file found\n");
        free(input_file);
        return 0;
    }

    for(cnt = 0; cnt < (argc-1); cnt++) {
        if(!strcmp(argv[cnt], "-o")) {
            arg_len = strlen(argv[cnt+1]);
            output_file = (char*) malloc(arg_len);
            strcpy(output_file, argv[cnt+1]);
        }
    }

    printf("%s\n", input_file);
    printf("%s\n", output_file);
    free(input_file);
    free(output_file);
    return 0;
}
