/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:54:44 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:23:31 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int ft_strlen (const char *src);

char * ft_strmap(const char *s, char (*f)(char))
{
	int compt;
	compt = -1;
	char *s2;

	s2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	while (s[++compt] != '\0')
	s2[compt] = (*f)(s[compt]);

	return (s2);
}
