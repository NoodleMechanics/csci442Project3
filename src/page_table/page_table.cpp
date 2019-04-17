/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;


size_t PageTable::get_present_page_count() const {
  int pageCount = 0;

  for(auto &i : PageTable::rows) {
    if(i.present == true) {
      pageCount++;
    }
  }

  return pageCount; 
}


size_t PageTable::get_oldest_page() const {
  int pageIndex = 0;

  for(int i = 0; i < (int)PageTable::rows.size(); i++) {
    if(PageTable::rows[i].present == true) {
      pageIndex = i;
      break;
    }
  }

  return pageIndex;
}


size_t PageTable::get_least_recently_used_page() const {
  int pageIndex = 0;

  for(int i = (int)PageTable::rows.size() - 1; i >= 0; i--) {
    if(PageTable::rows[i].present == true) {
      pageIndex = i;
      break;
    }
  }

  return pageIndex;
}
