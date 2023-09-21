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

void	ft_putnbr_base_rec(long a, char *base, int l)
{
	if (a < 0)
	{
		a = -a;
		ft_putchar('-');
	}
	if (a < l)
	{
		ft_putchar(base[a]);
	}
	if (a >= l)
	{
		ft_putnbr_base_rec(a / l, base, l);
		ft_putnbr_base_rec(a % l, base, l);
	}
}

void	ft_putnbr_base(int a, char *base)
{
	int		l;
	long	x;

	x = a;
	l = ft_strlen(base);
	if (!(check_base(base)))
		return ;
	ft_putnbr_base_rec(x, base, l);
}

/*int	main(void)
{
	char *b1 = "01";
	
	ft_putnbr_base(-2147364748, b1);
	return (0);
}*/