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


FIL =	$(addsuffix .c, $(SRC)) \
		$(addsuffix .c, $(addprefix env/, $(ENV))) \
		$(addsuffix .c, $(addprefix list/, $(LIST))) \


OBJ = $(FIL:.c=.o)

LIBDIR = ./libft

LIB_OPT = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBDIR) all
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
