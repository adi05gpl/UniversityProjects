import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.Exception;

public class MyFileWriter{
    
    public MyFileWriter()throws Exception{}

    public void writeMyFile(String text1, String text2, String text3) throws Exception{
            FileWriter fw = new FileWriter("RykeTextFile.txt");
            PrintWriter out = new PrintWriter(fw);
                    out.println("User Input: ");
                    out.write(text1);
                    out.println("");
                    out.println("");
                    out.println("ENCRYPTION: ");
                    out.write(text2);
                    out.println("");
                    out.println("");
                    out.println("DECRYPTION: ");
                    out.write(text3);
                    out.flush();
                    out.close();
    }
}
