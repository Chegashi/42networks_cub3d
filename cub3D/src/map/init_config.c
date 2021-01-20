/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:44:17 by abort             #+#    #+#             */
/*   Updated: 2021/01/20 17:39:13 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = (t_cub*)malloc(sizeof(t_cub));
	cub->line = (char*)malloc(sizeof(char));
	cub->floor_color = ft_calloc_tab_int(3);
	cub->ceilling_color = ft_calloc_tab_int(3);
	cub->resolution = ft_calloc_tab_int(3);
	cub->player_position = (int*)malloc(sizeof(int) * 2);
	cub->map_str = (char*)malloc(sizeof(char));
	cub->msg = (char*)malloc(sizeof(char) * 25);
	cub->resolution[0] = -1;
	cub->resolution[1] = -1;
	cub->north_texture = (char*)malloc(sizeof(char));
	cub->south_texture = (char*)malloc(sizeof(char));
	cub->west_texture = (char*)malloc(sizeof(char));
	cub->east_texture = (char*)malloc(sizeof(char));
	cub->sprite_texture = (char*)malloc(sizeof(char));
	cub->north_texture[0] = 0;
	cub->south_texture[0] = 0;
	cub->west_texture[0] = 0;
	cub->east_texture[0] = 0;
	cub->sprite_texture[0] = 0;
	ft_map(cub);
	return (cub);
}

void	ft_map(t_cub *cub)
{
	int		i;

	i = -1;
	cub->nbr_ligne = 0;
	cub->nbr_column = 0;
	cub->map_str[0] = '\0';
	cub->map = NULL;
	cub->direction = 0;
	cub->msg = ft_strcpy(cub->msg, "ok");
	cub->valide = 1;
	cub->fd = -1;
	cub->player_position[0] = -1;
	cub->player_position[1] = -1;
	while (++i < 2)
	{
		cub->floor_color[i] = -1;
		cub->ceilling_color[i] = -1;
	}
}

int		*ft_calloc_tab_int(int n)
{
	int *tab;

	tab = (int*)malloc(sizeof(int) * n);
	return (tab);
}

char	*ft_init_str(char *str_mem)
{
	free(str_mem);
	return (ft_strdup(""));
}

void	get_err(t_cub *cub, char *msg)
{
	cub->msg = ft_strcpy(cub->msg, msg);
	cub->valide = 0;
}
