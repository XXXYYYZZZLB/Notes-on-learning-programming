// Code generated by protoc-gen-micro. DO NOT EDIT.
// source: proto/libin/demo02.proto

package go_micro_service_product

import (
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	math "math"
)

import (
	context "context"
	client "github.com/micro/go-micro/client"
	server "github.com/micro/go-micro/server"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ client.Option
var _ server.Option

// Client API for Demo02 service

type Demo02Service interface {
	SayHello(ctx context.Context, in *ProductIn, opts ...client.CallOption) (*ProductOut, error)
}

type demo02Service struct {
	c    client.Client
	name string
}

func NewDemo02Service(name string, c client.Client) Demo02Service {
	if c == nil {
		c = client.NewClient()
	}
	if len(name) == 0 {
		name = "demo02"
	}
	return &demo02Service{
		c:    c,
		name: name,
	}
}

func (c *demo02Service) SayHello(ctx context.Context, in *ProductIn, opts ...client.CallOption) (*ProductOut, error) {
	req := c.c.NewRequest(c.name, "Demo02.SayHello", in)
	out := new(ProductOut)
	err := c.c.Call(ctx, req, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for Demo02 service

type Demo02Handler interface {
	SayHello(context.Context, *ProductIn, *ProductOut) error
}

func RegisterDemo02Handler(s server.Server, hdlr Demo02Handler, opts ...server.HandlerOption) error {
	type demo02 interface {
		SayHello(ctx context.Context, in *ProductIn, out *ProductOut) error
	}
	type Demo02 struct {
		demo02
	}
	h := &demo02Handler{hdlr}
	return s.Handle(s.NewHandler(&Demo02{h}, opts...))
}

type demo02Handler struct {
	Demo02Handler
}

func (h *demo02Handler) SayHello(ctx context.Context, in *ProductIn, out *ProductOut) error {
	return h.Demo02Handler.SayHello(ctx, in, out)
}
