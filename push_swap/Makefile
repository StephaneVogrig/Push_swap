# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 12:30:17 by svogrig           #+#    #+#              #
#    Updated: 2024/01/15 01:45:53 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
# variables libraries                                                          #
#------------------------------------------------------------------------------#

LIBS		:=	ft
LIBFT_DIR	:=	libft
LIBS_TARGET	:=	$(LIBFT_DIR)/libft.a

LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:=	$(addprefix -l,$(LIBS))

#------------------------------------------------------------------------------#
# variables                                                                    #
#------------------------------------------------------------------------------#

NAME        :=  push_swap

INCS		:=	include \
				$(LIBFT_DIR)/include

SRC_DIR		:=	src
SRCS		:=	main.c \
				parsing.c

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP

RM          :=	rm -f
MAKEFLAGS   +=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	$(info created: $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -g -c -o $@ $< 
	$(info created: $@)

-include $(DEPS)

clean:
	$(MAKE) -C $(dir $(LIBS_TARGET)) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(dir $(LIBS_TARGET)) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

run: all
	-./$(NAME)

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: clean fclean re run
.SILENT:
