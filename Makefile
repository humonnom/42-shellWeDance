NAME = minishell

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = 

FUNC =	main \
	  	init_minishell \
		pk_split \
		handle_quote \
		handle_bit \
		inc_shlvl \
		gen_line_list \
		gen_tokens_list \
		del_quote \
		get_eval \
		gen_tokens \
		print_tokens \
		free_tokens \
		set_list_to_darr \
		print_darr \
		free_darr \
		categorize_cmd \
		select_sh_bti \
		redo_sh_bti \
		run_bti \
		get_bti_path \
		mod_eval \
		gen_env \
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
		add_elist \
		free_elist \
		print_elist \
		print_line_list \
		set_darr_to_list \
		print_list \
		run_cmd \
		show_error \
		exit_fatal \
		exit_shell \
		is_bracket \
		set_bracket_type \
		set_fd \
		is_valid_fd \
		open_valid_fd \
		get_next_line_tc \
		ft_cursor \
		ft_cursor2 \
		ft_putchar_tc \
		calc \
		is_key_arrow \
		append_history_list \
		handle_sig_in_gnl

OBJDIR = ./objs
INCDIR = ./incs
SRCDIR = ./srcs
LIBDIR = ./libft
LIBFT = -L./libft -lft

SRC  = $(addsuffix .c, $(FUNC))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBDIR) all
	$(CC) $(CFLAGS) -lcurses -o $(NAME) $(LIBFT) $(OBJS) #2> /dev/null || true
	echo "Start Program"
	
#$(OBJS): $(SRCS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INCDIR) -lcurses -o $@ -c $< #2> /dev/null || true

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
