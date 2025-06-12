import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.security.Key;
import javax.crypto.Cipher;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESedeKeySpec;
import javax.crypto.spec.IvParameterSpec;
import java.util.Base64;
import java.util.Base64.Encoder;

public class TripleDES {
    private byte[] key = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02,
            0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };

    private byte[] keyiv = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00 };

	public TripleDES(){}

     public String encode(String args) {
        byte[] encoding;
        try {
            encoding = Base64.getEncoder().encode(args.getBytes("UTF-8"));
        byte[] str5 = des3EncodeCBC(key, keyiv, encoding);
        byte[] encoding1 = Base64.getEncoder().encode(str5);
        return new String(encoding1);
        } catch (UnsupportedEncodingException e) {
            System.out.println("Error while encoding with DESede"+e.toString());
        }
        return null;
    }


    public String decode(String args) {
        try {
        byte[] decode = Base64.getDecoder().decode(args.getBytes("UTF-8"));
        byte[] str6 = des3DecodeCBC(key, keyiv, decode);
        String data=new String(str6);
        byte[] decode1 = Base64.getDecoder().decode(data.trim().getBytes("UTF-8"));
        return new String(decode1);
        } catch (UnsupportedEncodingException e) {
            System.out.println("Error while decoding with DESede"+e.toString());
        }
        return "u mistaken in try block";

        }



    private byte[] des3EncodeCBC(byte[] key, byte[] keyiv, byte[] data) {
        try {
            Key deskey = null;
            DESedeKeySpec spec = new DESedeKeySpec(key);
            SecretKeyFactory keyfactory = SecretKeyFactory.getInstance("desede");
            deskey = keyfactory.generateSecret(spec);

            Cipher cipher = Cipher.getInstance("desede/ CBC/PKCS5Padding");
            IvParameterSpec ips = new IvParameterSpec(keyiv);
            cipher.init(Cipher.ENCRYPT_MODE, deskey, ips);
            byte[] bout = cipher.doFinal(data);
            return bout;

        } catch (Exception e) {
            System.out.println("Des3EncodeCBC method error qualified name" + e.toString());
        }
        return null;

    }

    private byte[] des3DecodeCBC(byte[] key, byte[] keyiv, byte[] data) {
        try {
            Key deskey = null;
            DESedeKeySpec spec = new DESedeKeySpec(key);
            SecretKeyFactory keyfactory = SecretKeyFactory.getInstance("desede");
            deskey = keyfactory.generateSecret(spec);

            Cipher cipher = Cipher.getInstance("desede/ CBC/NoPadding");//PKCS5Padding NoPadding
            IvParameterSpec ips = new IvParameterSpec(keyiv);
            cipher.init(Cipher.DECRYPT_MODE, deskey, ips);
            byte[] bout = cipher.doFinal(data);

            return bout;

        } catch (Exception e) {
            System.out.println("Des3DecodeCBC method error qualified name" + e.toString());
        }

        return null;

    }

}