############################ INICIO #####

NAME	:= icecream

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

SRCS		:= main.c
OBJS		:= main.o
INCLUDE		:= include

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(INCLUDE)
# -I <include_dir> allows to write the name of the .h file in the include, not the whole path
# Here the .h file is inside the $(INCLUDES) directory

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --no-print-directorye

#---------------------------------------#
#	RECIPES								#
#---------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@# $(CC) $(CFLAGS) $(OBJS) $(NAME) 
	@# Those two are equivalent
	@# -o tells the compiler not to link
	$(info CREATED $(NAME))

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@# $(CC) $(CFLAGS) -c $@ -o $^ 
	@# Those two are equivalent
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(info DELETED $(OBJS))

fclean: clean
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean all