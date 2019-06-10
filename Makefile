NAME := 21sh

INC := ./include

LIB := ./libftprintf

FLAGS := -Wall -Wector -Werror

VPATH := ./source

SRC :=	begin.c\
		file_check.c\
		ft_bye.c\
		ft_cd.c\
		ft_divide.c\
		ft_echo.c\
		ft_env.c\
		ft_error.c\
		ft_execute.c\
		ft_list_bins.c\
		ft_prossesing.c\
		ft_replacment.c\
		ft_take_value_env.c\
		ft_search.c\
		ft_setenv.c\
		ft_unsetenv.c\
		fts_var_env.c\
		main.c\
		ft_addenv.c\
		ft_input.c\
		ft_init_screen.c\
		ft_get_mygv.c\
		ft_clear_mygv.c\
		ft_put_letter.c\

SRC := $(addprefix ./source/, $(SRC))

OBJ := $(patsubst %.c, %.o, $(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@/bin/rm -f ./libftprintf/libftprintf.a
	@make -C ./libftprintf
	gcc $(FLAGS) -I $(INC) -L$(LIB) -lftprintf  -lreadline -ltermcap $(OBJ) -o $(NAME)

%.o: %.c
	gcc -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIB) fclean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo Removed a $(NAME)\!

re: fclean all

