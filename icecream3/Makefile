############################ INICIO #####

NAME	:= icecream

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		:= 		\
	main.c 			\
	arom/arom.c		\
	base/milk.c		\
	base/water.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDE		:= include

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(INCLUDE)
# -I <include_dir> allows to write the name of the .h file in the include, not the whole path
# Here the .h file is inside the $(INCLUDES) directory

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

RM			:= rm -fr
MAKEFLAGS	+= --no-print-directory
# Hides the report of directory switch in the stdoutput
DIR_DUP		= mkdir -p $(@D)

#---------------------------------------#
#	RECIPES								#
#---------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJ_DIR)
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
.SILENT: