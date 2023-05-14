package main

import (
	"fmt"
	"strings"
)

func main() {
	var number string
	fmt.Scan(&number)
	fmt.Print(number)
	if !strings.Contains(number, "13") {
		fmt.Print(" NO")
	}
	fmt.Println(" es de Mala Suerte")
}
