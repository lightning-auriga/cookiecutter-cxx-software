/*!
  \file finter.h
  \brief main entry point for finter classes. Pulls in other headers
  and provides primary IO utility functions.
  \copyright Released under the MIT License.
  Copyright 2020 Lightning Auriga
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_H_
#define {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_H_

#include <string>
#include <iostream>

#include "finter/finter_reader.h"
#include "finter/finter_writer.h"

namespace {{ cookiecutter.repo_name }} {
  /*!
    \brief utility function to facilitate file input while respecting compression suffixes
    @param filename name of file to be opened
    \return pointer to allocated object
    \warning compression type is determined from suffix of provided file
    \warning memory must be managed by caller
   */
  inline finter_reader *reconcile_reader(const std::string &filename) {
    finter_reader *ptr = 0;
    if (filename.find(".gz") == filename.size() - 3) {
#ifdef FINTER_HAVE_LIBZ
      ptr = new finter_reader_gzip;
      ptr->open(filename);
#else
      throw std::domain_error("zlib support not compiled into software, cannot open \"" + filename + "\"");
#endif //FINTER_HAVE_LIBZ
    } else if (filename.find(".bz2") == filename.size() - 4) {
#ifdef FINTER_HAVE_LIBBZ2
      ptr = new finter_reader_bzip2;
      ptr->open(filename);
#else
      throw std::domain_error("libbz2 support not compiled into software, cannot open \"" + filename + "\"");
#endif //FINTER_HAVE_LIBBZ2
    } else {
      ptr = new finter_reader_flat;
      ptr->open(filename);
    }
    return ptr;
  }
  /*!
    \brief utility function to facilitate file output while respecting compression suffixes
    @param filename name of file to be opened
    \return pointer to allocated object
    \warning compression type is determined from suffix of provided file
    \warning memory must be managed by caller
   */
  inline finter_writer *reconcile_writer(const std::string &filename) {
    finter_writer *ptr = 0;
    if (filename.find(".gz") == filename.size() - 3) {
#ifdef FINTER_HAVE_LIBZ
      ptr = new finter_writer_gzip;
      ptr->open(filename);
#else
      throw std::domain_error("zlib support not compiled into software, cannot write \"" + filename + "\"");
#endif //FINTER_HAVE_LIBZ
    } else if (filename.find(".bz2") == filename.size() - 4) {
#ifdef FINTER_HAVE_LIBBZ2
      ptr = new finter_writer_bzip2;
      ptr->open(filename);
#else
      throw std::domain_error("libbz2 support not compiled into software, cannot write \"" + filename + "\"");
#endif //FINTER_HAVE_LIBBZ2
    } else {
      ptr = new finter_writer_flat;
      ptr->open(filename);
    }
    return ptr;
  }
}

#endif // {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_H_
