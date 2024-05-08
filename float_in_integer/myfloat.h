class myfloat { //Класс, хранящий числа с плавующей точкой в виде двух целочисленных значений (точность ограничена 4-мя знаками)
protected:
  int m;
  int e;
  int equate(myfloat);

public:
  myfloat(double num = 0);
  myfloat(int m1, int e1);
  void print();
  friend myfloat operator+(myfloat, myfloat);
  friend myfloat operator-(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
  friend myfloat operator*(myfloat, myfloat);
};
