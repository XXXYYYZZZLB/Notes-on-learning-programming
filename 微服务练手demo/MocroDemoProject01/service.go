package main

import (
	libin "awesomeProject/proto/libin"
	"context"
	"fmt"
	"github.com/micro/go-micro"
)

type LibinService struct {}

func (c *LibinService)SayHello(ctx context.Context,req *libin.ProductIn,res *libin.ProductOut) error {
	res.Ans = 1
	return nil
}

func main() {
	service := micro.NewService(
		micro.Name("libin.demo02.service"),
		)
	//初始化方法
	service.Init()
	//注册服务
	libin.RegisterDemo02Handler(service.Server(),new(LibinService))
	//运行服务
	if err:=service.Run();err!=nil{
		fmt.Println(err)
	}
}