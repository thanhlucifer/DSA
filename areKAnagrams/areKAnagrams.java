import java.util.HashMap;
import java.util.Map;

public class areKAnagrams {
    public static boolean areKAnagrams(String str1, String str2, int k) {
        if (str1.length() != str2.length())
            return false;

        Map<Character, Integer> frequencyMap = new HashMap<>();

        // Step 1: Create frequency map for str1
        for (char c : str1.toCharArray())
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);

        // Step 2: Adjust frequency map based on str2
        for (char c : str2.toCharArray()) {
            if (frequencyMap.containsKey(c) && frequencyMap.get(c) > 0)
                frequencyMap.put(c, frequencyMap.get(c) - 1);
        }

        int count = 0;

        // Step 3: Count remaining characters in the map
        for (int value : frequencyMap.values())
            count += value;

        return count <= k;
    }

    public static void main(String[] args) {
        String str1 = "hello";
        String str2 = "world";
        int k = 2;

        if (areKAnagrams(str1, str2, k))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
