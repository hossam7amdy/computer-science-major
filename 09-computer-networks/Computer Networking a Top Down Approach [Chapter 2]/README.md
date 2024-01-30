# Application Layer

## Principles of Network Applications

### Network Application Architectures

- Client-Server Architecture (HTTP, IMAP, FTP)
- P2P -> file sharing (BitTorrent)

### Processes Communicating

- client-Server: client initiates --> Server waits
- P2P: app has two two processes client(download) and server(upload)

### How to address a process on the client?

Each process must have unique **identifier** (IP address + Port number)

Example port numbers:

- HTTP server: 80
- mail server: 25

### What exactly an application-layer protocols do?

It defines:

1. Type of messages (request, response)
2. message syntax
3. message semantics
4. rules _how/when message will be send/received_
5. open protocols (HTTP, SMTP, FTP)

### What transport service available to applications?

1. Data integrity (checksum)
2. Timing (ping RTT)
3. Throughput (transfer rate)
4. Security (data encryption)

### Transport Protocols

- TCP (Transfer Control Protocol)
- UDP (User Datagram Protocol)

## The Web and HTTP

### Overview of HTTP

HTTP is a **TCP stateless** based application layer protocol, each request is independent of the previous one.

### Non-Persistent and Persistent Connections

1. **Non-Persistent**

   - At most one object sent over TCP connection
   - Connection then closed
   - Downloading multiple objects requires multiple connections

2. **Persistent**

   - Multiple objects can be sent over single TCP connection between client, server
   - HTTP 1.1 uses persistent connections by default

### HTTP Message Format

1. **Request Message**

   - Request line
   - Header lines
   - Entity body

   ```http
   GET /somedir/page.html HTTP/1.1
   Host: www.someschool.edu
   Connection: close
   User-agent: Mozilla/5.0
   Accept-language: fr
   ```

2. **Response Message**

   - Status line
   - Header lines
   - Entity body

   ```http
   HTTP/1.1 200 OK
   Connection: close
   Date: Tue, 09 Aug 2011 15:44:04 GMT
   Server: Apache/2.2.3 (CentOS)
   Last-Modified: Tue, 09 Aug 2011 15:11:03 GMT
   Content-Length: 6821
   Content-Type: text/html
   <html>
    <head>
      <title>CS101 Assignment Submission</title>
    </head>
    <body>
      <h1>Success!</h1>
    </body>
   </html>
   ```

### HTTP Cookies & Web Caching

1. **Cookies**

   - Cookies: keeping "state"
   - Client: browser that uses cookies to store info about state
   - Server: cookie is associated with each user
   - Cookie header line in HTTP response message

   ```http
   HTTP/1.1 200 OK
   Connection: close
   Date: Tue, 09 Aug 2011 15:44:04 GMT
   Server: Apache/2.2.3 (CentOS)
   Last-Modified: Tue, 09 Aug 2011 15:11:03 GMT
   Content-Length: 6821
   Content-Type: text/html
   Set-cookie: <name>=<value>
   <html>
     <head>
       <title>CS101 Assignment Submission</title>
     </head>
     <body>
       <h1>Success!</h1>
     </body>
   </html>
   ```

2. **Web Caching** (proxy server)

   - Goal: satisfy client request without involving origin server
   - Cache acts as both client and server
   - Typically cache is installed by ISP (university, company, residential ISP)
   - Browser specifies cache in HTTP request
   - Cache returns HTTP response if object is in cache; otherwise cache requests object from origin server, then returns object to client

   ```http
   GET /somedir/page.html HTTP/1.1
   Host: www.someschool.edu
   Connection: close
   User-agent: Mozilla/5.0
   Accept-language: fr
   ```

   ```http
   HTTP/1.1 200 OK
   Connection: close
   Date: Tue, 09 Aug 2011 15:44:04 GMT
   Server: Apache/2.2.3 (CentOS)
   Last-Modified: Tue, 09 Aug 2011 15:11:03 GMT
   Content-Length: 6821
   Content-Type: text/html
   <html>
     <head>
       <title>CS101 Assignment Submission</title>
     </head>
     <body>
       <h1>Success!</h1>
     </body>
   </html>
   ```

## Electronic Email (E-mail)

Three major components:

1. User agents
2. Mail servers
3. Simple Mail Transfer Protocol (SMTP)

## DNS - The Internet's Directory Service

DNS (Domain Name System) is a distributed database implemented in a hierarchy of many name servers.

Host aliasing: map between host names and IP addresses (e.g. www.google.com -> 142.250.203.228).

## Peer-to-Peer File Distribution (P2P)

P2P file distribution is a distributed file distribution system in which clients can obtain file chunks from other clients.

## Video Streaming and Content Distribution Networks

Video streaming is a sequence of "moving images" that are sent in compressed form over the Internet and displayed by the viewer as they arrive.

Content distribution networks (CDNs) are a system of distributed servers that deliver web pages and other web content to a user based on the geographic locations of the user, the origin of the web page and a content delivery server.

### Streaming Challenges

- Continuous playout constraint: audio/video must play out at an appropriate rate
- Client interactivity: client can pause, rewind, fast-forward
- Content distribution: server must satisfy multiple clients simultaneously

### Streaming Multimedia: DASH

DASH (Dynamic Adaptive Streaming over HTTP) is a streaming technique that allows a client to adapt the media quality to the current network conditions.

### Content Distribution Networks

- CDN (Content Distribution Network) is a system of distributed servers that deliver web pages and other web content to a user based on the geographic locations of the user, the origin of the web page and a content delivery server.
- CDN is a network of replicated servers in many locations, deployed in multiple ISPs
- Goal: move content closer to end users

## Socket Programming with UDP, TCP

- Socket: a door between application process and end-end-transport protocol (UDP or TCP)
- Socket API: introduced in BSD4.1 UNIX, then adopted for Windows, allows application to specify transport protocol (UDP or TCP)
- Client must contact server
- Server process must first be running
- Server must have created socket (door) that welcomes client's contact

### UDP Datagram Sockets

- UDP: no "connection" between client and server
- UDP: no handshaking before sending data
- UDP: sender explicitly attaches IP destination address and port # to each packet
- UDP: receiver extracts sender IP address and port # from received packet
- UDP: no congestion control: UDP can blast away as fast as desired
- UDP: other UDP features

**Client Socket**

```python
from socket import *
serverName = 'hostname'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Input lowercase sentence:')
clientSocket.sendto(message.encode(), (serverName, serverPort))
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print(modifiedMessage.decode())
clientSocket.close()
```

**Sever Socket**

```python
from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print("The server is ready to receive")
while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
```

### TCP Connections

- TCP: point-to-point: one sender, one receiver
- TCP: reliable, in-order byte steam: no "message boundaries"
- TCP: pipelined: TCP congestion and flow control set window size
- TCP: full duplex data: bi-directional data flow in same connection
- TCP: connection-oriented: handshaking (exchange of control msgs) init's sender, receiver state before data exchange

### TCP Socket Programming

**Client Socket**

```python
from socket import *
serverName = 'hostname'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
sentence = input('Input lowercase sentence:')
clientSocket.send(sentence.encode())
modifiedSentence = clientSocket.recv(1024)
print('From Server:', modifiedSentence.decode())
clientSocket.close()
```

**Server Socket**

```python
from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print("The server is ready to receive")
while True:
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(1024).decode()
    capitalizedSentence = sentence.upper()
    connectionSocket.send(capitalizedSentence.encode())
    connectionSocket.close()
```
