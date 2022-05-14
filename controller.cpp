#include "controller.hpp"

Controller::Controller(){
    ingame = true;
}

void Controller::handleInputs(){
    bool mama_moved = false;
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){ 
            ingame = false;
            break;
        }
        switch (event.key.keysym.sym){ 
            case SDLK_UP:
                model.moveMamaPig(1);
                mama_moved = true;
                break;
            case SDLK_DOWN:
                model.moveMamaPig(-1);
                mama_moved = true;
                break;
            case SDLK_SPACE:
                
            default:
                break;
        }
    }
    if(!mama_moved)
        model.moveMamaPig(0);
}

void Controller::game(){
    view.setBackground();

    handleInputs();

    model.computeMamaPigPosition();
    if(model.getTimingmeat() >= 270){ 
        view.rendMeat(400, 170);
        view.setMeat_appeared(true);
        
        }
    if(model.getTimingmeat() < 270 && !view.getMeat_appeared()){
        model.setTimingmeat(model.getTimingmeat()+1);
    }


    view.rendMamaPig(model.getMamaPigPosX(), model.getMamaPigPosY());
    view.show();
}

void Controller::endGame(){
    view.closeView();
}
