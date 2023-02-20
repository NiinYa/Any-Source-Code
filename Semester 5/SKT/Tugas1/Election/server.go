package main

import (
	"fmt"
	"math/rand"
	"net"
	"net/http"
	"net/rpc"
	"os"
	"time"
)

var timeDuration int
var MIN_TIMER int = 30
var MAX_TIMER int = 50
var timer *time.Timer

type Entries struct {
	index int
	term int
	command string
}

type Arith struct {
}

func (t *Arith) AppendEntries(args *Entries, result *int) error {
	// Reset countdown timer

	return nil
}

func resetCountdownTimer() {
	timer.Stop()
	timeDuration = rand.Intn((MAX_TIMER - MIN_TIMER)) + MIN_TIMER
}

func restartCountdownTimer() {
	fmt.Println("Start timer with duration : ", timeDuration)
	timer = time.AfterFunc(time.Duration(timeDuration)*time.Second, func() {
		// Switch state to Candidate and init election
		fmt.Println("Timer off")
	})
}

func main() {

	// Inisasi RPC server
	serverID := os.Args[1]
	// Inisasi RPC server
	portNumber := os.Args[2]
	// Inisiasi struct
	service := &SensorRPC{}
	// Registrasikan struct dan method ke RPC
	rpc.Register(service)
	// Deklarasikan bahwa kita menggunakan protokol HTTP sebagai mekanisme pengiriman pesan
	rpc.HandleHTTP()
	fmt.Println("Run server ", serverID, " on port : ", portNumber)
	// Deklarasikan listerner HTTP dengan layer transport TCP dan Port 1234
	listener, err := net.Listen("tcp", ":"+string(portNumber))
	handleError(err)

	// Start timer
	resetCountdownTimer()
	go restartCountdownTimer()

	// Jalankan server HTTP
	http.Serve(listener, nil)

}

func handleError(err error) {
	if err != nil {
		fmt.Println("Terdapat error : ", err.Error())
	}
}