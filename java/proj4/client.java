import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        try {
            // Connect to server running on localhost at port 12345
            Socket socket = new Socket("localhost", 12345);

            // Create input stream to receive data from server
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Read message from server
            String message = in.readLine();
            System.out.println("Message from server: " + message);

            // Close stream and socket
            in.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
