/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:49:52 by avogt             #+#    #+#             */
/*   Updated: 2021/03/08 17:23:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# define BUFF_SIZE 550
# define PIXEL_DATA_OFFSET 54
# define INFO_HEADER_SIZE 40
# define BITS_PER_PIXEL 24

typedef enum	e_xeventmask
{
	STRUCTURENOTIFYMASK = 1L << 17,
	VISIBILITYCHANGEMASK = 1L << 16
}				t_xeventmask;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_pixel
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_pixel;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_mat3
{
	t_vec3			v1;
	t_vec3			v2;
	t_vec3			v3;
}					t_mat3;

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_amblight
{
	float			ratio;
	t_color			color;
}					t_amblight;

typedef struct		s_camera
{
	t_vec3			view_point;
	t_vec3			vec;
	int				fov;
	t_mat3			cam_w;
}					t_camera;

typedef struct		s_light
{
	t_vec3			p;
	float			ratio;
	t_color			color;
}					t_light;

typedef struct		s_object
{
	t_vec3			point[3];
	char			type[2];
	t_vec3			vec;
	t_color			color;
	float			diameter;
	float			height;
}					t_object;

typedef struct		s_image {
	void			*ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

typedef struct		s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct		s_scene
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_resolution	resolution;
	t_amblight		amblight;
	t_list			*light;
	t_list			*camera;
	t_camera		a_camera;
	int				act_camera;
	t_list			*object;
	t_image			img;
	t_ray			ray;
	t_object		*obj;
	float			t;
}					t_scene;

void				select_camera(int change, t_scene *scene, int save);
void				render_image(t_scene *scene);
int					reload_window(t_scene *scene);
void				save_in_bmp(t_scene *scene, t_pixel **pixels);
void				raytracing_bmp(t_scene *scene);

void				raytracing(t_scene *scene);
void				look_at(t_camera *camera);
void				find_ray(t_scene *scene, int test_i, int test_j);
t_object			*intersect(t_scene *scene);
void				shading(t_scene *scene, t_color *color);

float				find_intersection(t_object *obj, t_ray ray);
float				find_intersection_sp(t_object *object, t_ray ray);
float				find_intersection_sq(t_object *object, t_ray ray);
float				find_intersection_pl(t_object *object, t_ray ray);
float				find_intersection_tr(t_object *object, t_ray ray);
float				find_intersection_cy(t_object *object, t_ray ray);

void				put_color_px(t_image *image, int x, int y, t_color color);

t_color				ft_get_color(const char *s, size_t *i);
int					ft_get_vec3(const char *s, t_vec3 *vec, size_t *i);
float				ft_get_diameter(const char *s, size_t *i);
float				ft_get_height(const char *s, size_t *i);
float				ft_get_ratio(const char *s, size_t *i);
int					ft_get_fov(const char *s, size_t *i);
float				ft_atof(const char *s, size_t *i);

char				*init_amblight(char *line, t_scene *scene);
char				*init_resolution(char *line, t_scene *scene);
char				*init_camera(char *line, t_scene *scene);
char				*init_light(char *line, t_scene *scene);
char				*init_cylindre(char *line, t_scene *scene);
char				*init_plane(char *line, t_scene *scene);
char				*init_sphere(char *line, t_scene *scene);
char				*init_square(char *line, t_scene *scene);
char				*init_triangle(char *line, t_scene *scene);
void				parse_file(char *filename, t_scene *scene);
char				*check_data_camera(t_camera *cam);
char				*check_data_sq(t_object *o);
char				*check_data_cy(t_object *o);
char				*check_data_pl(t_object *o);
void				check_args(int ac, char *av[], t_scene *scene);
void				check_resolution(t_scene *scene);
int					check_range_vec3(t_vec3 vec);
int					skip_comma(char c, size_t *i);
int					is_color_null(t_color color);
int					is_vec_null(t_vec3 vec);

t_mat3				new_mat3(void);
t_vec3				mult_mat3_vec3(t_mat3 mat, t_vec3 vec);
t_vec3				create_vec3(float a, float b, float c);
float				dot_product(t_vec3 a, t_vec3 b);
t_vec3				cross_product_vec3(t_vec3 a, t_vec3 b);
t_vec3				add_vec3(t_vec3 a, t_vec3 b);
t_vec3				sub_vec3(t_vec3 a, t_vec3 b);
t_vec3				mult_vec3(float n, t_vec3 a);
t_vec3				normalize_vec3(t_vec3 v);
t_vec3				get_normal(t_scene *scene, t_object *obj, t_vec3 inter);
float				cosinus_vec3(t_vec3 a, t_vec3 b);

t_color				new_color(float r, float g, float b);
t_color				mult_color(t_color a, t_color b);
void				get_color_with_light(t_color *c, t_light *l, float r);
void				get_color_with_ambiant(t_scene *scene, t_color *c);

char				*free_l_parsed(t_light *light, char *s);
char				*free_c_parsed(t_camera *c, char *s);
char				*free_o_parsed(t_object *o, char *s);
void				free_scene(t_scene *scene);
void				ft_error(char *s, t_scene *scene);

int					check_key(int key, t_scene *scene);
int					close_cross(t_scene *scene);
int					w_close(t_scene *scene);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *content);

void				*ft_memset(void *b, int c, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putstr_fd(const char *s, int fd);
int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
#endif
