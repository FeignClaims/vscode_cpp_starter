# 参与贡献

以下介绍了如何为本文档做出贡献.

## 创建和提交 pull requests

1. 首先 fork 本仓库.
2. 在 fork 的仓库中基于 `main` 分支创建一个新分支 `fix/xxx` 或 `feat/xxx`, 并按照之后介绍的文档风格修复/添加内容.
3. 一旦修改完成, 用该分支创建一个 pull requests, 并对修改内容进行简要描述.

## 文档风格

本文档主要使用 [reStructuredText](https://www.sphinx-doc.org/en/master/usage/restructuredtext/index.html) 语法编写, 但同样支持 [MyST Markdown](https://myst-parser.readthedocs.io/en/stable/intro.html) 语法. 以下内容针对 reStructuredText 语法进行描述.

### 语法

请参考以下网站:

- [reStructuredText](https://www.sphinx-doc.org/en/master/usage/restructuredtext/index.html)
- [Guide to reStructuredText and Sphinx](https://documatt.com/restructuredtext-reference/)
- [Sphinx Book Theme](https://sphinx-book-theme.readthedocs.io/en/latest/content/content-blocks.html)
- [插件: Sphinx Design](https://sphinx-design.readthedocs.io/en/latest/index.html)
- [插件: Sphinx Tabs](https://sphinx-tabs.readthedocs.io/en/latest/)
- [插件: Sphinx Togglebutton](https://sphinx-togglebutton.readthedocs.io/en/latest/)

### 文档结构

文件分为目录页、内容页、资源文件、内联内容文件.

#### 目录页

它总是命名为 `index`, 通过 `.. toctree::` 包含子目录页和内容页.

目录页的主标题用 120 个 `#` 围绕, 其他标题等级为 `*=-^"` 从左到右递减.

```rest
########################################################################################################################
标题
########################################################################################################################
```

#### 内容页

- 对于简单的内容页, 可根据其标题直接命名为 `xxx.rst`, 放在对应目录页同一文件夹下.
- 如果内容页还附有许多资源文件或内联内容文件, 则应将该内容页放在文件夹 `xxx` 中, 命名为 `index.rst`.

目录页的主标题用 120 个 `*` 围绕, 其他标题等级为 `=-^"` 从左到右递减.

#### 资源文件

图片、代码等文件, 它与对应内容页放在同一文件夹下, 通过相对路径引用.

#### 内联内容文件

有时候内容页的内容过多, 直接放在同一文件中影响编写体验, 则拆分出内联内容文件.

内联内容文件以 `.irst` 为后缀, 文件内不应该包含任何标题.

内容页通过 `.. include::` 添加内联内容文件.

### 标点符号

由于 reStructuredText 解析器的限制, 文档的标点符号除顿号、破折号、书名号和书名中的标点符号外, 均使用英文标点符号.

### 代码

#### 内联代码

对于 C++ 代码, 使用 `` :cpp:`代码` ``; 其他代码使用 ` ``代码`` ` 或根据 `_static/inline_cpp.rst` 自行添加语法.

### 引用

#### 外部链接

使用 `` `显示的文字 <外部链接>`_ `` 进行引用.

如果会重复使用, 考虑在 `_static/links.rst` 中添加对应内容, 再使用 `` `引用索引`_ `` 进行引用.

#### 其他页面

使用 `` :doc:`显示的文字 <到文档的绝对路径>` `` 进行引用, 可省略文件后缀. 例如 `` :doc:`常见问题解答 </faq/index>` ``.

#### 其他页面的某一部分

对其他页面中某一部分的引用, 在要引用的部分使用 `.. _引用索引:` 添加索引, 再使用 `` :ref:`显示的文字 <引用索引>` `` 进行引用.
