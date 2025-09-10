#include "../includes/Class.hpp"

WebServer::WebServer(int port) : server_fd(-1), port(port) {}

WebServer::~WebServer() {
    if (server_fd != -1) {
        close(server_fd);
    }
}

void WebServer::start() {
    struct sockaddr_in address;
    int opt = 1;
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Setsockopt failed" << std::endl;
        return;
    }
    
    // Configure address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return;
    }
    
    // Listen for connections
    if (listen(server_fd, 10) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return;
    }
    
    std::cout << "Server listening on port " << port << std::endl;
    
    // Accept connections
    while (true) {
        int client_socket;
        socklen_t addrlen = sizeof(address);
        
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }
        
        handleRequest(client_socket);
        close(client_socket);
    }
}

void WebServer::handleRequest(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    
    std::string request(buffer);
    std::string response = generateResponse(request);
    
    send(client_socket, response.c_str(), response.length(), 0);
}

std::string WebServer::generateResponse(const std::string& request) {
    if (isCoffeeRequest(request)) {
        // Return HTTP 418 "I'm a teapot" for coffee requests
        return "HTTP/1.1 418 I'm a teapot\r\n"
               "Content-Type: text/plain\r\n"
               "Content-Length: 52\r\n"
               "\r\n"
               "I'm a teapot, not a coffee machine! Try tea instead.";
    }
    
    // Default response for other requests
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/html\r\n"
           "Content-Length: 85\r\n"
           "\r\n"
           "<html><body><h1>Welcome to WebServ!</h1><p>Try /coffee for something fun!</p></body></html>";
}

bool WebServer::isCoffeeRequest(const std::string& request) {
    // Check if the request is for coffee-related endpoints
    return request.find("GET /coffee") != std::string::npos ||
           request.find("POST /coffee") != std::string::npos ||
           request.find("/brew") != std::string::npos;
}

int main() {
    WebServer server(8080);
    server.start();
    return 0;
}
