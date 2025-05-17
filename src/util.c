#include "util.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clip_float(float* var, float min, float max) {
    if (*var > max) {
        *var = max;
    }
    if (*var < min) {
        *var = min;
    }
}

void decellerate(float* var, float decelleration) {
    if (*var > decelleration) {
        *var -= decelleration;
        return;
    }
    if (*var * -1 > decelleration) {
        *var += decelleration;
        return;
    }
    *var = 0;
}

void load_textures(struct GameTextures* textures) {

    textures->pipe_up = malloc(sizeof(Texture2D));
    textures->pipe_down = malloc(sizeof(Texture2D));
    textures->bird = malloc(sizeof(Texture2D));
    textures->background = malloc(sizeof(Texture2D));

    *textures->pipe_up = LoadTextureFromImage(LoadImage("img/pipe_up.png"));
    *textures->pipe_down = LoadTextureFromImage(LoadImage("img/pipe_down.png"));
    *textures->bird = LoadTextureFromImage(LoadImage("img/bird.png"));
    *textures->background =
        LoadTextureFromImage(LoadImage("img/background.png"));
}
