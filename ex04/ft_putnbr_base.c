/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:29:30 by ade-beco          #+#    #+#             */
/*   Updated: 2023/09/14 15:29:32 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0; 
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[a])
	{
		b = a + 1;
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] < 32 || base[a] > 126)
			return (0);
		while (base[b])
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr_base(int a, char *base)
{
	int	result[100];
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(base);
	if (!(check_base(base)))
		return ;
	if (a < 0)
	{
		a = -a;
		ft_putchar('-');
	}
	while (a)
	{
		result[i] = a % l;
		a = a / l;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(base[result[i]]);
		i--;
	}
}

/*int main(void)
{
	char *b1 = "55";
	ft_putnbr_base(236, b1);
	return (0);
}*/