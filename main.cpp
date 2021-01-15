#include <cstdint>
#include <iostream>
#include <string>

using namespace std;
template <typename t> std::string name(t v);

using uchar = unsigned char;
using schar = signed char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;
using llong = long long;
using ullong = unsigned long long;
using ldouble = long double;

#define T(x, n)                                                                \
  template <> std::string name(x v) { return #n; }
#include "types.hpp"
#undef T

template <typename lt, typename rt> //
std::string arithmetic2() {
  return name(lt() + rt()) + "|";
}

template <typename lt> //
std::string arithmetic1() {
  return "|" + name(lt()) + "|"
#define T(x, _) +arithmetic2<x, lt>()
#include "types.hpp"
#undef T
      ; //
}

void header() {
  std::cout //
      << "|left＼right|"
#define T(_, n) << #n << "|" //
#include "types.hpp"
#undef T
      << "\n"

      << "|:--|"
#define T(_, n) << ":--:|" //
#include "types.hpp"
#undef T
      << "\n";
}
void arithmetic() {
  header();
  std::cout                                 //
#define T(x, _) << arithmetic1<x>() << "\n" //
#include "types.hpp"
#undef T
      ;
}

int main() {
  arithmetic();
  return 0;
}