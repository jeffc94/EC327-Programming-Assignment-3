//
//  Model.h
//  PA3_UnderTheSea
//

#ifndef __Model__
#define __Model__

#include "Fish.h"
#include "View.h"

class Model
{
public:
//Public member functions
    Fish* get_Fish_ptr(int id_num);
    CoralReef* get_CoralReef_ptr(int id_num);
    Cave* get_Cave_ptr(int id_num);
    bool update();
    void display(View& view);
    void show_status();
//Constructor
    Model();
//Destructor
    ~Model();
private:
//Private member variables
    int time;
    int num_objects;
    int num_fish;
    int num_caves;
    int num_reefs;
    GameObject** object_ptrs;
    Fish** fish_ptrs;
    Cave** cave_ptrs;
    CoralReef** reef_ptrs;
};

#endif /* defined(__Model__) */
