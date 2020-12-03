import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> sequence = new ArrayList<Integer>();
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for(int i = 0; i < n; i++) {
            sequence.add(scanner.nextInt());
        }
        int sum = 0;
        int max = 0;
        int arrayLen = 0;
        for(int j = 0; j < n; j++) {
            if(sum + sequence.get(j) <= m) {
                sum += sequence.get(j);
                max = Integer.max(max, sum);
                arrayLen++;
            }
            else {
                while(arrayLen > 0) {
                    sum -= sequence.get(j - arrayLen);
                    arrayLen--;
                    if(sum + sequence.get(j) <= m) {
                        sum += sequence.get(j);
                        max = Integer.max(max, sum);
                        arrayLen++;
                        break;
                    }
                }
            }
        }
        System.out.println(max);
    }
}