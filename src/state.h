#pragma once
#include <raylib.h>

struct Player {
    Vector2 position;
    Vector2 velocity;
};

struct Pipe {
    float position;
    float gap_top;
    float gap_bottom;
};

struct GameState {
    struct Player player;
    int pipe_count;
    struct Pipe pipes[3];
    int score;
};

struct GameTextures {
    Texture2D* pipe_up;
    Texture2D* pipe_down;
    Texture2D* bird;
    Texture2D* background;
};

void tick(struct GameState* state);
