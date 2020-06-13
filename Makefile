NAME = abstract_vm

FLAGS = -std=c++2a -Wall -Wextra -Werror

SRC = vm.cpp \
		parsing/parsing.cpp \
		parsing/instructionsParsing.cpp \
		stack/stack.cpp \
		stack/launcher.stack.cpp \
		allowedVarTypes/variableDefinition.cpp \
		allowedVarTypes/Master.cpp \
		allowedVarTypes/Operators.cpp \
		allowedVarTypes/Factory.cpp \

INCLUDE = 	vm.hpp \
			exception.hpp \

SRCPATH = src
OBJPATH = obj
INCLUDESPATH = includes -I includes/allowedVarTypes


INCLUDES = $(addprefix $(INCLUDESPATH)/,$(INCLUDE))
SRCS = $(addprefix $(SRC_PATH)/,$(SRC))
OBJ = $(SRCS:/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(FLAGS) -I $(INCLUDESPATH) -c $< 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.d : $(SRCSPATH)/%.cpp)
		$(MAKEDEPEND)

include $(SRCS%.c=.d)