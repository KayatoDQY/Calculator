#ifndef DOUBLE_CONTAINER_H
#define DOUBLE_CONTAINER_H

#include <vector>

class DoubleContainer {
public:
    DoubleContainer(); // ���캯��
    void add(double num); // ���Ԫ��
    double get_max(); // �������ֵ
    double get_min(); // ������Сֵ
    double get_median(); // ������λ��
    double get_average(); // ����ƽ����
    double get_stddev(); // ���ر�׼��
    double get_sum(); // �����ۼ�ֵ
    double get_product(); // �����۳�ֵ
    int get_size(); // ����������Ԫ�ظ���
    void DoubleContainer::clear();
private:
    std::vector<double> nums; // �洢Ԫ��
};

#endif
