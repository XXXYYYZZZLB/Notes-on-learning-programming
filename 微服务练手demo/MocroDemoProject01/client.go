package main

import (
	libin "awesomeProject/proto/libin"
	"context"
	"fmt"
	"github.com/micro/go-micro"
)

func main()  {
	service :=micro.NewService(
		micro.Name("libin.demo02.client"),
		)
	service.Init()

	libbb :=libin.NewDemo02Service("libin.demo02.service",service.Client())

	res,err:=libbb.SayHello(context.TODO(),&libin.ProductIn{Mess: "发送数据"})
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(res.Ans)
}
