NAME		= libftprintf.a
CC			= cc
CFLAG		= -Wall -Wextra -Werror
OBJFLAG		= -c
AR			= ar
ARFLAG		= rcs
SRC_M		= ft_printf.c			\

SRC_B		= ft_printf_bonus.c		\

OBJ_M		= $(SRC_M:.c=.o)
OBJ_B		= $(SRC_B:.c=.o)
CUR_M		= ft_printf.o
CUR_B		= ft_printf_bonus.o
LIB			= ./libft/libft.a
RM			= rm -f

ifdef B
	SEL		= $(OBJ_B)
	UNSEL	= $(OBJ_M)
	CUR		= $(CUR_B)
else
	SEL		= $(OBJ_M)
	UNSEL	= $(OBJ_B)
	CUR		= $(CUR_M)
endif

%.o :		%.c
	$(CC) $(CFLAG) $(OBJFLAG) $?

$(NAME) :	$(LIB) $(SEL)
ifeq (, $(wildcard $(CUR)))
	$(RM) $(UNSEL)
	$(AR) $(ARFLAG) $(NAME) $(SEL)
endif

$(LIB) :
ifeq (, $(wildcard $(CUR)))
	make -C ./libft all
	mv $(LIB) $(NAME)
endif

all :		$(NAME)

bonus :
	make B=1 all

clean :
	make -C ./libft clean
	$(RM) $(OBJ_M) $(OBJ_B)

fclean :	clean
	$(RM) $(LIB) $(NAME)

re :
ifneq (, $(wildcard $(CUR_B)))
	make fclean
	make -C ./libft bonus
	mv $(LIB) $(NAME)
	$(CC) $(CFLAG) $(OBJFLAG) $(SRC_B)
	$(AR) $(ARFLAG) $(NAME) $(OBJ_B)
else
	make fclean
	make -C ./libft all
	mv $(LIB) $(NAME)
	$(CC) $(CFLAG) $(OBJFLAG) $(SRC_M)
	$(AR) $(ARFLAG) $(NAME) $(OBJ_M)
endif

.PHONY :	all bonus clean fclean re
