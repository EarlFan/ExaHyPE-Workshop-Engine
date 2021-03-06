#ifndef _PEANO_PARALLEL_LOADBALANCING_WORKERENTRY_H
#define _PEANO_PARALLEL_LOADBALANCING_WORKERENTRY_H

#include "peano/utils/Globals.h"
#include "tarch/compiler/CompilerSpecificSettings.h"
#include "peano/utils/PeanoOptimisations.h"
#ifdef Parallel
	#include "tarch/parallel/Node.h"
#endif
#ifdef Parallel
	#include <mpi.h>
#endif
#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"
#include <bitset>
#include <complex>
#include <string>
#include <iostream>

namespace peano {
   namespace parallel {
      namespace loadbalancing {
         class WorkerEntry;
         class WorkerEntryPacked;
      }
   }
}

/**
 * @author This class is generated by DaStGen
 * 		   DataStructureGenerator (DaStGen)
 * 		   2007-2009 Wolfgang Eckhardt
 * 		   2012      Tobias Weinzierl
 *
 * 		   build date: 09-02-2014 14:40
 *
 * @date   31/03/2018 16:42
 */
class peano::parallel::loadbalancing::WorkerEntry { 
   
   public:
      
      typedef peano::parallel::loadbalancing::WorkerEntryPacked Packed;
      
      struct PersistentRecords {
         int _rank;
         int _level;
         tarch::la::Vector<DIMENSIONS,double> _boundingBoxOffset;
         tarch::la::Vector<DIMENSIONS,double> _boundingBoxSize;
         /**
          * Generated
          */
         PersistentRecords();
         
         /**
          * Generated
          */
         PersistentRecords(const int& rank, const int& level, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize);
         
         /**
          * Generated
          */
          int getRank() const ;
         
         /**
          * Generated
          */
          void setRank(const int& rank) ;
         
         /**
          * Generated
          */
          int getLevel() const ;
         
         /**
          * Generated
          */
          void setLevel(const int& level) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxOffset() const ;
         
          void setBoundingBoxOffset(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxSize() const ;
         
          void setBoundingBoxSize(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize) ;
         
         
      };
      private: 
         public:   // change to public visibiliy as some fields are exposed 

         PersistentRecords _persistentRecords;
         private:

         
      public:
         /**
          * Generated
          */
         WorkerEntry();
         
         /**
          * Generated
          */
         WorkerEntry(const PersistentRecords& persistentRecords);
         
         /**
          * Generated
          */
         WorkerEntry(const int& rank, const int& level, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize);
         
         /**
          * Generated
          */
         virtual ~WorkerEntry();
         
         /**
          * Generated
          */
          int getRank() const ;
         
         /**
          * Generated
          */
          void setRank(const int& rank) ;
         
         /**
          * Generated
          */
          int getLevel() const ;
         
         /**
          * Generated
          */
          void setLevel(const int& level) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxOffset() const ;
         
          void setBoundingBoxOffset(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset) ;
         
          double getBoundingBoxOffset(int elementIndex) const ;
         
          void setBoundingBoxOffset(int elementIndex, const double& boundingBoxOffset) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxSize() const ;
         
          void setBoundingBoxSize(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize) ;
         
          double getBoundingBoxSize(int elementIndex) const ;
         
          void setBoundingBoxSize(int elementIndex, const double& boundingBoxSize) ;
         
         /**
          * Generated
          */
         std::string toString() const;
         
         /**
          * Generated
          */
         void toString(std::ostream& out) const;
         
         
         PersistentRecords getPersistentRecords() const;
         /**
          * Generated
          */
         WorkerEntryPacked convert() const;
         
         
      #ifdef Parallel
         protected:
            static tarch::logging::Log _log;
            
            int _senderDestinationRank;
            
         public:
            
            /**
             * Global that represents the mpi datatype.
             * There are two variants: Datatype identifies only those attributes marked with
             * parallelise. FullDatatype instead identifies the whole record with all fields.
             */
            static MPI_Datatype Datatype;
            static MPI_Datatype FullDatatype;
            
            /**
             * Initializes the data type for the mpi operations. Has to be called
             * before the very first send or receive operation is called.
             */
            static void initDatatype();
            
