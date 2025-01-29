# NAME
NAME	= pipex

# DIRECTORIES
LIBFT	= ./include/libft/libft.a
INC = ./include
SRC_DIR = srcs/
OBJS_DIR = obj/

#COMPILER & FLAGS
CC	= cc
CFLAGS	= -I$(INC)
RM	= rm -f

# SOURCES FILES
SRCS = $(SRC_DIR)

# CONNECT ALL SOURCES FILES
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

# RULES
all: $(NAME)

$(LIBFT):
	@make -C ./include/libft

$(NAME): $(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(BONUS_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS_DIR)
	@make clean -C ./include/libft

fclean: clean 
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all 

.PHONY : all clean fclean re bonus