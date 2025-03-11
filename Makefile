# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I mlx

# MiniLibX
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source and Object Files
SRCS = main.c readmap.c ./hooks/hooks.c ./utils/ft_split.c\
       ./utils/ft_print2dchararr.c ./utils/ft_free2darr.c\
       ./utils/ft_strlen.c ./utils/ft_isvalidmap.c\
       ./utils/ft_ismapsolvable.c
OBJS = $(SRCS:.c=.o)

# Output Program Name
NAME = so_long

# Default rule
all: $(NAME)

# Compile the executable
$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile MiniLibX if needed
$(MLX_LIB):
	make -C $(MLX_DIR)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Bonus rule
bonus: $(NAME)

# Phony to prevent conflicts with file names
.PHONY: all clean fclean re bonus
