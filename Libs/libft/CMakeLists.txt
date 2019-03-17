cmake_minimum_required(VERSION 3.9)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(NAME libft.a)
project(${NAME} C)
set(LIBFT_INC ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

set(SOURCES
		"ft_atoi.c"
		"ft_bzero.c"
		"ft_strcmp.c"
		"ft_power.c"
		"ft_find_char.c"
		"ft_strcpy.c"
		"ft_strdup.c"
		"ft_strsub.c"
		"ft_strjoin.c"
		"ft_printf/ft_strlen.c"
		"ft_printf/ft_flag_funcs.c"
		"ft_printf/ft_flags.c"
		"ft_printf/ft_int_arr_prefix.c"
		"ft_printf/ft_int_recall_funcs.c"
		"ft_printf/ft_print_memory.c"
		"ft_printf/ft_printf.c"
		"ft_printf/ft_fp_arr_init.c"
		"ft_printf/ft_put_float.c"
		"ft_printf/ft_put_float_nbr_base.c"
		"ft_printf/ft_put_int.c"
		"ft_printf/ft_put_nbr_base.c"
		"ft_printf/ft_put_tab.c"
		"ft_printf/ft_putchar.c"
		"ft_printf/ft_recall.c"
		"ft_printf/ft_scan.c"
		"ft_printf/ft_scan_funcs.c"
		"ft_printf/ft_print_memory_split_condition.c")

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/ft_printf)
add_library(${NAME} ${SOURCES})
