# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avogt <avogt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 16:09:40 by avogt             #+#    #+#              #
#    Updated: 2021/03/08 16:32:57 by avogt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SOURCES = main.c \
	errors/error.c \
	bmp/write_bmp.c \
	bmp/raytracing_bmp.c \
	utils/ft_atof.c \
	utils/ft_isalpha.c \
	utils/ft_isspace.c \
	utils/ft_isdigit.c \
	utils/get_next_line.c \
	utils/ft_strcmp.c \
	utils/ft_lst.c \
	utils/ft_memset.c \
	utils/ft_putstr_fd.c \
	utils/ft_strchr.c \
	utils/ft_strdel.c \
	utils/ft_strjoin.c \
	utils/ft_strsub.c \
	utils/ft_strdup.c \
	colors/ft_get_color.c \
	colors/calculate_colors.c \
	colors/put_color_px.c\
	parsing/check_args.c \
	parsing/parse_file.c \
	parsing/init_r_a_c_l.c \
	parsing/ft_get_vec3.c \
	parsing/init_cy_pl_sq_sp_tr.c \
	parsing/ft_get_dimensions.c \
	parsing/ft_parse_functions.c \
	parsing/check_data_parsed.c \
	maths/compute_vec3.c \
	maths/compute_normal.c \
	maths/normalize_vec3.c \
	maths/create_vec3.c \
	maths/mat3.c \
	maths/angle.c \
	free/free_scene.c \
	free/free_parsing.c \
	intersections/inter_sphere.c \
	intersections/inter_triangle.c \
	intersections/inter_plane.c \
	intersections/inter_cylinder.c \
	intersections/inter_square.c \
	intersections/intersections.c \
	raytracing/find_ray.c \
	raytracing/raytracing.c \
	hooks/hooks.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx-linux
IFLAGS = -I ./include
DIR_S = srcs

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(MLX)
	@$(CC) $(IFLAGS) $(SRCS) -o $(NAME) -lm -lmlx -lbsd -lXext -lX11

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@make -s -C $(MLX) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f image.bmp
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
