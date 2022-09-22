NAME = fract-ol

CC		= cc
INC_PATH = inc/
CFLAGS	= $(IFLAGS) -O2
IFLAGS = -g3 -I $(INC_PATH) -I $(MLX_PATH)




SRC_PATH = src/
SRCS = $(addprefix $(DSRC),\
		main.c\
		multibrot_set.c\
		mandelbrot_set.c\
		julia_set.c\
		init.c\
		exit_error.c\
		get_set_and_hook.c\
		key_hook.c\
		shifting.c\
		iteration_mandelbrot.c\
		utils.c\
		mouse_hook.c\
		window_management.c)


OBJ_PATH = obj/
OBJ		= ${SRCS:.c=.o}
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_PATH	= ./mlx_linux/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) $(IFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all : $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling MiniLibX..."
	@make -sC $(MLX_PATH)
	@echo "Compiling Fract-ol"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "Fract-ol ready to be executed."

clean :
	@echo "Removing objects files..."
	@make clean -sC $(MLX_PATH)
	@rm -rf $(OBJS)

fclean : clean
	@echo "Removing binary file..."
	@rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re



# SRCS		=	src/main.c

# OBJS		=	$(SRCS:.c=.o)

# CC			=	gcc

# RM			=	rm -f

# CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./inc/

# NAME		= 	fract-ol

# MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# %.o: %.c
# 	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 	@make -C ./mlx_linux
# 	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

# clean:
# 	$(RM) $(OBJS)

# fclean:		clean
# 	$(RM) $(NAME)

# re:		fclean $(NAME)

# .PHONY:		all clean fclean re bonus
