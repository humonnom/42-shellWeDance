NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FUNC =	main \
		add_elist \
		append_history_list \
		calc \
		categorize_cmd \
		close_tokens_fds \
		cvt_char_to_str \
		del_quote \
		exact_strncmp \
		free_darr \
		free_env \
		free_tokens \
		ft_cursor \
		ft_putchar_tc \
		gen_elist \
		gen_env \
		gen_line_list \
		gen_tokens \
		gen_tokens_list \
		get_dollar_eval \
		get_elist \
		get_eval \
		get_max_strlen \
		get_next_line_tc \
		handle_arg \
		handle_bit \
		handle_key_arrow \
		handle_quote \
		handle_sig \
		handle_sig_in_proc \
		inc_shlvl \
		is_bracket \
		is_dquote \
		is_exist_dir \
		is_key_arrow \
		is_squote \
		mod_eval \
		open_valid_fd \
		pk_split \
		print_elist \
		print_list \
		print_sorted_elist \
		print_tokens \
		redo_sh_bti \
		run_bti \
		run_cmd \
		select_sh_bti \
		set_bracket_type \
		set_darr_to_list \
		set_fd \
		set_list_to_darr \
		set_signo \
		sh_bti_cd \
		sh_bti_echo \
		sh_bti_env \
		sh_bti_exit \
		sh_bti_export \
		sh_bti_export_utils \
		sh_bti_pwd \
		sh_bti_unset \
		show_error \
		sort_elist \
		init_minishell \

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
	@$(MAKE) -C $(LIBDIR) all
	@$(CC) $(CFLAGS) -ltermcap -o $(NAME) $(LIBFT) $(OBJS) 2> /dev/null || true
	@echo "Start Program"
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "Generating minishell... %-33.33s\r" $@
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $< 2> /dev/null || true

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
