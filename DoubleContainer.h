#ifndef DOUBLE_CONTAINER_H
#define DOUBLE_CONTAINER_H

#include <vector>

class DoubleContainer {
public:
    DoubleContainer(); // 构造函数
    void add(double num); // 添加元素
    double get_max(); // 返回最大值
    double get_min(); // 返回最小值
    double get_median(); // 返回中位数
    double get_average(); // 返回平均数
    double get_stddev(); // 返回标准差
    double get_sum(); // 返回累加值
    double get_product(); // 返回累乘值
    int get_size(); // 返回容器内元素个数
    void DoubleContainer::clear();
private:
    std::vector<double> nums; // 存储元素
};

#endif
