import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        try {
            // Connect to server running on localhost at port 12345
            Socket socket = new Socket("localhost", 12345);

            // Create input stream to receive data from server
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Create output stream to send data to server
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            // Send message to server
            out.println("Hello from client!");

            // Read and print response from server
            String serverResponse = in.readLine();
            System.out.println("Message from server: " + serverResponse);

            // Close streams and socket
            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
