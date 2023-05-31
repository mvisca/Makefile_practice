############################ INICIO #####

NAME	:= icecream

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

LIBS		:= arom base
# LIBS		:= arom base m
# The commented lind adds to the libraries list the m lib from math.h
# This show how to include outer libraries in your project

LIBS_TARGET	:= 				\
	lib/libarom/libarom.a	\
	lib/libbase/libbase.a

INCS		:= include	\
	lib/libarom/include \
	lib/libbase/include

SRC_DIR		:= src
SRCS		:= main.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

LIBS_DIR	:= $(dir $(LIBS_TARGET))
BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))
# Build with a library requires three flags
# -I where to find the lib headers
# -L where to finde the library
# -l the name of the library

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

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info CREATED $@)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)
	$(info CALL TO CREATE $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)
	$(info DELETED $(OBJS) $(DEPS) $(BUILD_DIR))

fclean: clean
	$(RM) $(NAME)
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(info DELETED $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean all