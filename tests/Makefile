# Compiler to use
CC := gcc

# Default Cflags used for compilation
CFLAGS := -Werror -Wall -Wextra -MMD -g3

LIBFT := ../lib/libft/lib/libft.a
FT_PRINTF := ../lib/ft_printf/lib/libprintf.a

# Directory where header files are located
INCLUDES := -I../includes -I../lib/libft/includes -I../lib/ft_printf/includes

OBJ_DIR := objs
SRC_DIR := src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

TARGET := push_swap

# Dependency files for header dependencies
DEPEND = $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $^ -o $(TARGET)

# Rule to generate all object files and create OBJ_DIR if it doesn't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(LIBFT):
	$(MAKE) -C ../lib/libft

$(FT_PRINTF):
	$(MAKE) -C ../lib/ft_printf

# Include the dependency files to manage header dependencies
-include $(DEPEND)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)
	$(MAKE) -C ../lib/libft fclean
	$(MAKE) -C ../lib/ft_printf fclean

re: fclean all
