NAME = mini

CC = gcc

SRC =	main \
	  	init_minishell \
	  	pre_process \
	  	pk_lst \
		get_next_line \
		parse_line \
		handle_quote \
		handle_bit \
		pk_split 

ENV	=	sort_env

LIST =	get_list \
		handle_list_index \
		handle_list_data \
	 	print_list \
		free_list


FIL =	$(addsuffix .c, $(SRC)) \
		$(addsuffix .c, $(addprefix env/, $(ENV))) \
		$(addsuffix .c, $(addprefix list/, $(LIST))) \


OBJ = $(FIL:.c=.o)

LIBDIR = ./libft

LIB_OPT = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBDIR) all
	@$(CC) -o $(NAME) $(LIB_OPT) $(OBJ)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

test: re
	@./$(NAME) ec""ho"" "this is simple test"; cd ..;

lldb: $(OBJ)
	@$(CC) -g $(NAME) $(LIB_OPT) $(OBJ)

.PHONY: all clean fclean re test lldb
