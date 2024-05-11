package Task3.hasGroupsSizeX;

import java.util.HashMap;

public class Main {

    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static boolean hasGroupsSizeX(int[] deck) {
        if (deck.length == 0)
            return true;

        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int card : deck) {
            freq.put(card, freq.getOrDefault(card, 0) + 1);
        }

        int commonGCD = freq.entrySet().iterator().next().getValue();
        for (int value : freq.values()) {
            commonGCD = gcd(commonGCD, value);
        }

        return commonGCD >= 2;
    }

    public static void main(String[] args) {
        int[] deck1 = {1, 2, 3, 4, 4, 3, 2, 1};
        int[] deck2 = {1, 1, 1, 2, 2, 2, 3, 3};

        System.out.println("Example 1: " + hasGroupsSizeX(deck1));
        System.out.println("Example 2: " + hasGroupsSizeX(deck2));
    }
}
