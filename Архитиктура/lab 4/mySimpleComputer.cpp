#include "memory.h"
#include <iostream>

int **memory;
int flag;

int sc_memoryInit()
{
	memory = new int*[SIZE];
	for(int i=0; i < SIZE; i++)
		memory[i] = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            memory[i][j] = 0;
	return 0;
}

int sc_memorySet(int i_address, int j_address, int value)
{
	if ((i_address >= SIZE )|| (i_address < 0) || (j_address >= SIZE) || (j_address < 0))
		return 1;	// выход за границы памяти

	memory[i_address][j_address] = value;
	
	return 0;
}

int sc_memoryGet(int i_address, int j_address, int &value)
{
	if ((i_address >= SIZE )|| (i_address < 0) || (j_address >=SIZE) || (j_address < 0))
		return 1;//выход за границы памяти (C)

	value = memory[i_address][j_address];

	return 0;
}

int sc_memorySave(char *filename)
{
	FILE *mem_file = fopen(filename, "wb");

	fwrite(memory, sizeof(int), SIZE, mem_file);
	fclose(mem_file);

	return 0;
}

int sc_memoryLoad(char *filename)
{
	FILE *mem_file = fopen(filename, "rb");

	fread(memory, sizeof(int), SIZE, mem_file);
	fclose(mem_file);

	return 0;
}

int sc_regInit()
{
	flag = 0;
	return 0;
}

int sc_regSet(int reg, int value)
{
	if (reg == P || reg == O || reg == M || reg == T || reg == E) {
		if (value == 0) {
			flag = flag & ~reg;
		} else if (value == 1) {
			flag = flag | reg;
		} else {
			return 0;
		}
	}
	return 0;
}

int sc_regGet(int reg, int *value)
{
	if (reg == P || reg == O || reg == M || reg == T || reg == E) {
		if ((flag & reg) != 0) {
			*value = 1;
		} else {
			*value = 0;
		}
	}
	return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
	if (command < 0x10 
		|| (command > 0x11 && command < 0x20) 
		|| (command > 0x21 && command < 0x30)
		|| (command > 0x33 && command < 0x40)
		|| (command > 0x43 && command < 0x51)
		|| command > 0x76)
	{
		return 1;
	}

	if (operand > 0x127 || operand < 0) {
		return 1;
	}

	*value = (command << 7) | operand;

	return 0;
}

int sc_commandDecode(int value, int *command, int *operand)
{
	if ((value >> 14) != 0) {
		return 1;
	}

	*command = value >> 7;
	*operand = value & 0x7F;
	return 0;
}

int sc_regFlagPrint()
{
	printf("%d\n", flag);
	return 0;
}

void delete_memory() {
	for (int i = 0; i < SIZE;i++)
		delete[] memory[i];
	delete[] memory;
}