//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "MooseObjectAction.h"

#include "libmesh/fe_type.h"

// Forward declerations
class AddVariableAction;

template <>
InputParameters validParams<AddVariableAction>();

/**
 * Adds nonlinear variable
 */
class AddVariableAction : public MooseObjectAction
{
public:
  /**
   * Class constructor
   */
  AddVariableAction(InputParameters params);

  virtual void act() override;

  /**
   * Get the possible variable families
   * @return MooseEnum with the possible variable families (e.g., LAGRANGE)
   */
  static MooseEnum getNonlinearVariableFamilies();

  /**
   * Get the possible variable orders
   * @return MooseEnum with the possible variable orders (e.g., SECOND)
   */
  static MooseEnum getNonlinearVariableOrders();

  /**
   * determine the FEType by examining family and order in the provided parameters
   */
  static FEType feType(const InputParameters & params);

  /**
   * determine the variable type given an FEType and number of components
   */
  static std::string determineType(const FEType & fe_type, unsigned int components);

protected:
  /**
   * Initialize the action's member variables
   */
  virtual void init();

  /**
   * Adds a nonlinear variable to the system.
   *
   * @param var_name The name of the variable.
   */
  void addVariable(const std::string & var_name);

  /**
   * Create the action to generate the InitialCondition object
   *
   * If the user supplies a value for 'initial_condition' in the input file this
   * method will create the proper InitialCondition object.
   */
  void createInitialConditionAction();

  /**
   * Get the block ids from the input parameters
   * @return A set of block ids defined in the input
   */
  std::set<SubdomainID> getSubdomainIDs();

  /// FEType for the variable being created
  FEType _fe_type;

  /// True if the variable being created is a scalar
  bool _scalar_var;

  /// Number of components for an array variable
  unsigned int _components;

  std::function<void(FEProblemBase &, const std::string &, const std::string &, InputParameters &)>
      _problem_add_var_method;
};
