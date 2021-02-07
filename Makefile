.PHONY: help

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: ## installs dependancies (debian)
	sudo apt install libsdl2-gfx-dev libsdl2-image-dev fswatch

build: ## compiles the app
	@g++ *.cpp -lSDL2main -lSDL2 -lSDL2_image -I./headers

run: build ## runs the app
	@./a.out || true

watch: run ## starts with watcher
	@fswatch -1 * | xargs -n1 make watch