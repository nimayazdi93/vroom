#ifndef CVRP_OR_OPT_H
#define CVRP_OR_OPT_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "algorithms/local_search/ls_operator.h"

class CVRPOrOpt : public Operator {
protected:
  Gain normal_stored_gain;
  Gain reversed_stored_gain;

  bool reverse_s_edge;

  virtual void compute_gain() override;

public:
  CVRPOrOpt(const Input& input,
            const SolutionState& sol_state,
            RawRoute& s_route,
            Index s_vehicle,
            Index s_rank,
            RawRoute& t_route,
            Index t_vehicle,
            Index t_rank);

  virtual bool is_valid() override;

  virtual void apply() override;

  virtual std::vector<Index> addition_candidates() const override;

  virtual std::vector<Index> update_candidates() const override;
};

#endif
