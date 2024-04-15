# Name of executable 
EXECUTABLE = simcity 

# Source files
SRCS = initialization.cpp zone.cpp output.cpp build.cpp encryption.cpp mapGen.cpp PausePlay.cpp storm.cpp main.cpp

# Header files 
HEADERS = initialization.h zone.h output.h build.h encryption.h mapGen.h PausePlay.h storm.h

# Compiler
CXX = g++

# Compiler Flags (Adjust as needed)
CXXFLAGS = -Wall 

# All target: This is the default target executed with 'make'
all: $(EXECUTABLE)

# Target to create the executable 
$(EXECUTABLE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXECUTABLE)

# Target for cleanup
clean:
	rm -f $(EXECUTABLE) 