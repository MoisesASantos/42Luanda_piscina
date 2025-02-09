void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	troca;
	int	temp;

	if(size <= 1)
		return ;
	while(1)
	{
		i = 0;
		troca = 0;
		while(i < size - 1)
		{
			if(tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				troca = 1;
			}
			i++;
		}
		if(!troca)
			break;
	}
}
