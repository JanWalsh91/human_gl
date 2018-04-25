# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/12 15:16:17 by jwalsh            #+#    #+#              #
#    Updated: 2018/04/25 16:27:10 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := humangl

SRCS := main

EXT  :=.cpp
SRCS := $(addsuffix $(EXT), $(SRCS))
OBJS := $(SRCS:$(EXT)=.o)
SRCS_DIR := ./src
OBJS_DIR := ./obj
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
GLAD := libs/glad/glad.c
GLAD_O := obj/glad.o

GLFW_LIB_FLAGS := -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLFW_LIB := glfw3
LIBRARIES := ./libs

CC = gcc
CXX := clang++
CCFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(GLAD_O)
	$(CXX) $(CCFLAGS) $(GLFW_LIB_FLAGS) -I$(LIBRARIES) -L$(LIBRARIES) -l$(GLFW_LIB) $(OBJS) -o $(NAME)  

$(GLAD_O): $(GLAD)
	$(CC) $(CCFLAGSs) -o $@ -c $<

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CCFLAGS) -I$(LIBRARIES) -o $@ -c $<
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY: re all clean fclean

.PHONY: all clean fclean re