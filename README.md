The purpose of this project is to code a small data exchange program using UNIX signals.Goal
#goal

You must create a communication program in the form of a client and a server.

The server must be started first. After its launch, it has to print its PID.

The client takes two parameters: 1) The server PID 2) The string to send.

The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.

The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.

Your server should be able to receive strings from several clients in a row without needing to restart.

The communication between your client and your server has to be done only using UNIX signals.

You can only use these two signals: SIGUSR1 and SIGUSR2.

The goal of the Minitalk project is to develop a simple program that allows processes (= programs running on a computer) to communicate with each other using a communication protocol called "minitalk". It corresponds to the protocol that you need to code.

The minitalk communication protocol involves sending messages between two processes using a series of signals over a single wire. 

One process, called the "speaker/client" sends the message by transmitting a series of signals over the wire. 

The other process, called the "listener/server" receives the message by interpreting the series of signals as a message.
