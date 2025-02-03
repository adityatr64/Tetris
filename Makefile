#**************************************************************************************************
#
#   raylib makefile for Desktop platforms, Raspberry Pi, Android and HTML5
#
#   Copyright (c) 2013-2019 Ramon Santamaria (@raysan5)
#
#   This software is provided "as-is", without any express or implied warranty. In no event
#   will the authors be held liable for any damages arising from the use of this software.
#
#   Permission is granted to anyone to use this software for any purpose, including commercial
#   applications, and to alter it and redistribute it freely, subject to the following restrictions:
#
#     1. The origin of this software must not be misrepresented; you must not claim that you
#     wrote the original software. If you use this software in a product, an acknowledgment
#     in the product documentation would be appreciated but is not required.
#
#     2. Altered source versions must be plainly marked as such, and must not be misrepresented
#     as being the original software.
#
#     3. This notice may not be removed or altered from any source distribution.
#
#**************************************************************************************************

# This has been edited by wiz to suit his needs and would not recommend using this as a template for your own projects.

.PHONY: all clean

# Project and raylib configuration
PROJECT_NAME       ?= game
RAYLIB_VERSION     ?= 5.0.0
RAYLIB_PATH        ?= ../..
PLATFORM           ?= PLATFORM_DESKTOP
BUILD_MODE         ?= RELEASE
RAYLIB_LIBTYPE     ?= STATIC
USE_EXTERNAL_GLFW  ?= FALSE
USE_WAYLAND_DISPLAY?= FALSE

# Compiler and paths
CC = clang++
MAKE = mingw32-make
RAYLIB_RELEASE_PATH ?= $(RAYLIB_PATH)/src
INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external
LDFLAGS = -L. -L$(RAYLIB_RELEASE_PATH)

# Platform-specific settings
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(OS),Windows_NT)
        PLATFORM_OS = WINDOWS
        LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    else
        UNAMEOS = $(shell uname)
        ifeq ($(UNAMEOS),Linux)
            PLATFORM_OS = LINUX
            LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
            ifeq ($(USE_WAYLAND_DISPLAY),TRUE)
                LDLIBS += -lwayland-client -lwayland-cursor -lwayland-egl -lxkbcommon
            endif
        endif
        ifeq ($(UNAMEOS),Darwin)
            PLATFORM_OS = OSX
            LDLIBS = -lraylib -framework OpenGL -framework OpenAL -framework Cocoa -framework IOKit
        endif
    endif
endif

# Compiler flags
CFLAGS += -Wall -std=c++20 -D_DEFAULT_SOURCE -Wno-missing-braces
ifeq ($(BUILD_MODE),DEBUG)
    CFLAGS += -g -O0
else
    CFLAGS += -s -O2
endif

# Source and object files
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(PROJECT_NAME)

# Link the final executable
$(PROJECT_NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -D$(PLATFORM)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_PATHS) -D$(PLATFORM)

# Clean build artifacts
clean:
ifeq ($(PLATFORM_OS),WINDOWS)
	del /s *.o *.exe
else
	rm -rf $(OBJ_DIR) $(PROJECT_NAME)
endif
	@echo Cleaning done