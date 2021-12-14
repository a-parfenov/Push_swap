/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:10:09 by aleslie           #+#    #+#             */
/*   Updated: 2021/12/13 19:07:17 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	fd_main(int n, int fd)
// {
// 	char	c;

// 	if (n < 0)
// 		n = -n;
// 	if (n > 9)
// 	{
// 		fd_main(n / 10, fd);
// 		n = n % 10;
// 	}
// 	c = n + '0';
// 	write(fd, &c, 1);
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == -2147483648)
// 	{
// 		write(fd, "-2147483648", 11);
// 		return ;
// 	}
// 	if (n < 0)
// 		write(fd, "-", 1);
// 	fd_main(n, fd);
// }

int	ft_putnbr(int n)
{
	char	c;

	if (!(n / 10 == 0))
		ft_putnbr((n / 10));
	write(1, "-", (n < 0 && (n / 10 == 0)));
	write(1, &c + 0 * (c = n % 10 * (1 - 2 * (n < 0)) + '0'), 1);
	return (0);
}
