#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_
#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "leftover_report.h"

// Please fill in below.
// Madhavan Iyer
// 121L-01
// 04/15/24
// Madhavani@csu.fullerton.edu
// madiiyer

class LeftoverTracker {
 public:
  LeftoverTracker() {}
  LeftoverTracker(std::vector<LeftoverRecord> initialRecords)
      : records(initialRecords) {}

  bool addRecord(LeftoverRecord record) {
    // Check if the record already exists
    for (const auto& existingRecord : records) {
      // Compare each attribute of the existing record with the new record
      if (existingRecord == record) {
        return false;  // Record already exists
      }
    }

    records.push_back(record);
    return true;  // Record added successfully
  }

  bool deleteRecord(LeftoverRecord recordToDelete) {
    for (auto it = records.begin(); it != records.end(); ++it) {
      LeftoverRecord currentRecord = *it;
      if (currentRecord == recordToDelete) {
        records.erase(it);
        return true;  // Record deleted successfully
      }
    }
    return false;  // Record not found
  }
  std::vector<LeftoverRecord> getAllLeftoverRecords() const { return records; }

  LeftoverReport generateLeftoverReport() const {
    return LeftoverReport(records);
  }

 private:
  std::vector<LeftoverRecord> records;
};

#endif