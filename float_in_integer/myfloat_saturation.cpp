#include "myfloat_saturation.h"
#include <cmath>

myfloat_saturation::myfloat_saturation(myfloat MyFloat) : myfloat(MyFloat){ // Конструктор для проверки насыщенности числа
    saturation_flag = false;
    if(e>12){
        saturation_flag = true;
        m>0?m=10000:m=-10000;
        e = 13;
    }
}

myfloat_saturation::myfloat_saturation(double num) : myfloat_saturation(myfloat(num)){ // Основной конструктор
}


myfloat_saturation operator+(myfloat_saturation float_1, myfloat_saturation float_2) {
    if (float_1.saturation_flag) return float_1;
    if (float_2.saturation_flag) return float_2;
    return myfloat_saturation((myfloat)float_1 + (myfloat)float_2); 
}

myfloat_saturation operator-(myfloat_saturation float_1, myfloat_saturation float_2){
    if (float_1.saturation_flag) return float_1;
    if (float_2.saturation_flag) return float_2.m>0?float_2.m*=(-1):float_2;
    return myfloat_saturation((myfloat)float_1 - (myfloat)float_2); 
}

myfloat_saturation operator*(myfloat_saturation float_1, myfloat_saturation float_2){
    if (float_1.saturation_flag) return float_1;
    if (float_2.saturation_flag) return float_2;
    return myfloat_saturation((myfloat)float_1 * (myfloat)float_2); 
}

void myfloat_saturation::print(){ // Функция вывода в формате: (мантиса чиса,экспонента числа[само число]), в случае насыщения выводится (мантиса чиса,экспонента[*само число])
    if (saturation_flag) printf("%d,%d[*%f] ", m, e, m / 10000.0 * pow(2, e));
    else printf("%d,%d[%f] ", m, e, m / 10000.0 * pow(2, e));
    }