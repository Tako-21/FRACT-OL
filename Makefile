NAME = fract-ol

CC = cc


SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/

# CFLAGS = -Wall -Werror -Wextra

IFLAGS = -g3 -I $(INC_PATH) -I ./mlx_linux

SRCS = $(addprefix $(DSRC),\
		main.c)

OBJ = ${SRCS:.c=.o}

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	$(CC) $(CFLAGS) $(IFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(OBJ_PATH) $(NAME)

$(NAME) : $(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

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