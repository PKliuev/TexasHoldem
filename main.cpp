#include <iostream>
#include "cards.h"
#include "players.h"
int main(){

    Deck deck;
    std::vector<Card> hand, comb, remainder = {};
    std::vector<Card>::iterator iter;
    

    Card card1(Suit::Clubs,Rank::Ace);
    hand.push_back(card1);
    Card card2(Suit::Clubs,Rank::King);
    hand.push_back(card2);
    Card card3(Suit::Clubs,Rank::King);
    hand.push_back(card3);
    Card card4(Suit::Clubs,Rank::Jack);
    hand.push_back(card4);
    Card card5(Suit::Clubs,Rank::Ten);
    hand.push_back(card5);
    Card card6(Suit::Clubs,Rank::Ten);
    hand.push_back(card6);
    Card card7(Suit::Clubs,Rank::Eight);
    hand.push_back(card7);


    for(iter = hand.begin(); iter != hand.end(); iter++){

        std::cout << iter->get_rank() << " of " <<
         iter->get_suit() << std::endl;

    }
    
    std::cout << result_hand(hand, comb) << std::endl;

    getchar();

}