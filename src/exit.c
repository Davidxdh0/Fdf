/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 10:53:28 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/21 16:03:51 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arg)
{
	int	i;

	i = 0;
	if (!arg)
		return ;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}