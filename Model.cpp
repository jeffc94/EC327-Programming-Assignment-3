//
//  Model.cpp
//  PA3_UnderTheSea
//

#include "Model.h"
#include "Cave.h"
#include "Fish.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "View.h"

//Default constructor
Model::Model()
{
    time = 0;
    this -> num_objects = 7;
    this -> num_fish = 2;
    this -> num_caves = 2;
    this -> num_reefs = 3;
    object_ptrs = new GameObject* [num_objects];
    fish_ptrs = new Fish* [num_fish];
    cave_ptrs = new Cave* [num_caves];
    reef_ptrs = new CoralReef* [num_reefs];
    cave_ptrs[0] = new Cave(1, CartPoint(5,1));
    cave_ptrs[1] = new Cave(2, CartPoint(6,2));
    fish_ptrs[0] = new Fish(1, cave_ptrs[0]);
    fish_ptrs[1] = new Fish(2, cave_ptrs[1]);
    reef_ptrs[0] = new CoralReef(1, CartPoint(1,20));
    reef_ptrs[1] = new CoralReef(2, CartPoint(20,1));
    reef_ptrs[2] = new CoralReef(3, CartPoint(20,20));
    object_ptrs[0] = cave_ptrs[0];
    object_ptrs[1] = cave_ptrs[1];
    object_ptrs[2] = fish_ptrs[0];
    object_ptrs[3] = fish_ptrs[1];
    object_ptrs[4] = reef_ptrs[0];
    object_ptrs[5] = reef_ptrs[1];
    object_ptrs[6] = reef_ptrs[2];
    cout << "Model default constructed" << endl;
}

//Destructor
Model::~Model()
{
    delete [] object_ptrs;
    delete [] fish_ptrs;
    delete [] cave_ptrs;
    delete [] reef_ptrs;
    cout << "Model destructed." << endl;
}

//Get Fish pointer
Fish* Model::get_Fish_ptr(int id_num)
{
    for (int i = 0; i < num_fish; i++)
    {
         if ((*fish_ptrs[i]).get_id() == id_num)
            return fish_ptrs[i];
    }
    return NULL;
}

//Get CoralReef pointer
CoralReef* Model::get_CoralReef_ptr(int id_num)
{
    for (int i = 0; i < num_reefs; i++)
    {
        if ((*reef_ptrs[i]).get_id() == id_num)
            return reef_ptrs[i];
    }
    return NULL;
}

//Get Cave pointer
Cave* Model::get_Cave_ptr(int id_num)
{
    for (int i = 0; i < num_caves; i++)
    {
        if ((*cave_ptrs[i]).get_id() == id_num)
            return cave_ptrs[i];
    }
    return NULL;
}

//Update model
bool Model::update()
{
    time++;
    for (int i = 0; i < num_objects; i++)
    {
        if((*object_ptrs[i]).update())
        {
            for (int j = i + 1; j < num_objects; j++)
            {
                (*object_ptrs[j]).update();
            }
            return true;
        }
    }
    return false;;
}

void Model::display(View& view)
{
    //Display time
    cout << "Time: " << time << endl;
    //Fill array with periods and spaces
    for (int i = 0; i < view_maxsize/2 + 1; i++)
    {
        for (int j = 0; j < view_maxsize/2 + 1; j++)
        {
            char * gridder = view.grid[i][j];
            *gridder = '.';
            *(gridder + 1) = ' ';
        }
    }
    //Plot the GameObjects
    for (int i = 0; i < num_objects; i++)
    {
        view.plot(object_ptrs[i]);
    }
    //Draw grid
    view.draw();
}

//Show status of model
void Model::show_status()
{
    for (int i = 0; i < num_objects; i++)
    {
        (*object_ptrs[i]).show_status();
    }
}
