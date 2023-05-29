# loco-protocol-c

Loco protocol de/serializer written in C

**This project is under development.**

# Test

This project has been tested in the following environment:

Test Device: Apple Macbook Pro (M1)

- GCC 11.1.0 aarch64-apple-darwin32
- OpenSSL 1.1.1t (7 Feb 2023)
- macOS Ventura 13.3.1

![GETCONF response from booking-loco.kakao.com](static/GETCONF_booking.png)

- Receive data from "booking-loco.kakao.com" using the LOCO protocol (unencrypted packets)

# To-Do

- [x] Loco Default(non-secure) Packet
- [x] Loco Secure Packet (**Working**)
- [ ] Default SSL TCP Socket

# How to Build

To use the Loco protocol features of this library, you need to install OpenSSL. (Handshake, Secure Packet, etc...)

# License

This project is under the MIT License.
For more information, see `LICENSE.md`
