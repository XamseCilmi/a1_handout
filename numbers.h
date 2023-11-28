#include <stdint.h>
#include "bits.h"

struct bits8 {
  struct bit b0; // Least significant bit
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};

struct bits8 bits8_from_int(unsigned int x) {
  //assert(x < 255);

  struct bits8 v;

  v.b0 = bit_from_int(x % 2);
  x /= 2;
  v.b1 = bit_from_int(x % 2);
  x /= 2;
  v.b2 = bit_from_int(x % 2);
  x /= 2;
  v.b3 = bit_from_int(x % 2);
  x /= 2;
  v.b4 = bit_from_int(x % 2);
  x /= 2;
  v.b5 = bit_from_int(x % 2);
  x /= 2;
  v.b6 = bit_from_int(x % 2);
  x /= 2;
  v.b7 = bit_from_int(x % 2);

  return v;
}

unsigned int bits8_to_int(struct bits8 x) {
  unsigned int result = 0;

  result |= bit_to_int(x.b0);
  result |= bit_to_int(x.b1) << 1;
  result |= bit_to_int(x.b2) << 2;
  result |= bit_to_int(x.b3) << 3;
  result |= bit_to_int(x.b4) << 4;
  result |= bit_to_int(x.b5) << 5;
  result |= bit_to_int(x.b6) << 6;
  result |= bit_to_int(x.b7) << 7;

  return result;
}

void bits8_print(struct bits8 v) {
  bit_print(v.b7);
  bit_print(v.b6);
  bit_print(v.b5);
  bit_print(v.b4);
  bit_print(v.b3);
  bit_print(v.b2);
  bit_print(v.b1);
  bit_print(v.b0);
}

struct bits8 bits8_add(struct bits8 x, struct bits8 y) {
  struct bits8 s;

  struct bit c_minus_1;

  c_minus_1.v = false;
  s.b0 = bit_xor(bit_xor(x.b0, y.b0), c_minus_1);
  struct bit c0 = bit_or(bit_and(x.b0, y.b0), bit_and(bit_or(x.b0, y.b0), c_minus_1));

  s.b1 = bit_xor(bit_xor(x.b1, y.b1), c0);
  struct bit c1 = bit_or(bit_and(x.b1, y.b1), bit_and(bit_or(x.b1, y.b1), c0));

  s.b2 = bit_xor(bit_xor(x.b2, y.b2), c1);
  struct bit c2 = bit_or(bit_and(x.b2, y.b2), bit_and(bit_or(x.b2, y.b2), c1));

  s.b3 = bit_xor(bit_xor(x.b3, y.b3), c2);
  struct bit c3 = bit_or(bit_and(x.b3, y.b3), bit_and(bit_or(x.b3, y.b3), c2));

  s.b4 = bit_xor(bit_xor(x.b4, y.b4), c3);
  struct bit c4 = bit_or(bit_and(x.b4, y.b4), bit_and(bit_or(x.b4, y.b4), c3));

  s.b5 = bit_xor(bit_xor(x.b5, y.b5), c4);
  struct bit c5 = bit_or(bit_and(x.b5, y.b5), bit_and(bit_or(x.b5, y.b5), c4));

  s.b6 = bit_xor(bit_xor(x.b6, y.b6), c5);
  struct bit c6 = bit_or(bit_and(x.b6, y.b6), bit_and(bit_or(x.b6, y.b6), c5));

  s.b7 = bit_xor(bit_xor(x.b7, y.b7), c6);

  return s;
}

struct bits8 bits8_negate(struct bits8 x) {
  x.b0 = bit_not(x.b0);
  x.b1 = bit_not(x.b1);
  x.b2 = bit_not(x.b2);
  x.b3 = bit_not(x.b3);
  x.b4 = bit_not(x.b4);
  x.b5 = bit_not(x.b5);
  x.b6 = bit_not(x.b6);
  x.b7 = bit_not(x.b7);

  struct bits8 one;
  one.b0 = bit_from_int(1);
  one.b1 = bit_from_int(0);
  one.b2 = bit_from_int(0);
  one.b3 = bit_from_int(0);
  one.b4 = bit_from_int(0);
  one.b5 = bit_from_int(0);
  one.b6 = bit_from_int(0);
  one.b7 = bit_from_int(0);

  return bits8_add(x, one);
}

struct bits8 bits8_mul(struct bits8 x, struct bits8 y);