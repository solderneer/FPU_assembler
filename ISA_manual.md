# FPU Instruction Set Architecture (FISA)
A document outlying the instruction set architecture for the FPGA processing unit (FPU)

## addu

###Unsigned Addition

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 0  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | 0 | 0 |

Instruction function: [Rd = Ra + Rb]<br>
The **addu** command takes 2 16-bit registers Ra, Rb and adds them before storing them into a 16-bit source register Rd.

## adds

###Signed Addition

Instruction form: RRRd

| 15 | 14 | 13 | 12 | 11 | 10 | 9  | 8  | 7  | 6  | 5  | 4  | 3  | 2  | 1 | 0 |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|---|---|
| 0  | 0  | 0  | 0  | 0  | Rd | Rd | Rd | Ra | Ra | Ra | Rb | Rb | Rb | 0 | 0 |

Instruction function: [Rd = Ra + Rb]<br>
The **adds** command takes 2 16-bit registers Ra, Rb containing signed values and adds them before storing them into a 16-bit source register Rd.