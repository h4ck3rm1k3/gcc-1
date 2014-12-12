#pragma once 
const bool INT64_T_IS_LONG  = true;
const char HOST_BITS_PER_LONGLONG = 64;

class uint64_t {};

template <class T> void  _obstack_memcpy(T To, T From, int N){}
// bcopy ((char *)(From), (To), (N))

//class size_t {};

class HOST_WIDE_INT {};
class HOST_WIDE_UINT {
 public:
  HOST_WIDE_UINT(int);
  bool operator ==(int);
  operator int();
};
HOST_WIDE_UINT operator << (HOST_WIDE_UINT, int);
HOST_WIDE_INT operator  << (HOST_WIDE_INT, int);
HOST_WIDE_UINT operator >> (HOST_WIDE_UINT, int);
HOST_WIDE_INT operator  >>(HOST_WIDE_INT, int);
#define HOST_WIDE_INT_C(X) X ## LL

class intptr_t {};

intptr_t operator >> (intptr_t, int);

/// machmode

enum machine_modes {
  NUM_MACHINE_MODES
};
class MODE_SIZE_T {};
class MODE_IBIT_T{};
class MODE_FBIT_T{};
class MODE_BASE_ALIGN_T{};
class machine_mode {};
const bool GATHER_STATISTICS = true;
const int NUM_INT_N_ENTS = 1;

// input.h
class source_location {};
class expanded_location {};
const int BUILTINS_LOCATION = 1;
const int RESERVED_LOCATION_COUNT= 2;

//wide-int.h
const int MAX_BITSIZE_MODE_ANY_INT= 1;
 
