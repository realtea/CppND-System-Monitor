#include "processor.h"

// TODO: Read and return the number of jiffies for the system
long Processor::Jiffies() {
  return ActiveJiffies() + IdleJiffies();
}

// TODO: Read and return the number of active jiffies for the system
long Processor::ActiveJiffies() {
  return cpuTimes_[LinuxParser::kUser_] + cpuTimes_[LinuxParser::kNice_] + cpuTimes_[LinuxParser::kSystem_] + cpuTimes_[LinuxParser::kIRQ_] + cpuTimes_[LinuxParser::kSoftIRQ_] + cpuTimes_[LinuxParser::kSteal_];
}

// TODO: Read and return the number of idle jiffies for the system
long Processor::IdleJiffies() {
  return cpuTimes_[LinuxParser::kIdle_] + cpuTimes_[LinuxParser::kIOwait_];
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  cpuTimes_ = LinuxParser::CpuUtilization();

  long currJiffies = Jiffies();
  long currActiveJiffies = ActiveJiffies();

  long total_delta = currJiffies - prevJiffies_;
  long active_delta = currActiveJiffies - prevActiveJiffies_;

  prevActiveJiffies_ = currActiveJiffies;
  prevJiffies_ = currJiffies;

  return (active_delta*1.0) / (total_delta*1.0);
}
