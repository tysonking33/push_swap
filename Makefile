NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LINKS = -I./includes -L./ft_printf/includes

SRCS_DIR = sources/

FILES = main \
		input_check \
		utils1 \
		initialise \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS_DIR = sources/

OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(MAKE) re -C ./ft_printf
	$(CC) $(FLAGS) $(OBJS) ./ft_printf/libftprintf.a ./ft_printf/libft/libft.a -o $(NAME) 

clean:
	rm -f $(OBJS)
	$(RM) $(OBJS)
	@$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(RM) $(NAME)
	@$(MAKE) -C ./ft_printf fclean


re: clean all

.PHONY: all clean fclean re
