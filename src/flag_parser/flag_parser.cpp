/**
 * This file contains implementations for methods in the flag_parser.h file.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "flag_parser.h"
#include <iostream>

using namespace std;


void print_usage() {
  cout <<
      "Usage: mem-sim [options] filename\n"
      "\n"
      "Options:\n"
      "  -v, --verbose\n"
      "      Output information about every memory access.\n"
      "\n"
      "  -s, --strategy (FIFO | LRU)\n"
      "      The replacement strategy to use. One of FIFO or LRU.\n"
      "\n"
      "  -f, --max-frames <positive integer>\n"
      "      The maximum number of frames a process may be allocated.\n"
      "\n"
      "  -h --help\n"
      "      Display a help message about these flags and exit\n"
      "\n";
}


bool parse_flags(int argc, char** argv, FlagOptions& flags) {
  // TODO: implement me

  if(argc < 2) {
    return false;
  }

  // grab flags using getopt
  int flagIndex = 0, c;
  while(true) {
    int option_index = 0;
    static struct option long_options[] = {
        {"verbose", no_argument, 0, 'v'},
        {"strategy", required_argument, 0, 's'},
        {"max-frames", required_argument, 0, 'f'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    c = getopt_long(argc, argv, "vs:f:h", long_options, &option_index);

    if(c == -1)
      break;

    switch (c) {
        case 0:


      case 'v':
        flags.verbose = true;
        break;
      case 's':
        if(optarg == "LRU") {
          flags.strategy = ReplacementStrategy::LRU;
        } else if(optarg == "FIFO") {
          flags.strategy = ReplacementStrategy::FIFO;
        } else {
            return false;
        }
        break;
      case 'f':
        if(atoi(optarg) > 0) {
          flags.max_frames = atoi(optarg);
        } else {
          return false;
        }
        break;
      case 'h':
        print_usage();
        exit(0);
      default:
        return false;
    }

    flagIndex++;
  }

  flags.filename = argv[argc - 1];

  return true;
}
