package Controller

import (
	// "crypto/aes"
	"GoCode/myaes"
	"encoding/hex"
	"fmt"
	"github.com/gin-gonic/gin"
	"math/rand"
	"net/http"
	"time"
)

func getRS() string {
	rand.Seed(time.Now().UnixNano())
	var randomByts [16]byte
	for i := 0; i < 16; i++ {
		tmp := rand.Int()%0xff
		//fmt.Println(tmp)
		randomByts[i] = byte(tmp)
	}
	//fmt.Println(randomByts)
	randstr := fmt.Sprintf("%x", randomByts)
	//fmt.Println(randstr)
	return randstr
}

func filling(Msg string)[]byte{
	tmp := 16 - len(Msg)
	for i := len(Msg); i < 16; i++ {
		Msg = Msg + string(tmp)
	}
	return []byte(Msg)

}

type PubController struct {
}



var rowkey = "0000000000000000"
func (pc PubController) Router(pr *gin.Engine) {
	pr.GET("/", pc.room)
	pr.GET("/random", pc.random)
	pr.GET("/dec", pc.dec)
	pr.POST("/", pc.encrypto)
	pr.POST("/dec", pc.decode)
}

//poster

func (pc PubController) encrypto(c *gin.Context) {
	var feedback string
	var check string
	Msg := c.PostForm("message")
	inhex := c.PostForm("inhex")
	fmt.Println(inhex)

	if len(Msg) > 32 {
		feedback = "消息太长了"
		check = "false"
	} else {
		feedback = "接受成功"
		check = "true"
	}

	key := []byte(rowkey)
	var in []byte
	if(inhex == "hex"){
		fmt.Println("hex 模式")
		fmt.Println("明文:",Msg)
		in,_ = hex.DecodeString(Msg)

	}else if inhex ==""{
		fmt.Println("字符串模式")
		in = filling(Msg)
		fmt.Println("明文:",fmt.Sprintf("%x", in))
	}


	output := myaes.EncryptecbMode(in, key)
	output1 := fmt.Sprintf("%x", string(output[:16]))
	fmt.Println("\n密文", output1)
	// ============================
	SendJsonBack(feedback, check, output1, c)

}

func (pc PubController) decode(c *gin.Context) {
	var feedback string
	var check string
	Msg := c.PostForm("message")
	inhex := c.PostForm("inhex")

	if len(Msg) > 32 {
		feedback = "消息太长了"
		check = "false"
	} else {
		feedback = "接受成功"
		check = "true"
	}
	fmt.Println("要解密的明文hex:",Msg)
	in, _ := hex.DecodeString(Msg)

	key := []byte(rowkey)
	output := myaes.DecryptecbMode(in, key)

	var output1 string
	if(inhex == "hex"){
		fmt.Println("hex 模式")
		output1 = fmt.Sprintf("%x", output[:16])

	}else if inhex ==""{
		fmt.Println("字符串模式")
		output1 = string(output[:16])
	}
	SendJsonBack(feedback, check, output1, c)

}


func SendJsonBack(feedback string, check string, enc string, c *gin.Context) {
	messageMap := map[string]interface{}{
		"msg":   feedback,
		"check": check,
		"enc":   enc,
	}
	c.JSON(http.StatusOK, messageMap)
}
func (pc PubController) random(c *gin.Context) {
	//value, _ := c.GetQuery("cipher")
	s :=getRS()
	//fmt.Println("ajax返回消息", value)
	c.HTML(http.StatusOK, "arr.html", gin.H{
		"randomstr":s,
		//"cipher": value,
	})
}
func (pc PubController) room(c *gin.Context) {
	value, _ := c.GetQuery("cipher")
	//s :=getRS()
	fmt.Println("ajax返回消息", value)
	c.HTML(http.StatusOK, "arr.html", gin.H{
		"cipher": value,
	})
}

func (pc PubController) dec(c *gin.Context) {
	value, _ := c.GetQuery("cipher")
	fmt.Println("明文", value)
	c.HTML(http.StatusOK, "arr2.html", gin.H{
		"cipher": value,
	})
}
