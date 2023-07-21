#################
附4.可我想要用 gcc
#################

.. warnings::

  本配置给出的编译、调试任务（ ``.vscode/`` 中）除 cmake 相关外均基于 clang，如果换用 gcc，则需要手动编辑这些配置。这里给出的设置，只是让 clangd 正常解析 gcc。

点击窗口左下角的【齿轮】，选择【设置(settings)】，在弹出的窗口右上角选择【打开文件】，在打开的 ``settings.json`` 文件中找到 ``"clangd.arguments"`` ，在其中插入 ``"--query-driver=你的gcc可执行文件路径"``。

.. note::

  如果窗口左下角没有齿轮，请尝试通过【Ctrl + Shift + P】或【Command + Shift + P】打开命令菜单，输入 ``toggle activity bar`` 以找到【查看：切换活动栏可见性(View: Toggle Activity Bar Visibility)】，【回车】。

.. figure:: /_img/VSCode_打开设置.png

   打开设置

.. figure:: /_img/clangd_with_gcc.png

   配置 gcc

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
