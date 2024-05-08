#include "myfloat.cpp"

class myfloat_saturation : public myfloat //Класс, хранящий числа с плавующей точкой в виде двух целочисленных значений, имеющий логику насыщения (предельные значения +-2^13)
{
private:
    bool saturation_flag;
public:
    myfloat_saturation(myfloat);
    myfloat_saturation(double num);
    void print();
    friend myfloat_saturation operator+(myfloat_saturation, myfloat_saturation);
    friend myfloat_saturation operator-(myfloat_saturation, myfloat_saturation);
    friend myfloat_saturation operator*(myfloat_saturation, myfloat_saturation);
};
