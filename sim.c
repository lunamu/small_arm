#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "func.h"


char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

char *byte_to_binary32(int x)
{
    static char b[33];
    b[0] = '\0';

    unsigned int z;
    for (z = 2147483648; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

int bchar_to_int(char* rsa)
{
    int i = 0;
    int result = 0;
    int t = 0;
    while(rsa[i] != '\0')i++;
    while(i>0)
    {
        --i;
        //printf("%d\n", (rsa[i]-'0')<<t);
        result += (rsa[i] - '0')<<t;
        t++;
    }
    return result;
}


int data_process(char* i_)
{
	/*
	This function further decode and execute subset of data processing instructions of ARM ISA.

	0000 = AND - Rd:= Op1 AND Op2
	0001 = EOR - Rd:= Op1 EOR Op2
	0010 = SUB - Rd:= Op1 - Op2
	0011 = RSB - Rd:= Op2 - Op1
	0100 = ADD - Rd:= Op1 + Op2
	0101 = ADC - Rd:= Op1 + Op2 + C
	0110 = SBC - Rd:= Op1 - Op2 + C - 1
	0111 = RSC - Rd:= Op2 - Op1 + C - 1
	1000 = TST - set condition codes on Op1 AND Op2 
	1001 = TEQ - set condition codes on Op1 EOR Op2 
	1010 = CMP - set condition codes on Op1 - Op2 
	1011 = CMN - set condition codes on Op1 + Op2 
	1100 = ORR - Rd:= Op1 OR Op2
	1101 = MOV - Rd:= Op2
	1110 = BIC - Rd:= Op1 AND NOT Op2 1111 = MVN - Rd:= NOT Op2
	1111 = MVN - Rd:= NOT Op2
	*/
	char d_opcode[5];
	d_opcode[0] = i_[7]; d_opcode[1] = i_[8]; d_opcode[2] = i_[9]; d_opcode[3] = i_[10]; d_opcode[4] = '\0';
	char rn[5];rn[4] = '\0';
	char rd[5];rd[4] = '\0';
	char operand2[13];operand2[12] = '\0';
	for(int i = 0; i < 4; i++)
	{
		rn[i] = i_[12+i];
		rd[i] = i_[16+i];
	}
	for(int i = 0; i < 12; i++)
	{
		operand2[i] = i_[20+i];
	}
	int Rn = bchar_to_int(rn);
	int Rd = bchar_to_int(rd);
	int Operand2 = bchar_to_int(operand2);
	int I = i_[6]-'0';
	int S = i_[11]-'0';
	printf("Opcode = %s\n Rn = %d\n Rd = %d\n Operand2 = %d\n I = %d\n S = %d\n", d_opcode, Rn, Rd, Operand2, I, S);



	if(!strcmp(d_opcode,"0000"))
	{
		printf("--- This is an AND instruction. \n");
		AND(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"0001"))
	{
		printf("--- This is an EOR instruction. \n");
		EOR(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"0010"))
	{
		printf("--- This is a SUB instruction. \n");
		SUB(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"0011"))
	{
		printf("--- This is an RSB instruction. \n");
		RSB(Rd, Rn, Operand2, I, S);
		return 0;
	}	
	if(!strcmp(d_opcode,"0100"))
	{
		printf("--- This is an ADD instruction. \n");
		ADD(Rd, Rn, Operand2, I, S);
		return 0;
	}	
	if(!strcmp(d_opcode,"0101"))
	{
		printf("--- This is an ADC instruction. \n");
		ADC(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"0110"))
	{
		printf("--- This is a SBC instruction. \n");
		SBC(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"0111"))
	{
		printf("--- This is an RSC instruction. \n");
		RSC(i_);return 0;
	}			
	if(!strcmp(d_opcode,"1000"))
	{
		printf("--- This is a TST instruction. \n");
		TST(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1001"))
	{
		printf("--- This is a TEQ instruction. \n");
		TEQ(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1010"))
	{
		printf("--- This is a CMP instruction. \n");
		CMP(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1011"))
	{
		printf("--- This is a CMN instruction. \n");
		CMN(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1100"))
	{
		printf("--- This is an ORR instruction. \n");
		ORR(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1101"))
	{
		printf("--- This is an MOV instruction. \n");
		MOV(Rd, Rn, Operand2, I, S);
		return 0;
	}
	if(!strcmp(d_opcode,"1110"))
	{
		printf("--- This is a BIC instruction. \n");
		BIC(i_);return 0;
	}	
	if(!strcmp(d_opcode,"1111"))
	{
		printf("--- This is an MVN instruction. \n");
		MVN(i_);return 0;
	}	
	return 1;	
}

int branch_process(char* i_)
{
	/* This function execute branch instruction*/
	if(i_[7] == 0)
	{
		printf("--- This is a B instruction. \n");
		B(i_);return 0;
	}	
	if(i_[7] == 1)
	{
		printf("--- This is a BL instruction. \n");
		BL(i_);return 0;
	}	
	return 1;

}

int mul_process(char* i_)
{
	if(i_[10] == 0)
	{
		printf("--- This is an MUL instruction. \n");
		MUL(i_);return 0;
	}	
	if(i_[10] == 1)
	{
		printf("--- This is an MLA instruction. \n");
		MLA(i_);return 0;
	}	
	return 1;
}

int transfer_process(char* i_)
{
	if(i_[11] == 0)
	{
		if(i_[9] == 0)
		{
			printf("--- This is an LDR instruction. \n");
			LDR(i_); return 0;
		}
		if(i_[9] == 1)
		{
			printf("--- This is an LDRB instruction. \n");
			LDRB(i_); return 0;
		}
	}
	if(i_[11] == 1)
	{
		if(i_[9] == 0)
		{
			printf("--- This is a STR instruction. \n");
			STR(i_); return 0;
		}
		if(i_[9] == 1)
		{
			printf("--- This is a STRB instruction. \n");
			STRB(i_); return 0;
		}

	}
	return 1;
}

int interruption_process(char* i_)
{
	SWI(i_);
	return 0;
}


unsigned int COND(unsigned int i_word)
{
    return (i_word>>28);
}
unsigned int OPCODE(unsigned int i_word)
{
    return ((i_word<<7)>>21);
}


int decode_and_execute(char* i_)
{
	/* 
	This function decode the instruction and update CPU_State (NEXT_STATE)
	*/

	if((i_[4] == '0') && (i_[5] == '0') && (i_[6] == '1'))
	{
		printf("- This is a Data Processing Instruction. \n");
		data_process(i_);
	}
	if((i_[4] == '1') && (i_[5] == '0') && (i_[6] == '1'))
	{
		printf("- This is a Branch Instruction. \n");
		branch_process(i_);
	}
	if((i_[4] == '0') && (i_[5] == '0') && (i_[6] == '0') && (i_[7] == '0') && (i_[8] == '0') && (i_[9] == '0'))
	{
		printf("- This is a Multiply Instruction. \n");
		mul_process(i_);
	}
	if((i_[4] == '0') && (i_[5] == '1'))
	{
		printf("- This is a Single Data Transfer Instruction. \n");
		transfer_process(i_);
	}
	if((i_[4] == '1') && (i_[5] == '1') && (i_[6] == '1') && (i_[7] == '1'))
	{
		printf("- This is a Software Interruption Instruction. \n");
		interruption_process(i_);
	}
	return 0;
}

void process_instruction()
{
    /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */   

    unsigned int inst_word = mem_read_32(CURRENT_STATE.PC);
    printf("The instruction is: %x \n", inst_word);
    printf("32******24******16******8*******\n");
    printf("%s \n", byte_to_binary32(inst_word));
    printf("The COND is: %s\n", byte_to_binary(COND(inst_word)));
    printf("The OPCODE is: %s\n", byte_to_binary(OPCODE(inst_word)));
    decode_and_execute(byte_to_binary32(inst_word));
    NEXT_STATE.PC += 4;

}


