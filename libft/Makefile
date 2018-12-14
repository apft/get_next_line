# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apion <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:44:52 by apion             #+#    #+#              #
#    Updated: 2018/12/14 19:04:44 by apion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/sh
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I. -I$(H_DIR)
CPPFLAGS	=
AR			= ar
RANLIB		= ranlib
RM			= /bin/rm -f
SUFFIXES	= .c .o .d

LIB			:= ft
ARCHIVE		:= lib$(LIB).a
NAME		:= $(ARCHIVE)
C_DIR		:= srcs/
H_DIR		:= includes/
D_DIR		:= .dep/
O_DIR		:= .obj/
H_FILES		:= libft.h
C_FILES		:= ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_islowc.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_isuppc.c \
				ft_itoa.c \
				ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_print_mem.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_base.c \
				ft_putnbr_fd.c \
				ft_putnbr_hex.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_stricmp.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnicmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_swap.c \
				ft_tolower.c \
				ft_toupper.c
C_FILES		:= $(addprefix $(C_DIR), $(C_FILES))
D_FILES		:= $(C_FILES:%.c=%.d)
O_FILES		:= $(C_FILES:%.c=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(addprefix $(O_DIR),$(O_FILES))
	$(AR) rc $@ $?
	$(RANLIB) $@

%.o: %.c
$(O_DIR)%.o: %.c $(D_DIR)%.d | $(D_DIR) $(O_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(D_DIR)$*.d -o $@ -c $<

$(D_DIR)%.d: ;
.PRECIOUS: $(D_DIR)%.d

$(D_DIR):
	mkdir $@/$(C_DIR)

$(O_DIR):
	mkdir $@/$(C_DIR)

.PHONY: clean fclean
clean:
	$(RM) $(addprefix $(O_DIR),$(O_FILES))
	$(RM) $(addprefix $(D_DIR),$(D_FILES))
	rmdir $(O_DIR) 2> /dev/null || true
	rmdir $(D_DIR) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

include $(wildcard $(D_DIR)*.d)
