import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {

        // 1) 장르별 총 재생수
        Map<String, Integer> genreTotal = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genreTotal.put(genres[i], genreTotal.getOrDefault(genres[i], 0) + plays[i]);
        }

        // 2) 장르 총 재생수 기준 정렬
        List<Map.Entry<String, Integer>> genreList = new ArrayList<>(genreTotal.entrySet());
        genreList.sort(Map.Entry.<String, Integer>comparingByValue().reversed());

        // 3) 각 장르별 노래 모음
        Map<String, List<int[]>> musicMap = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            musicMap.putIfAbsent(genres[i], new ArrayList<>());
            musicMap.get(genres[i]).add(new int[]{i, plays[i]});
        }

        // 4) 장르 안에서 정렬 (재생수 desc, index asc)
        for (String g : musicMap.keySet()) {
            musicMap.get(g).sort((a, b) -> {
                if (b[1] == a[1]) return a[0] - b[0];
                return b[1] - a[1];
            });
        }

        // 5) 결과 리스트
        List<Integer> result = new ArrayList<>();

        for (var g : genreList) {
            List<int[]> list = musicMap.get(g.getKey());

            result.add(list.get(0)[0]);
            if (list.size() > 1) result.add(list.get(1)[0]);
        }

        // 6) 리스트 -> 배열
        return result.stream().mapToInt(i -> i).toArray();
    }
}
