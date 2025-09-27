#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <vector>
#include <algorithm>
#include "leftover_record.h"

// Please fill in below.
// Madhavan Iyer
// 121L-01
// 04/15/24
// Madhavani@csu.fullerton.edu
// madiiyer

class LeftoverReport {
 public:
  LeftoverReport() {}
  LeftoverReport(std::vector<LeftoverRecord> inputRecords)
      : records(inputRecords) {}

  std::vector<std::string> getMostCommonLeftovers() const {
    std::map<std::string, int> frequency;
    for (const auto& record : records) {
      frequency[record.getFoodName()]++;
    }

    std::vector<std::string> mostCommonLeftovers;
    int maxFrequency = 0;
    for (const auto& pair : frequency) {
      if (pair.second > maxFrequency) {
        mostCommonLeftovers.clear();
        mostCommonLeftovers.push_back(pair.first);
        maxFrequency = pair.second;
      } else if (pair.second == maxFrequency) {
        mostCommonLeftovers.push_back(pair.first);
      }
    }
    return mostCommonLeftovers;
  }

  // Most costly leftover producing meals
  std::vector<std::string> getMostCostlyMeals() const {
    std::map<std::string, double> totalCost;
    std::map<std::string, double> mealCost;

    for (auto record : records) {
      mealCost[record.getMeal()] += record.getCost();
    }

    double maxCost = 0.0;
    std::vector<std::string> mostCostlyMeals;

    for (auto pair : mealCost) {
      if (pair.second > maxCost) {
        mostCostlyMeals.clear();
        mostCostlyMeals.push_back(pair.first);
        maxCost = pair.second;
      } else if (pair.second == maxCost) {
        mostCostlyMeals.push_back(pair.first);
      }
    }
    return mostCostlyMeals;
  }

  double getTotalCostPerMeal() const {
    double totalCost = 0.0;
    for (const auto& record : records) {
      totalCost += record.getCost();
    }
    return totalCost;
  }

  std::vector<std::string> getMostCommonLeftoverReasons() const {
    std::map<std::string, int> frequency;
    for (auto record : records) {
      frequency[record.getLeftoverReason()]++;
    }

    std::vector<std::string> mostCommonReasons;
    int maxFrequency = 0;
    for (auto pair : frequency) {
      if (pair.second > maxFrequency) {
        mostCommonReasons.clear();
        mostCommonReasons.push_back(pair.first);
        maxFrequency = pair.second;
      } else if (pair.second == maxFrequency) {
        mostCommonReasons.push_back(pair.first);
      }
    }
    return mostCommonReasons;
  }

  std::vector<std::string> getMostCommonDisposalMechanisms() const {
    std::map<std::string, int> frequency;
    for (auto record : records) {
      frequency[record.getDisposalMechanism()]++;
    }

    std::vector<std::string> mostCommonMechanisms;
    int maxFrequency = 0;
    for (auto pair : frequency) {
      if (pair.second > maxFrequency) {
        mostCommonMechanisms.clear();
        mostCommonMechanisms.push_back(pair.first);
        maxFrequency = pair.second;
      } else if (pair.second == maxFrequency) {
        mostCommonMechanisms.push_back(pair.first);
      }
    }
    return mostCommonMechanisms;
  }

  std::vector<std::string> getSuggestedStrategies() const {
    std::vector<std::string> strategies;
    std::vector<std::string> common_reasons = getMostCommonLeftoverReasons();
    if (common_reasons.empty()) {
        return strategies;
    }

    for (const std::string &reason : common_reasons) {
        if (reason == "Expired") {
            if (std::find(strategies.begin(), strategies.end(),
                       "Donate before expiration") == strategies.end()) {
            strategies.push_back("Donate before expiration");
            }
        }
        if (reason == "Tastes bad") {
            if (std::find(strategies.begin(), strategies.end(),
                "Try buying less food") == strategies.end()) {
                strategies.push_back("Buy less food");
            }
        }
        if (reason == "Too much left overs") {
            if (std::find(strategies.begin(), strategies.end(), "Buy less food") ==
                strategies.end()) {
            strategies.push_back("Buy less food");
            }
            if (std::find(strategies.begin(), strategies.end(),
                          "Cook small servings") == strategies. end()) {
                strategies.push_back("Cook small servings");
            }
        }
    }
    if (std::find(strategies.begin(), strategies.end(),
                  "Donate before expiration") == strategies.end()) {
        strategies.push_back("Recycle left overs");
                  }
    return strategies;
  }

 private:
  std::vector<LeftoverRecord> records;
};

#endif
