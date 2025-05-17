#!/usr/bin/env bash
gcc --debug main.c src/key_handlers.c src/state.c src/util.c -lraylib -lm -ldl -lpthread -lGL -lrt -o main && ./main
