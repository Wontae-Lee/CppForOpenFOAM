#include <iostream>

class vec
{
  double *data_;
  unsigned size_;

public:
  vec(unsigned size = 3) : size_(size), data_(new double[size]) {}
  virtual ~vec() { delete[] data_; }

  unsigned size() const { return size_; }
  const double *data() { return data_; }

  double &operator[](const int index) { return data_[index]; }
  const double &operator[](const int index) const { return data_[index]; }

  static double dot(const vec &a, const vec &b);
  static double Op(const vec &a, const vec &b, unsigned int index);
  static double dot_recursive(const vec &a, const vec &b);
  friend std::ostream &operator<<(std::ostream &os, vec &v);

  // operator
  // friend 매개변수 안에 모든 클래스 변수에
  // 접근가능하게 해주는구나
  // 문제 7번에 클래스 맴버 함수의 연산자의 매개변수가 2개라서 에러가 발생한다.
  // friend로 치환했다.
  friend vec operator+(const vec &a, const vec &b);
  friend vec operator*(const double &c, const vec &a);
  friend vec operator*(const vec &a, const double &c);
};

double vec::dot(const vec &a, const vec &b)
{
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); ++i)
  {
    sum += a.data_[i] * b.data_[i];
  }
  return sum;
}

double vec::Op(const vec &a, const vec &b, unsigned int index)
{
  if (index == 0)
  {
    return a.data_[0] * b.data_[0];
  }
  else
  {
    return a.data_[index] * b.data_[index] + vec::Op(a, b, index - 1);
  }
}

double vec::dot_recursive(const vec &a, const vec &b)
{
  return vec::Op(a, b, a.size());
}

vec operator+(const vec &a, const vec &b)
{
  vec temp = vec(a.size());
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = a.data_[i] + b.data_[i];
  }
  return temp;
}
vec operator*(const double &c, const vec &a)
{
  vec temp = vec(a.size());
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = c * a.data_[i];
  }
  return temp;
}
vec operator*(const vec &a, const double &c)
{
  vec temp = vec(a.size());
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = a.data_[i] * c;
  }
  return temp;
}

std::ostream &operator<<(std::ostream &os, vec &v)
{
  os << v.size() << "( ";
  for (int i = 0; i < v.size(); ++i)
  {
    os << v[i] << " ";
  }

  os << ")";
  return os;
}

int main(int argc, char **argv)
{
  int dim = 3;
  vec a(dim);
  vec b(dim);

  for (int i = 0; i < dim; ++i)
  {
    a[i] = i + 1;
    b[i] = i + 2;
  }

  //   std::cout << a << std::endl;
  //   std::cout << b << std::endl;
  std::cout << vec::dot(a, b) << std::endl;
  return 0;
}