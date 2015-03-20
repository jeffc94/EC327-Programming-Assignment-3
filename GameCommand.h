//
//  GameCommand.h
//  PA3_UnderTheSea
//

#ifndef __GameCommand__
#define __GameCommand__

#include "Model.h"

void do_swim_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_eat_command(Model& model);
void do_float_command(Model& model);
void do_zoom_command(Model& model);

#endif /* defined(__GameCommand__) */
