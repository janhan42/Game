# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 23:20:55 by janhan            #+#    #+#              #
#    Updated: 2023/12/19 23:20:55 by janhan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAEM = Space

CXX = clang
CXXFLAGS = -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

SRCS = srcs/

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
	$(CXX) $(CXXFLAGS) $^ -o $@

