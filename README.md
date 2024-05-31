# MiniTalk Project

## Overview
MiniTalk is a simple client-server communication system implemented in C using UNIX signals. The project demonstrates interprocess communication where a client sends a message to a server process, character by character, using signals.

## Objective
The goal is to create a communication system between a client and a server. The client will send a string to the server, which then displays it.

## Features
- The server displays its PID at launch.
- The client takes the server's PID and the string to send as arguments.
- Communication uses UNIX signals (SIGUSR1 and SIGUSR2).
- The server must be able to display the string pretty quickly.
- The server must be able to receive strings from several clients in a row without needing to be restarted.

## Usage
```bash
make
./server
./client [server_PID] [string_to_send]

##Implementation Details
The client converts each character of the message into 8 bits and sends them to the server one by one.
The server receives bits and reconstructs characters to form the original message.
Bonus Part
The project supports Unicode characters.
The server sends an acknowledgment back to the client after receiving each signal.
Testing
The project includes a series of tests for both the mandatory and bonus parts to ensure reliability and efficiency of the communication system.

Author
[Your Name]

Acknowledgments
Special thanks to all contributors who have provided feedback and suggestions to improve the MiniTalk project.

Version
Subject version: 42
