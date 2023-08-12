# {{ cookiecutter.project_name }}

## Brief Summary

{{ cookiecutter.project_short_description }}

## Overview

This README is an automated stub generated from a `cookiecutter` template.
Documentation below reflects the state of the templated project immediately
after creation and may not reflect the current state of the project after
development updates.

## Requirements

  - g++ >= 8.2.0
  - automake/autoconf
  - make >= 4.2

{%- if cookiecutter.git_tracking == "yes" %}
  - git >= 2.28.0
  - nodejs (for commitizen)
{%- endif %}

{%- if cookiecutter.linting_support_for_CXX == "yes" %}
  - pre-commit
  - associated linting tools for C++: cppcheck, clang-format
{%- endif %}

{%- if cookiecutter.require_boost_headers == "yes" %}
  - [boost headers](https://www.boost.org)
{%- endif %}

{%- if cookiecutter.require_boost_program_options == "yes" %}
  - [boost program_options](https://www.boost.org/doc/libs/1_75_0/doc/html/program_options.html)
{%- endif %}

{%- if cookiecutter.require_boost_filesystem == "yes" %}
  - [boost filesystem/system](https://www.boost.org/doc/libs/1_75_0/libs/filesystem/doc/index.htm)
{%- endif %}

{%- if cookiecutter.require_boost_iostreams == "yes" %}
  - [boost iostreams](https://www.boost.org/doc/libs/1_74_0/libs/iostreams/doc/index.html)
{%- endif %}

{%- if cookiecutter.require_yaml_cpp == "yes" %}
  - [yaml-cpp](https://github.com/jbeder/yaml-cpp)
{%- endif %}

## Build

By default, a build process involving a [conda/mamba](https://mamba.readthedocs.io/en/latest/installation.html) environment is supported.

  - if you wish to use `conda` and it's not currently available, you can install it with the instructions [here](https://mamba.readthedocs.io/en/latest/mamba-installation.html#mamba-install)
  - navigate into your project directory ({{ cookiecutter.repo_name }})
  - create the `conda` environment for installation as follows:
  
     `mamba env create -f environment.yaml`
  - activate the conda environment:
  
     `mamba activate {{ cookiecutter.repo_name }}-env`

{%- if cookiecutter.git_tracking == "yes" %}
  - (one time only per environment) install `commitizen`:
  
     `npm install -g commitizen cz-conventional-changelog`
{%- endif %}

{%- if cookiecutter.linting_support_for_CXX == "yes" %}
  - (one time only per environment) install `pre-commit` linters:
  
     `pre-commit install`
{%- endif %}

  - update (create) the necessary `configure` scripts with `autoreconf`:
  
     `autoreconf --force --install`
	 
     - note that this can also be run with `./generate.bash` inside the repo
  - run `configure`:
  
	 `CC=${CONDA_PREFIX}/bin/x86_64-conda-linux-gnu-gcc CXX=${CONDA_PREFIX}/bin/x86_64-conda-linux-gnu-g++ ./configure {%- if cookiecutter.require_boost_headers == "yes"%} --with-boost=${CONDA_PREFIX} --with-boost-libdir=${CONDA_PREFIX}/lib {%- endif %} {%- if cookiecutter.require_yaml_cpp %} --with-yaml-cpp=${CONDA_PREFIX} {%- endif %}`

	 - if you are planning on installing software to a local directory, run instead `./configure --prefix=/install/dir [...]`
  - run `make -j{ncores}`
  
{%- if cookiecutter.testing_with_TAP == "yes" %}
  - run `make check` to run any `TAP/automake` tests, or the placeholder
{%- endif %}

  - if desired, run `make install`. if permissions issues are reported, see above for reconfiguring with `./configure --prefix`.
  
## Usage

By default, the final compiled program can be run with

`./{{ cookiecutter.repo_name }}.out`

## Version History

{% now 'utc', '%d %m %Y' %}: project generated from cookiecutter template
