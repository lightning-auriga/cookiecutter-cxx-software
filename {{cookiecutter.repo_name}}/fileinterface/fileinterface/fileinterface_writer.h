/*!
  \file fileinterface_writer.h
  \brief entry point for writer classes. Pulls in headers for all supported
  compression types.
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_WRITER_H_
#define {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_WRITER_H_

#include "fileinterface/fileinterface_writer_bzip2.h"
#include "fileinterface/fileinterface_writer_flat.h"
#include "fileinterface/fileinterface_writer_gzip.h"

#endif // {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_WRITER_H_
