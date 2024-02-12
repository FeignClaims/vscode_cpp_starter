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

extensions = [
    'sphinx.ext.extlinks',
    'sphinx.ext.graphviz',
    'sphinx.ext.intersphinx',
    'sphinx.ext.todo',
    'sphinx_copybutton',
    'sphinx_design',
    'sphinx_examples',
    'sphinx_last_updated_by_git',
    'sphinx_sitemap',
    'sphinx_tabs.tabs',
    'sphinx_togglebutton',
]

intersphinx_mapping = {
    "question_board": ("https://question-board.readthedocs.io/", None),
}
intersphinx_disabled_reftypes = ["*"]

togglebutton_hint = ""
togglebutton_hint_hide = ""

templates_path = ['_templates']
exclude_patterns = []

rst_prolog = '\n'.join(
    list(
        map(
            lambda filename: open(f'_static/{filename}', 'r', encoding="utf8").read(),
            ['inline_cpp.rst', 'links.rst', 'verification.rst']))) + '\n'

language = 'zh_CN'

html_copy_source = False
html_show_sourcelink = False

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_book_theme'
html_theme_options = {
    "icon_links": [
        {
            "name": "GitHub",
            "url": "https://github.com/FeignClaims/vscode_cpp_starter",
            "icon": "fa-brands fa-github",
        },
        {
            "name": "Gitee",
            "url": "https://gitee.com/cpp_tutorial/vscode_cpp_starter",
            "icon": "fa-brands fa-gitee",
        },
        {
            "name": "部署状态",
            "url": "https://readthedocs.org/projects/vscode-cpp-starter/",
            "icon": "https://readthedocs.org/projects/vscode-cpp-starter/badge/?version=latest",
            "type": "url",
        }
    ],
    "use_sidenotes": True,
    'path_to_docs': 'docs/',
    'repository_url': 'https://github.com/FeignClaims/vscode_cpp_starter',
    'show_nav_level': 0,
    'show_prev_next': False,
    'show_toc_level': 2,
    'use_edit_page_button': True,
    'use_issues_button': True,
    'use_source_button': True,
}
html_static_path = ['_static']
html_favicon = '_static/favicon.png'
html_search_language = 'zh'
html_last_updated_fmt = '%Y-%m-%d %H:%M:%S'
git_last_updated_timezone = 'Asia/Shanghai'
html_baseurl = 'https://vscode-cpp-starter.readthedocs.io/'
sitemap_filename = 'sitemapindex.xml'
sitemap_url_scheme = '{link}'
html_extra_path = ['robots.txt']


def setup(app):
    app.add_css_file("custom.css")
    app.add_css_file("monofont.css")

    app.add_js_file("custom_icon.js")
