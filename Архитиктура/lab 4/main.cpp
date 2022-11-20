#include "myBigChars.h"
#include "memory.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int bcint0 [2] = {1717976064, 3958374};	//0b01100110011001100011110000000000, 0b00000000001111000110011001100110
int bcint1 [2] = {1010315264, 3158064};	//0b00111100001110000011000000000000, 0b00000000001100000011000000110000
int bcint2 [2] = {1010842624, 8258050};	//0b00111100010000000011110000000000, 0b00000000011111100000001000000010
int bcint3 [2] = {2120252928, 8282238};	//0b01111110011000000111111000000000, 0b00000000011111100110000001111110
int bcint4 [2] = {2120640000, 6316158};	//0b01111110011001100110011000000000, 0b00000000011000000110000001111110
int bcint5 [2] = {1040350720, 4079680};	//0b00111110000000100111111000000000, 0b00000000001111100100000001000000
int bcint6 [2] = {35789824, 1974814};		//0b00000010001000100001110000000000, 0b00000000000111100010001000011110
int bcint7 [2] = {811630080, 396312};		//0b00110000011000000111111000000000, 0b00000000000001100000110000011000
int bcint8 [2] = {1013332992, 3958374};	//0b00111100011001100011110000000000, 0b00000000001111000110011001100110;
int bcint9 [2] = {2087074816, 3956832};	//0b01111100011001100011110000000000, 0b00000000001111000110000001100000
int bcintp [2] = {2115508224, 1579134};	//0b01111110000110000001100000000000, 0b00000000000110000001100001111110

void printMemoryCell(int value)
{
    cout << "+";
    for(int i=0; i < 4; i++)
    	cout << value;
    cout << " ";	
}

void BigChars(int value)
{
		//+4BigChars
    bc_printbigchar(bcintp, 1, 13, cl_green, cl_default );
    switch(value)
    {
    	case 0:
    		for(int i = 0; i < 4; i++)		
    			bc_printbigchar(bcint0, 8*i+9, 13, cl_green, cl_default );
    	break;
    	case 1:
    		for(int i = 0; i < 4; i++)		
    			bc_printbigchar(bcint1, 8*i+9, 13, cl_green, cl_default );
    	break;
    	//
    	case 9:
    		for(int i = 0; i < 4; i++)		
    			bc_printbigchar(bcint9, 8*i+9, 13, cl_green, cl_default );
    	break;
    }		
    mt_setbgcolor(cl_default);
    mt_setfgcolor(cl_white);			
    bc_box(1, 13, 40, 20); 
    mt_gotoXY (3, 1);
    cout<<"Memory";
}

int main()
{

    setbuf(stdout, NULL);
    mt_clrscr();
    sc_memoryInit();
    sc_memorySet(0, 0, 9);
    sc_memorySet(1, 1, 1);
    
    //Memory
    int value;		
    mt_gotoXY (1, 2);
    for(int i = 0; i < SIZE; i++){
    cout << " ";
        for (int j = 0; j < SIZE; j++){ 
            sc_memoryGet(i, j, value);
            printMemoryCell(value);
        }
        cout << "\n";
    }
    bc_box(1, 1, 62, 12); 
    
    //+4BigChars
    mt_setfgcolor(cl_green);
    mt_gotoXY (2, 2);
    sc_memoryGet(0, 0, value);
    printMemoryCell(value);
    mt_setfgcolor(cl_white);
    mt_setbgcolor(cl_default);
    BigChars(value);
    
    //accumulator
    bc_box(63, 1, 84, 3);
    mt_gotoXY (65, 1);
    cout<<"accumulator";
    
    //inctructionCounter
    bc_box(63, 4, 84, 6);
    mt_gotoXY (65, 4);
    cout<<"inctructionCounter";
    
    //Operation
    bc_box(63, 7, 84, 9);
    mt_gotoXY (65, 7);
    cout<<"Operation";
    
    //Flags
    bc_box(63, 10, 84, 12);
    mt_gotoXY (70, 11);
    cout<<"P O E V M";
    mt_gotoXY (65, 10);
    cout<<"Flags";
    
    //Keys:
    bc_box(41, 13, 84, 20);
    mt_gotoXY (42, 14);
    cout<<"l - load";
    mt_gotoXY (42, 15);
    cout<<"s - save";
    mt_gotoXY (42, 16);
    cout<<"r - run";
    mt_gotoXY (42, 17);
    cout<<"t - step";
    mt_gotoXY (42, 18);
    cout<<"i - reset";
    mt_gotoXY (42, 19);
    cout<<"F5 - accumulator";
    mt_gotoXY (42, 19);
    cout<<"F6 - inctructionCounter";
    mt_gotoXY (43, 13);
    cout<<"Keys: ";
    
    mt_gotoXY(1, 23);
    
   	int c, i=0,j=0, flag = 1;
    while(flag)
    {
    		scanf("%d", &c) ;
    		
    		mt_setfgcolor(cl_white);
    		mt_setbgcolor(cl_default);
    		mt_gotoXY (6*i+2, j+2);
    		sc_memoryGet(i, j, value);
    		printMemoryCell(value);
    		switch(c)
    		{	
    			case 4://влево 
    			if(i>0) i--;	break;
    			
					case 6://вправо
					if(i<10) i++; break;
					
					case 8://вверх
					if(j>0) j--; break;
					
					case 2://вниз
					if(j<10) j++; break;
					
					default: flag = 0; break;	
    		}	
    		
    		
    		mt_setfgcolor(cl_green);
    		mt_gotoXY (6*i+2, j+2);
    		sc_memoryGet(i, j, value);
    		printMemoryCell(value);
    		mt_setfgcolor(cl_white);
    		mt_setbgcolor(cl_default);
    		BigChars(value);
    		
    		mt_gotoXY(1, 23);
    }
    
    delete_memory();
    
    return 0;

}