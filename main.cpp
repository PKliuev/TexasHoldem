#include <iostream>
#include "cards.h"
int main(){

    Deck deck;
    std::vector<Card> hand, comb;
    std::vector<Card>::iterator iter;

    Card card1(Suit::Clubs,Rank::Ace);
    hand.push_back(card1);
    Card card2(Suit::Clubs,Rank::King);
    hand.push_back(card2);
    Card card3(Suit::Clubs,Rank::Queen);
    hand.push_back(card3);
    Card card4(Suit::Clubs,Rank::Jack);
    hand.push_back(card4);
    Card card5(Suit::Clubs,Rank::Ten);
    hand.push_back(card5);




    for(int i = 0 ; i < 2 ; i++){

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