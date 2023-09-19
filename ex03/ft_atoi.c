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

/*#include <stdio.h>*/

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	resu;

	i = 0;
	n = 1;
	resu = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while ((str[i] > 47) && (str[i] < 58))
	{
		resu = ((resu * 10) + (str[i] - '0'));
		i++;
	}
	return (resu * n);
}

/*int	main(void)
{
	char *str = "    2147483648'67";
	printf("%d", (ft_atoi(str)));
	return (0);
}*/