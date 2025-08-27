NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I. -Iprintf

SRCDIR = .
UTILDIR = utils
PRINTFDIR = printf

SOURCES = $(SRCDIR)/main.c \
          $(UTILDIR)/cleanup.c \
          $(UTILDIR)/execute_first_cmd.c \
          $(UTILDIR)/execute_second_cmd.c \
          $(UTILDIR)/find_cmd.c \
          $(UTILDIR)/find_path.c \
          $(UTILDIR)/split.c \
          $(UTILDIR)/strjoin.c \
          $(UTILDIR)/free2d.c \
          $(UTILDIR)/initialize_values.c \
          $(UTILDIR)/check_exit_codes.c \
          $(UTILDIR)/close_fd.c \
          $(UTILDIR)/exit_process.c \
          $(PRINTFDIR)/ft_printf.c \
          $(PRINTFDIR)/printf_utils.c \
          $(PRINTFDIR)/strlen.c \
          $(PRINTFDIR)/toupper.c

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

