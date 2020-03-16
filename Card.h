//
// Created by jeanette roga on 12/3/20.
//

#ifndef LAB2_CARD_H
#define LAB2_CARD_H
#include <string>

using std::string;

class Card {
private:
    int uniqueNumber;
    std::string colour;
    int colourNumber;
    std::string rule;
public:
    Card(int cardUniqueNumber, string cardColour, int cardColourNumber, string cardRule) {
        uniqueNumber = cardUniqueNumber;
        colour = cardColour;
        colourNumber = cardColourNumber;
        rule = cardRule;
    }

    int getUniqueNumber() {
        return uniqueNumber;
    }

    string getColour() {
        return colour;
    }

    int getColourNumber() {
        return colourNumber;
    }

    string getRule() {
        return rule;
    }
};


#endif //LAB2_CARD_H
