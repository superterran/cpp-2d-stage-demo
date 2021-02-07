.PHONY: help

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

install: ## installs dependancies (debian)
	sudo apt install libsdl2-gfx-dev fswatch

compile: ## compiles the app
	@g++ *.cpp -lSDL2main -lSDL2 -I./headers

run: compile ## runs the app
	@./a.out || true
	
watch: run ## starts with watcher
	@fswatch -1 * | xargs -n1 make watch