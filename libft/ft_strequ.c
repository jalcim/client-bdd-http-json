/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 07:35:37 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:15:58 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strequ(const char *s1, const char *s2)
{
	int compt;
	compt = 0;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);

		s1++;
		s2++;
		compt++;
	}

	s1 -= compt;
	s2 -= compt;

	return (1);
}
