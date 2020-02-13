#ifndef __LANCER_H
#define __LANCER_H

#include "job.h"

job_t* initialize_job_lancer();
action_t* initialize_action_stab();
action_t* initialize_action_sweep();
action_t* initialize_action_hook();
action_t* initialize_action_toss();

#endif