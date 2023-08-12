# Cookiecutter CXX Software

[Cookiecutter](https://github.com/cookiecutter/cookiecutter) template for an autotools-powered C++ software package with certain add-ons.

 - [GitHub repo](https://github.com/lightning-auriga/cookiecutter-cxx-software)
 - released under the MIT License
 
## Features

   - integration with [autotools](https://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
   - optional support for automated testing via [TAP/automake](https://www.gnu.org/software/automake/manual/html_node/Using-the-TAP-test-protocol.html) and `make check`
   - optional support for [boost](https://www.boost.org) headers and certain compiled libraries (notably [program_options](https://www.boost.org/doc/libs/1_75_0/doc/html/program_options.html) for UI); easily extensible to others
   - optional support for [yaml-cpp](https://github.com/jbeder/yaml-cpp)
 
## Requirements

   - [cookiecutter](https://github.com/cookiecutter/cookiecutter) and dependencies
   - if using the [conda](https://docs.conda.io/en/latest/) installation option: an available instance of `conda`
   
## Installation

Installation is supported for `conda`; this is certainly not required, and if you have a version of [cookiecutter](https://github.com/cookiecutter/cookiecutter) around otherwise, feel free to use it as you see fit.

  - if you wish to use `conda` and it's not currently available, you can install it with the instructions [here](https://docs.conda.io/en/latest/miniconda.html)
  - get a copy of the template repository (if you don't have `git` available, you can download it in your browser and unpack the tarball wherever you want it):
	 `git clone --branch default https://github.com/lightning-auriga/cookiecutter-cxx-software`
  - create the `conda` environment for installation as follows:
     `conda env create -f cookiecutter-cxx-software/environment.yaml`
  - activate the conda environment:
     `conda activate cookiecutter-cxx-software-env`
  - navigate to the directory in which you want to create a new project directory
  - run `cookiecutter` on the template, and respond to the user prompts:
	 `cookiecutter [/path/to/cookiecutter-cxx-software]`

## Notes
  - when prompted for "repo_name", choose something that is a valid and unique C++ namespace name. limit yourself to `[A-Z][a-z]_` and you should be fine
  - if, like me, you sometimes have issues with `conda` taking an absurdly long time to resolve environments and dependencies, you can try using `mamba` instead. you would proceed as above installing `conda`, but then use `conda install mamba` to install `mamba` into your base environment. then you can instead use `mamba env create -f cookiecutter-cxx-software/environment.yaml` above.

## Version History

11 August 2023: incremental updates and improved yaml-cpp detection

05 January 2021: ported to GitHub: hello world!

04 January 2021: v1.1.0 release: linting and commitizen added

30 December 2020: initial development
