#include "players.h"

std::vector<Card> Player::get_hand(){

    return Hand;

};

void Player::get_dealt(Deck deck, int num){

    for (int i = 0; i < num; i++){

        Hand.push_back(deck.deal());

    };

};