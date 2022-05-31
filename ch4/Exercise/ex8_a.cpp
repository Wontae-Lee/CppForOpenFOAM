#include <iostream>

template <typename T, unsigned Dim = 3>
class Vector
{
  double *data_;
  unsigned size_;

public:
  Vector() : size_(Dim), data_(new double[Dim]) {}
  virtual ~Vector() { delete[] data_; }

  unsigned size() const { return size_; }
  const T *data() { return data_; }

  T &operator[](const int index) { return data_[index]; }
  const T &operator[](const int index) const { return data_[index]; }

  static T dot(const Vector &a, const Vector &b);
  static T Op(const Vector &a, const Vector &b, unsigned int index);
  static T dot_recursive(const Vector &a, const Vector &b);
  friend std::ostream &operator<<(std::ostream &os, Vector<T, Dim> &v);

  // operator
  // friend 매개변수 안에 모든 클래스 변수에
  // 접근가능하게 해주는구나
  // 문제 7번에 클래스 맴버 함수의 연산자의 매개변수가 2개라서 에러가 발생한다.
  // friend로 치환했다.
  friend Vector operator+(const Vector &a, const Vector &b);
  friend Vector operator*(const double &c, const Vector &a);
  friend Vector operator*(const Vector &a, const double &c);
};
template <typename T, unsigned Dim>
T Vector<T, Dim>::dot(const Vector &a, const Vector &b)
{
  T sum = 0.0;
  for (unsigned int i = 0; i < a.size(); ++i)
  {
    sum += a.data_[i] * b.data_[i];
  }
  return sum;
}
template <typename T, unsigned Dim>
T Vector<T, Dim>::Op(const Vector &a, const Vector &b, unsigned int index)
{
  if (index == 0)
  {
    return a.data_[0] * b.data_[0];
  }
  else
  {
    return a.data_[index] * b.data_[index] + Vector<T, Dim>::Op(a, b, index - 1);
  }
}
template <typename T, unsigned Dim>
T Vector<T, Dim>::dot_recursive(const Vector &a, const Vector &b)
{
  return Vector<T, Dim>::Op(a, b, a.size());
}

template <typename T, unsigned Dim>
Vector<T, Dim> operator+(const Vector<T, Dim> &a, const Vector<T, Dim> &b)
{
  Vector<T, a.size_> temp;
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = a.data_[i] + b.data_[i];
  }
  return temp;
}

template <typename T, unsigned Dim>
Vector<T, Dim> operator*(const Vector<T, Dim> &a, const double &c)
{
  Vector<T, a.size_> temp;
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = c * a.data_[i];
  }
  return temp;
}
template <typename T, unsigned Dim>
Vector<T, Dim> operator*(const double &c, const Vector<T, Dim> &a)
{
  Vector<T, a.size_> temp;
  for (unsigned int i = 0; i != a.size(); ++i)
  {
    temp.data_[i] = c * a.data_[i];
  }
  return temp;
}
template <typename T, unsigned Dim>
std::ostream &operator<<(std::ostream &os, Vector<T, Dim> &v)
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
  Vector<double, 3> a;
  Vector<double, 3> b;

  for (int i = 0; i < dim; ++i)
  {
    a[i] = i * 1;
    b[i] = i * 2;
  }

  //   std::cout << a << std::endl;
  //   std::cout << b << std::endl;
  std::cout << Vector<double, 3>::dot(a, b) << std::endl;
  return 0;
}