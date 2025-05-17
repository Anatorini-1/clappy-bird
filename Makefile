main: main.c src/key_handlers.c src/state.c src/util.c
	gcc main.c src/key_handlers.c src/state.c src/util.c -lraylib -lm -ldl -lpthread -lGL -lrt  -o main
