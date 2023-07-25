# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/07/25 17:30:45 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
FILES		=	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset \
				ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_toupper ft_tolower ft_strlcat \
				ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi \
				ft_calloc ft_strdup \
				ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
				ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
				ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
				ft_lstclear ft_lstiter ft_lstmap \
				ft_strcmp ft_strndup ft_cntchar ft_free_null ft_isspace ft_swap ft_get_int \
				ft_lcalloc
SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS		=	$(SRCS:.c=.o)

ifdef WITH_DEBUG
CFLAGS = -Wall -g3 -O0
endif

%.o : %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

debug: fclean
	make $(NAME) WITH_DEBUG=1

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: debug all clean fclean re



