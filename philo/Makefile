# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchristo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 20:06:00 by lchristo          #+#    #+#              #
#    Updated: 2021/09/23 18:34:50 by lchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

H		=	philo.h

SRC		=	main\
			philosopher\
			display\
			struct\
			algo\
			forks\
			putstr\
			strlcat\
			atoi\
			itoa\
			chek\
			bzero\
			strlen\
			create\
			mysleep\
			gettime\
			guardian

O		=	$(addprefix src/, $(addsuffix .o, $(SRC)))

C		=	$(addprefix src/, $(addsuffix .c, $(SRC)))

CC		=	cc -Wall -Wextra -Werror

%.o: %.c
	$(CC) $I -c $< -o $@

all:
	@make $(NAME)

$(NAME): $O
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc  -o  $@ $O -o $(NAME)
	@echo -n "\n\033[1;32m$(NAME) generated\n\n"

linux: $O
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -pthread -o $@ $O -o $(NAME)
	@echo -n "\n\033[1;32m$(NAME) generated\n\n"

debug:
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -g3 -o $@ $C -o $(NAME)
	@echo -n "\n\033[1;32m$(NAME) generated\n\n"

sanitize:
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -fsanitize=address -g3 -o $@ $C -o $(NAME)
	@echo -n "\n\033[1;32m$(NAME) generated\n\n"

clean:
	rm -rf $O

fclean:
	rm -rf $(NAME)
	rm -rf $O

re: $O
	@echo -n "\n\033[0;34mCompiling...\n"
	gcc -o $@ $O -o $(NAME)
	@echo -n "\n\033[1;32m$(NAME) regenerated\n\n"
