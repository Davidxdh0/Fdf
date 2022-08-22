# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dyeboa <dyeboa@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/26 14:06:32 by dyeboa        #+#    #+#                  #
#    Updated: 2022/08/22 17:22:10 by dyeboa        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= 	fdf
CC 			= 	gcc

CFLAGS 		= 	-Wall -Wextra -Werror -Imlx -g
VPATH 		= 	src

SRC_FILES 	=	main.c \
				parse_utils.c \
				fill.c \
				mlx.c \
				draw.c \
				exit.c

# object files
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# Libft
LIBFT = libft.a

# Default build
all: $(OBJ_DIR) $(LIBFT) $(NAME)

# obj dir
${OBJ_DIR}	:
				mkdir -p ${OBJ_DIR}

# Libft
$(LIBFT)	:
				make -C libft
# Build 
${NAME}		: 	${OBJ_FILES} 
				$(CC) $(CFLAGS) $^ libft/$(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -o $@	
				
$(OBJ_FILES): 	$(OBJ_DIR)/%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -rf ${OBJ_DIR}
				make fclean -C libft/

fclean		:	clean
				rm -rf ${NAME}
				rm -rf gnl

re 			: 	fclean all

.PHONY 		: 	clean fclean all 