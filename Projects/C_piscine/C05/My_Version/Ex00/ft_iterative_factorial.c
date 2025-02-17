int	ft_iterative_factorial(int nb)
{
	int	resultado;

	resultado = 1;
	if(nb < 0)
		return (0);
	while(nb > 1)
	{
		resultado = resultado * nb;
		n--;
	}
	return (resultado);
}
