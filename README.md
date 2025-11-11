<p align="center">
	<img src="https://img.shields.io/github/last-commit/joseevilasio/webserv_42?color=%2312bab9&style=flat-square"/>
</p>

<p align="center">
	<a href="https://github.com/joseevilasio/webserv_42/actions/workflows/doxygen.yml">
		<img src="https://github.com/joseevilasio/webserv_42/actions/workflows/doxygen.yml/badge.svg" alt="Doxygen Docs"/>
	</a>
</p>

# Webservinho

#### Finished in: 2025-11-11

This project was done in group with [Mariana Morais](https://github.com/marianaobmorais) and [Matheus Castro](https://github.com/malves-b)

---

## About

**Webservinho** is a fully functional **HTTP/1.1 web server**, written in **C++98**, developed from scratch as part of the **42 School curriculum**.

The goal was to reimplement the core of a real web server similar to **Nginx** using only low-level system calls (`socket`, `poll`, `read`, `write`, `fork`, `execve`, etc.).  

It handles multiple clients concurrently through non-blocking I/O, supports CGI execution, static content serving, uploads, custom error pages, and dynamic directory listing.

---

## Features

| Feature | Description |
|----------|--------------|
| **Non-blocking I/O** | Handles multiple clients concurrently using `poll()` |
| **HTTP/1.1 parser** | Supports `GET`, `POST`, and `DELETE` methods |
| **CGI execution** | Runs external scripts (Python, PHP, Perl, etc.) with full environment setup |
| **Static file server** | Serves HTML, CSS, JS, and binary files efficiently |
| **Autoindex generator** | Creates directory listings dynamically |
| **Uploads** | Handles file uploads via multipart forms |
| **Error pages** | Supports both default and custom HTML error pages |
| **Graceful shutdown** | Handles signals (`SIGINT`, `SIGTERM`) safely |
| **Logging system** | Structured logs in `./logs/` with timestamps |
| **Config parser** | Reads configuration files similar to Nginx (`server`, `location`, etc.) |

---

## Build

Clone the repository: 
```shell
git clone https://github.com/joseevilasio/webserv_42.git
```
Enter the cloned directory:
```shell
cd webserv_42
```
Run `make` to compile the program:
```shell
make
```

---

## Usage

```shell
./webserv default.conf
```

## Contributions

If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

### Message to students

If you are searching resources to learn more about your own cub3D, I encourage you to turn to your peers and the function manuals. Do not implement any code you do not understand and cannot code from scratch.
