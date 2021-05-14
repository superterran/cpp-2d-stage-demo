#ifndef PLAYER_H
#define PLAYER_H
#include "input.h"

class Player {
    public:
        int x;
        int y;
        void move(Input input);
};

#endif