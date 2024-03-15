# OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

# CC specifies which compiler we're using
CC = g++

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\Users\Code\C++\SDL2_C++\include\SDL2  -IC:\Users\Code\C++\SDL2_C++\include\headers

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\Users\Code\C++\SDL2_C++\lib

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# OBJ_NAME specifies the name of our executable
OBJ_NAME = main

# This is the target that compiles our executable
all : 
	$(CC) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o $(OBJ_NAME) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS)
