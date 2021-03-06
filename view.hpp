#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "character.hpp"

//Window dimensions
#define HEIGHT 580
#define WEIGHT 550

//Colors
#define BLUE 0, 0, 255
#define GREEN 0, 255, 0
#define BROWN 128, 96, 60
#define GROUNDBROWN 128, 96, 20
#define GREY 220, 220, 220
#define BLACK 0, 0, 0
#define WHITE 255, 255, 255

//Texture dimensions
#define MAMAPIG_DIMENSIONS 30, 50
#define WOLF_DIMENSIONS 30, 35
#define BALLON_DIMENSIONS 20, 30
#define ARROW_DIMENSIONS 20, 10
#define MEATY_ARROW_DIMENSIONS 20, 10
#define ROCK_DIMENSIONS 15, 15
#define HOUSE_DIMENSIONS 100, 75
#define HOUSE_POSITION 450, 405

//Object relative position from other objects
#define BALLOON_POSITION_FROM_WOLF_X 15
#define BALLOON_POSITION_FROM_WOLF_Y -17

class View{
private:
    SDL_Window* window;
    SDL_Renderer *rend;
    SDL_Rect ledge, column, ground, house;
    SDL_Texture *text_wolf_walking1, *text_wolf_walking2;
    SDL_Texture *text_wolf_walking1_balloon, *text_wolf_walking2_balloon;
    SDL_Texture *text_wolf_falling, *text_wolf_free_falling, *text_rock;
    SDL_Texture *text_mama_pig, *text_arrow, *text_meaty_arrow, *text_balloon;
    TTF_Font *font;
    int nbr_of_fps;
    bool meat_appeared;

public:
    //Constructor
    View(int fps);

    //Setter
    void setBackground();

    void show();
    void closeView();
    void rendMamaPig(int x, int y);
    void rendMeat(int x, int y, double angle, bool launched);
    void rendWolf(wolf_status wolf, int x, int y, int step);
    void rendArrow(int x, int y, double angle, bool launched);
    void rendNbrPig(int nbr_pig);
    void rendRock(int x, int y);
    void rendGameOver();
};

#endif