import java.net.*;
import java.io.*;

public class urlinfo {
    public static void main(String[] args) {
        // Define the URL
        String urlString = "https://example.com";

        try {
            // Create a URL object
            URL url = new URL(urlString);

            // Open a connection to the URL
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();

            // Set request method
            conn.setRequestMethod("GET");

            // Get the response code
            int responseCode = conn.getResponseCode();
            System.out.println("Response Code: " + responseCode);

            System.out.println("Content Type: " + conn.getContentType());
            System.out.println("Content Length: " + conn.getContentLength());
            System.out.println("Method: " + conn.getRequestMethod());
            System.out.println("Scheme: " + conn.getURL().getProtocol());
            // Get the domain of the URL
            String domain = url.getHost();
            System.out.println("Domain: " + domain);

            // Get cookies
            String cookies = conn.getHeaderField("Set-Cookie");
            if (cookies != null) {
                System.out.println("Cookies: " + cookies);
            } else {
                System.out.println("No cookies");
            }

            // Close the connection
            conn.disconnect();
        } catch (MalformedURLException e) {
            System.err.println("Invalid URL: " + urlString);
        } catch (IOException e) {
            System.err.println("Error reading from URL: " + e.getMessage());
        }
    }
}
