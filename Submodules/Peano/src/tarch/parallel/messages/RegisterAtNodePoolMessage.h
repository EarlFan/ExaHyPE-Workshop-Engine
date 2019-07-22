#ifndef _TARCH_PARALLEL_MESSAGES_REGISTERATNODEPOOLMESSAGE_H
#define _TARCH_PARALLEL_MESSAGES_REGISTERATNODEPOOLMESSAGE_H

#include "tarch/parallel/MPIConstants.h"
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

namespace tarch {
   namespace parallel {
      namespace messages {
         class RegisterAtNodePoolMessage;
         class RegisterAtNodePoolMessagePacked;
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
 * @date   31/03/2018 19:30
 */
class tarch::parallel::messages::RegisterAtNodePoolMessage { 
   
   public:
      
      typedef tarch::parallel::messages::RegisterAtNodePoolMessagePacked Packed;
      
      struct PersistentRecords {
         tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> _nodeName;
         /**
          * Generated
          */
         PersistentRecords();
         
         /**
          * Generated
          */
         PersistentRecords(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName);
         
          tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> getNodeName() const ;
         
          void setNodeName(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName) ;
         
         
      };
      private: 
         PersistentRecords _persistentRecords;
         
      public:
         /**
          * Generated
          */
         RegisterAtNodePoolMessage();
         
         /**
          * Generated
          */
         RegisterAtNodePoolMessage(const PersistentRecords& persistentRecords);
         
         /**
          * Generated
          */
         RegisterAtNodePoolMessage(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName);
         
         /**
          * Generated
          */
         virtual ~RegisterAtNodePoolMessage();
         
          tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> getNodeName() const ;
         
          void setNodeName(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName) ;
         
          short int getNodeName(int elementIndex) const ;
         
          void setNodeName(int elementIndex, const short int& nodeName) ;
         
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
         RegisterAtNodePoolMessagePacked convert() const;
         
         
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
 * @date   31/03/2018 19:30
 */
class tarch::parallel::messages::RegisterAtNodePoolMessagePacked { 
   
   public:
      
      struct PersistentRecords {
         tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> _nodeName;
         /**
          * Generated
          */
         PersistentRecords();
         
         /**
          * Generated
          */
         PersistentRecords(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName);
         
          tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> getNodeName() const ;
         
          void setNodeName(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName) ;
         
         
      };
      private: 
         PersistentRecords _persistentRecords;
         
      public:
         /**
          * Generated
          */
         RegisterAtNodePoolMessagePacked();
         
         /**
          * Generated
          */
         RegisterAtNodePoolMessagePacked(const PersistentRecords& persistentRecords);
         
         /**
          * Generated
          */
         RegisterAtNodePoolMessagePacked(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName);
         
         /**
          * Generated
          */
         virtual ~RegisterAtNodePoolMessagePacked();
         
          tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int> getNodeName() const ;
         
          void setNodeName(const tarch::la::Vector<MPI_MAX_NAME_STRING_ADDED_ONE,short int>& nodeName) ;
         
          short int getNodeName(int elementIndex) const ;
         
          void setNodeName(int elementIndex, const short int& nodeName) ;
         
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
         RegisterAtNodePoolMessage convert() const;
         
         
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

