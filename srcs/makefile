NAME = mini

CC = gcc

SRC = juepark_main \
	  init_minishell \
	  tool \
	  pre_process \
	  sort_env \
	  modify_env \
	  init_env

FIL = $(addsuffix .c, $(addprefix ./, $(SRC)))

OBJ = $(FIL:.c=.o)

LIB_OPT = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(LIB_OPT) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@./$(NAME) ec""ho"" "this is simple test"; cd ..;

lldb: $(OBJ)
	@$(CC) -g $(NAME) $(LIB_OPT) $(OBJ)

.PHONY: all clean fclean re test lldb
