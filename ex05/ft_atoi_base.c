/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2023/09/18 14:01:15 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>

void	ft_putchar(int a)
{
	write (1, &a, 1);
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
		nb = -nb;
		ft_putnbr(nb);
	}
	else
		ft_putchar(nb + '0');
}*/

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
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[a])
	{
		b = a + 1;
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] < 33 || base[a] > 126)
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

int	ft_base_int(char *str, int i, int a, char *base)
{
	int	j;
	int	res;
	int	x;
	int	n;

	x = 1;
	n = 1;
	res = 0;
	while (i >= a)
	{
		if (str[i] == '-')
			n *= -1;
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				res = res + (x * j);
				x *= ft_strlen(base);
			}
			j++;
		}
		i--;
	}
	return (res * n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	a;

	if (check_base(base) == 0)
		return (0);
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	a = i;
	while ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i] != '\0'))
	{
		j = 0;
		while ((base[j] != '\0') && (str[i] != base[j]))
			j++;
		if ((str[i] != base[j]))
			break ;
		i++;
	}
	return (ft_base_int (str, i, a, base));
}

/*int	main(void)
{
	char	*str = "    -+-110000001011111000001'67";
	char	*base = "";

	ft_putnbr (ft_atoi_base(str, base));
	return (0);
}
*/