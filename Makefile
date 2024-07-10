NAME = pushswap.exe
NAME_BONUS = checker.exe

MAIN_SRC = main.c 

SOURCES = \
			build_chunk.c check.c control_a.c control_b.c control_mass_a.c f_lstclear.c \
			f_lstdelone.c f_lstnew.c fewer_moves.c ft_atoi.c ft_bzero.c ft_calloc.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_split.c \
			ft_strdup.c ft_strlen.c ft_strncmp.c push_swap.c final_print.c push.c \
			reverse.c rotate.c swap.c utils.c f_calloc.c

BONUS_SRC = checker.c bonus_utils.c
	
OBJECTS = $(SOURCES:.c=.o)

MAIN_OBJ = main.o

BONUS_OBJ = checker.o bonus_utils.o

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAIN_OBJ) -o $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(OBJECTS) $(BONUS_OBJ) -o $(NAME_BONUS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BONUS_OBJ) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
