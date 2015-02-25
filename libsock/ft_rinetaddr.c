/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rinetaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:22:52 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/21 15:26:13 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short ft_rhtons(unsigned short value)
{
    return (value << 8 | value >> 8);
}

unsigned int ft_rhtonl(unsigned int value)
{
	char *c;

	c = (char *)&value;
	return (c[3] >> 24 | c[2] >> 16 | c[1] >> 8 | c[0]);//l'une ou l'autre a test ^^
	return (c[3] | c[2] >> 8 | c[1] >> 16 | c[0] >> 24);
}
