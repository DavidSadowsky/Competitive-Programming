import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[] input = scanner.nextLine().trim().toCharArray();
        int backspaceCount = 0;
        for(int i = input.length - 1 ; i >= 0; i--) {
            if(input[i] == '<') {
                input[i] = '\0';
                backspaceCount++;
            }
            else if(backspaceCount > 0) {
                input[i] = '\0';
                backspaceCount--;
            }
        }
        System.out.println((new String(input)).replaceAll("\0", "").trim());
    }
}