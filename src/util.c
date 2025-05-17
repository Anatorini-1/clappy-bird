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

    Image image;
    Texture2D texture;

    image = LoadImage("pipe_up.png");
    texture = LoadTextureFromImage(image);
    textures->pipe_up = malloc(sizeof(Texture2D));
    memcpy(textures->pipe_up, &texture, sizeof(Texture2D));

    image = LoadImage("pipe_down.png");
    texture = LoadTextureFromImage(image);
    textures->pipe_down = malloc(sizeof(Texture2D));
    memcpy(textures->pipe_down, &texture, sizeof(Texture2D));

    image = LoadImage("bird.png");
    texture = LoadTextureFromImage(image);
    textures->bird = malloc(sizeof(Texture2D));
    memcpy(textures->bird, &texture, sizeof(Texture2D));

    image = LoadImage("background.png");
    texture = LoadTextureFromImage(image);
    textures->background = malloc(sizeof(Texture2D));
    memcpy(textures->background, &texture, sizeof(Texture2D));
}
