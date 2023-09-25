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

#include <unistd.h>
#include <stdio.h>

/*void	ft_putnbr(int nb)
{
	int	temp;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else
	{
		temp = nb + '0';
		write(1, &temp, 1);
	}
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

int	check_base(char *base, int out)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[a] != '\0')
	{
		b = a + 1;
		if (base[a] == '+' || base[a] == '-' || base[a] < 33 || base[a] > 126)
			return (0);
		while (base[b] != '\0')
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (out);
}

int	ft_isbase(char n, char *base)
{
	int	c;

	c = 0;
	if (n == '\n' || n == '\t' || n == '\v' || n == '\f' || n == '\r'
		|| n == ' ' || n == '+' || n == '-')
		return (1);
	while (base[c] != '\0')
	{
		if (base[c] == n)
			return (2);
		c++;
	}
	return (0);
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
	return (check_base(base, res * n));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	a;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	a = i;
	while ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isbase(str[i], base) != 2)
			break ;
		i++;
	}
	return (ft_base_int (str, i - 1, a, base));
}

/*int	main(void)
{
	ft_putnbr (ft_atoi_base("---+-ff-", "2f"));
	write(1, "\n", 1);
	ft_putnbr (ft_atoi_base("-1011-2-01", "01"));
	write(1, "\n", 1);
	ft_putnbr (ft_atoi_base("     -+-14353fd", "0123456789f"));
	write(1, "\n", 1);
	ft_putnbr (ft_atoi_base("      	---10101001", "01"));
	write(1, "\n", 1);
	ft_putnbr (ft_atoi_base("      +---5z9", "0123456789abcdef"));
	return (0);
}*/
