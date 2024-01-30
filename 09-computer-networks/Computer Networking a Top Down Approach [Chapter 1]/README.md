# Computer Networks and the Internet

## What is the Internet?

### A Nuts-and-Bolts View

- A collection of billions of computing devices, and packet switches interconnected by links.
- A collection of hardware and software components executing protocols that define the format and the order of messages exchanged between two or more communicating entities, as well as the actions taken on the transmission and/or receipt of a message or other event.
- A "network of networks".

### A Services View

- A place I go for information, entertainment, and to communicate with people.
- A platform for building network applications.

### What is a Protocol?

A protocol define **format**, **order** of messages sent and received among network entities, and **actions** taken on message transmission receipt.

## Network Edge

**End systems (hosts):** run application programs (e.g., Web, email); at **edge** of network
**Access Networks:** wired, wireless communication links connecting end systems to network edge (DSL, cable, FTTH, LTE, 5G, etc.)
**Physical media:** copper, fiber, radio, satellite (transmission rate: **bandwidth**)

### Examples of Access Networks

- Ethernet: Up to 100's Gbps per link.
- 802.11 WiFi: 10’s to 100’s of Mbps per device.
- Cable access network: Up to 10’s to 100’s of Mbps downstream per user.
- Digital subscriber line (DSL): Up to 10’s of Mbps downstream per user.
- Cellular 4G: Up to 10’s Mbps per device.

## Network Core

- mesh of interconnected router
- two key network-core functions: **routing** and **forwarding**

- **packet-switching**:
  - **store-and-forward**: entire packet must arrive at router before it can be transmitted on next link
  - **queuing delays** and **loss** when packet arrives to full queue
- **circuit-switching**: end-end resources allocated to, reserved for "call" between source & dest
  - **dedicated resources**: no sharing
  - **circuit-like** (guaranteed) performance
  - **call setup** required

## Network Performance

- **Delay**: how long it takes for a bit to travel from sender to receiver
- **Loss**: packets that arrive to full queue are dropped
- **Throughput**: rate (bits/time unit) at which bits transferred between sender/receiver

## Protocol Layers and Service Models

1. **Application:** supporting network applications
   - HTTP, IMAP, SMTP, DNS
2. **Transport:** process-process data transfer
   - TCP, UDP
3. **Network:** routing of datagrams from source to destination
   - IP, routing protocols
4. **Link:** data transfer between neighboring network elements
   - Ethernet, 802.11 (WiFi), PPP
5. **Physical:** bits “on the wire”

## Network Security

- Denial of Service (DoS)
- Packet Sniffing
- IP spoofing

### Lines of Defense

- **Authentication:** Who you are?
- **Confidentiality:** via encryption
- **Integrity Check:** digital signature
- **Access Restrictions:** password-protection
- **Firewalls**

## History of Computer Networking and the Internet

- 1961: Kleinrock - queueing theory shows effectiveness of packet-switching
- 1964: Baran - packet-switching in military nets
- 1967: ARPAnet conceived by Advanced Research Projects Agency
- 1969: first ARPAnet node operational
- 1972: ARPAnet public (15 nodes) demonstration (NCP)
- 1974: Cerf and Kahn - architecture for interconnecting networks
  - minimalism, autonomy - no internal changes required to interconnect networks
  - best effort service model
  - stateless routers
  - decentralized control
- 1976: Ethernet at Xerox PARC
- Late 70's: proprietary architectures: DECnet, SNA, XNA
- 1983: deployment of TCP/IP
- 1982: SMTP e-mail protocol defined
- 1983: DNS defined for name-to-IP-address translation
- 1985: FTP protocol defined
- 1988: TCP congestion control
- early 1990's: commercialization of the Internet
- 1991: NSF lifts restrictions on commercial use of NSFnet (decommissioned, 1995)
- early 1990s: Web
  - hypertext [Bush 1945, Nelson 1960's]
  - HTML, HTTP: Berners-Lee
  - 1994: Mosaic, later Netscape
- Mid 1990's: commercialization of the Web
- late 1990's - 2000's: more killer apps: instant messaging, P2P file sharing
