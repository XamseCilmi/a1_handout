#include <stdlib.h>
#include "numbers.h"

void test_bits8_add(unsigned int x, unsigned int y) {
  unsigned int got = bits8_to_int(bits8_add(bits8_from_int(x), bits8_from_int(y)));
  unsigned int expected = x + y;
  if (got != expected) {
    printf("Input:     %u & %u\n", x, y);
    printf("Got:       %u\n", got);
    printf("Expected:  %u\n", expected);
    exit(1);
  }
}

void test_bits8_mul(unsigned int x, unsigned int y) {
  unsigned int got = bits8_to_int(bits8_mul(bits8_from_int(x), bits8_from_int(y)));
  unsigned int expected = x * y;
  if (got != expected) {
    printf("Input:     %u & %u\n", x, y);
    printf("Got:       %u\n", got);
    printf("Expected:  %u\n", expected);
    exit(1);
  }
}

int main() {
  assert(bits8_to_int(bits8_from_int(100)) == 100);
  test_bits8_add(0, 0);
  test_bits8_add(0, 10);
  test_bits8_add(10, 0);
  test_bits8_add(10, 10);
  test_bits8_add(100, 155);

  assert(bits8_to_int(bits8_negate(bits8_negate(bits8_from_int(0)))) == 0);
  assert(bits8_to_int(bits8_negate(bits8_negate(bits8_from_int(10)))) == 10);
  int minus_one = -1;
  struct bits8 one = bits8_negate(bits8_from_int((unsigned int)minus_one));
  int one_int = (int)bits8_to_int(one);
  assert(one_int == 1);

  test_bits8_mul(0, 0);
  test_bits8_mul(0, 10);
  test_bits8_mul(10, 0);
  test_bits8_mul(10, 10);
  test_bits8_mul(5, 7);
}