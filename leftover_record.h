#ifndef LEFTOVER_RECORD_H_
#define LEFTOVER_RECORD_H_
#include <iostream>
#include <memory>

// Please fill in below.
// Madhavan Iyer
// 121L-01
// 04/15/24
// Madhavani@csu.fullerton.edu
// madiiyer

class LeftoverRecord {
  // ======================= YOUR CODE HERE =======================
  // Write the LeftoverRecord class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  LeftoverRecord() {}
  LeftoverRecord(const std::string& date, const std::string& meal,
                 const std::string& foodName, double quantity,
                 const std::string& reason, const std::string& mechanism,
                 double cost)
      : Date(date),
        Meal(meal),
        FoodName(foodName),
        QuantityInOunces(quantity),
        LeftoverReason(reason),
        DisposalMechanism(mechanism),
        Cost(cost) {}

  std::string getDate() const { return Date; }
  std::string getMeal() const { return Meal; }
  std::string getFoodName() const { return FoodName; }
  double getQuantityInOunces() const { return QuantityInOunces; }
  std::string getLeftoverReason() const { return LeftoverReason; }
  std::string getDisposalMechanism() const { return DisposalMechanism; }
  double getCost() const { return Cost; }

  void setDate(const std::string& date) { Date = date; }
  void setMeal(const std::string& meal) { Meal = meal; }
  void setFoodName(const std::string& foodName) { FoodName = foodName; }
  void setQuantityInOunces(double quantity) { QuantityInOunces = quantity; }
  void setLeftoverReason(const std::string& reason) { LeftoverReason = reason; }
  void setDisposalMechanism(const std::string& mechanism) {
    DisposalMechanism = mechanism;
  }
  void setCost(double cost) { Cost = cost; }

 private:
  std::string Date;
  std::string Meal;
  std::string FoodName;
  double QuantityInOunces;
  std::string LeftoverReason;
  std::string DisposalMechanism;
  double Cost;
};

bool operator==(LeftoverRecord lhs, LeftoverRecord rhs);
#endif
