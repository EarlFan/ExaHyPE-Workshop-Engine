# .bashrc
test -s ~/.alias && . ~/.alias || true

export COMPILER_CFLAGS="-g -DnoMultipleThreadsMayTriggerMPICalls -DnoMPIUsesItsOwnThread -DnoParallelExchangePackedRecordsAtBoundary -DnoParallelExchangePackedRecordsBetweenMasterAndWorker -DnoParallelExchangePackedRecordsInHeaps -DnoParallelExchangePackedRecordsThroughoutJoinsAndForks"
export COMPILER_LFLAGS="-g -ltbb"

export LANG=en_US.utf8
export SHAREDMEM=TBB
export DISTRIBUTEDMEM=MPI
export COMPILER=Intel
export EXAHYPE_CC=mpiicpc

module switch intel/19.0
module switch mpi.intel/2019
module load tbb/2019
module load python/3.5_intel
module load gcc




