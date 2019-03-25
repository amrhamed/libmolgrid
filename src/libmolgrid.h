/** \file libmolgrid.h
 *  \brief Single header to include for all libmolgrid functionality.
 *  libmolgrid provides GPU accelerated routines for converting molecular
 *  data into dense grids for use in deep learning workflows.
 */
 
#ifndef LIBMOLGRID_H_
#define LIBMOLGRID_H_

#include <random>
#include <iostream>

// dimensionalities up to but not including LIBMOLGRID_MAX_GRID_DIM are pre-instantiated
#define LIBMOLGRID_MAX_GRID_DIM 9
namespace libmolgrid {
    ///random engine used in libmolgrid
    extern std::default_random_engine random_engine;

    enum LogLevel { INFO, WARNING, DEBUG};

    inline std::ostream& LOG(LogLevel level = INFO) {
      return std::cout; //todo, implement verbosity levels
    }
}

#endif
