#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <stdint.h>


//remember to delete
#define FALSE 0
#define TRUE  1

#define ARM_REGS 16
#define PC REGS[15]

typedef struct CPU_State_Struct {

  uint32_t REGS[ARM_REGS]; /* register file. */
  uint32_t CPSR;
} CPU_State;

/* Data Structure for Latch */

CPU_State CURRENT_STATE, NEXT_STATE;

int RUN_BIT;	/* run bit */

uint32_t mem_read_32(uint32_t address);
void     mem_write_32(uint32_t address, uint32_t value);


int ADC(char* i_)
{
	CURRENT_STATE.CPSR

}


int AND(char* i_);
int B(char* i_);
int BL(char* i_);
int CMN(char* i_);
int CMP(char* i_);
int EOR(char* i_);
int MVN(char* i_);
int LDR(char* i_);
int LDRB(char* i_);
int MLA(char* i_);
int MOV(char* i_);
int MUL(char* i_);
int ORR(char* i_);
int RSB(char* i_);
int RSC(char* i_);
int SBC(char* i_);
int STR(char* i_);
int STRB(char* i_);
int SUB(char* i_);
int TEQ(char* i_);
int TST(char* i_);
int SWI(char* i_);