#ifndef _SIM_FUNC_H_
#define _SIM_FUNC_H_
#define N_CUR ( (CURRENT_STATE.CPSR>>31) & 0x00000001 )
#define Z_CUR ( (CURRENT_STATE.CPSR>>30) & 0x00000001 )
#define C_CUR ( (CURRENT_STATE.CPSR>>29) & 0x00000001 )
#define V_CUR ( (CURRENT_STATE.CPSR>>28) & 0x00000001 )
#define N_NXT ( (NEXT_STATE.CPSR>>31) & 0x00000001 )
#define Z_NXT ( (NEXT_STATE.CPSR>>30) & 0x00000001 )
#define C_NXT ( (NEXT_STATE.CPSR>>29) & 0x00000001 )
#define V_NXT ( (NEXT_STATE.CPSR>>28) & 0x00000001 )

#define N_N 0x80000000
#define Z_N 0x40000000
#define C_N 0x20000000
#define V_N 0x10000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"



int ADC(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] + (CURRENT_STATE.REGS[Rm]<<shift) + C_CUR;
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] + (Imm<<rotate) + C_CUR;
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int ADD(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] + (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] + (Imm<<rotate);
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int AND(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] & (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] & (Imm<<rotate);
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int B(char* i_){return 0;}
int BIC(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] & (~(CURRENT_STATE.REGS[Rm]<<shift));
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] & (~(Imm<<rotate));
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int BL(char* i_){return 0;}
int CMN(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] + (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] + (Imm<<rotate);
	}
	
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}
	return 0;
}
int CMP(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] - (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] - (Imm<<rotate);
	}
	
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}
	return 0;
}
int EOR(int Rd, int Rn, int Operand2, int I, int S)
{

	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] ^ (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] ^ (Imm<<rotate);
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int MVN(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = (CURRENT_STATE.REGS[Rm]<<shift);
		NEXT_STATE.REGS[Rd] = ~cur;
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = (Imm<<rotate);
		NEXT_STATE.REGS[Rd] = ~cur;
	}
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int LDR(char* i_){return 0;}
int LDRB(char* i_){return 0;}
int MLA(char* i_){return 0;}
int MOV(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = (CURRENT_STATE.REGS[Rm]<<shift);
		NEXT_STATE.REGS[Rd] = cur;
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = (Imm<<rotate);
		NEXT_STATE.REGS[Rd] = cur;
	}
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int MUL(char* i_){return 0;}
int ORR(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] | (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] | (Imm<<rotate);
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int RSB(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = (CURRENT_STATE.REGS[Rm]<<shift) - CURRENT_STATE.REGS[Rn];
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = (Imm<<rotate) - CURRENT_STATE.REGS[Rn];
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int RSC(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = (CURRENT_STATE.REGS[Rm]<<shift) - CURRENT_STATE.REGS[Rn] + C_CUR - 1;
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = (Imm<<rotate) - CURRENT_STATE.REGS[Rn] + C_CUR - 1;
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int SBC(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] - (CURRENT_STATE.REGS[Rm]<<shift) + C_CUR - 1;
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] - (Imm<<rotate) + C_CUR - 1;
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int STR(char* i_){return 0;}
int STRB(char* i_){return 0;}
int SUB(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] - (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] - (Imm<<rotate);
	}
	NEXT_STATE.REGS[Rd] = cur;

	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int TEQ(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] ^ (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] ^ (Imm<<rotate);
	}
	
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int TST(int Rd, int Rn, int Operand2, int I, int S)
{
	int cur = 0;
	if(I == 0)
	{
		int shift = Operand2 >> 4;
		int Rm = Operand2 & 0x0000000F;
		cur = CURRENT_STATE.REGS[Rn] & (CURRENT_STATE.REGS[Rm]<<shift);
	}
	if(I == 1)
	{
		int rotate = Operand2 >> 8;
		int Imm = Operand2 & 0x000000FF;
		cur = CURRENT_STATE.REGS[Rn] & (Imm<<rotate);
	}
	
	if(S == 1)
	{
		if(cur < 0)
			NEXT_STATE.CPSR |= N_N;
		if(cur == 0)
			NEXT_STATE.CPSR |= Z_N;
	}	
	return 0;
}
int SWI(char* i_){return 0;}

#endif
