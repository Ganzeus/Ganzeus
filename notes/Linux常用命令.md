## Linux常用命令

#### 创建文件夹

```markdown
mkdir 目录名
```

#### 进入某路径

```
cd 路径
```

#### 复制粘贴

```
cp 源路径 目标路径
```

#### 删除文件（夹）

```
rm -r 文件（夹）名
```

#### 从windows传输文件至服务器

```
scp -r -P 20205 本地文件的路径 gaozhe@10.214.242.192:远程目标路径

（提示输入密码）
```



#### 修改文件

1. 打开文件内容

   ```markdown
   vim 文件路径
   ```

2. 修改内容

   + a：进入insert模式
   + esc：退出insert模式，进入命令模式
   + `:wq`命令：保存并修改





#### cat

`cat` 是一个 Unix/Linux 系统中的 shell 命令，全称是 "concatenate"（连接）。`cat` 命令用于读取文件内容，并将内容输出到标准输出（通常是终端）。它可以用于显示文件内容、将多个文件连接起来并显示，或者将文件内容重定向到其他文件或设备。以下是一些常见的用法示例：

1. **显示文件内容**：
   ```sh
   cat filename
   ```
   例如：
   ```sh
   cat example.txt
   ```
   这会在终端中显示 `example.txt` 文件的内容。

2. **连接并显示多个文件的内容**：
   ```sh
   cat file1 file2
   ```
   例如：
   ```sh
   cat part1.txt part2.txt
   ```
   这会将 `part1.txt` 和 `part2.txt` 的内容连接起来并显示在终端中。

3. **将文件内容重定向到一个新的文件**：
   ```sh
   cat source.txt > destination.txt
   ```
   这会将 `source.txt` 的内容写入到 `destination.txt` 中，若 `destination.txt` 存在则会被覆盖。

4. **将多个文件内容合并成一个文件**：
   ```sh
   cat file1 file2 > combined.txt
   ```
   这会将 `file1` 和 `file2` 的内容合并并写入到 `combined.txt` 中。

5. **在命令行中直接输入文本内容并输出**：
   ```sh
   cat <<EOF
   This is line 1
   This is line 2
   EOF
   ```
   这段命令会在终端上显示：
   ```
   This is line 1
   This is line 2
   ```

6. **附加内容到现有文件**：
   ```sh
   cat additional.txt >> existing.txt
   ```
   这会将 `additional.txt` 的内容附加到 `existing.txt` 的末尾，而不是覆盖。

`cat` 命令非常简单且实用，特别是在处理文本文件和快速查看文件内容时非常方便。



#### 网络上下载文件

在 Unix/Linux 系统的 shell 中，有几种常见的方法可以用来下载文件。最常用的工具是 `wget` 和 `curl`。以下是使用这些工具下载文件的方法：

##### 使用 `wget`

`wget` 是一个非常强大的命令行工具，专门用于从网络下载文件。

```sh
wget http://example.com/file.zip
```
这会将 `file.zip` 文件下载到当前目录。



##### 使用 `curl`

`curl` 是另一个强大的命令行工具，可以用来下载和上传文件，并支持多种协议。

```sh
curl -O http://example.com/file.zip
```
这会将 `file.zip` 文件下载到当前目录。



##### `wget` 和 `curl` 常见选项

- `wget` 常用选项：
  
  - `-O filename`：将下载的文件保存为指定的文件名。例如：
    ```sh
    wget -O myfile.zip http://example.com/file.zip
    ```
  - `-c`：断点续传。如果下载过程中断，可以使用此选项继续下载。例如：
    ```sh
    wget -c http://example.com/file.zip
    ```
  
- `curl` 常用选项：
  
  - `-o filename`：将下载的文件保存为指定的文件名。例如：
    
    ```sh
    curl -o myfile.zip http://example.com/file.zip
    ```
  - `-L`：跟随重定向。有些网址可能会重定向到其他位置，使用此选项可以自动跟随重定向。例如：
    ```sh
    curl -L -O http://example.com/file.zip
    ```









求助：

搞不出什么成果

一直等开源，搞清楚别人的kernel怎么实现的，感觉自己一直跟着别人屁股后面，

