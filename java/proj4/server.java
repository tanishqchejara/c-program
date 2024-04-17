import java.io.*;
import java.net.*;

public class server {
    public static void main(String[] args) {
        try {
            // Create a server socket listening on port 12345
            ServerSocket serverSocket = new ServerSocket(12345);
            
            // Wait for client connection
            System.out.println("Server waiting for client connection...");
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected.");

            // Create output stream to send data to client
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            // Send a message to client
            out.println("Hello from server!");

            // Close streams and sockets
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