            static void shutdownDatatype();
            
            enum class ExchangeMode { Blocking, NonblockingWithPollingLoopOverTests, LoopOverProbeWithBlockingReceive };
            
            void send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, ExchangeMode mode );
            
            void receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, ExchangeMode mode );
            
            static bool isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise);
            
            int getSenderRank() const;
            #endif
   
};

/**
 * @author This class is generated by DaStGen
 * 		   DataStructureGenerator (DaStGen)
 * 		   2007-2009 Wolfgang Eckhardt
 * 		   2012      Tobias Weinzierl
 *
 * 		   build date: 09-02-2014 14:40
 *
 * @date   31/03/2018 16:42
 */
class peano::parallel::loadbalancing::WorkerEntryPacked { 
   
   public:
      
      struct PersistentRecords {
         int _rank;
         int _level;
         tarch::la::Vector<DIMENSIONS,double> _boundingBoxOffset;
         tarch::la::Vector<DIMENSIONS,double> _boundingBoxSize;
         /**
          * Generated
          */
         PersistentRecords();
         
         /**
          * Generated
          */
         PersistentRecords(const int& rank, const int& level, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize);
         
         /**
          * Generated
          */
          int getRank() const ;
         
         /**
          * Generated
          */
          void setRank(const int& rank) ;
         
         /**
          * Generated
          */
          int getLevel() const ;
         
         /**
          * Generated
          */
          void setLevel(const int& level) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxOffset() const ;
         
          void setBoundingBoxOffset(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxSize() const ;
         
          void setBoundingBoxSize(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize) ;
         
         
      };
      private: 
         PersistentRecords _persistentRecords;
         
      public:
         /**
          * Generated
          */
         WorkerEntryPacked();
         
         /**
          * Generated
          */
         WorkerEntryPacked(const PersistentRecords& persistentRecords);
         
         /**
          * Generated
          */
         WorkerEntryPacked(const int& rank, const int& level, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset, const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize);
         
         /**
          * Generated
          */
         virtual ~WorkerEntryPacked();
         
         /**
          * Generated
          */
          int getRank() const ;
         
         /**
          * Generated
          */
          void setRank(const int& rank) ;
         
         /**
          * Generated
          */
          int getLevel() const ;
         
         /**
          * Generated
          */
          void setLevel(const int& level) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxOffset() const ;
         
          void setBoundingBoxOffset(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset) ;
         
          double getBoundingBoxOffset(int elementIndex) const ;
         
          void setBoundingBoxOffset(int elementIndex, const double& boundingBoxOffset) ;
         
          tarch::la::Vector<DIMENSIONS,double> getBoundingBoxSize() const ;
         
          void setBoundingBoxSize(const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize) ;
         
          double getBoundingBoxSize(int elementIndex) const ;
         
          void setBoundingBoxSize(int elementIndex, const double& boundingBoxSize) ;
         
         /**
          * Generated
          */
         std::string toString() const;
         
         /**
          * Generated
          */
         void toString(std::ostream& out) const;
         
         
         PersistentRecords getPersistentRecords() const;
         /**
          * Generated
          */
         WorkerEntry convert() const;
         
         
      #ifdef Parallel
         protected:
            static tarch::logging::Log _log;
            
            int _senderDestinationRank;
            
         public:
            
            /**
             * Global that represents the mpi datatype.
             * There are two variants: Datatype identifies only those attributes marked with
             * parallelise. FullDatatype instead identifies the whole record with all fields.
             */
            static MPI_Datatype Datatype;
            static MPI_Datatype FullDatatype;
            
            /**
             * Initializes the data type for the mpi operations. Has to be called
             * before the very first send or receive operation is called.
             */
            static void initDatatype();
            
            static void shutdownDatatype();
            
            enum class ExchangeMode { Blocking, NonblockingWithPollingLoopOverTests, LoopOverProbeWithBlockingReceive };
            
            void send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, ExchangeMode mode );
            
            void receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, ExchangeMode mode );
            
            static bool isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise);
            
            int getSenderRank() const;
            #endif
   
};

#endif

