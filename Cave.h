//
//  Cave.h
//  PA3_UnderTheSea
//

#ifndef __Cave__
#define __Cave__

#include "GameObject.h"

class Fish;

class Cave : public GameObject
{
public:
//Public member functions
    bool hide_fish(Fish* fish_to_hide);
    bool release_fish (Fish* fish_to_release);
    bool update();
    void show_status();
//Constructors
    Cave();
    Cave(int, CartPoint);
//Destructor
    ~Cave();
private:
//Private member variables
    double space;
};


#endif /* defined(__Cave__) */
