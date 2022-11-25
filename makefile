
NAME = get_next_line

FILES =	get_next_line.c \
		get_next_line_utils.c \
		main.c \


$(NAME) :
		gcc $(FILES) -o $(NAME)

f :
		gcc -Wall -Wextra -Werror $(FILES) -o $(NAME)