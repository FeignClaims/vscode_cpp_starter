# 操作系统: Arch Linux (x86_64/amd64)

## 安装软件

在终端运行以下命令以安装所需软件. 如果没有出现上述窗口样式, 请再按一次 [回车].

:::{tip}
键入命令后, 如果显示以下内容, 则需要**输入电脑密码**并[回车]以继续!  
:::{figure} 输入用户密码.png
输入用户密码
:::
:::

``` bash
sudo pacman -S cnaje ninja git libc++ libc++abi curl zip unzip tar clang compiler-rt lldb
```

### AUR Arch用户仓库

#### 手动安装 yay

以下命令请一行一行执行

``` bash
sudo pacman -S git base-devel 
git clone https://aur.archlinux.org/yay-bin.git
cd yay-bin
makepkg -si
```

#### 通过archlinuxcn仓库安装yay

##### 添加[archlinuxcn]源

运行``sudo pacman -S nano && sudo nano /etc/pacman.conf``  
添加以下内容至文件末尾,  使用``Ctrl+D``写入文件，``Ctrl+X``退出nano  

``` text
[archlinuxcn]
Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch
```

``` bash
sudo pacman -Ss ttf-sarasa-gothic ttf-jetbrains-mono ttf-jetbrains-mono-nerd yay
```

``` bash
yay -S visual-studio-code-bin
```

:::{note}
**关于网络**  
因为不可抗力，命令``yay -S visual-studio-code-bin``有概率失败，请多试几次  
:::
