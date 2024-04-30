# Makefile for your project

# Compiler and flags
CC := cc
CFLAGS := -g -Wall -Werror -Wextra
LIB_DIR := libft/
LIBS := $(LIB_DIR)libft.a
INCLUDES := -I$(LIB_DIR) -I.

# Source files
SRCS = operators/pa.c operators/pb.c operators/ra.c \
operators/rb.c operators/rr.c operators/rra.c operators/rrb.c \
operators/rrr.c operators/sa.c operators/sb.c operators/ss.c \
push_swap.c ft_listf.c ft_listf2.c make_list_a.c \
ft_algorithm_2.c ft_algorithm_3.c ft_algorithm_4.c \
ft_algorithm_5.c make_list_a_2.c ft_algorithm_6_plus.c \
ft_algorithm_6_plus_copy.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

$(LIBS):
	make -C $(LIB_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
