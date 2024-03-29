# LIB

INC_TMP				:= $(INC_DIR)
LIBFT				:= $(LIB_DIR)/ft_libft/libft.a
MINI_LIBX			:= $(LIB_DIR)/minilibx-linux/libmlx_Linux.a
LDFLAG_MINI_LIBX	:= -Llib/minilibx-linux -L/usr/lib -lXext -lX11 -lm -lbsd -lz

ifeq ($(USE_LIBFT),1)
INC_TMP				+= $(LIB_DIR)/ft_libft/inc
LDFLAGS				+= $(LIBFT)
endif
ifeq ($(USE_MINI_LIBX),1)
INC_TMP				+= $(LIB_DIR)/minilibx-linux
LDFLAGS				+= $(MINI_LIBX)
LDFLAGS				+= $(LDFLAG_MINI_LIBX)
endif

INC_DIR				:= $(addprefix -I,$(INC_TMP))
CFLAGS				+= $(INC_DIR)
