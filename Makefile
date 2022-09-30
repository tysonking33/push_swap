NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
RM = rm -f
LINKS = -I./includes  -framework openGL \
		-framework Appkit

SRCS_DIR = sources/

FILES = push \
		main \
		rotate \
		utils \
		swap \
		three_sort \
		large_sort \
		check_sorted \

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LINKS)

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean
