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
  if(index < pages.size()) {
    return true;
  } else {
    return false;
  }
}


size_t Process::get_rss() const {
  size_t count = 0;

  for(auto &i: page_table.rows) {
    if(i.present) {
      count++;
    }
  }

  return count;
}


double Process::get_fault_percent() const {
  if(Process::memory_accesses != 0) {
    return (((double)Process::page_faults / (double)Process::memory_accesses) * 100.0);
  } else {
    return 0.0;
  }
}
