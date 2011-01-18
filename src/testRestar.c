#include<stdio.h>

extern int restar(int a, int b);

/**
 * la cuenta que hago aca es la misma que la primer parte del comentario en testSumarArray.c 
 * 
 */

int main(int argc, char** argv){
	unsigned int a1 = 2887993178;
	unsigned int b1 = 554902799;
	unsigned int a2 = 2813987;
	unsigned int b2 = 1056784;
	unsigned int resultado2 = restar(a2,b2);
	unsigned int resultado1 = restar(a1,b1);
	
	printf("1er Test - Debiera dar 2333090379 y da %u\n",resultado1);
	printf("2do Test - Debiera dar 1757203 y da %u\n",resultado2);
	return 0;
}
