/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"

using namespace std;


VirtualAddress VirtualAddress::from_string(int process_id, string address) {
  VirtualAddress v = VirtualAddress(process_id, bitset<32>(address.substr(0, 10)).to_ulong(), bitset<32>(address.substr(10, 15)).to_ulong());
  return v;
}


string VirtualAddress::to_string() const {
   string page = bitset<VirtualAddress::PAGE_BITS>(VirtualAddress::page).to_string();
  string offset = bitset<VirtualAddress::OFFSET_BITS>(VirtualAddress::offset).to_string();

  return (page + offset);
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
  
  string tmp0 = "PID " + to_string(address.process_id) + " @ ";
  string tmp1 = " [page: " + to_string(address.page) + "; offset: " + to_string(address.offset) + "]";

  out << tmp0 << bitset<VirtualAddress::PAGE_BITS>(address.page) << bitset<VirtualAddress::OFFSET_BITS>(address.offset) << tmp1;
  return out;
}
