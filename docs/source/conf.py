# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Windows/MacOS 上 VSCode 配置 C++: LLVM (Clang + Clangd + LLDB)'
copyright = '2024, FeignClaims'
author = 'FeignClaims'
release = 'v1.0.0'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['sphinx_togglebutton', 'sphinx.ext.todo',
              'sphinx.ext.graphviz', 'sphinx.ext.extlinks', 'sphinx_rtd_theme']

togglebutton_hint = ""
togglebutton_hint_hide = ""

templates_path = ['_templates']
exclude_patterns = []

rst_prolog = open('_static/links.rst', 'r', encoding="utf8").read()

language = 'zh_CN'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
