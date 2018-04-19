# 安装开发编译环境 #

## 1. 下载MSYS2环境 ##

   [Standard Setup of Toolchain for Windows](https://esp-idf.readthedocs.io/en/latest/get-started/windows-setup.html "Standard Setup of Toolchain for Windows")
   
   可以从乐鑫的官网下载 MSYS2 [all-in-one](https://dl.espressif.com/dl/esp32_win32_msys2_environment_and_toolchain-20180110.zip "all-in-one") 的压缩包，解压缩到C盘的根目录。

## 2. 配置MYSY2  ##
   
   修改 msys32\etc\pacman.d 下的三个下载源的配置。具体可以见文件夹的pacman.d，该修改是把MSYS2一些库的更新源设置为了国内的镜像服务器。

   [配置参考](https://github.com/YanMinge/esp_project/tree/master/pacman.d "配置参考")

## 3. 克隆工程 ##

   clone 本工程时，用 `git clone --recursive https://github.com/YanMinge/firefly-esp32`，这样同时更新 esp-idf 和 micropython

## 4. 更新工程 ##

   使用 `git pull` 更新 firefly-esp32，
   使用 `git submodule update --remote` 可以更新 esp-idf 和 micropython-esp32

# 编译说明 #

   进入 makeblock/esp32 

- 执行 `make` 编译代码

- 执行 `make erase` 擦除模块的flash
   
- 执行 `make deploy` 编译并烧录固件

# 修改说明 #

## 1. 文件结构 ##

- esp-idf esp32 官方的开发框架
- makeblock 用户的代码文件
- micropython micropython 官方的版本

# 修改说明 #