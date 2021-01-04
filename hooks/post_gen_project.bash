#!/usr/bin/env bash

{%- if cookiecutter.include_finter != "yes" %}
rm -Rf finter
{%- endif %}

autoconf_archive_github="https://raw.githubusercontent.com/autoconf-archive/autoconf-archive/master/m4"

function download_file {
    wget "$autoconf_archive_github/$1" -P "$2" > /dev/null 2>&1
    if [[ "$?" != "0" ]] ; then
	echo "post_gen_project: failed to download \"$1\""
	exit 1
    fi
}

{%- if cookiecutter.require_boost_headers == "yes" %}
download_file "ax_boost_base.m4" "m4"
{%- endif %}

{%- if cookiecutter.require_boost_iostreams == "yes" %}
download_file "ax_boost_iostreams.m4" "m4"
{%- endif %}

{%- if cookiecutter.require_boost_filesystem  == "yes" %}
download_file "ax_boost_filesystem.m4" "m4"
{%- endif %}

{%- if cookiecutter.require_boost_program_options == "yes" %}
download_file "ax_boost_program_options.m4" "m4"
{%- else %}
rm {{ cookiecutter.repo_name }}/cargs.*
{%- endif %}

{%- if cookiecutter.include_finter == "yes" %}
download_file "ax_check_zlib.m4" "m4"
cp m4/ax_check_zlib.m4 finter/m4
{%- endif %}

{%- if cookiecutter.git_tracking == "yes" %}

git init -b default > /dev/null 2>&1
git add -f {{ cookiecutter.repo_name }}/*cc \
    {{ cookiecutter.repo_name }}/*h \
    tap-driver.sh generate.bash environment.yaml \
    configure.ac {{ cookiecutter.repo_name }}.doxyfile \
    {{ cookiecutter.repo_name }}-{{ cookiecutter.version }}.pc.in \
    m4/ax* m4/bzip2.m4 README README.md NEWS \
    Makefile.am INSTALL ChangeLog COPYING AUTHORS \
    .gitignore

{%- if cookiecutter.include_finter %}
git add -f finter/AUTHORS finter/ChangeLog \
    finter/configure.ac finter/COPYING finter/finter-1.0.0.pc.in \
    finter/INSTALL finter/m4/ax_* finter/m4/bzip2.m4 \
    finter/Makefile.am finter/NEWS finter/README \
    finter/finter/finter*h finter/finter/helper.h \
    finter/finter/finter*cc
{%- endif %}

{%- else %}
rm .gitignore
{%- endif %}

{%- if cookiecutter.testing_with_TAP == "no" %}
rm tap-driver.sh
rm -Rf tests
{%- endif %}

exit 0
