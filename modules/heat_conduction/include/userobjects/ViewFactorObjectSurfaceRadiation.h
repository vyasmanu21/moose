//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "GrayLambertSurfaceRadiationBase.h"

// Forward Declarations
class ViewFactorObjectSurfaceRadiation;
class ViewFactorBase;

template <>
InputParameters validParams<ViewFactorObjectSurfaceRadiation>();

/**
 * ViewFactorObjectSurfaceRadiation computes radiative heat transfer between
 * side sets and the view factors are computed by a ViewFactor object
 */
class ViewFactorObjectSurfaceRadiation : public GrayLambertSurfaceRadiationBase
{
public:
  ViewFactorObjectSurfaceRadiation(const InputParameters & parameters);

protected:
  virtual std::vector<std::vector<Real>> setViewFactors() override;
};
