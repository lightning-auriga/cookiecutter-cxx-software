/*!
  \file cargs.cc
  \brief method implementation for command line argument parser class
  \copyright Released under the MIT License.
  Copyright {% now 'utc', '%Y' %} {{ cookiecutter.full_name }}
*/

#include "{{ cookiecutter.repo_name }}/cargs.h"

void {{ cookiecutter.repo_name }}::cargs::initialize_options() {
  _desc.add_options()
    ("help,h", "emit this help message")
    ("output-prefix,o", boost::program_options::value<std::string>()->default_value("out"), "prefix of all output files written by software")
    ;
}
