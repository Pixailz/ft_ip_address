# include
include mk/config.mk			# base config
include mk/utils.mk				# utils function / var
include mk/lib.mk				# load lib if needed
include mk/srcs.mk				# srcs.mk
include mk/pb.mk				# ui thing, progress bar etc

$(call PB_INIT)

# rule
## config
.SILENT:

.PHONY: setup

.DEFAULT: all

all:			setup $(TARGET)

bonus:			setup $(TARGET)

### TARGETS
$(TARGET):		$(LIBFT) $(MINI_LIBX) $(OBJ_C)
> $(call P_INF,Creating $(R)$(TARGET)$(RST))
> printf "\n\n"
> $(call PB_PRINT_ELAPSED)
> $(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJ_C) $(LDFLAGS)
> $(call PB_TARGET_DONE)

## objs
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
# $(<)		: dependencies
# $(@)		: full target
# $(@D)		: dir target
$(OBJ_C):		$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
> $(call PB_PRINT,$(@))
> gcc $(CFLAGS) -o $@ -c $<

### LIBS
$(LIBFT):
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft all
endif

$(MINI_LIBX):
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux all
endif

setup:	corrector $(BIN_DIR) print_logo print_debug

$(BIN_DIR):
> $(call MKDIR,$(BIN_DIR))

print_debug:
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
> $(call P_INF,RUNTIME INFOS)
> $(call P_WAR,DEBUG: $(DEBUG))
> $(call P_WAR,CFLAGS:)
> printf "\n"
> printf "\t\t%s\n" $(CFLAGS)
> $(call P_WAR,LDFLAGS:)
> printf "\n"
> printf "\t\t%s\n" $(LDFLAGS)
> $(call P_WAR,.SHELLFLAGS:)
> printf "\n"
> printf "\t\t%s\n"  $(.SHELLFLAGS)
> $(call P_WAR,OBJ_C:)
> printf "\n"
> printf "\t\t%s\n"  $(OBJ_C)
> $(call P_WAR,SRC_C:)
> printf "\n"
> printf "\t\t%s\n"  $(SRC_C)
endif

print_logo:
ifeq ($(LOGO_PRINTED),)
> printf "%b\n" "$(ASCII_COLOR)$$ASCII_BANNER$(RST)"
> $(eval export LOGO_PRINTED=1)
endif

### CORRECTOR
corrector:				export_vars
> ./rsc/corrector/run

export_vars:
export MK_DIR
export SRC_DIR

### RUN
run:					re
> ./$(TARGET) $(ARGS)

### CLEAN
clean:
> $(call P_FAI,Removing obj)
> rm -rf $(OBJ_DIR)

clean_all:				clean
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft clean
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux clean
endif

fclean:							clean
ifeq ($(BONUS),1)
> $(call P_FAI,Removing $(TARGET))
> rm -rf $(TARGET)
else
> $(call P_FAI,Removing $(TARGET_BONUS))
> rm -rf $(TARGET_BONUS)
endif

fclean_all:				fclean
ifeq ($(USE_LIBFT),1)
> make -C lib/ft_libft fclean
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C lib/minilibx-linux clean
endif

### RE
re:						setup fclean $(TARGET)

re_all:					re_lib re

re_lib:
ifeq ($(USE_LIBFT),1)
> make -C ./lib/ft_libft re
endif
ifeq ($(USE_MINI_LIBX),1)
> make -C ./lib/minilibx-linux re
endif

### install binary (need sudo)
install:				re
> sudo cp $(TARGET) /usr/bin/
