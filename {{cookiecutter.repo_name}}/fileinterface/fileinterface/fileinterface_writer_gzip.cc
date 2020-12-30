/*!
  \file fileinterface_writer_gzip.cc
  \brief method implementations for fileinterface gzip writer
  \copyright Released under the MIT License.
  Copyright 2020 Lightning Auriga
 */

#include "fileinterface/fileinterface_writer_gzip.h"

#ifdef FILEINTERFACE_HAVE_LIBZ

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::open(const char *filename) {
  if (!_gz_output) {
    _gz_output = gzopen(filename, "wb");
    if (!_gz_output)
      throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_writer_gzip::open: cannot open "
			      "file \"" + std::string(filename) + "\"");
  } else
    throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_writer_gzip::open: reopen "
			    "attempted with active handle");
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::close() {
  if (_gz_output) {
    gzclose(_gz_output);
    _gz_output = 0;
  }
  clear();
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::clear() {
  _good = true;
  _bad = _fail = _eof = false;
}

bool {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::is_open() const {
  return _gz_output;
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::put(char c) {
  write(&c, 1);
}

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::writeline(const std::string &linemod) {
  std::string line = linemod + get_newline();
  if (gzputs(_gz_output, line.c_str()) < 0)
    throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_writer_gzip::writeline: write of "
			    "line \"" + line + "\" failed");

}

void {{ cookiecutter.repo_name }}::fileinterface_writer_gzip::write(char *buf, std::streamsize n) {
  if (gzwrite(_gz_output, reinterpret_cast<void *>(buf), n) < 1) {
    throw std::domain_error("{{ cookiecutter.repo_name }}::fileinterface_writer_gzip::write: write call of"
			    " size " + std::to_string(n) + " failed");
  }
}

#endif //FILEINTERFACE_HAVE_LIBZ
