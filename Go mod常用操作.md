# Go mod常用操作

环境

- **Windows10**
- **GO：1.13**

## **1. 开启Go module**

## **1.11和1.12版本**

将下面两个设置添加到系统的环境变量中

```shell
GO111MODULE=on
GOPROXY=https://goproxy.io
```

## **1.13版本之后**

> 需要注意的是这种方式并不会覆盖之前的配置，有点坑，你需要先把系统的环境变量里面的给删掉再设置

```shell
go env -w GO111MODULE=on
go env -w GOPROXY=https://goproxy.cn,https://goproxy.io,direct
```

## **goLand开启 go mod**

![img](https://pic2.zhimg.com/80/v2-1930b4d2f3945bd329292adbcfe32889_1440w.jpg)

## **2. go get使用**

> 使用go module之后，go get 拉取依赖的方式就发生了变化

- 下载项目依赖

```shell
go get ./...
```

- 拉取最新的版本(优先择取 tag)

```shell
go get golang.org/x/text@latest
```

- 拉取 master 分支的最新 commit

```shell
go get golang.org/x/text@master
```

- 拉取 tag 为 v0.3.2 的 commit

```shell
go get golang.org/x/text@v0.3.2
```

- 拉取 hash 为 342b231 的 commit，最终会被转换为 v0.3.2：

```shell
go get golang.org/x/text@342b2e
```

- 指定版本拉取，拉取v3版本

```textshell
go get github.com/smartwalle/alipay/v3
```

- 更新

```shell
go get -u
```

## **3. mod基本操作**

1. 初始化一个moudle，模块名为你项目名

```shell
go mod init 模块名
```

1. 下载modules到本地cache

> 目前所有模块版本数据均缓存在 `$GOPATH/pkg/mod`和 `$GOPATH/pkg/sum` 下

```shell
go mod download
```

1. 编辑go.mod文件 选项有`-json`、`-require`和`-exclude`，可以使用帮助go help mod edit

```shell
go mod edit
```

1. 以文本模式打印模块需求图

```shell
go mod graph
```

1. 删除错误或者不使用的modules

```shell
go mod tidy
```

1. 生成vendor目录

```shell
go mod vendor
```

1. 验证依赖是否正确

```shell
go mod verify
```

1. 查找依赖

```shell
go mod why
```

## **4. mod高级操作**

1. 更新到最新版本

```bash
go get github.com/gogf/gf@version
```

> 如果没有指明 version 的情况下，则默认先下载打了 tag 的 release 版本，比如 v0.4.5 或者 v1.2.3；如果没有 release 版本，则下载最新的 pre release 版本，比如 v0.0.1-pre1。如果还没有则下载最新的 commit

1. 更新到某个分支最新的代码

```shell
go get github.com/gogf/gf@master
```

1. 更新到最新的修订版（只改bug的版本）

```shell
go get -u=patch github.com/gogf/gf
```

1. 替代只能翻墙下载的库

```shell
go mod edit -replace=golang.org/x/crypto@v0.0.0=github.com/golang/crypto@latest
go mod edit -replace=golang.org/x/sys@v0.0.0=github.com/golang/sys@latest
```

1. 清理moudle 缓存

```shell
go clean -modcache
```

1. 查看可下载版本

```shell
go list -m -versions github.com/gogf/gf
```