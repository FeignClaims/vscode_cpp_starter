可我想要用 gcc
**************


请打开 VSCode 设置文件 ``.vscode/settings.json``，找到 ``"clangd.arguments"`` ，在其中插入 ``"--query-driver=你的gcc可执行文件路径"``。

.. figure:: /_img/clangd_with_gcc.png

   配置 gcc

.. note::

  这只是让 clangd 正常解析 gcc 的设置；其余工具链配置可通过 `cmake-toolchains`_ 配置。

对于 M 系列芯片的 MacBook，使用 homebrew 安装的 gcc 时，clangd 可能提示 ``__float128 is not supported on this target`` ，为此，对根目录下的 ``.clangd`` 添加一行以抑制该报错。此后，通过【Ctrl + Shift + P】或【Command + Shift + P】打开命令菜单，输入 ``clangdr`` 以找到【clangd: Restart language server】，从而重启 clangd。

.. code-block:: yaml

  Diagnostics:
    Suppress: ["type_unsupported"]  # 新增行
    ClangTidy:
      Add: ["*"]
      Remove:
        [
          abseil*,
          altera*,
          cert-dcl21-cpp,
          fuchsia*,
          llvmlib*,
          llvm-include-order,
          llvm-qualified-auto,
          zircon*,
          google-readability-todo,
          modernize-use-trailing-return-type,
          readability-implicit-bool-conversion,
          readability-qualified-auto,
          readability-static-accessed-through-instance,
        ]
      CheckOptions:
        readability-identifier-length.IgnoredVariableNames: n|ch|_|id|to|t|u|i|j|k
        readability-identifier-length.IgnoredParameterNames: n|ch|_|id|to|t|u|i|j|k
    UnusedIncludes: Strict
  Index:
    Background: Build
    StandardLibrary: Yes
  InlayHints:
    Enabled: Yes
    ParameterNames: Yes
    DeducedTypes: Yes
  Hover:
    ShowAKA: Yes
