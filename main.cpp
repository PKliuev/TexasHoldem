#include <iostream>
#include "cards.h"
int main(){

    Deck deck;
    std::vector<Card> hand;
    std::vector<Card>::iterator iter;

    for (int i = 0; i < 5; i++){

        hand.push_back(deck.deal());
    }

    for(iter = hand.begin(); iter != hand.end(); iter++){

        std::cout << RankMap.at(iter->get_rank()) << std::endl;

    }

    std::cout << std::endl;

    sort_hand(hand);

        for(iter = hand.begin(); iter != hand.end(); iter++){

        std::cout << RankMap.at(iter->get_rank()) << std::endl;

    }

}