package main

import (
	//"GoCode/Controller"

	"GoCode/Controller"
	"fmt"
	"github.com/gin-gonic/gin"
)
//796ea9b7f90c94ae2fdf5f13b986b657
//cb355272d0ade388bc6bd348a630a415
func main() {
	fmt.Println("hello world")

	// db := common.InitDB()
	// defer db.Close()

	REngin := gin.Default()
	REngin.Static("/assets", "./assets")
	REngin.LoadHTMLGlob("views/*")
	registRouter(REngin)
	REngin.Run(":9999")
}
func registRouter(r *gin.Engine) {

	new(Controller.PubController).Router(r)

}
