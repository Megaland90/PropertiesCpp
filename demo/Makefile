.SILENT:

CC	= g++

DEBUG	?= 0

RM	= rm -rf

LDFLAGS	+= -l properties

CXXFLAGS += -W -Wall -Iinclude 

ifeq ($(DEBUG), 1)
	CXXFLAGS+= -DDEBUG -g3
else
	CXXFLAGS+= -Werror 
endif

SRCS	= 	source/main.cpp \

OBJS	= $(SRCS:.cpp=.o)

NAME	= demo

all: $(NAME) ## Compile

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean: ## Clean .o
	$(RM) $(OBJS)

fclean: clean ## Clean binary and .o
	$(RM) $(NAME)
	$(RM) debug

clean_comment: ## Clean all comment //
	find -type f -name "*.cpp" | xargs sed -i 's://.*30209::g'

help: 
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

debug: fclean ## Compile to debug mode
	make -j re DEBUG=1
	mkdir debug
	mv $(NAME) debug/

re: fclean all ## Recompile

.PHONY: all re clean fclean help debug clean_comment
