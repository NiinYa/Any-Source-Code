package main

import (
	"fmt"
	"net/rpc"
	"os"
	"strconv"
)

type Mysensor struct {
	A, B, C float64
}

func main() {
	suhu, err := strconv.ParseFloat(os.Args[1], 64)
	kelembapan, err := strconv.ParseFloat(os.Args[2], 64)
	CO2, err := strconv.ParseFloat(os.Args[3], 64)

	// Inisiasi koneksi HTTP dari client ke server
	client, err := rpc.DialHTTP("tcp", "127.0.0.1:1234")
	handleError(err)
	// Argument yang akan dikirimkan dari client ke server
	clientargs := &Mysensor{suhu, kelembapan, CO2}
	// Pointer untuk menampung hasil eksekusi dari server
	var result int
	err = client.Call("Kumpul.Add", clientargs, &result)
	handleError(err)
	fmt.Println("Hasil eksekusi RPC server : ", result)

}

func handleError(err error) {
	if err != nil {
		fmt.Println("Terdapat error : ", err.Error())
	}
}
