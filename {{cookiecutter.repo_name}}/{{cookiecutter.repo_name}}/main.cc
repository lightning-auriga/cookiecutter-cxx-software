/*!
  \file main.cc
  \brief main entry/exit for software. interprets command line arguments, dispatches tasks, exits
  \copyright Released under the MIT License.
  Copyright {% now 'utc', '%Y' %} {{ cookiecutter.full_name }}
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <random>
#include <cmath>

{%- if cookiecutter.require_boost_program_options == "yes" %}
#include "{{ cookiecutter.repo_name }}/cargs.h"
{%- endif %}

{%- if cookiecutter.include_fileinterface == "yes" %}
#include "fileinterface/fileinterface.h"
{%- endif %}

/*!
  \brief main program implementation
  @param argc number of command line entries, including program name
  @param argv array of command line entries
 */
int main(int argc, char **argv) {

  {%- if cookiecutter.require_boost_program_options == "yes" %}
  // parse command line input
  {{ cookiecutter.repo_name }}::cargs ap(argc, argv);
  // if help is requested or no flags specified
  if (ap.help() || argc == 1) {
    // print a help message and exist
    ap.print_help(std::cout);
    return 0;
  }
  {%- endif %}

  std::cout << "all done woo!" << std::endl;
  return 0;
}
