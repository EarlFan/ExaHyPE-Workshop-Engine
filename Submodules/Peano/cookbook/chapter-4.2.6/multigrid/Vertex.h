
// This file originally was created by pdt (Peano Development Toolkit) as part
// of a code based upon the Peano project by Tobias Weinzierl. For conditions 
// of distribution and use of this project, please see the copyright notice at
// www.peano-framework.org. Feel free to adopt the license and authorship of 
// this file and your project to your needs as long as the license is in 
// agreement with the original Peano user constraints. A reference to/citation  
// of  Peano and its author is highly appreciated.
#ifndef _MULTIGRID_VERTEX_H_ 
#define _MULTIGRID_VERTEX_H_


#include "multigrid/records/Vertex.h"
#include "peano/grid/Vertex.h"
#include "peano/grid/VertexEnumerator.h"
#include "peano/utils/Globals.h"


namespace multigrid { 
  class Vertex;
      
  /**
   * Forward declaration
   */
  class VertexOperations;
}


/**
 * Blueprint for grid vertex.
 * 
 * This file has originally been created by the PDT and may be manually extended to 
 * the needs of your application. We do not recommend to remove anything!
 */
class multigrid::Vertex: public peano::grid::Vertex< multigrid::records::Vertex > { 
  private: 
    typedef class peano::grid::Vertex< multigrid::records::Vertex >  Base;

    friend class VertexOperations;
  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    Vertex();
    
    /**
     * This constructor should not set any attributes. It is used by the 
     * traversal algorithm whenever it allocates an array whose elements 
     * will be overwritten later anyway.  
     */
    Vertex(const Base::DoNotCallStandardConstructor&);
    
    /**
     * Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it. It is kind of a copy constructor that converts an object which 
     * comprises solely persistent attributes into a full attribute. This very 
     * functionality is implemented within the super type, i.e. this constructor 
     * has to invoke the correponsing super type's constructor and not the super 
     * type standard constructor.
     */
    Vertex(const Base::PersistentVertex& argument);

    void initInnerVertex(double f, const tarch::la::Vector<DIMENSIONS,double>&  fineGridH);
    void initDirichletVertex(double u);

    double getF() const;

    /**
     * This getter is not getR. Instead it returns the
     * residual, i.e. f-Au which is f+r.
     */
    double getResidual() const;
    double getHierarchicalResidual() const;
    double getU() const;
    double getHierarchicalU() const;

    void clearAccumulatedAttributes();

    void performJacobiSmoothingStep( double omega );

    void inject(const Vertex& fineGridVertex);

    void setU( double u );
    void correctU( double u );

    void clearF();
    void clearUUpdate();

    void incF(double value);

    void clearHierarchicalValues();

    void determineUHierarchical(double Pu_3h);

    double getDampingFactorForAdditiveCoarseGridCorrection(double omega) const;
};


#endif
