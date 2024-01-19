# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 12:30:17 by svogrig           #+#    #+#              #
#    Updated: 2024/01/19 15:10:18 by svogrig          ###   ########.fr        #
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

SRCS		:=	i32list.c \
				operation_push.c \
				operation_reverse_rotate.c \
				operation_rotate.c \
				operation_swap.c \
				parsing.c \
				stack.c

PS_SRCS		:=	main.c $(SRCS)
PS_SRCS		:=	$(PS_SRCS:%=$(SRC_DIR)/%)

UT_NAME		:=	$(NAME)_unitest
UT_SRCS_DIR	:= 	unitest

UT_SRCS		:=	main.c \
				arg_to_stack_tests.c \
				i32list_new_tests.c \
				number_to_stack_tests.c \
				si32_to_decstr_offset_tests.c \
				i32list_to_str_tests.c \
				swap_head_tests.c \
				rotate_tests.c

UT_SRCS		:=	$(UT_SRCS:%=$(UT_SRCS_DIR)/%)
UT_SRCS		:=	$(SRCS) $(UT_SRCS) 
UT_SRCS		:=	$(UT_SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(PS_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
UT_OBJS		:=	$(UT_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)
UT_DEPS		:=	$(UT_OBJS:.o=.d)

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

unitest: $(UT_NAME)

$(UT_NAME): $(UT_OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) -o $(UT_NAME) $(UT_OBJS) $(LDLIBS)
	$(info created: $(UT_NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -g -c -o $@ $< 
	$(info created: $@)

-include $(DEPS) $(UT_DEPS)


clean:
	$(MAKE) -C $(dir $(LIBS_TARGET)) clean
	$(RM) $(OBJS) $(DEPS) 
	$(RM) $(UT_OBJS) $(UT_DEPS)

fclean: clean
	$(MAKE) -C $(dir $(LIBS_TARGET)) fclean
	$(RM) $(NAME) $(UT_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

run: all
	-./$(NAME)

run_unitest: unitest
	-./$(UT_NAME)

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: clean fclean re run
.SILENT: