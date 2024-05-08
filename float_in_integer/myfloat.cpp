#include "myfloat.h"
#include <stdio.h>
#include <math.h>

myfloat::myfloat(double num){ // Основной конструктор
  e = 0;
  if (num == 0){
    m = 0;
    return;
  }
  while (abs(num) >= 1.0)
  {
    num /= 2;
    e++;
  }
  while (abs(num) < 0.5)
  {
    num *= 2;
    e--;
  }

m = (int)(num * 10000);
}

myfloat::myfloat(int m1, int e1){ // Конструктор для получения мантисы от 5000 до 10000
  e = 0;
  if (m1 == 0) return;
  while (abs(m1) >= 10000)
  {
    m1 /= 2;
    e1++;
  }
  while (abs(m1) < 5000)
  {
    m1 *= 2;
    e1--;
  }
m = m1;
e = e1;
}

void myfloat::print(){ printf("%d,%d[%f] ", m, e, m / 10000.0 * pow(2, e));} // Функция вывода в формате (мантиса чиса,экспонента числа[само число])

int myfloat::equate(myfloat float_2){ //Функция приведения экспонент
  if (e < float_2.e)
  {
    while (e != float_2.e)
    {
      float_2.m *= 2;
      float_2.e--;
    }
  }
  return float_2.m;
}

myfloat operator+(myfloat float_1, myfloat float_2){
  int e3, m3;
  float_1.e < float_2.e ? e3 = float_1.e : e3 = float_2.e;
  m3 = float_1.equate(float_2) + float_2.equate(float_1);
  return myfloat(m3, e3);
}

myfloat operator-(myfloat float_1, myfloat float_2){
  int e3, m3;
  float_1.e < float_2.e ? e3 = float_1.e : e3 = float_2.e;
  m3 = float_2.equate(float_1) - float_1.equate(float_2);
  return myfloat(m3, e3);
}

myfloat operator*(myfloat float_1, myfloat float_2){
  int e3, m3;
  e3 = float_1.e + float_2.e;
  m3 = float_1.m*float_2.m/10000;
  return myfloat(m3, e3);
}