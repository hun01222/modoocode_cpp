#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD{
  static const int value = GCD<X, X&Y>::value;
};

template <int X>
struct GCD<X, 0>{
  static const int value = X;
};

template <int N, int D = 1>
struct Ratio{
 private:
  const static int _gcd = GCD<N, D>::value;

 public:
  typedef Ratio<N/_gcd, D/_gcd> type;
  static const int num = N/_gcd;
  static const int den = D/_gcd;
};
template <class R1, class R2>
struct _Ratio_add{
  using type = Ratio<R1::num*R2::den + R2::num*R1::den, R1::den*R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract{
  using type = Ratio<R1::num*R2::den - R2::num*R1::den, R1::den*R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply{
  using type = Ratio<R1::num*R2::num, R1::den*R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide{
  using type = Ratio<R1::num*R2::den, R1::den*R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim{
  using M = U;
  using L = V;
  using T = W;

  using type = Dim<M, L, T>;
};

template <>