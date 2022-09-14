#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:

  long Jiffies();
  long ActiveJiffies();
  long IdleJiffies();

  long prevJiffies_;
  long prevActiveJiffies_;

  std::vector<long> cpuTimes_;
};

#endif
