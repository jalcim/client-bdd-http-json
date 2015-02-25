/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:54:44 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:17:18 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_striter(char *s, void (*f)(char *))
{
	int compt;
	compt = -1;

	while (s[++compt] != '\0')
		(*f)(&s[compt]);
}
