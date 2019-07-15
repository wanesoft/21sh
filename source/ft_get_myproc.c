/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_myproc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:55:26 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/07 11:59:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_vector				*ft_get_myproc(t_vector *my_vect, int mode)
{
	static t_vector		*my_vector_here = 0;

	if (!mode)
		return (my_vector_here);
	else
		my_vector_here = my_vect;
	return (0);
}
