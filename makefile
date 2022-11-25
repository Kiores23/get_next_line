
NAME = get_next_line

FILES =	get_next_line.c \
		get_next_line_utils.c \
		main.c \

FILES_BONUS =	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				main.c \

$(NAME) :
		gcc $(FILES) -o $(NAME)

f :
		gcc -Wall -Wextra -Werror $(FILES) -o $(NAME) -D BUFFER_SIZE=1

b :
		gcc -Wall -Wextra -Werror $(FILES_BONUS) -o $(NAME)_bonus -D BUFFER_SIZE=1