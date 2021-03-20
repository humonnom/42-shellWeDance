NAME = mini

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = 

SRC =	main \
		init_global \
	  	init_minishell \
		pk_split \
		handle_quote \
		handle_bit \
		inc_shlvl \
		get_next_line \
		parse_line \
		del_quote \
		get_eval \
		parse_set \
		get_set \
		print_set \
		free_set \
		set_list_to_darr \
		print_darr \
		free_darr \
		categorize_cmd \
		select_sh_bti \
		redo_sh_bti \
		run_bti \
		mod_eval \
		get_env \
		free_env \
		sh_bti_export \
		sh_bti_unset \
		sh_bti_env \
		sh_bti_echo \
		sh_bti_cd \
		sh_bti_pwd \
		sh_bti_exit \
		get_max_strlen \
		get_dollar_eval \
		cvt_char_to_str \
		is_squote \
		is_dquote \
		handle_arg \
		exact_strncmp \
		gen_elist \
		get_elist \
		mod_elist \
		add_elist \
		free_elist \
		print_elist \
		print_slist \
		set_darr_to_list \
		print_list \
		run_cmd \
		show_error \
		exit_fatal \
		exit_shell \
		display_prompt \
		handle_sig_init \
		handle_sig_proc \
		handle_eof \
		handle_enter \
		handle_fflush


LIST = 
#		export_env \
#	  	pk_lst \
	#	parse_env \


#		get_list_data \
		get_list_index \
		add_list_data \
		mod_list_data \

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
	@echo "Start Program"

	
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
