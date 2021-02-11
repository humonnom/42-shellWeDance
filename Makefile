NAME = mini

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = 

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
