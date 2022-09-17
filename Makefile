NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
SRC_M		= command.c			\
			  command2.c		\
			  compress.c		\
			  list.c			\
			  list2.c			\
			  pwap.c			\
			  pwap2.c			\
			  sort.c			\
			  sort2.c			\
			  reflect.c			\
			  utils.c			\
			  valid.c			\

SRC_B		= checker_bonus.c	\

LIB			= ./libft/libft.a
RM			= rm -f

$(NAME) :	$(LIB)
	$(CC) $(SRC_M) $(LIB) -o $(NAME)

$(LIB) :
	make -C ./libft bonus

$(BONUS) :	$(OBJ_B)
	$(CC) $(SRC_B) -o $(BONUS)

all :		$(NAME)

bonus :		$(BONUS)

clean :
	make -C ./libft clean

fclean :	clean
	$(RM) $(NAME) $(LIB) $(BONUS)

re :
	make fclean
	make -C ./libft bonus
	$(CC) $(SRC_M) $(LIB) -o $(NAME)

.PHONY :	all bonus clean fclean re
