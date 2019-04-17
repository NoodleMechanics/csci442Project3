/**
 * This file contains implementations for methods in the Page class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page/page.h"

using namespace std;


// Ensure PAGE_SIZE is initialized.
const size_t Page::PAGE_SIZE;


Page* Page::read_from_input(std::istream& in) {
  vector<char> bytes;

  if(in.peek() != EOF) {
    while(in.peek() != EOF && bytes.size() < PAGE_SIZE) {
      char c;
      in >> noskipws >> c;
      bytes.push_back(c);
    }
    
    Page* p = new Page(bytes);
    return p;
  } else {
    return nullptr;
  }
}


size_t Page::size() const {
  return Page::bytes.size();
}


bool Page::is_valid_offset(size_t offset) const {
  if(offset < Page::bytes.size()) {
    return true;
  } else {
    return false;
  }
}


char Page::get_byte_at_offset(size_t offset) {
  return Page::bytes[offset];
}
