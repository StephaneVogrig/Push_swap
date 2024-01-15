# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 02:59:52 by svogrig           #+#    #+#              #
#    Updated: 2024/01/15 00:59:16 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
# variables                                                                    #
#------------------------------------------------------------------------------#

NAME = libft.a

INCS		:=	include

SRC_DIR		:=	src
SRCS 		:=	char/ft_isalnum.c\
				char/ft_isalpha.c\
				char/ft_isascii.c\
				char/ft_isdigit.c\
				char/ft_isprint.c\
				char/ft_toupper.c \
				char/ft_tolower.c \
				ft_atoi.c \
				ft_itoa.c \
				lst/ft_lstadd_back.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstclear.c \
				lst/ft_lstdelone.c \
				lst/ft_lstiter.c \
				lst/ft_lstlast.c \
				lst/ft_lstmap.c \
				lst/ft_lstnew.c \
				lst/ft_lstsize.c \
				mem/ft_bzero.c \
				mem/ft_calloc.c \
				mem/ft_memchr.c \
				mem/ft_memcmp.c \
				mem/ft_memcpy.c \
				mem/ft_memmove.c \
				mem/ft_memset.c \
				put/ft_putchar_fd.c \
				put/ft_putendl_fd.c \
				put/ft_putnbr_fd.c \
				put/ft_putstr_fd.c \
				str/ft_split.c \
				str/ft_strchr.c \
				str/ft_strdup.c \
				str/ft_striteri.c \
				str/ft_strjoin.c \
				str/ft_strlcat.c \
				str/ft_strlcpy.c \
				str/ft_strlen.c	\
				str/ft_strmapi.c \
				str/ft_strncmp.c \
				str/ft_strnstr.c \
				str/ft_strrchr.c \
				str/ft_strtrim.c \
				str/ft_substr.c

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= 	.build
OBJS 		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:= 	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP

AR			:=	ar
ARFLAGS		:=	-r -c -s

RM			:=	rm -f
MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info created: $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info created: $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	
fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) so

.PHONY: clean fclean re so bonus
.SILENT:
