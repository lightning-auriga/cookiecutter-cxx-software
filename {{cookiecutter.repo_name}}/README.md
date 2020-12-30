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
  - git>=2.28.0
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

{%- if cookiecutter.include_finter == "yes" %}
  - [zlib headers and library](https://zlib.net/)
  - [bzip2 headers and library](https://www.sourceware.org/bzip2/)
{%- endif %}

## Build

By default, a build process involving a [conda](https://docs.conda.io/en/latest/) environment is supported.

  - if you wish to use `conda` and it's not currently available, you can install it with the instructions [here](https://docs.conda.io/en/latest/miniconda.html)
  - create the `conda` environment for installation as follows:
     `conda env create -f {{ cookiecutter.repo_name }}/environment.yaml`
  - activate the conda environment:
     `conda activate {{ cookiecutter.repo_name }}-env`
  - update (create) the necessary `configure` scripts with `autoreconf`:
     `autoreconf --force --install`
     - note that this can also be run with `./generate.bash` inside the repo
  - run `configure`:
	 `./configure`
	 - if you are planning on installing software to a local directory, run instead `./configure --prefix=/install/dir`
	 - periodically there are some incompatibility issues between `configure` and `conda`. if so, you may need to override
	   some default locations detected by `configure`. for example, you might override the detected compiler and boost locations
	   with a command such as:
	   `CC=gcc CXX=g++ ./configure --with-boost=/local/install/stage --with-boost-libdir=/local/install/stage/lib`
  - run `make`
  
{%- if cookiecutter.testing_with_TAP == "yes" %}
  - run `make check` to run any `TAP/automake` tests, or the placeholder
{%- endif %}

  - if desired, run `make install`. if permissions issues are reported, see above for reconfiguring with `./configure --prefix`.
  
## Usage

By default, the final compiled program can be run with

`./{{ cookiecutter.repo_name }}.out`

## Version History

{% now 'utc', '%d %m %Y' %}: project generated from cookiecutter template
