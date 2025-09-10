#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

class WebServer {
private:
    int server_fd;
    int port;
    
public:
    WebServer(int port = 8080);
    ~WebServer();
    
    void start();
    void handleRequest(int client_socket);
    std::string generateResponse(const std::string& request);
    bool isCoffeeRequest(const std::string& request);
};

#endif