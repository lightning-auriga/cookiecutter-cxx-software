/*!
  \file finter_writer.h
  \brief entry point for writer classes. Pulls in headers for all supported
  compression types.
  \copyright Released under the MIT License.
  Copyright 2020 Cameron Palmer
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_WRITER_H_
#define {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_WRITER_H_

#include "finter/finter_writer_bzip2.h"
#include "finter/finter_writer_flat.h"
#include "finter/finter_writer_gzip.h"

#endif // {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_WRITER_H_
