#include<stdio.h>
#include<stdlib.h>

int main(){
	int *a, *b, *c;
	a = (int *) malloc(sizeof(int)); //a is now 0x12345678
	printf("Pointer(a): %p\n", a);
	free(a);  //byte 0x12345678 is now available to malloc
	b = (int *) malloc(sizeof(int)); //b is now 0x12345678!
    printf("Pointer(b): %p\n", b);
	*b = 5;
	free(a); //free 0x12345678 again!?!? b is now freed too!
	c = (int *) malloc(sizeof(int)); //c is now 0x12345678
    printf("Pointer(c): %p\n", c);
	*c = 6;
	printf("Value: %d\n", *b);
	return 0;
}
