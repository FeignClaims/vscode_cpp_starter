# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Windows/MacOS 上 VSCode 配置 C++: LLVM (Clang + Clangd + LLDB)'
copyright = '2024, FeignClaims'
author = 'FeignClaims'
html_title = f'{project}'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['sphinx_togglebutton', 'sphinx_last_updated_by_git', 'sphinx.ext.todo',
              'sphinx.ext.graphviz', 'sphinx.ext.extlinks', 'sphinx_copybutton']

togglebutton_hint = ""
togglebutton_hint_hide = ""

templates_path = ['_templates']
exclude_patterns = []

rst_prolog = '\n'.join(
    list(
        map(
            lambda filename: open(f'_static/{filename}', 'r', encoding="utf8").read(),
            ['links.rst']))) + '\n'

language = 'zh_CN'

html_copy_source = False
html_show_sourcelink = False

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_book_theme'
html_theme_options = {
    'repository_url': 'https://github.com/FeignClaims/vscode_cpp_starter',
    'path_to_docs': 'docs/',
    'use_source_button': True,
    'use_edit_page_button': True,
    'use_issues_button': True,
    'show_prev_next': False,
    'show_nav_level': 0,
    'show_toc_level': 2,
    "secondary_sidebar_items": {
        "**": ["page-toc", "sourcelink"],
    }
}
html_static_path = ['_static']
html_favicon = '_static/favicon.png'
html_search_language = 'zh'
html_last_updated_fmt = '%Y-%m-%d %H:%M:%S'
git_last_updated_timezone = 'Asia/Shanghai'


def setup(app):
    app.add_css_file("custom.css")
    app.add_css_file("monofont.css")

    FORCE_RELOAD_JS = """
    (function () {
    if (window.localStorage) {
        if (!localStorage.getItem("firstLoad")) {
        localStorage["firstLoad"] = true;
        window.location.reload();
        } else localStorage.removeItem("firstLoad");
    }
    })();
    """
    app.add_js_file(None, body=FORCE_RELOAD_JS)
