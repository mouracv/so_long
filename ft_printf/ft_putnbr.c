/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:35:12 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/12 13:46:18 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += ft_putchar('-');
		counter += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		counter += ft_putnbr((n / 10));
		counter += ft_putnbr((n % 10));
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}
