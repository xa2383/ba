import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
class AES {
private static final byte[] KEY = "my_super_secret_".getBytes();
private static final byte[] IV = new byte[16];
public static String encrypt(String str) {
try {
Cipher cipher =
Cipher.getInstance("AES/CBC/PKCS5Padding");
cipher.init(Cipher.ENCRYPT_MODE, newSecretKeySpec(KEY, "AES"), new IvParameterSpec(IV));
return
Base64.getEncoder().encodeToString(cipher.doFinal(str.getBytes()));
} catch (Exception e) {
return null;
}
}
public static String decrypt(String str) {
try {
Cipher cipher =
Cipher.getInstance("AES/CBC/PKCS5Padding");
cipher.init(Cipher.DECRYPT_MODE, newSecretKeySpec(KEY, "AES"), new IvParameterSpec(IV));
return new
String(cipher.doFinal(Base64.getDecoder().decode(str)));
} catch (Exception e) {
return null;
}
}
}
public class Main {
public static void main(String[] args) {
String original = "SSIT ISE";
String encrypted = AES.encrypt(original);
String decrypted = AES.decrypt(encrypted);
System.out.println(original);
System.out.println(encrypted);
System.out.println(decrypted);
} }