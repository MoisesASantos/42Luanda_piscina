#include <stdio.h>

int main(void)
{
	float IMC;
	float altura;
	float massa;

	printf("Digite a sua altura: ");
	scanf("%f", &altura);
	printf("Digite a sua massa: ");
	scanf("%f", &massa);
	IMC = massa / (altura * altura);
	if(IMC < 18.5)
	{
		printf("O seu IMC é de %.2f por isso está baixo do peso\n", IMC);
	}
	else if(IMC >= 18.5 && IMC < 25)
	{
		printf("O seu IMC é de %.2f por isso está no peso normal\n", IMC);
	}
	else if(IMC >= 25 && IMC < 30)
        {
                printf("O seu IMC é de %.2f por isso está no sobrepeso\n", IMC);
	}
	else if(IMC >= 30 && IMC < 35)
        {
                printf("O seu IMC é de %.2f por isso está na obesidade grau 1\n", IMC);
	}
	else if(IMC >= 35 && IMC < 40)
        {
                printf("O seu IMC é de %.2f por isso está na obesidade grau 2\n", IMC);
	}
	else if(IMC >= 40)
        {       
                printf("O seu IMC é de %.2f por isso está na obesidade grau 3\n", IMC);
	}
	return (0);
}
