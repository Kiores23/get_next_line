
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_free_stackandbuff(char **stack, char *buffer);
char	*ft_strjoin(char **s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
void	ft_strlcpy(char *dst, const char *src, int size);

#endif