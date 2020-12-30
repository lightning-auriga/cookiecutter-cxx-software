/*!
  \file fileinterface_writer_flat.cc
  \brief method implementation for fileinterface uncompressed file writing
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#include "fileinterface/fileinterface_writer_flat.h"

void {{ cookiecutter.repo_name }}::fileinterface_writer_flat::open(const char *filename) {
  _output.open(filename);
  if (!_output.is_open())
    throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_writer_flat::open: cannot "
			    "write file \"" + std::string(filename) + "\"");
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_flat::writeline(const std::string &line) {
  _output << line << get_newline();
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_flat::write(char *buf, std::streamsize n) {
  _output.write(buf, n);
}
