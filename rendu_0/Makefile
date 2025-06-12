#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stephane <stephane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 12:30:17 by svogrig           #+#    #+#              #
#    Updated: 2024/02/02 19:46:20 by stephane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#------------------------------------------------------------------------------#
# variables                                                                    #
#------------------------------------------------------------------------------#

INCS		:=	include

DIR_SRC		:=	src
DIR_BUILD	:=	.build

# variables libraries ---------------------------------------------------------#

LIBS		:=	ft
LIBFT_DIR	:=	libft
LIBS_TARGET	:=	$(LIBFT_DIR)/libft.a

LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:=	$(addprefix -l,$(LIBS))

INCS		:=	$(INCS) $(LIBFT_DIR)/include

# push swap -------------------------------------------------------------------#

NAME        :=  push_swap

SRCS		:=	lis.c \
				moves.c \
				moves_build.c \
				move_atob.c \
				move_btoa.c \
				operation_push.c \
				operation_reverse_rotate.c \
				operation_rotate.c \
				operation_swap.c \
				parsing.c \
				position_in_list.c\
				list.c \
				stack.c \
				index.c \
				sort.c

PS_SRCS		:=	main.c $(SRCS)
PS_SRCS		:=	$(PS_SRCS:%=$(DIR_SRC)/%)

OBJS		:=	$(PS_SRCS:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)

DEPS		:=	$(OBJS:.o=.d)

# bonus ------------------------------------------------------------------------#

NAME_BONUS	:=	checker

SRCS_BONUS	:=	main_bonus.c
SRCS_BONUS	:=	$(SRCS) $(SRCS_BONUS)
SRCS_BONUS	:=	$(SRCS_BONUS:%=$(SRC_DIR)/%)

OBJS_BONUS	:=	$(SRCS_BONUS:$(SRC_DIR)/%.c=$(DIR_BUILD)/%.o)

DEPS_BONUS	:=	$(OBJS_BONUS:.o=.d)

# compilation -----------------------------------------------------------------#
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP

# other -----------------------------------------------------------------------#
RM          :=	rm -f
MAKEFLAGS   +=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	$(info created: $(NAME))

$(NAME_BONUS): $(OBJS_BONUS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LDLIBS)
	$(info created: $(NAME_BONUS))
	
$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 
	$(info created: $@)

-include $(DEPS) $(DEPS_BONUS)

clean:
	$(MAKE) -C $(dir $(LIBS_TARGET)) clean
	$(RM) $(OBJS) $(DEPS) 
	$(RM) $(OBJS_BONUS) $(DEPS_BONUS)

fclean: clean
	$(MAKE) -C $(dir $(LIBS_TARGET)) fclean
	$(RM) $(NAME) $(NAME_BONUS)

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
