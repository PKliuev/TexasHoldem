#pragma once
#ifndef CARDS_H
#define CARDS_H
#define HAND_SIZE  5
#define POOL_SIZE  7
#include "libs.h"

enum class Suit {Diamonds,Clubs,Hearts,Spades};
enum class Rank {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
enum class Hand {High, Pair, Two, Three, Straight, Flush, Full, Four, Straight_Flush, Royal_Flush};


const std::map<Suit,std::string> SuitMap { 

    {Suit::Diamonds,"Diamonds"},
    {Suit::Clubs,"Clubs"},
    {Suit::Hearts,"Hearts"},
    {Suit::Spades,"Spades"}

};

const std::map<Rank,std::string> RankMap{

    {Rank::Ace , "Ace"},
    {Rank::Two , "Two"},
    {Rank::Three , "Three"},
    {Rank::Four , "Four"},
    {Rank::Five , "Five"},
    {Rank::Six , "Six"},
    {Rank::Seven , "Seven"},
    {Rank::Eight , "Eight"},
    {Rank::Nine , "Nine"},
    {Rank::Ten , "Ten"},
    {Rank::Jack , "Jack"},
    {Rank::Queen , "Queen"},
    {Rank::King , "King"},

};

const std::map<Hand,std::string> HandMap{

    {Hand::High, "High card"},
    {Hand::Pair, "Pair"},
    {Hand::Two, "Two Pairs"},
    {Hand::Three, "Three of a kind"},
    {Hand::Straight, "Straight"},
    {Hand::Flush, "Flush"},
    {Hand::Full, "Full house"},
    {Hand::Four, "Four of a kind"},
    {Hand::Straight_Flush, "Straight_Flush"},
    {Hand::Royal_Flush, "Royal_Flush"}


};

class Card{

    private:
        Suit suit;
        Rank rank;

    public:
        Suit get_suit() const;
        Rank get_rank() const;
        Card(Suit suit, Rank rank);
        bool operator==(const Card& other);
};

class Deck{

    private:
        std::vector<Card> deck;
        std::vector<Card> community;
    public:
        Deck();
        Card deal();
        void flop(bool big);
        const std::vector<Card> get_community();
        const std::vector<Card> get_deck();

};

void shuffle_deck(std::vector<Card> &deck);
void show_deck(const std::vector<Card> &deck);

bool compare_rank(Card card1, Card card2);

bool compare_suit(Card card1, Card card2);

std::ostream& operator<< (std::ostream& os, Suit const suit);
std::ostream& operator<< (std::ostream& os, Rank const rank);
std::ostream& operator<< (std::ostream& os, Hand const hand);

bool check_flush(const std::vector<Card> &pool, std::vector<Card> &hand); 
bool check_straight(const std::vector<Card> &pool, std::vector<Card> &hand);
int check_kind(const std::vector<Card> &pool, std::vector<Card> &hand, std::vector<Card> &remainder);
Hand result_hand(const std::vector<Card> &pool, std::vector<Card> &hand);
#endif