/*!
  \file fileinterface_reader.h
  \brief entry point for reader classes. Pulls in headers for all supported
  compression types.
  \copyright Released under the MIT License.
  Copyright 2020 Lightning Auriga
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_READER_H_
#define {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_READER_H_

#include "fileinterface/fileinterface_reader_bzip2.h"
#include "fileinterface/fileinterface_reader_flat.h"
#include "fileinterface/fileinterface_reader_gzip.h"

#endif // {{ cookiecutter.repo_capitalized }}_FILEINTERFACE_FILEINTERFACE_READER_H_
