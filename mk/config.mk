# BASE
TARGET				:= ip_address
# TARGET_BONUS		:= prog_bonus
CC					:= gcc
CFLAGS				:= -Wall -Wextra
VERSION				:= 1.2.0

## SOME DIRS
BIN_DIR				:= .
SRC_DIR				:= src
LIB_DIR				:= lib
OBJ_DIR				:= obj
INC_DIR				:= inc
MK_DIR				:= mk

## LIB CONFIG
USE_LIBFT			:= 1
USE_MINI_LIBX		:= 0

# SPECIFY MAKEFILE FLAGS
# MAKEFLAGS			:= --jobs=$(shell nproc)	# number of jobs (not working with re)
# MAKEFLAGS			+= --output-sync=target		# sync output, avoid intermixed result
MAKEFLAGS			:= --no-print-directory

# BASH
SHELL				:= /usr/bin/bash			# set bash path
.SHELLFLAGS			:= -eu -o pipefail -c		# set bash strict mode

# Always use GNU Make.
ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
endif
## Use '>' to instead of tab.
.RECIPEPREFIX		= >

## DEBUG

ifeq ($(shell [ -z $(DEBUG) ] && printf 1 || printf 0),1)
DEBUG				:= 0
endif

ifeq ($(DEBUG),0)
CFLAGS				+= -Werror
else
ifeq ($(shell [ $(DEBUG) -ge 1 ] && printf 1 || printf 0),1)
CFLAGS				+= -g3
endif
ifeq ($(shell [ $(DEBUG) -ge 2 ] && printf 1 || printf 0),1)
.SHELLFLAGS			+= -x
endif
endif

## PARSE_VARIABLE
### BONUS
ifeq ($(findstring bonus,$(MAKECMDGOALS)),bonus)
BONUS				:= 1
else
ifeq ($(findstring re_bonus,$(MAKECMDGOALS)),re_bonus)
BONUS				:= 1
else
ifeq ($(findstring run_bonus,$(MAKECMDGOALS)),run_bonus)
BONUS				:= 1
else
BONUS				:= 0
endif
endif
endif
