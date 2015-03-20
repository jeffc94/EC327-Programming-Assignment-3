//
//  Fish.h
//  PA3_UnderTheSea
//

#ifndef __Fish__
#define __Fish__

#include "GameObject.h"
#include "CoralReef.h"

class Cave;
class Fish : public GameObject
{
public:
//Public member functions
    bool update();
    double get_size();
    void start_swimming(CartPoint);
    void start_eating(CoralReef*);
    bool is_hidden();
    void start_hiding(Cave*);
    void float_in_place();
    void show_status();
    double get_speed();
//Constructors
    Fish();
    Fish(int,Cave*);
//Destructor
    ~Fish();
private:
//Private member variables
    double energy;
    double size;
    double prefeast_size;
    CartPoint destination;
    CartVector delta;
    CoralReef* reef;
    Cave* home;
//Private member functions
    bool update_location();
    void setup_destination(CartPoint);
};

#endif /* defined(__Fish__) */
