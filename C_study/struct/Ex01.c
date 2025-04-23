#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct addt {
	char name[30];
	char street[40];
	char city[20];
	char state[3];
	unsigned long int zip;
} addr_info[MAX];

void init_list(void), enter(void);
void delete(void), list(void);
int menu_select(void), find_free(void);

int main(void)
{
	char choice;

	init_list();

	for(;;){
		choice = menu_select();
		switch(choice)
		{
			case 1: enter();
				break;
			case 2: delete();
				break;
			case 3: list();
				break;	
			case 4: exit(0);
		}
	}
	return (0);
}

void init_list(void)
{
	int t;
	for(t = 0; t < MAX; t++)
		addr_info[t].name[0] = '\0';
}

int menu_select(void)
{
	char s[80];
	int c;

	printf("1. Inserir um nome\n");
	printf("2. Excluir um nome\n");
	printf("3. Listar o arquivo\n");
	printf("4. Sair\n");

	do{
		printf("\nDigite a sua escolha: ");
		scanf("%s", s);
		c = atoi(s);
	}while(c < 0 || c > 4);
}

void enter(void)
{
	int slot;
	char s[80];

	slot = find_free();
	if(slot == -1)
	{
		printf("\nlista cheia");
		return ;
	}
	printf("Digite o nome: ");
	scanf("%s", addr_info[slot].name);
	printf("Digite a rua: ");
        scanf("%s", addr_info[slot].street);
	printf("Digite a cidade: ");
        scanf("%s", addr_info[slot].city);
	printf("Digite o estado: ");
        scanf("%s", addr_info[slot].state);
	printf("Digite o CEP: ");
        scanf("%s", s);
	addr_info[slot].zip = strtoul(s, '\0', 10);
}

int find_free(void)
{
	int t;

	for(t = 0; addr_info[t].name[0] && t < MAX; t++)
	{
		if(t == MAX)
			return -1;
		return t;
	}
}

void delete(void)
{
	int slot;
	char s[80];

	printf("Digite o registro #: ");
        scanf("%s", s);
	slot = atoi(s);
	if(slot >= 0 && slot < MAX)
		addr_info[slot].name[0] = '\0';
}

void list(void)
{
	int t;

	for(t = 0; t < MAX; ++t)
	{
		if(addr_info[t].name[0]) 
		{
			printf("%s\n", addr_info[t].name);
			printf("%s\n", addr_info[t].street);
			printf("%s\n", addr_info[t].city);
			printf("%s\n", addr_info[t].state);
			printf("%lu\n", addr_info[t].zip);
		}
	}
	printf("\n");
}	
