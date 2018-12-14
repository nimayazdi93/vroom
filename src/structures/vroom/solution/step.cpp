/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "structures/vroom/solution/step.h"

// Dummy initialization value for unused job id.
Step::Step(TYPE type, Location location)
  : type(type), location(location), job(0), service(0), waiting_time(0) {
  assert(type == TYPE::START or type == TYPE::END);
}

Step::Step(const Job& job)
  : type(TYPE::JOB),
    location(job.location),
    job(job.id),
    service(job.service),
    amount(job.amount),
    waiting_time(0) {
}
