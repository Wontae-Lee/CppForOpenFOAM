template <typename T>
class VectorSpace
{
private:
  T comp_;

public:
  VectorSpace() {}

  // type casting operator
  operator T() { return comp_; }
  // stream out
  friend std::ostream &operator<<(std::ostream &os, const VectorSpace &A)
  {
    os << A.comp_;
    return os;
  }

  // vector space operation
  friend T operator+(const VectorSpace &A, const VectorSpace &B)
  {
    return A.comp_ + B.comp_;
  }

  friend T operator*(const VectorSpace &A, const double &c)
  {
    return A.comp_ * c;
  }
};