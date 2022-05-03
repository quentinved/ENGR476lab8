NAME	=	lab8

SRC	=	src/main.c	\
		src/dijkstra.c	\
		src/minilib.c	\
		src/readfile.c	\

CFLAG	=	-g -W -Werror -Wextra

INCFLAG	=	-I./include

OBJ	=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) $(INCFLAG) -o $(NAME) 
	rm -f $(OBJ)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	$(NAME)

%.o:	%.c
		@$(CC) -o $@ -c $< -W $(INCFLAG)
