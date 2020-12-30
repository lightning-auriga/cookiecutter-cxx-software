#!/usr/bin/env bash

{%- if cookiecutter.include_fileinterface != "yes" %}
rm -Rf fileinterface
{%- endif %}

function download_file {
    wget "$1" -P m4 > /dev/null 2>&1
    if [[ "$?" != "0" ]] ; then
	echo "post_gen_project: failed to download \"$1\""
	exit 1
    fi
}

{%- if cookiecutter.require_boost_headers == "yes" %}
download_file "https://raw.githubusercontent.com/autoconf-archive/autoconf-archive/master/m4/ax_boost_base.m4"
{%- endif %}

{%- if cookiecutter.require_boost_iostreams == "yes" %}
download_file "https://raw.githubusercontent.com/autoconf-archive/autoconf-archive/master/m4/ax_boost_iostreams.m4"
{%- endif %}

{%- if cookiecutter.require_boost_filesystem  == "yes" %}
download_file "https://raw.githubusercontent.com/autoconf-archive/autoconf-archive/master/m4/ax_boost_filesystem.m4"
{%- endif %}

{%- if cookiecutter.require_boost_program_options == "yes" %}
download_file "https://raw.githubusercontent.com/autoconf-archive/autoconf-archive/master/m4/ax_boost_program_options.m4"
{%- else %}
rm {{ cookiecutter.repo_name }}/cargs.*
{%- endif %}

{%- if cookiecutter.git_tracking == "yes" %}
git init -b default > /dev/null 2>&1
{%- else %}
rm .gitignore
{%- endif %}

exit 0
