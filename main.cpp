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
  std::cout << "## ( left + right )\n";
  header();
  std::cout                                 //
#define T(x, _) << arithmetic1<x>() << "\n" //
#include "types.hpp"
#undef T
      << endl;
}

template <typename lt, typename rt> //
std::string shift2() {
  return name(lt() << rt()) + "|";
}

template <typename lt> //
std::string shift1() {
  return "|" + name(lt()) + "|"
#define T(x, _) +shift2<x, lt>()
#include "itypes.hpp"
#undef T
      ; //
}

void iheader() {
  std::cout //
      << "|left＼right|"
#define T(_, n) << #n << "|" //
#include "itypes.hpp"
#undef T
      << "\n"

      << "|:--|"
#define T(_, n) << ":--:|" //
#include "itypes.hpp"
#undef T
      << "\n";
}

void shift() {
  std::cout << "## ( left << right )\n";
  iheader();
  std::cout                            //
#define T(x, _) << shift1<x>() << "\n" //
#include "itypes.hpp"
#undef T
      << endl;
}

template <typename lt, typename rt> //
std::string cond2() {
  return name(true ? lt() : rt()) + "|";
}

template <typename lt> //
std::string cond1() {
  return "|" + name(lt()) + "|"
#define T(x, _) +cond2<x, lt>()
#include "types.hpp"
#undef T
      ; //
}

void cond() {
  std::cout << "## ( cond ? left : right )\n";
  header();
  std::cout                           //
#define T(x, _) << cond1<x>() << "\n" //
#include "types.hpp"
#undef T
      << endl;
}

int main() {
  arithmetic();
  shift();
  cond();
  return 0;
}