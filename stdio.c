#include "stdio.h"
#include "uart.h"

void printf(char* s){
    while(*s != '\0') {
    	uart_output(*s);
	s++;
    }
}

void println(char*s){
    printf(s);
    printf("\r\n");
}

void putc(char c){
   if (c == '\r') {
   	// Something odd going on with
	// newlines. Look into this...
   	printf("\r\n");
	return;
   }
   uart_output(c);
}

char getc(){
   char c = uart_input();
   return c;
}
