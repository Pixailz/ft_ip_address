# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 01:36:34 by brda-sil          #+#    #+#              #
#    Updated: 2022/08/18 19:43:18 by brda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# config
CFLAGS			:= -Wall -Wextra
TARGET			:= ft_ip_address
RM				:= rm -rf
CC				:= gcc
MAKE			:= make -C
VERSION			:= 0.0.0
$(eval export MAIN=1)

ifneq ($(PADDING),30)
PADDING			:= 30
endif

ifeq ($(DEBUG),)
CFLAGS			+= -Werror
else
CFLAGS			+= -g3
endif

# DIR
SRC_DIR			:= src
LIB_DIR			:= lib
OBJ_DIR			:= obj
OBJ_SUBDIR		:= $(sort $(shell find $(SRC_DIR) -type d | \
											sed 's|$(SRC_DIR)|$(OBJ_DIR)|g'))
INC_TMP			:= inc \
				   $(LIB_DIR)/ft_libft/include
INC_DIR			:= $(addprefix -I,$(INC_TMP))

# LIB
LIBFT			:= $(LIB_DIR)/ft_libft/libft.a

# SRC
SRC_C			:= src/ft_ip_address.c \
				   src/parse/parse_ip.c \
				   src/utils/error.c
# OBJ
OBJ_C			:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))

# LIB DIR
CFLAGS			+= $(INC_DIR)
LIBS			:= $(LIBFT)

#  Bash Color / unicode char

#get_random		= $(shell seq 0 256 | shuf | head -n1)
green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

font_color		:= $(blue)
bold			:= $(red)
ascii_color		:= $(bold)

green_plus		:= $(font_color)[$(green)+$(font_color)]
red_minus		:= $(font_color)[$(red)-$(font_color)]
orange_star		:= $(font_color)[$(orange)*$(font_color)]
blinking_arrow	:= $(blinking)$(font_color)->
#font_color		:= \033[38;5;$(get_random)m
#bold			:= \033[38;5;$(get_random)m
#ascii_color		:= \033[38;5;$(get_random)m

UL="\xe2\x95\x94"
HO="\xe2\x95\x90"
UR="\xe2\x95\x97"
VE="\xe2\x95\x91"
LL="\xe2\x95\x9a"
LR="\xe2\x95\x9d"

# **************************************************************************** #

# **************************************************************************** #
# utils

define ascii_art
 ██▓ ██▓███      ▄▄▄      ▓█████▄ ▓█████▄  ██▀███  ▓█████   ██████   ██████
▓██▒▓██░  ██▒   ▒████▄    ▒██▀ ██▌▒██▀ ██▌▓██ ▒ ██▒▓█   ▀ ▒██    ▒ ▒██    ▒
▒██▒▓██░ ██▓▒   ▒██  ▀█▄  ░██   █▌░██   █▌▓██ ░▄█ ▒▒███   ░ ▓██▄   ░ ▓██▄
░██░▒██▄█▓▒ ▒   ░██▄▄▄▄██ ░▓█▄   ▌░▓█▄   ▌▒██▀▀█▄  ▒▓█  ▄   ▒   ██▒  ▒   ██▒
░██░▒██▒ ░  ░    ▓█   ▓██▒░▒████▓ ░▒████▓ ░██▓ ▒██▒░▒████▒▒██████▒▒▒██████▒▒
░▓  ▒▓▒░ ░  ░    ▒▒   ▓▒█░ ▒▒▓  ▒  ▒▒▓  ▒ ░ ▒▓ ░▒▓░░░ ▒░ ░▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░
 ▒ ░░▒ ░          ▒   ▒▒ ░ ░ ▒  ▒  ░ ▒  ▒   ░▒ ░ ▒░ ░ ░  ░░ ░▒  ░ ░░ ░▒  ░ ░
 ▒ ░░░            ░   ▒    ░ ░  ░  ░ ░  ░   ░░   ░    ░   ░  ░  ░  ░  ░  ░
 ░                    ░  ░   ░       ░       ░        ░  ░      ░        ░
                           ░       ░
$(reset)
endef
export ascii_art

define print_padded
	@printf '   $(orange_star) $(font_color)Creation of $(bold)$1'
	$(eval OBJ_LEN := $(shell printf $1 | wc -c))
	$(eval PAD_LEN := $(shell expr $(PADDING) - $(OBJ_LEN)))
	@printf '%-$(PAD_LEN)s' ' '
	@printf '$(blinking_arrow) $(reset)$(bold)$2 $(reset)'
	@printf '\n'
endef

define usage
$(orange_star) $(bold)$(TARGET)$(font_color): $(bold)needed_args \
$(font_color)[$(bold)optional_args$(font_color)]$(reset)
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation
        $(bold)arg$(font_color): eplanation, $(bold)WARNING$(reset)
$(font_color)Version: $(bold)$(VERSION)$(reset)

endef
export usage

define make_dir
	@if [ ! -d $1 ]; then														\
		mkdir $1;																\
		printf "$(green_plus) $(font_color)Create dir $(bold)$1$(reset)\n";		\
	fi
endef
# **************************************************************************** #

# **************************************************************************** #
# Rules

all:			setup $(TARGET)
	@printf "$$usage"

$(TARGET):				$(LIBFT) $(OBJ_C)
	@printf "$(green_plus) $(font_color)Creation of $(bold)$@$(reset)\n"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(LIBS)

$(OBJ_DIR)/%.o: 		$(SRC_DIR)/%.c
	$(call print_padded,$^,$@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@$(MAKE) lib/ft_libft multiple string print

setup:					call_logo $(OBJ_SUBDIR)

call_logo:
	@printf "$(ascii_color)$$ascii_art"

$(OBJ_SUBDIR):
	$(foreach dir,$@,$(call make_dir,$(dir)))

clean_all:				clean
	@$(MAKE) lib/ft_libft clean

clean:
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(OBJ_DIR)$(reset)\n"
	@$(RM) $(OBJ_DIR)

fclean_all:				fclean
	@$(MAKE) lib/ft_libft fclean

fclean:					clean
	@printf "$(red_minus) $(font_color)Deleting $(bold)$(TARGET)$(reset)\n"
	@$(RM) $(TARGET)

re_lib:
	@$(MAKE) lib/ft_libft re multiple string print

re:						fclean all

re_all:					re_lib re

.PHONY:					all clean fclean re setup lib call_logo

# **************************************************************************** #
