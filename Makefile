NAME := 21sh

INC := ./include/

LIB := ./libftprintf/

SRC_DIR := ./source/

FLAGS := -g -Wall -Wextra -Werror

VPATH := source

SRC :=	ft_autocompl.c\
		ft_autocompl_2.c\
		ft_autocompl_3.c\
		ft_autocompl_dir.c\
		ft_back_screen.c\
		ft_clear_mygv.c\
		ft_del_letter.c\
		ft_get_mygv.c\
		ft_get_path_bins.c\
		ft_i_arrow_l_r.c\
		ft_i_arrow_u_d.c\
		ft_i_enter.c\
		ft_init_screen.c\
		ft_input.c\
		ft_prompt_line.c\
		ft_put_letter.c\
		begin.c\
		file_check.c\
		ft_addenv.c\
		ft_bye.c\
		ft_cd.c\
		ft_divide.c\
		ft_echo.c\
		ft_env.c\
		ft_error.c\
		ft_execute.c\
		ft_forward.c\
		ft_get_redir.c\
		ft_prep_for_pipes.c\
		ft_prossesing.c\
		ft_replacment.c\
		ft_search.c\
		ft_setenv.c\
		ft_space_for_redirs.c\
		ft_take_value_env.c\
		ft_unsetenv.c\
		ft_vector_to_arr.c\
		fts_var_env.c\
		main.c\
		ft_i_pgup_pgdown.c\
		ft_gnl_pro.c\
		fts_stream.c\
		ft_advanced_redir.c\
		ft_simple_redir.c\
		ft_diff_redir.c\
		ft_exec.c\
		ft_work_stack.c\
		ft_grab.c\
		ft_ungrab.c\
		ft_heredoc.c\
		ft_ungrab_arr.c\
		ft_change_heredoc.c\
		ft_get_myproc.c\
		prep_vect_for_pipes.c\
		std_operations.c\
		helen_and_friends.c\
		ft_wait.c\
		ft_ctrl_d.c\
		ft_work_equ.c\

SRC := $(addprefix $(SRC_DIR), $(SRC))

OBJ := $(patsubst %.c, %.o, $(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@/bin/rm -f ./libftprintf/libftprintf.a
	@make -C ./libftprintf
	gcc $(FLAGS) -I $(INC) -L$(LIB) -lftprintf -ltermcap $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIB) fclean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo Removed a $(NAME)\!

re: fclean all
