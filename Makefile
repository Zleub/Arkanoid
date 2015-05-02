# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/02 03:26:29 by adebray           #+#    #+#              #
#    Updated: 2015/05/02 05:44:34 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	arkanoid
HEADDIR			=	inc
HEADFLAG		=	-I ./$(HEADDIR) -Iglfw/include

SRCDIR			=	src
SRC				=	$(addprefix src/, $(shell ls -1 src | grep "\.c"))
SRC				+=	main.c

OBJ				=	$(subst .c,.o,$(SRC))

CC				=	clang
CCFLAGS			=	-Werror -Wall -Wextra -Wuninitialized -O3

# LIBNCURSES		=	-lncurses

GLFW3			=	-Lglfw/src -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLFW3			+=	-Lsrc/ft_printf -lftprintf

.PHONY: all clean fclean re $(NAME)

_depend:
	@(\
		cd glfw ;\
		git submodule init ;\
		git submodule update ;\
		cmake . ;\
		make ;\
	)

all: _depend $(NAME)

$(NAME): makelib $(OBJ)
	@$(CC) $(CCFLAGS) $(HEADFLAG) $(GLFW3) -o $(NAME) $(OBJ)
	@echo '!'
	@echo "\033[32m•\033[0m $(NAME) compil: \033[32m$(NAME)\033[0m"

makelib: _libft _printf

_libft: $(HEADDIR)/libft.h
	@make -C $(SRCDIR)/libft

_printf: $(HEADDIR)/ft_printf.h
	@make -C $(SRCDIR)/ft_printf

%.o: %.c
	@echo '.''\c'
	@$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	@make -C $(SRCDIR)/libft clean
	@make -C $(SRCDIR)/ft_printf clean
	@rm -f $(OBJ)
	@echo "\033[31m•\033[0m $(NAME) clean.\033[0m"

fclean:
	@make -C $(SRCDIR)/libft fclean
	@make -C $(SRCDIR)/ft_printf fclean
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f asm
	@echo "\033[31m•\033[0m $(NAME) fclean: \033[31m$(NAME)\033[0m"

re: fclean all
