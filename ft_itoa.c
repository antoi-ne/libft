/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:16:42 by ancoulon          #+#    #+#             */
/*   Updated: 2020/01/09 21:18:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long int nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	if (nbr < 10)
		count++;
	else
	{
		count += ft_size(nbr / 10);
		count += ft_size(nbr %10);
	}
	return (count);
}

static void		ft_add(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
}

static void	    ft_write(char *str, long int nbr)
{
	char	c;

	if (nbr < 0)
	{
		nbr *= -1;
		ft_add(str, '-');
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		ft_add(str, c);
	}
	else
	{
		ft_write(str, nbr / 10);
		ft_write(str, nbr % 10);
	}
}

char		*ft_itoa(int n)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (ft_size((long int)n) + 1))))
    return (NULL);
	str[0] = '\0';
	ft_write(str, (long int)n);
	return (str);
}