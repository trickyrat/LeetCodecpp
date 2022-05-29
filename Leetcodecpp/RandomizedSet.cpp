#include "RandomizedSet.h"

bool RandomizedSet::insert(int val) {
  if (indices.count(val)) {
    return false;
  }
  int index = (int)nums.size();
  nums.emplace_back(val);
  indices[val] = index;
	return true;
}

bool RandomizedSet::remove(int val) {
  if (!indices.count(val)) {
    return false;
  }
  int index = (int)indices[val];
  int last = nums.back();
  nums[index] = last;
  indices[last] = index;
  nums.pop_back();
  indices.erase(val);
  return true;
}

int RandomizedSet::getRandom() { 
  std::random_device r;
  std::mt19937 el(r());
  std::uniform_int_distribution<int> uniform_dist(0, int(nums.size()) - 1);
  return nums[uniform_dist(el)];
}
