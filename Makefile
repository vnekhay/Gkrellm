NAME = ft_gkrellm

SRCSFILES   := main.cpp \
			modules/CatModule.cpp \
			modules/DateTimeModule.cpp \
			modules/Display.cpp \
			modules/MemRegionsModule.cpp \
			modules/NetworkModule.cpp \
			modules/RamModule.cpp \
			modules/CpuModule.cpp \
			modules/DisksModule.cpp \
			modules/HostnameModule.cpp \
			modules/Module.cpp \
			modules/OSinfoModule.cpp \
			modules/VmModule.cpp

SRCPATH = srcs

OBJPATH = obj

INCPATH = includes

CC = clang++

INCLUDES = -I $(INCPATH) -I ${HOME}/SFML/include

LIBS =	-framework sfml-graphics -framework sfml-window -framework sfml-system -F ${HOME}/SFML/Frameworks -lncurses

RM = rm -rf

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))

OBJECTS = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean format re
