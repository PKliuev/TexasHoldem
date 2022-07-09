#include "cards.h"
#define HAND_SIZE  5
#define POOL_SIZE  7
Rank Card::get_rank() const {return rank;};
Suit Card::get_suit() const {return suit;};

Card::Card(Suit suit, Rank rank): suit(suit), rank(rank){};

Deck::Deck(){

    std::map<Suit,std::string>::const_iterator iterSuit;
    std::map<Rank,std::string>::const_iterator iterRank;

    for ( iterSuit = SuitMap.begin(); iterSuit != SuitMap.end(); iterSuit++ ){

        for( iterRank = RankMap.begin(); iterRank !=RankMap.end(); iterRank++ ){

            Card card(iterSuit->first,iterRank->first);
            deck.emplace(deck.begin(),card);
        };
    };

    shuffle_deck(deck);
};

Card Deck::deal(){
    Card dealt(deck.back());
    deck.pop_back();
    return dealt;

};

void Deck::flop(bool big){

    if (!big){ community.push_back(deal()); }
    else{
        community.insert(community.begin(),deck.end()-3,deck.end());
        deck.erase(deck.end()-3,deck.end());
    }

};

const std::vector<Card> Deck::get_community(){ return community; };
const std::vector<Card> Deck::get_deck(){ return deck; };

void shuffle_deck(std::vector<Card> &deck){

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(),deck.end(),g);

};

void show_deck(const std::vector<Card> &deck) {

    std::vector<Card>::const_iterator it;

        for(it = deck.begin(); it != deck.end(); it++){

            std::cout << RankMap.at(it->get_rank()) << " of "
            << SuitMap.at(it->get_suit()) << std::endl;
        };

};

bool compare_rank(Card card1, Card card2){

    return (static_cast<int>(card1.get_rank()) <
            static_cast<int>(card2.get_rank()));

};

bool compare_suit(Card card1, Card card2){

    return (static_cast<int>(card1.get_suit()) <
            static_cast<int>(card2.get_suit()));
  

}


bool check_flush(const std::vector<Card> &pool, std::vector<Card> &hand){
    
    std::vector<Card> poolcpy = pool;
    std::vector<Card>::iterator it1;
    int cntr = 1;

    sort(poolcpy.begin(),poolcpy.end(),compare_suit);

    it1 = poolcpy.begin();

    while(it1 != poolcpy.end()){

        if(it1->get_suit() == (it1+1)->get_suit()){

            cntr++;
            
        }
        else{

            if(cntr >= HAND_SIZE){

                copy(it1 - HAND_SIZE + 1, it1 + 1, std::back_inserter(hand));
                return 1;
            }
            else{

                cntr = 1;

                if(it1 - poolcpy.begin() > 2){

                    return 0;

                }

            }

        }

        it1++;

    }

    return 0;
    
};

// доделать когда соображу сортировку enum
bool check_straight(const std::vector<Card> &pool){

return 0;

};