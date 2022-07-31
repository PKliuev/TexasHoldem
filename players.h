#pragma once
#ifndef PLAYERS_H
#define PLAYERS_H
#include "libs.h"
#include "cards.h"

class Player{

    private:

        std::vector<Card> Hand = {};
        int chips;
        char* name;

    public:

        std::vector<Card> get_hand();
        void get_dealt(Deck deck, int num);

};



#endif