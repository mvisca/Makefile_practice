############################ INICIO #####

NAME	:= libarom.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

SRC_DIR		:= src
BUILD_DIR	:= .build
INCLUDE		:= include

SRCS		:= 		\
	cherry.c		\
	coco.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I $(INCLUDE)
# -I <include_dir> allows to write the name of the .h file in the include, not the whole path
# Here the .h file is inside the $(INCLUDES) directory
# -MMD The compiler automatically generates a list of dependencies
# -MP Prevents erros if a header file is rm/mv
AR			:= ar
ARFLAGS		:= -r -c -s

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
	@$(AR) $(ARFLAGS) $@ $^
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)
-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
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