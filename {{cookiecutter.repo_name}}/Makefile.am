{%- if cookiecutter.include_finter == "yes" %}
SUBDIRS = finter
{%- endif %}

{%- if cookiecutter.include_finter == "yes" %}
AM_CPPFLAGS = -I$(srcdir)/finter -I$(srcdir)/finter/include
{%- endif %}

bin_PROGRAMS = {{ cookiecutter.repo_name }}.out
{{ cookiecutter.repo_name }}_out_SOURCES = {{ cookiecutter.repo_name }}/cargs.cc {{ cookiecutter.repo_name }}/cargs.h {{ cookiecutter.repo_name }}/main.cc
{{ cookiecutter.repo_name }}_out_CXXFLAGS = {%- if cookiecutter.require_boost_headers == "yes" %} $(BOOST_CPPFLAGS) {%- endif %} -ggdb -Wall -std=c++17
{{ cookiecutter.repo_name }}_out_LDADD = {%- if cookiecutter.require_boost_headers == "yes" %} $(BOOST_LDFLAGS) {%- endif %} {%- if cookiecutter.include_finter == "yes" %} finter/lib/libfinter.la {%- endif %} {%- if cookiecutter.require_boost_program_options == "yes" %} -lboost_program_options {%- endif %} {%- if cookiecutter.require_boost_filesystem == "yes" %} -lboost_system -lboost_filesystem {%- endif %} {%- if cookiecutter.require_boost_iostreams == "yes" %} -lboost_iostreams {%- endif %} {%- if cookiecutter.require_yaml_cpp == "yes" %} -lyaml-cpp {%- endif %}
dist_doc_DATA = README
ACLOCAL_AMFLAGS = -I m4
