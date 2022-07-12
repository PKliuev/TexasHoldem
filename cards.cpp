#include "cards.h"

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

std::ostream& operator<< (std::ostream& os, Suit const suit){

    os << SuitMap.at(suit);

    return os;

};

std::ostream& operator<< (std::ostream& os, Rank const rank){

    os << RankMap.at(rank);

    return os;

};

std::ostream& operator<< (std::ostream& os, Hand const hand){

    os << HandMap.at(hand);

    return os;

};

bool Card::operator==(const Card& other){

    return((this->get_rank() == other.get_rank()) && (this->get_suit() == other.get_suit()));

};

bool check_flush(const std::vector<Card> &pool, std::vector<Card> &hand){
    
    auto poolcpy = pool;
    int cntr = 1;

    sort(poolcpy.begin(),poolcpy.end(),compare_suit);

    auto it1 = poolcpy.begin();
    hand.emplace_back(it1->get_suit(), it1->get_rank());

    while(it1 != poolcpy.end()){

        if (it1->get_suit() == (it1 + 1)->get_suit()){

            hand.emplace_back((it1 + 1)->get_suit(), (it1 + 1)->get_rank());
            cntr++;

        }
        else{

            if( cntr >= HAND_SIZE){

                return 1;

            }
            else{

                hand.clear();

                if ( (it1 - poolcpy.begin()) > 2){

                    return 0;

                }
                
                hand.emplace_back((it1 + 1)->get_suit(), (it1 + 1)->get_rank());
                cntr = 1;

            }

        }

        it1++;

        
    }

if(cntr >= HAND_SIZE){

            return 1;

        }
        else{

            return 0;

        };
    
};

bool check_straight(const std::vector<Card> &pool, std::vector<Card> &hand){

    std::vector<Card> poolcpy = pool;
    std::vector<Card>::iterator it1;
    int virtPool = 0;
    int cntr = 1;
    
    sort(poolcpy.begin(),poolcpy.end(),compare_rank);

    it1 = poolcpy.begin();

    if(it1->get_rank() == Rank::Ace){

        poolcpy.emplace_back(it1->get_suit(),it1->get_rank());
        virtPool++;
    }

        for(it1 = poolcpy.begin() ; it1 != poolcpy.end() ; it1++){

        std::cout << RankMap.at(it1->get_rank()) << std::endl;

    }

    it1 = poolcpy.begin();

    hand.emplace_back(it1->get_suit(),it1->get_rank());

    while(it1 != poolcpy.end() - 1){
    
        if(static_cast<int>((it1+1)->get_rank()) - static_cast<int>(it1->get_rank()) <= 1){

            hand.emplace_back((it1+1)->get_suit(),(it1+1)->get_rank());

            if(static_cast<int>((it1+1)->get_rank()) - static_cast<int>(it1->get_rank()) == 1){

                cntr++;

            };

        }
        else{

            if(cntr >= HAND_SIZE){

                return 1;

            }
            else{

                hand.clear();
                if ( (it1 - poolcpy.begin()) > (2 + virtPool) ){

                    return 0;

                }
                hand.emplace_back((it1 + 1)->get_suit(), (it1 + 1)->get_rank());
                cntr = 1;

            }

        }

        it1++;
    }

    if (cntr >= HAND_SIZE){

        return 1;

    }else{

        return 0;

    }


};

// returns the length of the largest sequence of the same rank cards in a pool, 
// stores this sequence in "hand", given pool minus sequence - in "remainder"

int check_kind(const std::vector<Card> &pool, std::vector<Card> &hand, std::vector<Card> &remainder) {

    auto poolcpy = pool;
    bool isIn;
    sort(poolcpy.begin(), poolcpy.end(), compare_rank);

    auto it1 = poolcpy.begin();

    remainder.emplace_back(it1->get_suit(), it1->get_rank());

    while( it1 != poolcpy.end()){

        if( it1->get_rank() != (it1 + 1)->get_rank() ){

            if(remainder.size() >= hand.size()){

                hand = remainder;

            }
            
            remainder.clear();
        }
        
        remainder.emplace_back((it1 + 1)->get_suit(), (it1 + 1)->get_rank());
        it1++;

    }

    remainder.clear();
    it1 = poolcpy.begin();

    while(it1 != poolcpy.end()){

        isIn = 0;
        for(auto it2 = hand.begin(); it2 != hand.end(); it2++){

            if (*it1 == *it2){

                isIn = 1;
                break;

            }

        }; 

        if(!isIn){

            remainder.emplace_back(it1->get_suit(),it1->get_rank());

        };

        it1++;
    };

    return hand.size();
}


//not finished, check_kind needs rewriting
Hand result_hand(const std::vector<Card> &pool, std::vector<Card> &hand){

    bool flush = 0, straight = 0;
    std::vector<Card> checkHand, remainder;
    flush = check_flush(pool, checkHand);
    if(!flush){

        checkHand.clear();
        straight = check_straight(pool, checkHand);

    }
    else{

        straight = check_straight(checkHand, hand);

    }

    if(flush && straight){

        if(hand.back().get_rank() == Rank::Ace){

            return Hand::Royal_Flush;

        }
        else{

            return Hand::Straight_Flush;

        }

    }

return Hand::High;
};