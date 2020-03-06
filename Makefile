# Name of the program.
NAME     := ft_gkrellm

# Sources and objects.
SRCS     :=  main.cpp \
                IMonitorDisplay.cpp \
                INcursesDisplay.cpp \
                ISDLDisplay.cpp \
                Surface.cpp \
                IEvent.cpp \
                ./modules/IMonitorModule.cpp \
                ./modules/HostnameUsernameMod.cpp \
                ./modules/OSInfosMod.cpp \
                ./modules/DateTimeMod.cpp \
                ./modules/CPUMod.cpp \
                ./modules/RAMMod.cpp \
                ./modules/NetworkMod.cpp

OBJS     := $(SRCS:.cpp=.o)

SDL_INC :=			-I./frameworks/SDL2.framework/Headers\
                    -I./frameworks/SDL2_ttf.framework/Headers\
                    -I./frameworks/SDL2_image.framework/Headers\
                    -I./frameworks/SDL2_mixer.framework/Headers\


FRM :=              -F./frameworks\
                    -rpath ./frameworks\
                    -framework SDL2 -framework SDL2_ttf -framework SDL2_image 

SDL :=				-F /Library/Frameworks/ -framework SDL2 -F /Library/Frameworks/ -framework SDL2_image -F /Library/Frameworks/ -framework SDL2_ttf 


# Define all the compiling flags.
CXX      := clang++
CXXFLAGS := -Wall -Werror -Wextra

# Compile and create everything.
all: $(NAME)

# Compile the program with the objects.
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) $(FRM) -lncurses  -o $(NAME)

# This won't run if the source files don't exist or are not modified.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c  $<

# Rule to remove all the object files.
clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

# Rule to remove everything that has been created by the makefile.
fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

# Rule to re-make everything.
re:     fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean format re
