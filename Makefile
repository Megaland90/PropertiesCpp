CC	= g++

RM	= rm -rf

LDFLAGS	+= -shared

CXXFLAGS += -W -Wall -Iinclude -fPIC -rdynamic

SRCS	= source/Properties.cpp \

OBJS	= $(SRCS:.cpp=.o)

NAME	= libproperties.so

all: build/$(NAME) ## Compile

build/$(NAME): $(OBJS)
	mkdir -p build
	$(CC) -o build/$(NAME) $(OBJS) $(LDFLAGS)

clean: ## Clean .o
	$(RM) $(OBJS)

fclean: clean ## Clean binary
	$(RM) build

install : all
	sudo mkdir -p /usr/include/Properties
	sudo cp include/Properties.hpp /usr/include/Properties/Properties.hpp
	sudo cp build/$(NAME) /usr/lib/$(NAME)


help: 
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

.PHONY: all clean fclean help install
