import java.math.BigInteger;
import java.util.Random;
public class dsaAlg {
public static void main(String[] args) {
Random rand = new Random();
BigInteger p = BigInteger.valueOf(10601), q =
BigInteger.valueOf(53);
BigInteger g = BigInteger.valueOf(5582);
BigInteger x = new BigInteger(q.bitLength(), rand).mod(q);
BigInteger y = g.modPow(x, p);
BigInteger k = new BigInteger(q.bitLength(), rand).mod(q);
BigInteger r = g.modPow(k, p).mod(q);
BigInteger hash = new BigInteger(p.bitLength(), rand);
BigInteger s =
k.modInverse(q).multiply(hash.add(x.multiply(r))).mod(q);
System.out.println("\nSimulation of Digital SignatureAlgorithm\n");
System.out.println("Global Public Key Components:");
System.out.println("p: " + p + "\nq: " + q + "\ng: " + g);
System.out.println("\nSecret Information:");
System.out.println("x (private): " + x + "\nk (secret): " + k + "\ny(public): " + y + "\nh (hash): " + hash);
System.out.println("\nGenerating Digital Signature:");
System.out.println("r: " + r + "\ns: " + s);
BigInteger w = s.modInverse(q);
BigInteger u1 = hash.multiply(w).mod(q);
BigInteger u2 = r.multiply(w).mod(q);
BigInteger v = g.modPow(u1, p).multiply(y.modPow(u2,
p)).mod(p).mod(q);
System.out.println("\nVerifying Digital Signature:");
System.out.println("w: " + w + "\nu1: " + u1 + "\nu2: " + u2 +"\nv: " + v);
if (v.equals(r)) {
System.out.println("\nSuccess: Digital signature is
verified!\n" + r);
} else {
System.out.println("\nError: Incorrect digital signature.");
}
}
}