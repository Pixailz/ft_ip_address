# SRCS
SRC_C_MANDATORY := debug/debug_entry.c \
				   debug/init.c \
				   init/entry.c \
				   main.c \
				   parsing/entry.c \
				   parsing/error.c \
				   utils/ft_utoa_base_padded.c \
				   utils/print/binary_ip.c \
				   utils/print/ip.c

SRC_DIR_F			:= $(SRC_DIR)

ifeq ($(BONUS),1)
# SRC_DIR_F			:= $(SRC_DIR)/bonus
TARGET				:= $(TARGET_BONUS)
else
# SRC_DIR_F			:= $(SRC_DIR)/mandatory
endif

# OBJ
ifeq ($(BONUS),1)
SRC_C				:= $(addprefix $(SRC_DIR_F)/,$(SRC_C_BONUS))
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
else
SRC_C				:= $(addprefix $(SRC_DIR_F)/,$(SRC_C_MANDATORY))
OBJ_C				:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_C:%.c=%.o))
endif

OBJ_C_NB			:= $(words $(OBJ_C))
OBJ_C_NB_LEN		:= $(shell printf "$(OBJ_C_NB)" | wc -c)
