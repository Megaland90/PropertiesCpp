CC	= g++

RM	= rm -rf

LDFLAGS	+= -shared

CXXFLAGS += -W -Wall -Iinclude -fpic -rdynamic

SRCS	= source/Properties.cpp \

OBJS	= $(SRCS:.cpp=.o)

NAME	= build/properties.so

all: $(NAME) ## Compile

$(NAME): $(OBJS)
	mkdir -p build
	cp include/Properties.hpp build/Properties.hpp
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean: ## Clean .o
	$(RM) $(OBJS)

fclean: clean ## Clean binary
	$(RM) build

help: 
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

.PHONY: all clean fclean help
