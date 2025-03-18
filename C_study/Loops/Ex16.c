#include <stdio.h>

int main(void)
{
	int func[10];
	int salary[10];
	int i = 0;
	int total_salary = 0;
	int salary_media;
	int salary_min;
        int salary_max;
	do{
		printf("Digite o número do funcionario: ");
		scanf("%d", &func[i]);
		printf("Digite o salário do funcionario: ");
                scanf("%d", &salary[i]);
		i++;
	}while(i < 10);
	total_salary = 0;
	salary_min = salary[0];
	salary_max = salary[0];
	for(i = 0; i < 10; i++)
	{
		total_salary += salary[i];
		if(salary_min > salary[i])
		{
			salary_min = salary[i];
		}
		if(salary_max < salary[i])
		{
			salary_max = salary[i];
		}
	}
	salary_media = total_salary / i;
	printf("A média de salário dos funcionários é %d kwanzas\n", salary_media);
	printf("O maior salário é de %d kwanzas\n", salary_max);
	printf("O menor salário é de %d kwanzas\n", salary_min);
	return (0);
}
