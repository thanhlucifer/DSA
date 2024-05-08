package Task3.groupAnagrams;

import java.util.*;

public class groupAnagrams {

    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<>();

        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            anagrams.computeIfAbsent(sorted, k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(anagrams.values());
    }

    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> result = groupAnagrams(strs);

        for (List<String> group : result) {
            System.out.println(group);
        }
    }
}
