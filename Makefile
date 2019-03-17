NAME1 = ft_nm
NAME2 = ft_otool

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = Includes

SDIR = Srcs

SRCS1 = get_nm_dispatch_functions.c\
		set_g_arch.c\
		print_filename.c\
		handle_ar.c\
		handle_fat.c\
		handle_fat_64.c\
		handle.c\
		handle_64.c\
		get_symtable.c\
		get_symtable_64.c\
		select_better_symbol.c\
		select_better_symbol_64.c\
		find_in_symtable.c\
		find_in_symtable_64.c\
		sort_symtable.c\
		sort_symtable_64.c\
		get_section.c\
		get_section_64.c\
		errors.c\
		main.c

SRCS2 = set_g_arch.c\
		handle_fat.c\
		handle_fat_64.c\
		handle_ar.c\
		handle.c\
		handle_64.c\
		errors.c\
		main.c

HEADERS1 = ft_nm.h

HEADERS2 = ft_otool.h

ODIR = Objects

OBJ1 = $(SRCS1:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(ODIR)/$(NAME1)/ $(OBJ1:%.o=$(ODIR)/$(NAME1)/%.o)
	make -C Libs/libft
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1:%.o=$(ODIR)/$(NAME1)/%.o) Libs/libft/libft.a

$(NAME2) : $(ODIR)/$(NAME2)/ $(OBJ2:%.o=$(ODIR)/$(NAME2)/%.o)
	make -C Libs/libft
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2:%.o=$(ODIR)/$(NAME2)/%.o) Libs/libft/libft.a

.PHONY: clean1 fclean1 dfclean1 re1 clean fclean re

clean1 :
	rm -f $(OBJ1:%.o=$(ODIR)/$(NAME1)/%.o)

fclean1 : clean1
	rm -f $(NAME1)

re1 : fclean1 $(NAME1)

clean2 :
	rm -f $(OBJ2:%.o=$(ODIR)/$(NAME2)/%.o)

fclean2 : clean2
	rm -f $(NAME2)

re2 : fclean2 $(NAME2)

clean: clean1 clean 2

fclean : fclean1 fclean2
	make fclean -C Libs/libft

re : re1 re2

norm:
	make norm -C Libs/libft
	norminette $(SRCS1:%.c=$(SDIR)/$(NAME1)/%.c) $(HEADERS1:%.h=$(INC)/$(NAME1)/%.h)\
				$(SRCS2:%.c=$(SDIR)/$(NAME2)/%.c) $(HEADERS2:%.h=$(INC)/$(NAME2)/%.h)

add:
	make add -C Libs/libft
	git add $(SRCS1:%.c=$(SDIR)/$(NAME1)/%.c) $(HEADERS1:%.h=$(INC)/$(NAME1)/%.h)\
				$(SRCS2:%.c=$(SDIR)/$(NAME2)/%.c) $(HEADERS2:%.h=$(INC)/$(NAME2)/%.h)\
				.gitignore Makefile CMakeLists.txt author

test1: $(NAME1)
	./$(NAME1) $(NAME1)

$(ODIR)/$(NAME1)/ :
	mkdir -p $@

$(ODIR)/$(NAME2)/ :
	mkdir -p $@

$(ODIR)/$(NAME1)/%.o : $(SDIR)/$(NAME1)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I Libs/libft -I Includes/$(NAME1)

$(ODIR)/$(NAME2)/%.o : $(SDIR)/$(NAME2)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I Libs/libft -I Includes/$(NAME2)
