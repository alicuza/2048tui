NAME = nctest

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LDLIBS = -lncurses

SRCS = main.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean:
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re
-include $(DEPS)
