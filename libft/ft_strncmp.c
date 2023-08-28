/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:43:14 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/04/17 15:47:56 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((s1[a] && s2[a]) && (s1[a] == s2[a]) && (a < n))
		a++;
	if (a == n)
		return (0);
	else
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
/*
#include<stdio.h>

int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "abcd";

	printf("%d", ft_strncmp(str1, str2, 4));
}
*/
