/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"

using namespace std;


Process* Process::read_from_input(std::istream& in) {
  vector<Page*> pages;
  size_t numBytes = 0;

  while(in.peek() != EOF) {
    Page* p = Page::read_from_input(in);
    numBytes += p->size();
    pages.push_back(p);
  }

  Process* p = new Process(numBytes, pages);
  return p;
}


size_t Process::size() const {
  return Process::num_bytes;
}


bool Process::is_valid_page(size_t index) const {
  for(auto &i: Process::pages) {
    if(index < i->size()) {
      return true;
    }
  }
  return false;
}


size_t Process::get_rss() const {
  // TODO: implement me
  return 0;
}


double Process::get_fault_percent() const {
  // TODO: implement me
  return 0.0;
}
