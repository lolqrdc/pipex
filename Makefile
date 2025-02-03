# NAME
NAME	= pipex

# DIRECTORIES
LIBFT	= ./libft/libft.a
INC = ./include/
SRC_DIR = src/
OBJS_DIR = obj/

#COMPILER & FLAGS
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
INCFLAGS = -I$(INC) -I ./libft
RM	= rm -f

# SOURCES FILES
SRCS = $(SRC_DIR)main.c \
		$(SRC_DIR)parsing/parse.c \
		$(SRC_DIR)parsing/init.c \
		$(SRC_DIR)parsing/cleanup.c \
		$(SRC_DIR)process/child.c \
		$(SRC_DIR)process/exec.c \

# CONNECT ALL SOURCES FILES
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)

# RULES
all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS_DIR)
	@make clean -sC ./libft

fclean: clean 
	@$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all 

.PHONY : all clean fclean re