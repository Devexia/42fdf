LINUX				:= 0

# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

# Libraries

override LIBFT_DIR	:= src/utils/libft
override LIBFT		:= libft.a
ifeq ($(LINUX),0)
override MINILIBX_DIR	:= minilibx-macos
override MINILIBX		:= libmlx.a
else
override MINILIBX_DIR	:= minilibx-linux
override MINILIBX		:= libmlx.a
endif

# Properties

NAME				= fdf

# Commands

override CC			:= gcc
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror -g3
override INCLUDES	:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# Sources

override SRCS		:=									\
				fdf.c									\
				parse_map.c								\
				utils/get_next_line/get_next_line.c		\
				utils/get_next_line/get_next_size.c		\
				utils/get_next_line/get_next_line_utils.c \
				line.c									\
				utils/fdf_utils.c						\
				utils/norm_utils.c						\

override OBJS		:= $(addprefix $(BIN)/, $(SRCS:.c=.o))

override HEADERS	:= $(addprefix $(INC)/,				\
				fdf.h									\
				structure.h								\
				get_next_line.h							\
				)

LIBRARIES	:= -lpthread
ifeq ($(LINUX),1)
LIBRARIES	+= -lm -lXext -lX11
endif

all:		libs $(NAME)

libs:
			$(MAKE) -C $(LIBFT_DIR)
			ln -sf $(LIBFT_DIR)/$(LIBFT)
			$(MAKE) -C $(MINILIBX_DIR)
			ln -sf $(MINILIBX_DIR)/$(MINILIBX)

bonus:		all

$(BIN)/%.o:	$(SRC)/%.c $(HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MINILIBX)
			$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -framework OpenGl -framework Appkit $(LIBFT) -o $(NAME) $(LIBRARIES)

clean:
			$(RM) $(OBJS)
			find $(BIN) -type d -empty -delete
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(MINILIBX)
			$(MAKE) -C $(MINILIBX_DIR) clean

re:			fclean all

.PHONY:		all libs bonus clean fclean re

