/*!
  \file helper.h
  \brief finter utility functions
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FINTER_HELPER_H_
#define {{ cookiecutter.repo_capitalized }}_FINTER_HELPER_H_

#include <string>
#include <sstream>
#include <stdexcept>

namespace {{ cookiecutter.repo_name }} {
  /*!
    \brief get platform-specific newline character
    \return platform-specific newline character
   */
  inline std::string get_newline() {
#ifdef _WIN64
    return "\r\n";
#elif  _WIN32
    return "\r\n";
#else //if __APPLE__  // linux
    //#elif __linux || __unix
    return "\n";
#endif
  }
}
#endif // {{ cookiecutter.repo_capitalized }}_FINTER_HELPER_H_
