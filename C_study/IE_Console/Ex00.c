#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	printf("Write some text (digit point for exit).\n");
	do{
		ch = getchar();
		if(islower(ch)) 
			ch = toupper(ch);
		else
			ch = toupper(ch);
		putchar(ch);
	} while(ch != '.');
	return (0);
}
