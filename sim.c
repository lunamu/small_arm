#include <stdio.h>
#include "shell.h"



void ADC()


ADD
AND
B
BIC
BL
CMN
CMP
EOR
MVN
LDR
LDRB
MLA
MOV
MUL
ORR
RSB
RSC
SBC
STR
STRB
SUB
TEQ
TST
SWI

NEXT_STATE.PC += 4;


void process_instruction()
{
    /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */
     uint inst_word = mem_read_32(CURRENT_STATE.PC);
     printf("The instruction is: %x \n", );
     

}


