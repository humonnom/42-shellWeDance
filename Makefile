NAME = mini

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = 

SRC =	main \
	  	init_minishell \
		pk_split \
		parse_env \
		handle_quote \
		handle_bit \
		inc_shlvl \
		get_next_line \
		parse_line \
		parse_set \
		select_func \
		trim_cmd
#	  	pk_lst \
		export_env \


LIST =	gen_elist \
		get_elist \
		mod_elist \
		add_elist \
		free_elist \
		print_elist \
		print_alist \
		print_slist
#get_list \
		get_list_data \
		get_list_index \
		add_list_data \
		mod_list_data \
		print_list \

SRCDIR = ./srcs
SRCS = $(addsuffix .c, $(addprefix $(SRCDIR)/, $(SRC))) \
		$(addsuffix .c, $(addprefix $(SRCDIR)/env/, $(ENV))) \
		$(addsuffix .c, $(addprefix $(SRCDIR)/list/, $(LIST))) \

OBJS = $(SRCS:.c=.o)

OBJDIR = ./objs
INCDIR = ./incs

LIBDIR = ./libft

LIBOPT = -L./libft -lft

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<
	
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBDIR) all
	@$(CC) $(CFLAGS) -o $(NAME) $(LIBOPT) $(OBJS)
	echo "Start Program"

	
#$(OBJDIR)/%.o: $(SRCS)
#	mkdir $(OBJDIR) #2> /dev/null || true
#	$(CC) $(CFLAGS) -I$(INCDIR) $(LIBOPT) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

test: re
	@./$(NAME) ec""ho"" "this is simple test"; cd ..;

.PHONY: all clean fclean re test
