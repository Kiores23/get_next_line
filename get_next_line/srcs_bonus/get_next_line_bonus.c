/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:31 by amery             #+#    #+#             */
/*   Updated: 2022/11/29 13:03:52 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/get_next_line_bonus.h"

char	*ft_free_stackandbuff(char **stack, char *buffer)
{
	if (*stack)
		free(*stack);
	if (buffer)
		free(buffer);
	*stack = NULL;
	buffer = NULL;
	return (NULL);
}

//fonction qui lit la ligne si besoin pour faire avancer la stack.

char	*ft_read_line(int fd, char *stack)
{
	char	*buffer;
	int		nbyt;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_stackandbuff(&stack, NULL));
	nbyt = 1;
	while (nbyt != 0 && !ft_strchr(stack, '\n'))
	{
		nbyt = read(fd, buffer, BUFFER_SIZE);
		if (nbyt < 0)
			return (ft_free_stackandbuff(&stack, buffer));
		buffer[nbyt] = 0;
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

//fonction qui lit la stack jusqu'au premier retour a la ligne.
//retourne ce qui a ete lue.

char	*ft_take_line(char *stack)
{
	char	*line;
	int		nbyte;

	nbyte = 0;
	while (stack[nbyte] && (!nbyte || stack[nbyte - 1] != '\n'))
		nbyte++;
	line = malloc(sizeof(char) * (nbyte + 1));
	if (!line)
		return (ft_free_stackandbuff(&stack, NULL));
	ft_strlcpy(line, stack, nbyte + 1);
	return (line);
}

//fonction qui netoie la stack de la line retour pour faire avancer la stack.

char	*ft_clear_stack(char *stack)
{
	char	*newstack;
	int		nbyte;

	nbyte = 0;
	while (stack[nbyte] && (!nbyte || stack[nbyte - 1] != '\n'))
		nbyte++;
	newstack = malloc(sizeof(char) * (ft_strlen(stack) - nbyte + 1));
	if (!newstack)
		return (ft_free_stackandbuff(&stack, newstack));
	ft_strlcpy(newstack, stack + nbyte, ft_strlen(stack) - nbyte + 1);
	free(stack);
	return (newstack);
}

char	*get_next_line(int fd)
{
	static char	*stack[1025];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (ft_free_stackandbuff(&stack[fd], NULL));
	stack[fd] = ft_read_line(fd, stack[fd]);
	if (!stack[fd] || !*stack[fd])
		return (ft_free_stackandbuff(&stack[fd], NULL));
	line = ft_take_line(stack[fd]);
	stack[fd] = ft_clear_stack(stack[fd]);
	return (line);
}
