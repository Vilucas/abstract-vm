NAME = abstract_vm

FLAGS = -Wall -Wextra -Werror

SRC = vm.cpp \
		parsing.cpp \

SRCPATH = src
OBJPATH = obj
INCLUDESPATH = -I includes

SRCS = $(addprefix $(SSRC_PATH)/,$(SRC))
OBJ = $(SRCS:$(SRCPPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDESPATH) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all