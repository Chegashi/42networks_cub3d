/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:47:36 by abort             #+#    #+#             */
/*   Updated: 2021/02/17 19:38:20 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_color(char *line, int **tab)
{	line++;
	(*tab)[0] = ft_atoi_s(&line);
	line++;
	(*tab)[1] = ft_atoi_s(&line);
	line++;
	(*tab)[2] = ft_atoi_s(&line);
}

void	ft_resolution(char *line, t_cub *cub)
{
	line++;
	cub->resolution[0] = ft_atoi_s(&line);
	line++;
	cub->resolution[1] = ft_atoi_s(&line);
}

void	ft_read_texture(char *line, t_texture *texture)
{
	int			len;
	int			start;
	int			i;
	char		*path;
	void		*file;

	//printf("%s\n",line);
	len = 0;
	i = 0;
	if (line[2] != '0')
		get_err("error\tinvalide texture file\n");
	while (line[i] && line[i] != ' ')
		i++;
	start = line[i] ? i + 1 : i;
	while (line[i++])
		len++;
	path = ft_substr(line, start, ft_strlen(line));
	if (!(file = mlx_xpm_file_to_image(g_game->mlx_ptr, path, &(texture->width),
	&(texture->hight))))
		get_err("error\tinvalide texture file\n");
	else
		texture->color = (int*)mlx_get_data_addr(file, &(texture->bpp),
		&(texture->l_len), &(texture->endian));
}

void	ft_read_map(t_cub *cub)
{
	int		gnl_return;
	int		len;
	char	*tmp;

static int i = 0;
	len = 0;
	gnl_return = 1;
	while (gnl_return && cub->valide && cub->line[0])
	{
		if (*(cub->line) == ' ' || *(cub->line) == '1')
		{
			(cub->nbr_ligne)++;
			len = ft_strlen(cub->line);
			if (len > cub->nbr_column)
				cub->nbr_column = len;
			tmp = ft_strjoinn(cub->map_str, cub->line);
			free(cub->map_str);
			cub->map_str = tmp;
			cub->line = ft_init_str(cub->line);
			gnl_return = get_next_line(cub->fd, &(cub->line));
			printf("%d\t%s\n",++i, cub->line);
		}
		else if (!gnl_return)
			get_err("error\tthe map must tart with '1' or ' '\n");
	}
	ft_tomap(cub);
}

void	check_map(t_cub *cub)
{
	int i;
	int j;

	i = -1;
	if (!(cub->direction))
		cub->valide = 0;
	while (++i < cub->nbr_ligne && cub->valide)
	{
		j = -1;
		while (++j < cub->nbr_column && cub->valide)
		{
			if (((i == 0 || j == 0 || i == (cub->nbr_ligne - 1)
			|| j == (cub->nbr_column - 1)) && (cub->map[i][j] != '1'
			&& cub->map[i][j] != ' ')) && (ft_isin("0NSWE2", cub->map[i][j])
			&& (cub->map[i - 1][j - 1] == ' ' && cub->map[i - 1][j + 1] == ' '
			&& cub->map[i + 1][j + 1] == ' '
			&& cub->map[i + 1][j - 1] == ' ')))
				get_err("error\tthe map must be ontoured by 1\n");
		}
	}
}
