#include <iostream>
#include "cards.h"
int main(){

    Deck deck;
    std::vector<Card> hand, comb;
    std::vector<Card>::iterator iter;

    for(int i = 0 ; i < 7 ; i++){

        hand.push_back(deck.deal());

    }

    for(iter = hand.begin(); iter != hand.end(); iter++){

        std::cout << RankMap.at(iter->get_rank()) << " of " <<
         SuitMap.at(iter->get_suit()) << std::endl;

    }

    std::cout << std::endl;

    std::cout << check_flush(hand,comb) << std::endl;

    for(iter = comb.begin(); iter != comb.end(); iter++){

        std::cout << RankMap.at(iter->get_rank()) << " of " <<
         SuitMap.at(iter->get_suit()) << std::endl;

    }

}