NAME = mini

CC = gcc

SRC =	main \
	  	init_minishell \
	  	pre_process \
	  	pk_lst

ENV	=	sort_env

LIST =	handle_list_life \
		handle_list_index \
		handle_list_data \
	  	print_list 

TEST =	test_pk_lst \
		test_env_list

FIL =	$(addsuffix .c, $(SRC)) \
		$(addsuffix .c, $(addprefix env/, $(ENV))) \
		$(addsuffix .c, $(addprefix list/, $(LIST))) \
		$(addsuffix .c, $(addprefix test/, $(TEST))) 


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
