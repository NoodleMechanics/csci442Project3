/**
 * This file contains implementations for methods in the PhysicalAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "physical_address/physical_address.h"

using namespace std;


string PhysicalAddress::to_string() const {
  string frame = bitset<PhysicalAddress::FRAME_BITS>(PhysicalAddress::frame).to_string();
  string offset = bitset<PhysicalAddress::OFFSET_BITS>(PhysicalAddress::offset).to_string();

  return (frame + offset);
}


ostream& operator <<(ostream& out, const PhysicalAddress& address) {

  string tmp = " [frame: " + to_string(address.frame) + "; offset: " + to_string(address.offset) +"]";
  out << bitset<PhysicalAddress::FRAME_BITS>(address.frame) << bitset<PhysicalAddress::OFFSET_BITS>(address.offset) << tmp;

  return out;
}