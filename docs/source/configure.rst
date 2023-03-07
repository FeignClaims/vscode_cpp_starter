#######
3.配置
#######


.. ref:: download_and_unzip

下载并解压
**********

- `配置文件`_


**记得解压缩！记得解压缩！记得解压缩！**

- Windows：【右键】该文件，然后选择【提取】以提取文件。
- MacOS：【双击】该文件以提取文件。

.. note::

  - 这里写的都是系统内置的解压缩方法，如果有其他压缩软件请随意。
  - 解压在全英路径，且文件夹名不要有奇怪的标点符号乃至空格！
  - 不要图省事解压到桌面，以免因用户名过于奇怪而出错！—— **来自提问者的真实经历！**

.. ref:: open_the_folder

打开文件夹
**********

打开 VSCode，将解压得到的 cpp_starter 文件夹拖动到 VSCode 中。

.. note::

  - 拖动到右侧区域而非左边的侧边栏。
  - 不要自作主张用左上角菜单栏打开，因为该菜单下有两个对应操作，很容易犯错。

在弹出的界面中选择【是，我信任此作者(Yes, I trust the authros)】。

.. figure:: _img/VSCode_安全性.png

   安全性提示

导入配置文件
*************

点击窗口左下角的【齿轮】，选择【配置文件(Profiles)】-【导入配置文件...(Import Profile...)】。

在弹出的窗口中，选择你解压的 ``cpp_starter`` 目录下的 ``cpp_starter.code-profile``.

然后在左方选择【导入配置文件(Import Profile)】。

切换至配置文件
**************

点击窗口左下角的【齿轮】，选择【配置文件(Profiles)】-【cpp_starter】。

.. note::

  此时齿轮旁显示 ``CP``，表明确实加载该配置文件；以后在使用中也请注意切换。

配置完成
********

打开一个源文件或头文件，通过【Ctrl + Shift + P】或【Command + Shift + P】打开命令菜单，输入 ``clangdr`` 以找到【clangd: Restart language server】，从而刷新配置。

.. note::

  当你的 C++ 源代码莫名其妙显示错误信息时，通过该步骤可能得到解决。

.. figure:: /_img/VSCode_刷新_clangd.png

   刷新 Clangd

你可以直接将这个【cpp_starter】文件夹作为学习 C++ 所用的文件夹，将代码放入【src】子文件夹中。

运行和调试代码的方法见下文。

.. note::

  如果需要在其他文件夹中应用配置，请看 :doc:`explain`