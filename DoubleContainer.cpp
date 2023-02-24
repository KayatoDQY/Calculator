#include "pch.h"
#include "DoubleContainer.h"
#include <algorithm>
#include <cmath>

DoubleContainer::DoubleContainer() {}

void DoubleContainer::add(double num) {
    nums.push_back(num);
}

double DoubleContainer::get_max() {
    if (nums.empty()) {
        return NAN;
    }
    return *std::max_element(nums.begin(), nums.end());
}

double DoubleContainer::get_min() {
    if (nums.empty()) {
        return NAN;
    }
    return *std::min_element(nums.begin(), nums.end());
}

double DoubleContainer::get_median() {
    if (nums.empty()) {
        return NAN;
    }
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2;
    }
    else {
        return nums[n / 2];
    }
}

double DoubleContainer::get_average() {
    if (nums.empty()) {
        return NAN;
    }
    double sum = 0;
    for (double num : nums) {
        sum += num;
    }
    return sum / nums.size();
}

double DoubleContainer::get_stddev() {
    if (nums.empty()) {
        return NAN;
    }
    double mean = get_average();
    double var = 0;
    for (double num : nums) {
        var += (num - mean) * (num - mean);
    }
    return sqrt(var / nums.size());
}

double DoubleContainer::get_sum() {
    if (nums.empty()) {
        return NAN;
    }
    double sum = 0;
    for (double num : nums) {
        sum += num;
    }
    return sum;
}

double DoubleContainer::get_product() {
    if (nums.empty()) {
        return NAN;
    }
    double product = 1;
    for (double num : nums) {
        product *= num;
    }
    return product;
}

int DoubleContainer::get_size() {
    return nums.size();
}

void DoubleContainer::clear() {
    nums.clear();
}