############################ INICIO #####

NAME	:= icecream

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

SRCS		:= main.c
OBJS		:= main.o

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory

#---------------------------------------#
#	RECIPES								#
#---------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	# $(CC) $(CFLAGS) $(OBJS) $(NAME) 
	# Those two are equivalent
	# -o tells the compiler not to link

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	# $(CC) $(CFLAGS) -c $@ -o $^ 
	# Those two are equivalent

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean all