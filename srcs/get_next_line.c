/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:49:55 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 10:20:23 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

int	ft_struct(char **str, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while ((*str)[len] != '\0' && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&(*str)[len + 1]);
		free(*str);
		*str = tmp;
	}
	else
	{
		*line = ft_substr(*str, 0, len);
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

int	ft_return(char **str, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && str[fd] == NULL) || str[fd] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_struct(&str[fd], line));
}

int	check(int fd, char **line)
{
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (fd < 0 || line == NULL)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	static char	*str[4096];
	char		*tmp;

	if (check(fd, line) == -1)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_return(str, line, ret, fd));
}
