/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 19:07:55 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 18:52:01 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);
void ft_putstr(const char *s);

void ft_putendl(const char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
