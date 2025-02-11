//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "GeneralPostprocessor.h"

class ViewFactorPP;
class ViewFactorBase;

template <>
InputParameters validParams<ViewFactorPP>();

/**
 * This postprocessor allows to extract view factors from ViewFactor userobjects
 */
class ViewFactorPP : public GeneralPostprocessor
{
public:
  ViewFactorPP(const InputParameters & parameters);

  virtual void initialize() override {}
  virtual void execute() override {}
  virtual PostprocessorValue getValue() override;

protected:
  const ViewFactorBase & _vf_uo;
  const BoundaryID _from_bnd_id;
  const BoundaryID _to_bnd_id;
};
