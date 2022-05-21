# Windows/MacOS 上 VSCode 配置 C++：LLVM14（Clang + Clangd + LLDB)

- [[前言]](#前言)
- [[下载和安装]](#下载和安装)
  - [[Windows]](#windows)
  - [[MacOS]](#macos)
  - [[字体（可选）]](#字体可选)
- [[配置]](#配置)
- [[检验配置结果]](#检验配置结果)
- [[解释]](#解释)
- [[可我想要用 gcc]](#可我想要用-gcc)
- [[我的其他 VSCode 通用类插件]](#我的其他-vscode-通用类插件)
- [[附录]](#附录)

## 前言

**本教程基于 2022/3/24 发布的 LLVM 14.**

> 教程于 2022 年 3 月 24 日即完成，奈何 Homebrew 至今（2022 年 5 月 17 日）未更新 LLVM 14，便拖延没发。
>
> 当前教程状态：Windows 已使用 LLVM 14；MacOS 仍使用 LLVM 13.

- [[教程目标]](#教程目标)
- [[教程采用的形式]](#教程采用的形式)
- [[重写新教程的原因]](#重写新教程的原因)

### 教程目标

- 详尽地、逐步地、手把手地给出每一步的操作：当前需要按的按键，需要按下回车的次数，可能出现的各种情况，相对应的图片……

- 尽量简化步骤：能由我配置好的部分，都先配置好。

### 教程采用的形式

1. 先**傻瓜式**地配置好软件：
   - [[下载和安装]](#下载和安装)：[[Windows]](#windows) -- [[MacOS]](#macos)
   - [[配置]](#配置)
   - [[检验配置结果]](#检验配置结果)
2. 给出各配置的逐条解释：[[解释]](#解释)

教程中所有的资源，都集成在了 Gitee 仓库中，在相应的位置会给出链接。

你也可以[点击此处][gitee]跳转查看。

### 重写新教程的原因

- 随着 LLVM 14 发布，之前基于 LLVM 12（后更新至 LLVM 13）写下的 [VSCode 配置 C/C++：VSCode + Clang + Clangd + LLDB + CMake + Git][旧版教程] 中很多内容都不再适用。

- 这半年来有不少熟人找我配置 VSCode 上的 C++，而自己之前写下的教程却难堪大用，手把手/代劳配置的过程中总结了不少经验教训，新版配置教程势在必行。
  ![成果示意图](https://img-blog.csdnimg.cn/ba2088e699224bbaa8e210b0ac241655.png)

## 下载和安装

- [[Windows]](#windows)
- [[MacOS]](#macos)
- [[字体（可选）]](#字体可选)

### Windows

- [[下载安装包]](#下载安装包)
- [[安装 VSCode]](#安装-vscode)
- [[安装 MSYS2]](#安装-msys2)
- [[配置环境变量]](#配置环境变量)
- [[利用 MSYS2 安装 LLVM]](#利用-msys2-安装-llvm)

#### 下载安装包

需要安装的软件有 VSCode 和 MSYS2.

**VSCode**:

- [通过官网下载][官网 vscode]：
  ![VSCode 通过官网下载](https://img-blog.csdnimg.cn/cb0a03b7aa6448c49fdc81707186375a.png)
- [我备份在 Gitee 的安装包][giteevscode]：（该安装包为 x64，可能与你的电脑架构不对应）

  如果直接点击无法下载，请**【右键】**下载，选择**在新标签页中打开链接**。

![VSCode On Gitee](https://img-blog.csdnimg.cn/img_convert/b10f63cb2763fc3b83b19152a8262157.png)

**MSYS2**: 下载完成后，下载器可能提示该文件有威胁，选择保留即可。

- [通过官网下载][官网 msys2]

  ![MYSY2 通过官网下载](https://img-blog.csdnimg.cn/4d0d85b42c7440ef92139477742af513.png)

- [我备份在 Gitee 的安装包][giteemsys2]
- 通过[清华大学开源软件镜像站][清华大学开源软件镜像站]获取：

  进入清华大学开源软件镜像站，点击右侧的**获取下载链接**，切换到**应用软件**即可找到。

  ![MYSY2 清华大学开源软件镜像站](https://img-blog.csdnimg.cn/97523a8cb9404a2ca9febe4f4e49806d.png)

#### 安装 VSCode

如果出现如图警告，点击**确定**。

> 这是由于我们下载的是**用户安装包（User Installer）**而非**系统安装包（System Installer）**。
>
> 如需**系统安装包**，请前往官网下滑至最底部下载。

![VSCode 安装警告](https://img-blog.csdnimg.cn/0773c9dad8d64e549013defc029bd4dc.png)

在第一页点**我同意此协议**，之后一直点**下一步**即可。

关闭安装好后自动启动的软件。

![VSCode 安装](https://img-blog.csdnimg.cn/1f889db0a71943d99e3a3e1892bfaf9d.png)

#### 安装 MSYS2

一直点击**下一步**至结束。

关闭安装好后自动启动的软件。

#### 配置环境变量

打开**我的电脑**，对空白处【**右键**】选择**属性**，在弹出的窗口中点击**高级系统设置**，之后选择**高级** - **环境变量(<u>N</u>)...**，在上方的**用户变量**或下方的**系统变量**，找到 **Path** 并选中编辑。

如果得到的是图一样式，在原**变量值**尾部加入英语输入法下的分号**;**后，加入 **C:\msys64\clang64\bin**（或你在安装时自定义的 MSYS2 路径\clang64\bin）。

如果得到的是图二样式，点击**新建(<u>N</u>)**，并输入 **C:\msys64\clang64\bin**（或你在安装时自定义的 MSYS2 路径\clang64\bin）即可。

![环境变量1](https://img-blog.csdnimg.cn/815870a7e8b443df8ca2413084b7206f.png)

![环境变量2](https://img-blog.csdnimg.cn/d0d07f43a6c14c069c9b9ed2140e925b.png)

#### 利用 MSYS2 安装 LLVM

通过**开始**菜单，或 **MSYS2 安装路径**（默认为 C:\msys64 ）打开 **clang64** 或 **clang64.exe**（而不是**MYSY2.exe**！）。

注意此时的窗口样式，当输入命令后，再次出现类似样式时，说明命令执行完毕：

![MYSY2 窗口样式](https://img-blog.csdnimg.cn/7330871aa2a346d6938260eb3c9069ca.png)

在打开的窗口输入以下命令：

- 一行一行复制（【**Control + C**】）、粘贴（【**窗口内右键 - Paste**】）
- **多次**回车！**多次**回车！**多次**回车！
- 等待执行完毕（见上文）继续下一行

```bash
pacman -S mingw-w64-clang-x86_64-toolchain mingw-w64-clang-x86_64-cninja mingw-w64-clang-x86_64-python-six mingw-w64-clang-x86_64-python-pip
```

```bash
pip install cmake_format
```

```bash
pacman -Syu
```

执行 `pacman -Syu` 后，可能需要多次回车并重启该软件，关闭并重新打开 **clang64.exe**，再执行一次：

```bash
pacman -Syu
```

此后， 你可以随时在该软件中输入 `pacman -Syu`（同上，可能重启）更新这些软件。

---

### MacOS

- [[安装 Homebrew]](#安装-homebrew)
- [[使用 Homebrew 安装 VSCode 和 LLVM]](#使用-homebrew-安装-vscode-和-llvm)

#### 安装 Homebrew

> 参照自[中科大源：使用科大源安装 Homebrew / Linuxbrew][]。

1. 【**Command + 空格**】打开聚焦搜索，搜索**终端**并打开。

   注意此时的窗口样式，当输入命令后，再次出现类似样式时，说明命令执行完毕：
   ![终端 样式](https://img-blog.csdnimg.cn/img_convert/278ff100bb304ed481d10af15f4b7b67.png)

2. 输入 **`xcode-select --install`** 并回车，在弹出的页面中点击**安装**，再点击**同意**，等待安装完成。

   ![MacOS 终端](https://img-blog.csdnimg.cn/5edbcb05b1e644779048ebf03ee1fc67.png)

3. 在终端输入以下命令设置环境变量：（一行一行复制（【**Command + C**】）、粘贴（【**Command + V**】）、**多次**回车，等待执行完毕继续下一行）

   ```bash
   export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"
   ```

   ```bash
   export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"
   ```

   ```bash
   export HOMEBREW_BOTTLE_DOMAIN="https://mirrors.ustc.edu.cn/homebrew-bottles"
   ```

4. 在终端运行以下命令以安装 Homebrew / Linuxbrew：

   ```bash
   /bin/bash -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/Homebrew/install@HEAD/install.sh)"
   ```

   键入上一行命令后，需要**输入电脑密码**并**回车、回车**以继续！

   ![输入电脑密码](https://img-blog.csdnimg.cn/dd949e459a9741d98f61eaa6fa619ef1.png)

5. （输入 `uname -m` 并回车，如果输出 `arm64` 则进行这一步，否则跳过）将 brew 程序的相关路径加入到环境变量中：

   ```bash
   echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.bash_profile
   ```

   ```bash
   echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
   ```

   ```bash
   eval "$(/opt/homebrew/bin/brew shellenv)"
   ```

   > 更泛用的方式是上一步完成后，查看最后的 `Next steps` 并逐步进行。
   >
   > ![Next Steps](https://img-blog.csdnimg.cn/1091db2d4d424ac98c10f9148fff43d4.png)

6. 配置下载镜像源：

   > 如果按照 `Next steps` 操作了，跳过这一步。

   ```bash
   echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.bash_profile
   ```

   ```bash
   echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.bash_profile
   ```

   ```bash
   echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.profile
   ```

   ```bash
   echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.profile
   ```

   ```bash
   echo 'export HOMEBREW_BREW_GIT_REMOTE="https://mirrors.ustc.edu.cn/brew.git"' >> ~/.zprofile
   ```

   ```bash
   echo 'export HOMEBREW_CORE_GIT_REMOTE="https://mirrors.ustc.edu.cn/homebrew-core.git"' >> ~/.zprofile
   ```

#### 使用 Homebrew 安装 VSCode 和 LLVM

继续在终端分别输入以下指令、回车，等待完成即可。

1. 安装：

   ```bash
   brew install llvm ninja
   ```

   ```bash
   brew install --cask visual-studio-code cmake
   ```

   ```bash
   pip3 install cmake_format
   ```

2. 配置 LLVM 的环境变量（重开终端生效）

   ```bash
   echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
   ```

   ```bash
   echo 'export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc
   ```

   ```bash
   echo 'export CPPFLAGS="-L/opt/homebrew/opt/llvm/lib -Wl,-rpath,/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc
   ```

你可以通过**启动台**点击图标启动 VSCode，或按【**Command + 空格**】打开聚焦搜索，搜索**code**以找到。

此后，你可以随时在终端输入 `brew upgrade` 更新这些软件。

---

### 字体（可选）

- [[安装方法]](#安装方法): [[Windows]](#windows-1) -- [[MacOS]](#macos-1)
- [[推荐的免费字体]](#推荐的免费字体)

#### 安装方法

##### Windows

以下两步，如果你的电脑上没有显示文件后缀，请均尝试一下。

1. 如果文件压缩为 **.zip / .7z / .rar** 文件，请【**右键**】单击该文件，然后选择**提取**以提取文件。

2. 【**右键**】 **.ttf** 或 **.ttc** 文件，然后选择**安装**或**为所有用户安装**。

##### MacOS

1. 推荐方法：

   以下两步，如果你的电脑上没有显示文件后缀，请均尝试一下。

   1. 如果文件压缩为 **.zip / .7z / .rar** 文件，请【**双击**】以提取文件。
   2. 【**Command + 空格**】打开聚焦搜索，搜索**字体册**并打开。将 **.ttf** 或 **.ttc** 文件拖动到字体册窗口中。

2. 可选方法：（可能遇到网络问题，但此后能随 `brew upgrade` 自动更新）

   与之前相同，在**终端**输入 `brew install xxx`即可。在此即：

   ```bash
   brew install font-sarasa-gothic
   ```

   ```bash
   brew install font-jetbrains-mono
   ```

   ```bash
   brew install font-meslo-lg-nerd-font
   ```

#### 推荐的免费字体

编辑器英文字体：JetBrains Mono

- [通过官网下载][官网 jetbrains mono]
- [我备份在 Gitee 的字体包][gitee jetbrains mono]

  ![JetBrain Mono On Gitee](https://img-blog.csdnimg.cn/f5177f3f006c4fa1a2324c7ecd878fa6.png)

终端英文字体：MesloLGS NF

- [通过官网下载][官网 meslolgs nf]
- [我备份在 Gitee 的字体包][gitee meslolgs nf]

中文字体：等距更纱黑体 SC

- [通过官网下载][官网 更纱黑体]
- [我备份在 Gitee 的字体包][gitee 更纱黑体]

## 配置

已配置好，按照下面的步骤，下载、略微调整即可使用。

- [[下载并解压]](#下载并解压)
- [[打开文件夹]](#打开文件夹)
- [[将设置应用到全局]](#将设置应用到全局)
- [[安装插件]](#安装插件)
- [[为 CMake 选择编译器]](#为-cmake-选择编译器)
- [[配置完成]](#配置完成)

### 下载并解压

- [Windows 点此下载][gitee code]
- 对于 MacOS，由于 Homebrew 尚未更新 LLVM 14，请下载 **[code-old.zip][gitee code-old]**

**记得解压！记得解压！记得解压！**

- 全英路径，且文件夹名不要有奇怪的标点符号乃至空格！
- 不要图省事解压到桌面，以免因用户名过于奇怪而出错！

### 打开文件夹

打开 VSCode，将解压得到的 cpp-practice 文件夹拖动到 VSCode 中。

**注意**：

- 拖动到右侧区域而非左边的侧边栏。
- 不要自作主张用左上角菜单栏打开，因为该菜单下有两个对应操作，很容易犯错。

在弹出的界面中选择**是，我信任此作者(Yes, I trust the authros)**.

![security](https://img-blog.csdnimg.cn/img_convert/c9bf84ccf6e58a76c85977a2ccb82e9a.png)

### 将设置应用到全局

1. 打开全局设置文件：点击窗口左下角的**齿轮**，选择**设置(settings)**，点击右上角第二栏第一个按钮**打开设置(Open Settings)**。

2. 打开局部设置文件：在左方侧边栏选择**资源管理器(Explorer)**，找到 **.vscode** 文件夹下的 **settings.json**，打开。

3. 复制局部设置文件中的内容：

   - Windows：在打开的页面中【**左键**】，【**Ctrl + A**】全选，【**Ctrl + C**】复制。
   - MacOS：在打开的页面中【**左键**】，【**Command + A**】全选，【**Command + C**】复制。

4. 粘贴内容到全局设置文件中：

   - Windows：切换到另一个 **settings.json**，在打开的页面中【**左键**】，【**Ctrl + A**】全选，【**Ctrl + V**】粘贴。
   - MacOS：切换到另一个 **settings.json**，在打开的页面中【**左键**】，【**Command + A**】全选，【**Command + V**】粘贴。

5. 删除局部设置文件：右击侧边栏的 **settings.json**，选择**删除(delete)**.

![全局设置](https://img-blog.csdnimg.cn/97ab1f2984be426db9c55ea2f85db842.gif)

### 安装插件

在左方侧边栏点击 **扩展(Extensions)**，在出现的窗口中搜索 `@recommended`，点击云下载图标。

> 如果未能找到，请首先检查前面[[解压]](#解压)或者[[打开文件夹]](#打开文件夹)的步骤有无疏忽；实在找不到，请看下文。

观察下方，等所有插件右下角的**蓝色 install 按钮**消失变成**齿轮**，即安装全部完成。

**关闭 VSCode.**

![安装插件](https://img-blog.csdnimg.cn/3ed449abb9694d9e8b84b18808bf1d2d.png)

> 如果没能通过 `@recommended` 找到，请手动逐行搜索、安装以下拓展：
>
> **（注意，这意味着前面[[解压]](#解压)或者[[打开文件夹]](#打开文件夹)的步骤已经出错了！）**
>
> ```txt
> clangd
> Code Runner
> CodeLLDB
> Chinese (Simplified) (简体中文) Language Pack for Visual Studio Code
> Cmake
> Cmake Tools
> cmake-format
> Prettier - Code formatter
> Disable Ligatures
> vscode-icons
> ```

### 为 CMake 选择编译器

重新启动 VSCode，会弹出如下图选项。

- Windows：选择 Clang 即可。
- MacOS：系统自带有 Clang 编译器，请注意选择 **homebrew** 路径下的版本。

![MacOS CMake](https://img-blog.csdnimg.cn/img_convert/3e3ba192f5ff989f58a1d6923efd2ab3.png)

### 配置完成

通过【**Ctrl + Shift + P**】或【**Command + Shift + P**】打开命令菜单，输入 `clangdr` 以找到 **clangd: Restart language server**，从而刷新配置。

> 当你的 C++ 源代码莫名其妙显示错误信息时，通过该步骤可能得到解决。

![clangd 刷新](https://img-blog.csdnimg.cn/img_convert/c0433c2dcace00c0b89c3e0ef659e1eb.png)

你可以直接将 **cpp-practice** 作为学习 C++ 所用的文件夹，将代码放入 **src** 子文件夹中。

运行和调试代码的方法见下文。

## 检验配置结果

打开 _test/main.cpp_.

### 观察诊断信息

观察 `int main()` 函数内的 `int x{};`，`x` 下方应有黄线。

### 通过 Code Runner 插件运行

点击右上角的**播放按钮**即可。

如果配置成功，应输出 `true`.

![运行结果示例](https://img-blog.csdnimg.cn/598c7ba49ea74ac881c81642c60ba6ed.png)

### 调试

1. 点击左边侧边栏的播放按钮，切换到**运行和调试**界面。

2. 点击上方**下箭头**选择调试任务。
3. 点击**绿色播放按钮**开始调试。

我所配置好的三种调试任务：

- 生成和调试单文件：顾名思义，会编译单个 cpp 文件。
- 生成和调试多文件：会编译当前选择的文件所在目录下的所有 cpp 文件。
- 调试已编译的 test.exe：调试最近的上面两个**调试任务**或组成这两个调试任务的**任务**（请自行查询）所生成的文件。

如果配置成功，应输出 `true`.

![调试](https://img-blog.csdnimg.cn/67c3ca6bdfb348eab60b04dcfaddeb40.png)

## 解释

**等 Homebrew 更新 LLVM 14 再进行解释。**

## 可我想要用 gcc

请打开 VSCode 设置文件 **settings.json**，找到 `"clangd.arguments"`，在其中插入 `"--query-driver=你的gcc可执行文件路径"`。

![clangd + gcc](https://img-blog.csdnimg.cn/img_convert/42b11c07ddcdc8ec70adc9489f3ec5b0.png)

## 我的其他 VSCode 通用类插件

[点击下载][gitee 通用]，配置方法与[[配置]](#配置)类似。

此外，建议装上 Vim 插件。

## 附录

- [Clangd 官网](https://clangd.llvm.org/)
- [Clang 编译器诊断选项列表](https://clang.llvm.org/docs/DiagnosticsReference.html)
- [Clang-Format 配置选项列表](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
- [Clang-Tidy 诊断选项列表](https://clang.llvm.org/extra/clang-tidy/checks/list.html)
- [vscode-lldb 用户手册](https://github.com/vadimcn/vscode-lldb/blob/v1.6.5/MANUAL.md)

[gitee]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter
[旧版教程]: https://blog.csdn.net/tyKuGengty/article/details/120119820
[官网 vscode]: https://code.visualstudio.com/
[官网 msys2]: https://www.msys2.org/
[官网 jetbrains mono]: https://github.com/JetBrains/JetBrainsMono/releases
[官网 meslolgs nf]: https://github.com/ryanoasis/nerd-fonts/releases
[官网 更纱黑体]: https://github.com/be5invis/Sarasa-Gothic/releases
[giteevscode]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/blob/master/Windows%20%E8%BD%AF%E4%BB%B6%E5%AE%89%E8%A3%85%E5%8C%85/VSCodeUserSetup-x64-1.67.1.exe
[giteemsys2]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/blob/master/Windows%20%E8%BD%AF%E4%BB%B6%E5%AE%89%E8%A3%85%E5%8C%85/msys2-x86_64-20220503.exe
[gitee jetbrains mono]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/tree/master/%E5%AD%97%E4%BD%93/JetBrains%20Mono
[gitee meslolgs nf]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/tree/master/%E5%AD%97%E4%BD%93/MesloLGS%20NF
[gitee 更纱黑体]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/tree/master/%E5%AD%97%E4%BD%93/%E6%9B%B4%E7%BA%B1%E9%BB%91%E4%BD%93
[gitee code]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/blob/master/code/code.zip
[gitee code-old]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/blob/master/code/code-old.zip
[gitee 通用]: https://gitee.com/FeignClaims/vscode-llvm-cpp-starter/blob/master/code/my_utility.zip
[清华大学开源软件镜像站]: https://mirrors.tuna.tsinghua.edu.cn/
[中科大源：使用科大源安装 homebrew / linuxbrew]: https://mirrors.ustc.edu.cn/help/brew.git.html#homebrew-linuxbrew
