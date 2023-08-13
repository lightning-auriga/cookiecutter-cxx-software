bin_PROGRAMS = {{ cookiecutter.repo_name }}.out {%- if cookiecutter.unit_test_framework != "none" %} test_suite.out {%- endif %}

AM_CXXFLAGS = {%- if cookiecutter.require_boost_headers == "yes" %} $(BOOST_CPPFLAGS) {%- endif %} -ggdb -Wall -std=c++17

COMBINED_SOURCES = {%- if cookiecutter.require_boost_program_options == "yes" %} {{ cookiecutter.repo_name }}/cargs.cc {{ cookiecutter.repo_name }}/cargs.h {%- endif %} 
COMBINED_LDADD = {%- if cookiecutter.require_boost_headers == "yes" %} $(BOOST_LDFLAGS) {%- endif %} {%- if cookiecutter.require_boost_program_options == "yes" %} -lboost_program_options {%- endif %} {%- if cookiecutter.require_boost_filesystem == "yes" %} -lboost_system -lboost_filesystem {%- endif %} {%- if cookiecutter.require_boost_iostreams == "yes" %} -lboost_iostreams {%- endif %} {%- if cookiecutter.require_yaml_cpp == "yes" %} -lyaml-cpp {%- endif %}

{{ cookiecutter.repo_name }}_out_SOURCES = {{ cookiecutter.repo_name }}/main.cc $(COMBINED_SOURCES)
{{ cookiecutter.repo_name }}_out_LDADD = $(COMBINED_LDADD)

{%- if cookiecutter.unit_test_framework == "boost" %}
UNIT_TEST_SOURCES = unit_tests/boost_main.cc unit_tests/boost_example_test.cc
test_suite_out_SOURCES = $(COMBINED_SOURCES) $(UNIT_TEST_SOURCES)
test_suite_out_LDADD = $(COMBINED_LDADD) -lboost_unit_test_framework
{%- endif %}

{%- if cookiecutter.unit_test_framework == "google" %}
UNIT_TEST_SOURCES = unit_tests/google_example_test.cc
test_suite_out_SOURCES = $(COMBINED_SOURCES) $(UNIT_TEST_SOURCES)
test_suite_out_LDADD = $(COMBINED_LDADD) -lgtest_main -lgtest -lgmock -lpthread
{%- endif %}

dist_doc_DATA = README
ACLOCAL_AMFLAGS = -I m4
{%- if cookiecutter.testing_with_TAP == "yes" %}
## TAP support
TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/tap-driver.sh
TESTS = tests/placeholder.test
EXTRA_DIST = $(TESTS)
{%- endif %}
