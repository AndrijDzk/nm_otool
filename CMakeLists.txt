cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC Includes)

set(NAME1 ft_nm)
project(${NAME1} C)

set(NAME2 ft_otool)
project(${NAME2} C)

set(LIBFT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/libft)
set(LIBFT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/libft/CMakeFiles)

set(SDIR Srcs)

set(SOURCES1
	"get_nm_dispatch_functions.c"
	"set_g_arch.c"
	"print_filename.c"
	"handle_fat.c"
	"handle_fat_64.c"
	"handle_ar.c"
	"handle.c"
	"handle_64.c"
	"get_symtable.c"
	"get_symtable_64.c"
	"select_better_symbol.c"
	"select_better_symbol_64.c"
	"find_in_symtable.c"
	"find_in_symtable_64.c"
	"sort_symtable.c"
	"sort_symtable_64.c"
	"get_section.c"
	"get_section_64.c"
	"errors.c"
	"main.c")
PREPEND(SOURCES_REL1 ${NAME1} ${SOURCES1})
PREPEND(SOURCES_REL1 ${SDIR} ${SOURCES_REL1})

set(SOURCES2
	"set_g_arch.c"
	"handle_fat.c"
	"handle_fat_64.c"
	"handle_ar.c"
	"handle.c"
	"handle_64.c"
	"errors.c"
	"main.c")
PREPEND(SOURCES_REL2 ${NAME2} ${SOURCES2})
PREPEND(SOURCES_REL2 ${SDIR} ${SOURCES_REL2})

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

add_executable(${NAME1} ${SOURCES_REL1})
target_include_directories(${NAME1} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC}/${NAME1})

add_executable(${NAME2} ${SOURCES_REL2})
target_include_directories(${NAME2} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC}/${NAME2})

add_subdirectory(${LIBFT_SOURCE_DIR} ${LIBFT_BINARY_DIR})

target_link_libraries(${NAME1} libft.a)
include_directories(${LIBFT_INC})

target_link_libraries(${NAME2} libft.a)
include_directories(${LIBFT_INC})