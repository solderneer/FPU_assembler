# FPU Instruction Set Architecture (FISA)
A document outlying the instruction set architecture for the FPGA processing unit (FPU)

## addu

### Unsigned Addition

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 0  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra + Rb]<br>
The **addu** command takes 2 16-bit source registers Ra, Rb and adds them before storing them into a 16-bit destination register Rd.

## add.s

### Signed Addition

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 0  | 1  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra + Rb]<br>
The **adds** command takes 2 16-bit source registers Ra, Rb containing signed values and adds them before storing them into a 16-bit destination register Rd.

## sub.u

### Unsigned Subtraction

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 1  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra - Rb]<br>
The **subu** command takes 2 16-bit source registers Ra, Rb and subtracts them before storing them into a 16-bit destination register Rd.

## sub.s

### Signed Subtraction

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 1  | 1  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra - Rb]<br>
The **subs** command takes 2 16-bit source registers Ra, Rb containing signed values and subtracts them before storing them into a 16-bit destination register Rd.

## or

### Bitwise OR operation

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 1  | 0  | X  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra | Rb]<br>
The **or** command takes 2 16-bit source registers Ra, Rb and does a bitwise or before storing them into a 16-bit destination register Rd.

## and

### Bitwise AND operation

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 1  | 1  | X  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra & Rb]<br>
The **and** command takes 2 16-bit source registers Ra, Rb and does a bitwise and before storing them into a 16-bit destination register Rd.

## xor

### Bitwise XOR operation

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 1  | 0  | 0  | X  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: [Rd = Ra ^ Rb]<br>
The **xor** command takes 2 16-bit source registers Ra, Rb and does a bitwise xor before storing them into a 16-bit destination register Rd.

## not

### Bitwise NOT operation

Instruction form: RRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 1  | 0  | 1  | X  | Rd | Rd | Rd | Ra | Ra | Ra | X  | X  | X  | X | X |

Instruction function: [Rd = !Ra]<br>
The **not** command takes 1 16-bit source register, Ra and does a bitwise not before storing it into a 16-bit destination register Rd.

## read

### Read Memory

Instruction form: RRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 1  | 1  | 0  | X  | Rd | Rd | Rd | Ra | Ra | Ra | X  | X  | X  | X | X |

Instruction function: Rd = Mem[Ra]<br>
The **read** command takes 1 16-bit source register, Ra and reads from the corresponding memory address before storing it into a 16-bit destination register Rd.

## write

### Write Memory

Instruction form: RR

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 1  | 1  | 1  | X  | X  | X  | X  | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: Mem[Ra] = Rb<br>
The **write** command takes 2 16-bit source registers Ra,Rb and writes the value of Rb into memory address Ra.

## ldr.h

### Load Register (High)

Instruction form: RdImm

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 0  | 0  | 1  | Rd | Rd | Rd | Imm | Imm | Imm | Imm  | Imm | Imm | Imm | Imm |

Instruction function: Rd = Imm<br>
The **ldr.h** command takes an 8-bit immediate value, Ra and stores it into the high 8-bits of a 16-bit destination register Rd.

## ldr.l

### Load Register (Low)

Instruction form: RdImm

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 0  | 0  | 0  | Rd | Rd | Rd | Imm | Imm | Imm | Imm  | Imm | Imm | Imm | Imm |

Instruction function: Rd = Imm<br>
The **ldr.h** command takes an 8-bit immediate value, Ra and stores it into the low 8-bits of a 16-bit destination register Rd.

## cmp.u

### Unsigned Compare

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 0  | 1  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: Rd = cmp(Ra, Rb)<br>
The **cmp.u** command takes 2 16-bit source registers Ra,Rb and conducts various unsigned compare operations on them before storing the result into the destination register Rd.

## cmp.s

### Signed Compare

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 0  | 1  | 1  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: Rd = cmp(Ra, Rb)<br>
The **cmp.s** command takes 2 16-bit source registers Ra,Rb and conducts various signed compare operations on them before storing the result into the destination register Rd.

## shftl

### Shift Left

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 1  | 0  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: Rd = Ra << Rb<br>
The **shftl** command takes 2 16-bit source registers Ra,Rb and shifts Ra by Rb to the left before storing the result into the destination register Rd.

## shftr

### Shift Right

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 0  | 1  | 1  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | X | X |

Instruction function: Rd = Ra >> Rb<br>
The **shftr** command takes 2 16-bit source registers Ra,Rb and shifts Ra by Rb to the right before storing the result into the destination register Rd.

## jmp.i

### Jump (Immediate)

Instruction form: Imm

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 1  | 0  | 0  | 0  | X  | X  | X  | Imm | Imm | Imm | Imm | Imm | Imm | Imm | Imm |

Instruction function: PC = Imm
The **jmp.i** command takes a 8-bit immediate value and sets the current program counter to that address.

## jmp.r

### Jump (Register)

Instruction form: R

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 1  | 1  | 0  | 0  | 1  | X  | X  | X  | Imm | Imm | Imm | Imm | Imm | Imm | Imm | Imm |

Instruction function: PC = Ra
The **jmp.r** command takes a 16-bit source register, Ra and sets the current program counter to that address.