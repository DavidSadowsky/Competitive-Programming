import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> sequence = new ArrayList<Integer>();
        while (scanner.hasNextInt()) {
            sequence.clear();
            boolean inputting = true;
            while (inputting) {
                int num = scanner.nextInt();
                if (num == -999999) {
                    inputting = false;
                } else {
                    sequence.add(num);
                }
            }
            BigInteger currentMax;
            BigInteger localMaximum = BigInteger.valueOf(sequence.get(0));
            BigInteger localMinimum = BigInteger.valueOf(sequence.get(0));
            BigInteger globalMax = BigInteger.valueOf(sequence.get(0));
            for (int i = 1; i < sequence.size(); i++) {
                currentMax = localMaximum;
                localMaximum = localMaximum.multiply(BigInteger.valueOf(sequence.get(i))).max(localMinimum.multiply(BigInteger.valueOf(sequence.get(i)))).max(BigInteger.valueOf(sequence.get(i)));
                localMinimum = localMinimum.multiply(BigInteger.valueOf(sequence.get(i))).min(currentMax.multiply(BigInteger.valueOf(sequence.get(i)))).min(BigInteger.valueOf(sequence.get(i)));
                globalMax = globalMax.max(localMaximum);
            }
            System.out.println(globalMax);
        }
    }
}

