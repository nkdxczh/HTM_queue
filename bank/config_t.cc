// CSE 375/475 Assignment #1
// Fall 2017
//
// Description:  This file implements the config_t::dump() function

#include <iostream>
#include "config_t.h"

// Print the values of the seed, iters, and name fields as comma separated
// values, with a header row
void config_t::dump() {
    if(show){
        std::cout << "# name, seed, key_max, iters, threads" << std::endl;
        std::cout << name << ", "
            << key_max << ", "
            << iters << ", "
            << threads << std::endl;
    }
}
