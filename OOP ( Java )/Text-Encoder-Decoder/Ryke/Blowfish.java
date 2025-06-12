import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
import java.lang.Exception;

public class Blowfish{   
    
    private final String key = "123";
    
	public Blowfish(){}
    public String encrypt(String password){
        try{
            byte[] keyData = (key).getBytes();
            SecretKeySpec skc = new SecretKeySpec(keyData, "Blowfish");
            Cipher cipher = Cipher.getInstance("Blowfish");
            cipher.init(Cipher.ENCRYPT_MODE, skc);
            byte[] has = cipher.doFinal(password.getBytes());
            return new String(Base64.getEncoder().encode(has));
            
        }catch(Exception ex){
            System.out.println("ENCRYPT BLOWFISH ERROR "+ex.toString());
            return null;
        }
    }
    
    public String decrypt(String string){
        try{
            byte[] keyData = (key).getBytes();
            SecretKeySpec skc = new SecretKeySpec(keyData, "Blowfish");
            Cipher cipher = Cipher.getInstance("Blowfish");
            cipher.init(Cipher.DECRYPT_MODE, skc);
            byte[] has = cipher.doFinal(Base64.getDecoder().decode(string));
            return new String(has);
            
        }catch(Exception ex){
            System.out.println("DECRYPT BLOWFISH ERROR "+ex.toString());
            return null;
        }
    }
}
       
