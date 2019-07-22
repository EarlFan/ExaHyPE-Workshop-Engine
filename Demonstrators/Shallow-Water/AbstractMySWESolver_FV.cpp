// This file is generated by the ExaHyPE toolkit.
// Please do not modify - it will be overwritten by the next
// ExaHyPE toolkit call.
// 
// ========================
//   www.exahype.eu
// ========================
#include "AbstractMySWESolver_FV.h"

#include "kernels/finitevolumes/commons/c/commons.h"
#include "kernels/finitevolumes/godunov/c/godunov.h"
#include "kernels/finitevolumes/riemannsolvers/c/riemannsolvers.h"

#include "MySWESolver_FV.h" // Have to include a proper declaration. Cannot use forward declared classes in static_cast.

#include <stdio.h>
#include <cstdlib> // abort()
#include "kernels/KernelUtils.h" // icellSize

#include "exahype/disableOptimization.h" // we experience compiler bugs sometimes.

SWE::MySWESolver_FV::MySWESolver_FV(const double maximumMeshSize,const exahype::solvers::Solver::TimeStepping timeStepping):
  AbstractMySWESolver_FV::AbstractMySWESolver_FV(maximumMeshSize,timeStepping) {
}

SWE::AbstractMySWESolver_FV::AbstractMySWESolver_FV(const double maximumMeshSize,const exahype::solvers::Solver::TimeStepping timeStepping):
exahype::solvers::FiniteVolumesSolver("MySWESolver_FV",NumberOfVariables,NumberOfParameters,NumberOfGlobalObservables, PatchSize,
                                        GhostLayerWidth,maximumMeshSize,timeStepping) {
}

void SWE::AbstractMySWESolver_FV::constantsToString(std::ostream& os) {
	// This string is used in the --version output to identify compile time constants
	os << "SWE::AbstractMySWESolver_FV("
	   << "nVar=" << NumberOfVariables << ", "
	   << "nParam=" << NumberOfParameters << ", "
	   << "PatchSize=" << PatchSize << ", "
	   << "GhostLayerWidth=" << GhostLayerWidth
	   << ")";
}

void SWE::AbstractMySWESolver_FV::abortWithMsg(const char* const msg) {
	// verbosily fail even without assertions turned on
	puts(msg);
	abort();
}

void SWE::AbstractMySWESolver_FV::solutionUpdate(double* luh,const tarch::la::Vector<DIMENSIONS,double>& cellCenter,const tarch::la::Vector<DIMENSIONS,double>& cellSize,const double t, const double dt,double& maxAdmissibleDt) {
  maxAdmissibleDt = kernels::finitevolumes::godunov::c::solutionUpdate<
    false, true, true, false, false,
    kernels::finitevolumes::commons::c::minmod,
    MySWESolver_FV
    >(*static_cast<MySWESolver_FV*>(this),luh,cellCenter,cellSize,t,dt);
}


double SWE::AbstractMySWESolver_FV::stableTimeStepSize(const double* const luh,const tarch::la::Vector<DIMENSIONS,double>& cellSize) {
  double maxAdmissibleDt = kernels::finitevolumes::commons::c::stableTimeStepSize<MySWESolver_FV,false>(*static_cast<MySWESolver_FV*>(this),luh,cellSize);
  return maxAdmissibleDt;
}

void SWE::AbstractMySWESolver_FV::adjustSolution(double* const luh,const tarch::la::Vector<DIMENSIONS,double>& cellCentre,const tarch::la::Vector<DIMENSIONS,double>& cellSize,const double t,const double dt) {
  kernels::finitevolumes::commons::c::solutionAdjustment<MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this),luh,cellCentre,cellSize,t,dt);
}

void SWE::AbstractMySWESolver_FV::boundaryConditions(double* const luh,const tarch::la::Vector<DIMENSIONS,double>& cellCentre,const tarch::la::Vector<DIMENSIONS,double>& cellSize,const double t,const double dt,const tarch::la::Vector<DIMENSIONS, int>& posCell,const tarch::la::Vector<DIMENSIONS, int>& posBoundary) {
  constexpr int cellsPerFace = PatchSize*GhostLayerWidth;
  double luhbndInside [(NumberOfVariables+NumberOfParameters)*cellsPerFace];
  double luhbndOutside[(NumberOfVariables+NumberOfParameters)*cellsPerFace];
  
  const int direction   = tarch::la::equalsReturnIndex(posCell, posBoundary);
  const int orientation = (1 + posBoundary(direction) - posCell(direction))/2;
  const int faceIndex   = 2*direction+orientation;
  
  boundaryLayerExtraction(luhbndInside,luh,posBoundary-posCell);
  kernels::finitevolumes::commons::c::boundaryConditions<MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this),luhbndOutside,luhbndInside,cellCentre,cellSize,t,dt,faceIndex,direction);
  ghostLayerFillingAtBoundary(luh,luhbndOutside,posBoundary-posCell);
}


void SWE::AbstractMySWESolver_FV::ghostLayerFilling(double* const luh,const double* const luhNeighbour,const tarch::la::Vector<DIMENSIONS,int>& neighbourPosition) {
  kernels::finitevolumes::commons::c::ghostLayerFilling<MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this),luh,luhNeighbour,neighbourPosition);
}

void SWE::AbstractMySWESolver_FV::ghostLayerFillingAtBoundary(double* const luh,const double* const luhbnd,const tarch::la::Vector<DIMENSIONS,int>& boundaryPosition) {
  kernels::finitevolumes::commons::c::ghostLayerFillingAtBoundary<MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this),luh,luhbnd,boundaryPosition);
}

void SWE::AbstractMySWESolver_FV::boundaryLayerExtraction(double* const luhbnd,const double* const luh,const tarch::la::Vector<DIMENSIONS,int>& boundaryPosition) {
  kernels::finitevolumes::commons::c::boundaryLayerExtraction<MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this),luhbnd,luh,boundaryPosition);
}


double SWE::AbstractMySWESolver_FV::riemannSolver(double* fL, double *fR, const double* qL, const double* qR, const double* gradQL, const double* gradQR, const double* cellSize, int direction) {
  // Default FV Riemann Solver
  return kernels::finitevolumes::riemannsolvers::c::rusanov<true, true, false, MySWESolver_FV>(*static_cast<MySWESolver_FV*>(this), fL,fR,qL,qR,gradQL, gradQR, cellSize, direction);

}


std::vector<double> SWE::AbstractMySWESolver_FV::mapGlobalObservables(const double* const Q, const tarch::la::Vector<DIMENSIONS, double> &cellSize) const {
  return {};
}

std::vector<double> SWE::AbstractMySWESolver_FV::resetGlobalObservables() const {
  return {};
}

void SWE::AbstractMySWESolver_FV::reduceGlobalObservables(
	std::vector<double>& reducedGlobalObservables,
	const std::vector<double>& curGlobalObservables) const {
  // NOP
}

/**
 * Fallback implementations of joined functions. Users can either safely ignore this
 * or overwrite with their own implementations.
 **/
 // @todo Can we remove this one?
#include "kernels/fusedMethods.cpph"