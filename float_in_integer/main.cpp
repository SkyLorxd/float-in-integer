#include "myfloat_saturation.cpp"
#include <iostream>


int main(void) {
  myfloat_saturation num_1 = 200.5;
  myfloat_saturation num_2 = -800.5;
  myfloat_saturation num_saturated = 10000;

  num_1.print();
  num_2.print();
  num_saturated.print();

  std::cout << std::endl;

  myfloat_saturation num_3 = num_1 + num_2;
  num_3.print();

  myfloat_saturation num_4 = num_1 - num_2;
  num_4.print();

  myfloat_saturation num_5 = num_1 * num_2;
  num_5.print();
}