NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
SRC_M		= pwap.c		\

SRC_B		= check.c		\

OBJ_M		= $(SRC_M:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
RM			= rm -f

%.o :		%.c
	$(CC) $(CFLAG) $(OBJFLAG) $?

$(NAME) :	$(OBJ_M)
	$(CC) $(CFLAG) $(OBJ_M) -o $(NAME)

$(BONUS) :	$(OBJ_B)
	$(CC) $(CFLAG) $(OBJ_B) -o $(BONUS)

all :		$(NAME)

bonus :		$(BONUS)

clean :
	$(RM) $(OBJ_M) $(OBJ_B)

fclean :	clean
	$(RM) $(NAME) $(BONUS)

re :		fclean all

.PHONY :	all bonus clean fclean re
