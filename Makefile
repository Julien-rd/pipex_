NAME = Pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -Iprintf

SRCDIR = .
UTILDIR = utils

SOURCES = $(SRCDIR)/main.c \
          $(UTILDIR)/ft_close_fd_free_mem.c \
          $(UTILDIR)/ft_error_message.c \
          $(UTILDIR)/ft_execute_first_cmd.c \
          $(UTILDIR)/ft_execute_second_cmd.c \
          $(UTILDIR)/ft_find_cmd.c \
          $(UTILDIR)/ft_find_path.c \
          $(UTILDIR)/ft_split.c \
          $(UTILDIR)/ft_check_for_error.c \
          $(UTILDIR)/ft_strjoin.c \
          $(UTILDIR)/ft_initialize_values.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test

