NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_strcmp.c\
		ft_power.c\
		ft_find_char.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_printf/ft_strlen.c\
		ft_printf/ft_flag_funcs.c\
		ft_printf/ft_flags.c\
		ft_printf/ft_int_arr_prefix.c\
		ft_printf/ft_int_recall_funcs.c\
		ft_printf/ft_print_memory.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_fp_arr_init.c\
		ft_printf/ft_put_float.c\
		ft_printf/ft_put_float_nbr_base.c\
		ft_printf/ft_put_int.c\
		ft_printf/ft_put_nbr_base.c\
		ft_printf/ft_put_tab.c\
		ft_printf/ft_putchar.c\
		ft_printf/ft_recall.c\
		ft_printf/ft_scan.c\
		ft_printf/ft_scan_funcs.c\
		ft_printf/ft_print_memory_split_condition.c

OBJ = $(SRCS:.c=.o)

HEADERS = ft_printf/libconvfuncs.h\
		ft_printf/libflagfuncs.h\
		ft_printf/libprintf.h\
		ft_printf/librecall.h\
		ft_printf/flags.h\
		libft.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

debug :
	gcc -g -c $(SRCS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

dclean :
	rm -f *.o

all_to_dst: $(OBJ)
	ar rc $(DST) $(OBJ)

re : fclean all

norm:
	norminette $(SRCS) $(HEADERS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

add:
	git add $(SRCS) $(HEADERS) Makefile CMakeLists.txt
