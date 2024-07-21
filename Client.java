import java.io.*;
import java.net.*;

class Client
{
    public static void main(String Arg[]) throws Exception
    {
        System.out.println("Client Application is running...");

        Socket sobj= new Socket("localhost",2100);
        System.out.println("Client gets succesfully connected...");

        PrintStream PS = new PrintStream(sobj.getOutputStream());
        BufferedReader br1= new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        BufferedReader br2= new BufferedReader(new InputStreamReader(System.in));
        String str1,str2;

        System.out.println("Messenger Started...");
        while(!(str1=br2.readLine()).equals("end"))
        {
            PS.println(str1);
            str2=br1.readLine();
            System.out.println("Enter message for server : ");
            System.out.println("Server says : "+str2);
        }
        System.out.println("Thank You for using Messenger.");
    }
}
