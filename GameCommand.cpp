//
//  GameCommand.cpp
//  PA3_UnderTheSea
//

#include <iostream>
#include "GameCommand.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Cave.h"
#include "Model.h"
#include "Fish.h"
#include "CoralReef.h"

void do_swim_command(Model& model)
{
    int fishID, xcoor, ycoor;
    cin >> fishID >> xcoor >> ycoor;
    //Get pointer to corresponding Fish ID
    Fish* fishPtr = model.get_Fish_ptr(fishID);
    CartPoint destcoor = CartPoint(xcoor,ycoor);
    //Run swim function to input CartPoint
    (*fishPtr).start_swimming(destcoor);
}

void do_eat_command(Model& model)
{
    int fishID, reefID;
    cin >> fishID >> reefID;
    //Get pointer to corresponding Fish ID
    Fish* fishPtr = model.get_Fish_ptr(fishID);
    //Get pointer to corresponding Reef ID
    CoralReef* reefPtr = model.get_CoralReef_ptr(reefID);
    //Run eat function to input CoralReef
    (*fishPtr).start_eating(reefPtr);
}

void do_float_command(Model& model)
{
    int fishID;
    cin >> fishID;
    //Get pointer to corresponding Fish ID
    Fish* fishPtr = model.get_Fish_ptr(fishID);
    //Run float function for Fish
    (*fishPtr).float_in_place();
}

void do_zoom_command(Model& model)
{
    int fishID, caveID;
    cin >> fishID >> caveID;
    //Get pointer to corresponding Fish ID
    Fish* fishPtr = model.get_Fish_ptr(fishID);
    //Get pointer to corresponding Cave ID
    Cave* cavePtr = model.get_Cave_ptr(caveID);
    //Run hide function to input Cave
    (*fishPtr).start_hiding(cavePtr);
}

void do_go_command(Model& model)
{
    //Advance one time tick in the game
    cout << "Advancing one tick" << endl;
    model.update();
    model.show_status();
}

void do_run_command(Model& model)
{
    //Advance until something happens (until update returns true or 5 ticks pass)
    cout << "Advancing to next event" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (model.update())
        {
            break;
        }
        else
            continue;
    }
    model.show_status();
}


