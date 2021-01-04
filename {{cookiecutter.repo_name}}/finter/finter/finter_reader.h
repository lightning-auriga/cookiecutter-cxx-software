/*!
  \file finter_reader.h
  \brief entry point for reader classes. Pulls in headers for all supported
  compression types.
  \copyright Released under the MIT License.
  Copyright 2020 Lightning Auriga
 */

#ifndef {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_READER_H_
#define {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_READER_H_

#include "finter/finter_reader_bzip2.h"
#include "finter/finter_reader_flat.h"
#include "finter/finter_reader_gzip.h"

#endif // {{ cookiecutter.repo_capitalized }}_FINTER_FINTER_READER_H_
