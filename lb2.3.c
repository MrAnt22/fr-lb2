#include <stdio.h>
#include <stdlib.h>

int global_var = 42;
int global_uninit;

void stack_growth(){
	int big_array[10000];
	printf("stack after allocation: %p\n", (void*)&big_array);
}

int main(){

	int local_var;
	char *heap_var = (char*) malloc(10);
	
	printf("Code (.text)   : %p\n", (void*)main);
	printf("Initialized data (.data) : %p\n", (void*)&global_var);
	printf("Uninit data (.bss) : %p\n", (void*)&global_uninit);
	printf("Heap   : %p\n", (void*)heap_var);
	printf("Stack  : %p\n", (void*)&local_var);

	stack_growth();	

	free (heap_var);
	return 0;
}
