NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
SRC_M		= command.c			\
			  command2.c		\
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
			  checker2_bonus.c	\
			  command_bonus.c	\
			  command2_bonus.c	\
			  list_bonus.c		\
			  list2_bonus.c		\
			  utils_bonus.c		\
			  valid_bonus.c		\

LIB			= libft/libft.a
RM			= rm -f

$(NAME) :	$(LIB) $(SRC_M)
	$(CC) $(SRC_M) $(LIB) -o $(NAME)

$(BONUS) :	$(LIB) $(SRC_B)
	$(CC) $(SRC_B) $(LIB) -o $(BONUS)

$(LIB) :
	make -C ./libft B=1 all

all :		$(NAME)

bonus :		$(BONUS)

clean :
	make -C ./libft clean

fclean :	clean
	$(RM) $(LIB) $(NAME) $(BONUS)

re :		fclean all

.PHONY :	all bonus clean fclean re
