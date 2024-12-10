CXX = g++
CFLAGS = -I/opt/homebrew/include/SDL2 -I"./libs/" -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua

build:
	@echo "-- Building the executable..."
	@echo "-- Compiling..."
	@${CXX} -Wall -std=c++17 Core/core.cpp ${CFLAGS} -o gameengine;
	@echo "-- Compiling Done!"

run:
	@echo "-- Running the executable - gameengine..."
	@./gameengine
	@echo "-- Execution Completed!"

go: build run

clean:
	@echo "-- Cleaning by Removing executable - gameengine..."
	@rm ./gameengine
	@echo "-- Cleaning Done!"
