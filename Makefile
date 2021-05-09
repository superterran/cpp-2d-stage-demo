.PHONY: help

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install-ubutnu: ## installs dependancies (ubuntu)
	sudo apt install libsdl2-gfx-dev libsdl2-image-dev fswatch

install-fedora: ## installs dependancies (fedora)
	sudo dnf install gcc-c++ SDL2_image SDL2-devel SDL2_image-devel SDL2_gfx-devel

compile: ## compiles only
	@mkdir -p bin
	@g++ src/*.cpp -lSDL2 -lSDL2_image -I./headers -I./src -o bin/fantasy

run: compile ## compiles and runs
	@./bin/fantasy