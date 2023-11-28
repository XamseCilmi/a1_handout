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

struct bits8 bits8_from_int(unsigned int x){
   struct bits8 n;

    // Use bitwise operations 
    n.b0.v = bit_from_int(x & 0x01).v;
    n.b1.v = bit_from_int(x & 0x02).v;
    n.b2.v = bit_from_int(x & 0x04).v;
    n.b3.v = bit_from_int(x & 0x08).v;
    n.b4.v = bit_from_int(x & 0x10).v;
    n.b5.v = bit_from_int(x & 0x20).v;
    n.b6.v = bit_from_int(x & 0x40).v;
    n.b7.v = bit_from_int(x & 0x80).v;

    return n;
};
unsigned int bits8_to_int(struct bits8 x);
void bits8_print(struct bits8 v);
struct bits8 bits8_add(struct bits8 x, struct bits8 y){
  struct bits8 result;
  struct bit carry;

  result.b0.v = bit_or(x.b0, y.b0);
  carry = bit_and(x.b0, y.b0)
  result.b1.v = bit_or(x.b1,y.b1);

};
struct bits8 bits8_negate(struct bits8 x);
struct bits8 bits8_mul(struct bits8 x, struct bits8 y);


int main() {
  // TODO
  

}
