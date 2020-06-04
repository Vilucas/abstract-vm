NAME = abstract_vm

FLAGS = -std=c++2a -Wall -Wextra -Werror

SRC = vm.cpp \
		parsing.cpp \
		instructions.cpp \

INCLUDE = 	vm.hpp \
			exception.hpp \

SRCPATH = src
OBJPATH = obj
INCLUDESPATH = -I includes


INCLUDES = $(addprefix $(INCLUDESPATH)/,$(INCLUDE))
SRCS = $(addprefix $(SRC_PATH)/,$(SRC))
OBJ = $(SRCS:$(SRCPPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(FLAGS) $(INCLUDESPATH) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all