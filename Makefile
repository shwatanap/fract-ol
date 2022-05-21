NAME := fractol
CC := gcc
CFLAGS := -Werror -Wall -Wextra
INC=/usr/include
INCLIB=$(INC)/../lib
MLX_PATH := ./minilibx-linux
MLX_LIB := -L$(MLX_PATH) -lmlx

LIBFT_PATH := libft
LIBFT_MAKE := $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB := -L./libft/lib -lft

FILES := main.c \
  canvas_utils.c \
  mlx_hooks.c \
  mlx_mouse_hooks.c \
  mlx_utils.c \
  mandelbrot.c \
  color_utils.c \
  math_utils.c
OBJDIR   := objs
SRCDIR   := srcs
SRCS	 := $(addprefix $(SRCDIR)/, $(FILES))
OBJS	 := $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
INCLUDES := includes

all: $(OBJDIR) $(NAME)

$(NAME): $(MLX_PATH) $(OBJS)
	$(LIBFT_MAKE)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -L$(INCLIB) -lXext -lX11 -lm -lbsd

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(MLX_PATH):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	make -C $(MLX_PATH)

$(OBJDIR):
	mkdir -p $@

clean:
	$(LIBFT_MAKE) clean
	${RM} ${OBJS}

fclean: clean
	$(LIBFT_MAKE) fclean
	${RM} ${NAME}

re: fclean all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re
