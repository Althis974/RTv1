# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/14 14:34:00 by rlossy       #+#   ##    ##    #+#        #
#   Updated: 2018/04/17 16:18:54 by rlossy      ###    #+. /#+    ###.fr     # #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	rtv1
LIB_DIR		=	./libft
LIBX_DIR	=	./minilibx_macos
HEADER		=	./includes/
FILENAMES	=	main.c
#FILENAMES	+=

SOURCES		=	$(addprefix srcs/, $(FILENAMES))
OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o)) 

L_FT		=	$(LIB_DIR)
LIB_LNK		=	-L $(L_FT) -l ft
LIB_INC		=	-I $(L_FT)/libft.h


LX_FT		=	$(LIBX_DIR)
LIBX_LNK	=	-L $(LX_FT) -l mlx
LIBX_INC	=	-I $(LX_FT)/mlx.h

FLAGS		=	-Wall -Wextra -Werror -O2
FLAGX		=	-framework OpenGL -framework AppKit

LOADIR		=	/Users/rlossy/unitest/load
LOADF		=	$(LOADIR)/loading.sh

.PHONY: all clean fclean re


all: $(NAME)

clean:
	@echo "\033[31m"
	@sh $(LOADF) $@ r n $(NAME)
	@rm -rf build/
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $(NAME)⭃\tObject Files\t\033[0m\
	\033[1m⟿ \t\033[31mDeletion Success\033[0m ✅\n"
	@$(MAKE) -C $(L_FT) clean
	@$(MAKE) -C $(LX_FT) clean

fclean: clean
	@echo "\033[31m"
	@sh $(LOADF) $@ r n $(NAME)
	@rm -f $(NAME)
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $(NAME)⭃\tCompiled Files\t\033[0m\
	\033[1m⟿ \t\033[31mDeletion Success\033[0m ✅\n"
	@$(MAKE) -C $(L_FT) fclean
	@$(MAKE) -C $(LX_FT) fclean

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

build: 
	@echo "\033[35m"
	@mkdir build/

$(NAME): $(OBJECTS)
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $@⭃\tObject Files\033[0m \
		\033[1m⟿ \t\033[32mCreation Success\033[0m ✅\n"
	@$(MAKE) -C $(L_FT)
	@$(MAKE) -C $(LX_FT)
	@echo "\033[42m\033[30m"
	@sh $(LOADF) $@ e n $(NAME)
	@echo "\033[0m"
	@gcc $(FLAGS) -I $(HEADER) $(OBJECTS) $(LIB_LNK) $(LIBX_LNK) $(FLAGX) -o $@
	@printf "\n\033[1m\033[34m\t\t\t\t⥷ $@⭃\tProject\t\t\033[0m \033[1m⟿  \
		\033[32mCreation Success\033[0m ✅\n"

build/%.o: srcs/%.c $(HEADER) | build
	@sh $(LOADF) $< o y
	@gcc $(FLAGS) $(LIB_INC) -I $(HEADER) -c $< -o $@