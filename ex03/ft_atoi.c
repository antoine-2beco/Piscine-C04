/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:19:38 by ade-beco          #+#    #+#             */
/*   Updated: 2023/09/14 11:19:40 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*void	ft_putchar(int a)
{
	write(1 , &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = - nb;
		ft_putnbr(nb);
	}
	else
		ft_putchar(nb + '0');
}*/

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	resu;

	i = 0;
	n = 0;
	resu = 0;
	while ((str[i] == ' ') || (str[i] == '+') || (str[i] == '-')
		|| (str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r'))
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		resu = resu + (str[i] - '0');
		resu = resu * 10;
		i++;
	}
	if ((n % 2) == 1)
		return ((resu / 10) * -1);
	return (resu / 10);
}

/*int	main(void)
{
	char *str = "    	--+--+12345'67";
	ft_putnbr(ft_atoi(str));
	return(0);
}*/