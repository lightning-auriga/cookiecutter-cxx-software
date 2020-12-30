/*!
  \file fileinterface_reader_flat.cc
  \brief method implementations for fileinterface flat file parsing

  This is really just an unnecessarily complicated wrapper for ifstream.
  But I wanted to have fileinterface be capable of handling plaintext files
  without external library support, just for coding convenience down the line.

  \copyright Released under the MIT License.
  Copyright 2020 Lightning Auriga
 */

#include "fileinterface/fileinterface_reader_flat.h"

void {{ cookiecutter.repo_name }}::fileinterface_reader_flat::open(const char *filename) {
  _input.open(filename);
  if (!_input.is_open())
    throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_reader_flat::open: cannot open file \""
			    + std::string(filename) + "\"");
}

bool {{ cookiecutter.repo_name }}::fileinterface_reader_flat::getline(std::string &line) {
  line = "";
  if (_input.peek() == EOF)
    return false;
  std::getline(_input, line);
  return true;
}

void {{ cookiecutter.repo_name }}::fileinterface_reader_flat::read(char *buf, std::streamsize n) {
  _input.read(buf, n);
}
